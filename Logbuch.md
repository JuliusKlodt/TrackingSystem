# Logbuch und Gedanken

## 11.12.2021
- Überlegungen zur Platzierung des Raspberry Pi's und einer Powerbank
- Vertiefung in Hauptplatform für Raspi
- Überlegungen für Steppermotor Driver, TMC2208
==> Wahrscheinlich eigene Platine entwickeln für 2xTMC2208 und 2x A3144 Hall Effect Sensor zum Kalibrieren

## 12.12.2021
- Überlegung eigene Platine mit EasyEDA zu entwickeln um Raspi mit TMC2208 und A3144 zu verbinden
- Modellierung des Abstandshalters mit Einschub für A3144 (kommt zwischen Motor und rechten tilt Fuß)
- Löcher an 64 Zahnrad zur Befestigung an Kamerabefestigung und für Kugellager
- Entwickelung eines Schaltplans für Verbindung von Raspi mit TMC2208 und A3144 in EasyEDA

## 13.12.2021
- Arbeit an Schaltplan in EasyEDA, TMC2208 anstatt 2x8 female pins, dadurch Abstand der Löcher in Platine exakt
- Überführung des Schaltplans auf Platine und Platzierung der Teile
- Treffen mit Thomas Baumgärtner in Moodle um 15 Uhr, um übers 3D Drucken zu sprechen.
- Drucken sollte klappen, bis auf 200mm Hauptplattform. Verschiedene Farben möglich. Er ist bis Ende Januar da, danach erstmal keiner verantwortlich für 3D Drucker
- Loch an rechtem Fuß für Kabelführung von Motor und Hall Effect Sensor
- Vertiefung für Magnet an statischer Basis
- Vertiefung für Hall Efect Sensor mit Kabelführungskanal an Hauptplattform
- Überlegung für Display und Menüführung
- https://www.youtube.com/watch?v=0dAcabcoKvg für rotary encoder programmierung als Quelle

## 14.12.2021
- Zusammenstellung aller Komponenten die bestellt werden sollen
- Löcher an Hauptplattform zur Befestigung einer Box, in welcher die ganze Elektronik organisiert werden soll
- Erstellung einer Befestigung um Pan-Tilt System auf 2 Alu-Rohren zu Befestigen und mit Motor Präzise zu Steuern

## 03.01.2021
- Füße für Slider erstellt
- 2 verschiedene Methoden um Zahnriemen an Fuß zu befestigen
- Befestigung an Rohr von eckig und beidseitig nutzbar zu einseitignutzbar und auf anderer Seite rund
- ==> Vorteil, dass Motor weiter oben, sodass weiter weg von Boden

## 04.01.2021
- Halterung für Motor, Umlenkrollen und 2 Magnetsensoren an Platte an Slider
- Kabelführung in der Halterung beachtet und das Zahnriemen nirgends schleift

## 05.01.2021
- Display, Joystick, Raspi grob modelliert um anschaulicher Elektronikbox planen zu können
- Erstellung der äußeren Elektronikbox, sodass Kamera bei 90° Schwenk gegen nix kommt

## 06.01.2021
- Elektronikbox in 5 Teile gegliedert um drucken zu können
- Kabelführungen in Elektronikbox integriert
- Löcher an Wänden der Elektronikbox. Nicht sicher ob druckbar. Wenn nicht, einfach Objekt aus den Schritten vor den Löchern entnehmen
- Zusammenstellung aller Komponenten

## 07.01.2021
- Platte zur Stabilisierung der Achsen durch Umlenkrollen konstruiert
- Alle Teile als STL Datei abgespeichert
- Neue Teile an Herrn Baumgärtner gesendet
- Baumgärtner schon folgende Teile gedruckt: Statische Basis, Rechte Kamerahalterung, Kugeleinführungsstopfen, Abstandhalter mit Sensorhalterung, 21 Zahnrad für Plattformdrehung, 17 Zahnrad für Plattformdrehung, Kamerabefestigung, Linke Kamerahalterung
- Versucht Joystick, Display und Hall Effect Sensor mit Raspi zu verbinden.
- Problem, da Raspi nur digital Input, (hab ich nicht beachtet gehabt)
- Magnet Sensor mit binärer Ausgabe funktioniert
- Joystick funktioniert nicht richtig, da nur runter, rechts, drücken erkannt wird. Nicht links hoch oder irgendwelche zwischenstufen
- Display funktioniert aber bis jetzt kein brauchbarer Output
- Idee um Probleme zu lösen, Arduino Nano nutzen um Analoge Inputs in Digitales SIgnal zu wandeln und an Raspi zu schicken.
- Arduino und Raspi sollen also über selbst entwickelten Bus kommunizieren?!?! ==> Erstmal nicht soo wichtig da steuerung mit display und joystick nicht notwendig für arbeit sind und ich mit der Zeit aufpassen muss
