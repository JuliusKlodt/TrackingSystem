import serial
import cv2 as cv2
import numpy as np
import matplotlib.pyplot as plt


arduino = serial.Serial(port='COM3', baudrate=250000, timeout=.1)
image_size_x = 1280
image_size_y = 720




def tracking():
    video_capture = cv2.VideoCapture(0)
    while True:
        ret, current_image = video_capture.read()
        dim = (image_size_x, image_size_y)
        current_image = cv2.resize(current_image, dim, interpolation = cv2.INTER_AREA)

        real_faces, other_objects, tracked_face = detect_and_return_rectangles(current_image)
        steps_x, speed_x, steps_y, speed_y = process_rectangle_to_steps(tracked_face)
        send_movement_to_ardunio(steps_x, speed_x, steps_y, speed_y)
        show_box(current_image, real_faces, other_objects, tracked_face)



def detect_and_return_rectangles(image):
        haar_cascade_face = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
        eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml') 

        #convert the test image to gray scale as opencv face detector expects gray images
        gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

        # Applying the haar classifier to detect faces
        faces_rect = haar_cascade_face.detectMultiScale(gray_image, 1.3,5,0)

        eyes_rect = eye_cascade.detectMultiScale(gray_image)

        real_faces = []
        other_objects = []
        for (x,y,w,h) in faces_rect:
            eyes = []
            for (ex,ey,ew,eh) in eyes_rect:
                if(ex > x and ex+ew < x+w and ey > y and ey+eh < y+h):
                    eyes.append((ex,ey,ew,eh))
            if(len(eyes) >= 2):
                real_faces.append((x,y,w,h,eyes))
            else:
                other_objects.append((x,y,w,h))

        biggest_face = [0,0]
        index = 0
        for (x,y,w,h,eyes) in real_faces:
            if(w*h> biggest_face[1]):
                biggest_face[0] = index
                biggest_face[1] = w*h
            index = index + 1
        
        tracked_face = ()
        if(len(real_faces)>0):
            tracked_face = real_faces[biggest_face[0]]


        return real_faces, other_objects, tracked_face

def process_rectangle_to_steps(tracked_face):
        if(len(tracked_face) == 0):
            return 0,0,0,0
        
        speed_x = 400
        speed_y = 400
        steps_x = 0
        steps_y = 0
        multiplier_x = 13
        multiplier_y = 0.8


        x = tracked_face[0]
        y = tracked_face[1]
        w = tracked_face[2]
        h = tracked_face[3]


        
        distance_right = image_size_x - (x+w)
        distance_down = image_size_y - (y+h)

        if(distance_right > x):
            steps_x = int((distance_right/x)*multiplier_x)
        else:
            steps_x = int(-((x/distance_right)*multiplier_x))

        if(distance_down > y):
            steps_y = int((distance_down/y)*multiplier_y)
        else:
            steps_y = int(-((y/distance_down)*multiplier_y))
            

        return steps_x, speed_x, steps_y, speed_y



def show_box(image, real_faces, other_objects, tracked_face):
    for (x,y,w,h, eyes) in real_faces:
        cv2.rectangle(image, (x, y), (x+w, y+h), (0, 200, 0), 2)
        for (ex,ey,ew,eh) in eyes:     
            cv2.rectangle(image, (ex, ey), (ex+ew, ey+eh), (0, 200, 40), 2)


    for (ex,ey,ew,eh) in other_objects:
        cv2.rectangle(image,(ex,ey),(ex+ew,ey+eh),(0,100,0),2)


    if(len(tracked_face)>0):
        cv2.rectangle(image, (tracked_face[0], tracked_face[1]), (tracked_face[0]+tracked_face[2], tracked_face[1]+tracked_face[3]), (0, 255, 0), 2)
        for (ex,ey,ew,eh) in tracked_face[4]:     
            cv2.rectangle(image, (ex, ey), (ex+ew, ey+eh), (255, 255, 0), 2)




    cv2.imshow("Live-feed", image)
    cv2.waitKey(10)
    

	 
    

def send_movement_to_ardunio(steps_x, speed_x, steps_y, speed_y):
    string_length = 5
    steps_x = str(steps_x).zfill(string_length)
    steps_y = str(steps_y).zfill(string_length)
    speed_x = str(speed_x).zfill(string_length)
    speed_y = str(steps_y).zfill(string_length)

    



    command = steps_x  + steps_y + speed_x + speed_y + "E"
    arduino.write(bytes(command, 'utf-8'))
    data = arduino.readline()
    print(data)



tracking()