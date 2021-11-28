# Objekt verfolgendes Kamera-System
---------------------------------

In diesem Git Repository wird eine Studienarbeit der DHBW Manhheim realisiert.

Zielsetzung dieser Arbeit ist es, ein System zu entwickeln, welches eine Kamera 2-dimensional (pan-tilt) bewegen kann, 
und Objekte wie Menschen, somit immer im Bild der Kamera verfolgt.


Das Projekt ist somit in 2 Teile gegliedert.


## Hardware
Zuerst wird mithilfe der Software FreeCAD ein System modeliert um eine Kamera (Sony A7 R2, Tamron 28-70mm f2.8, ca. 1,2 kg) zu bewegen.






## Software
Die Kamera liefert per HDMI ein live Bild an einen Raspberry Pi. Dieser soll mit Hilfe von vorhandenen machine-learning Bibliotheken Objekte erkennen und Befehle an die beiden Motoren des pan-tilt Systems schicken, sodass das Objekt immer im Bild bleibt.

