#ifndef OLED_display
#define OLED_display

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>


#define pin_disp_rst 9
#define pin_disp_a0 8
#define pin_disp_cs 10




Adafruit_ST7735 tft = Adafruit_ST7735(pin_disp_cs, pin_disp_a0, pin_disp_rst);



void oled_display_setup(){

  tft.initR(INITR_BLACKTAB);      // initialization with black background

  tft.setRotation(135);           // rotate display view to horizontal
}


void oled_disp_show_text(char *names[], int numbers[], int current_row, int selected){
  tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 2);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(2);
  tft.println(names[0]);
  tft.setCursor(0, 30);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(1);
  for(int i = 1; i < 7;i++){
    tft.setTextColor(ST77XX_RED);
    if(i==current_row){
        tft.setTextColor(ST77XX_GREEN);
    }
    if(i==current_row && selected){
      tft.setTextColor(ST77XX_BLUE);
    }
    tft.print(names[i]);
    if(numbers[i] != -9999){
      tft.print(numbers[i]);
    }
    tft.println("");
  }
}

void oled_disp_show_text_easy(char *zeile1, char *zeile2, char *zeile3, char *zeile4, char *zeile5, char *zeile6, char *zeile7){
  tft.setTextWrap(false);
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0, 2);
  tft.setTextColor(ST77XX_YELLOW);
  tft.setTextSize(3);
  tft.println(zeile1);
  tft.setCursor(0, 40);
  tft.setTextColor(ST77XX_RED);
  tft.setTextSize(1);
  tft.println(zeile2);
  tft.println(zeile3);
  tft.println(zeile4);
  tft.println(zeile5);
  tft.println(zeile6);
  tft.println(zeile7);
 
}



#endif
