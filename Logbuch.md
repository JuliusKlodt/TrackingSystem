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

## 03.01.2022
- Füße für Slider erstellt
- 2 verschiedene Methoden um Zahnriemen an Fuß zu befestigen
- Befestigung an Rohr von eckig und beidseitig nutzbar zu einseitignutzbar und auf anderer Seite rund
- ==> Vorteil, dass Motor weiter oben, sodass weiter weg von Boden

## 04.01.2022
- Halterung für Motor, Umlenkrollen und 2 Magnetsensoren an Platte an Slider
- Kabelführung in der Halterung beachtet und das Zahnriemen nirgends schleift

## 05.01.2022
- Display, Joystick, Raspi grob modelliert um anschaulicher Elektronikbox planen zu können
- Erstellung der äußeren Elektronikbox, sodass Kamera bei 90° Schwenk gegen nix kommt

## 06.01.2022
- Elektronikbox in 5 Teile gegliedert um drucken zu können
- Kabelführungen in Elektronikbox integriert
- Löcher an Wänden der Elektronikbox. Nicht sicher ob druckbar. Wenn nicht, einfach Objekt aus den Schritten vor den Löchern entnehmen
- Zusammenstellung aller Komponenten

## 07.01.2022
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

## 10.01.2022
- Herausgefunden, dass man Raspi und Arduino über Serielle Schnittstelle integriert in USB kommuniezieren lassen kann. Also Stromversorgung und Kommunikation in einem
- Ob Strom und Kommunikation zu Arduino über USB oder 4 pins ist egal
- Konstruktion einer Platte auf Raspi, damit Raspi Elektronik von Kabeln und Arduino getrennt
- Glücklicherweise genügend Platz für Arduino in Elektronikbox
- Schrauben gezählt und bestellt
- Die letzten Teile und Änderungen an Herrn Baumgärtner geschickt zum Drucken
- Komilitone in Mannheim, neben meiner WG, hat 3D Drucker. HAb gefragt, ob er mir das letzte Teil (Hauptplattform) welches nicht an DHBW gedruckt werden kann ausdrucken kann
- Joystick und Display zur Steuerung am Arduino zum laufen gebracht.  

## 11.01.2022
- Herr Baumgärtner bietet an, dass ich nächste Woche an die DHBW kommen kann um Teile abzuholen und zu bearbeiten (schleifen etc.). Dann wahrscheinlich auch alles zusammenbauen und löten
- Gedankengang: Erde dreht sich 360° am Tag ==> 360/24/60=0,25  ==> 0,25° pro Minute
- Motor Schrittwinkel 1,8°
- Statische Basis= 144 Zähne  ==> x / 144 * 1,8 = 0,125/0,25
- x = 10 / 20
- ==> Zahnrad mit 10 oder 20 Zähnen könnte nutzbar sein, um Kamera wenn entlang der Erdachse ausgerichtet, mit Erdrotation mitzudrehen


## 18.01.2022
- War im Labor an der DHBW und habe Teile abgeholt und dort von 13-18:30 Uhr Teile bearbeitet
- Entgrätet, geschliffen und geguckt was gut lief und nicht gut lief
- Viel gelernt übers 3D-Drucken ==> Unpräziser als gedacht und große Teile verziehen sich gerne beim Abkühlen
- Oft zu wenig/keine Toleranz gelassen, was zu unnötig viel schleifen (21-01 Uhr morgens) geführt hat
- Zahnräder erstaunlich gut und können direkt genutzt werden
- Kontakt mit Wassilij Kaiser hergestellt, der sich ab nächster Woche um die 3D-Drucker kümmern wird
- Meisten Sachen laufen aber erstaunlich gut. Z.B. selsbt entwickeltes Kugellager
- Große Unterschiede zwischen den 2 verwendeten 3D-Drucker, Ultimaker 2 deutlich besser als anderer

## 19.01.2022
- Selbst entwickelte Platine mit 98 Lötstellen zusammen gelötet und getestet ==> funktioniert super
- Platine und Arduino passen mit den Schrauben perfekt auf die vorhergesehenen Abstandshalter auf der Elektronikbox
- TMC2208 Treiber Spannugn eingestellt
- Ein paar Teile müssen neu gedruckt werden, da nicht mit Schleifen möglich wäre es richtig zu machen
- Neu zu druckende Teile in Auftrag gegeben

## 23.01.2022
- Angefangen Software zu designen
- Ardunio-Software in C ==> Organisation in mehrere Header-Files

## 24.01.2022
- Software und Pinbelegung organisiert
- Testsoftware um Hardware zu testen
- Alle Analogen Pins als Digital Output möglich bis auf A6/A7, welche ich natürlich genutzt habe und sehr SEHR lange nicht darauf gekommen bin
- Probleme beim Verkabeln

## 25.01.2022
- In DHBW Labor ==> Magnetsensoren verlötet
- Bearbeitung von Teilen wor z.B. Löcher zu klein waren
- Meeting mit Herrn Schultheis, ab jetzt wöchentlich Dienstags
- Neu ausdrucken von Front, Joystickhalterung - Elektronikbox, Objektivhalterung, Arduino-Halterung
- Abbruch des Drucks, da Ecken sich gelöst haben ==> Wahrscheinlich aufgrund abrundeungen in CAD Modell
- ABrundungen in CAD entfernt ==> Erfolgreich neu ausgedruckt

## 26.01.2022
- CAD Modell von Joystickhalterung angepasst und neuausgedruckt
- Gedanken gemacht, was mit alten Teilen/PLA-Müll passiert ==> https://recyclingfabrik.com ist eine gute Option um nachhaltig zu arbeiten
- Zusammenbau von weiteren Teilen
- Joystickhalterung funktioniert, schrauben aber noch auf halbe mm nicht perfekt
- Test-Software zum gleichzeitigen Bewegen der Motoren ==> Problem Mehrere Motoren in der gleichen Zeit unterschiedlich viele steps
- ==> Lösung eventuell Threads?!?
- Verkabelung in Elektronikbox mit jumper kabeln nicht optimal ==> Muss gelötet werden
- Objektivhalterung ohne Stützstruktur gedruckt ==> geht gut obwol teilweise in Luft gedruckt
- ==> Passt perfekt mit Objektiv

## 27.01.2022
- 1/4" Schraube für Kamera gedruckt ==> Geht erstaunlich gut und fixiert Kamera fest
- Test Kamerasteurung mit Joystick
- Anforderungen an Sofware geschrieben

## 28.01.2022
- Research zu Multithreading in C
- Anfang eines Flow-Charts des main-loops

## 29.01.2022
- Arbeit an UMl, FlowChart, Menü-Baum, User-Stories

## 01.02.2022
- Überführung von UML und User Stories in Formate die GitHub unterstützt
- Verlötung der Kabel im inneren der Elektronikbox an DHBW
- Besprechung der Struktur des Berichts

## 02.02.2022
- Abholung der 8 Teile Befestigung 2cm Rohr
- Innere Auswölbung war mit 8,8mm Kugeln, 9mm Kugeln war besser
- Hardware Tests, jetzt fertig

## 04.02.2022
- Aufgabenstellung erstellt
- Algorithmus zur gleichzeitigen Steuerung mehrerer Motoren gleichzeitig mit verschiedenen Geschwindigkeiten

## 05.02.2022
- Algorithmus verbessert / zum Funktionieren gebracht
- Positionssystem und Grenzen implementiert

## 10.02.2022
- Serielle Kommunikation C <=> Python (Arduino <=> PC)
- Gab viele Probleme mti Codierung/Decodierung

## 13.02.2022
- Erstes mal funktioniert Serielle Kommunikation
- Tracking funktioniert, sehr ruckelig, Probleme wenn mehr als ein Gesicht, erkennt manchmal random wo anders Gesichter
- Frage: Welches Gesicht soll getrackt werden?
- Einstellungen des Trackings in Python
- Optimierung der Gesichtserkennung durch Verknüpfung mit Augenerkennung & immer nur Gesicht erkenn, wenn 2 Augen drinnen sind
- Immer nur größtes echtes Gesicht (mit 2 Augen) tracken

## 14.02.2022
- Aufgabenstellung anpassen
- LaTex einrichten

## 16.02.2022
- Alle CAD-Modelle durchgehen, anpassen & bennen
- Git-Aktualisieren



