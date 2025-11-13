# Sprint 1

Im ersten Sprint soll das grundlegende Software-Design erstellt werden und in Form eines Klassen-, Sequenz- und Kommunikationsdiagramms dokumentiert werden.
Außerdem sollen die nötigen Requirements umgesetzt werden, um die Grundfunktionalität des Mahlwerks zu erreichen.
Hierfür wurden folgende Punkte identifiziert.

### Umzusetzende Requirements:

* 0.1) Das Programm muss in C++ programmiert werden
* 0.2) Alle Kommentare und Variablen im Sourcecode müssen auf Deutsch sein
* 1.3) Die gewünschte Menge an Bohnen muss im Wertebereich [1 Tasse bis 7 Tassen] eingegeben werden können
* 1.5) Die Mahldauer muss auf Basis der eingestellten Menge berechnet werden (t = n * k; t = Mahldauer; n = eingestellte Menge; k = 20 Sekunden pro Tasse)
* 3.1) Der Mahlvorgang muss gestartet werden können
* 3.2) Der Mahlvorgang muss gestoppt werden können
* 3.3) Der Mahlvorgang darf nicht gestartet werden, wenn der Oberbehälter leer ist
* 4.2) Die aktuelle Drehzahl soll angezeigt werden

### Software Design

- Mahlwerk:
    - Methoden:
        - StartMahlvorgang()
        - StartNutzerinteraktion()

- Bohnenmanager:
    - Attribute:
        - BohnenSollwert: int
        - AktuelleMenge: int

    - Methoden:
        - OeffneZufuhr()
        - SchliesseZufuhr()
        - GetAktuelleMenge()
        - SetBohnenmenge()

- Mahlgradmanager:
    - Attribute:
        - MahlgradOptionen: Enum
        - AktuellerMahlgrad: Enum

    - Methoden: 
        - SetMahlgrad()
        - GetDrehzahl()

- Wartungsmanager:
    - Attribute:
        - AnzahlMahlvorgaenge: int
        - WarnGrenzwert: int
        - WartungFaellig: bool

    - Methoden:
        - ZaehlerInktementieren()
        - ZaehlerZuruecksetzen()

- DateiManager: 
    - Attribute: 
        - Dateipfad: string

    - Methoden: 
        - ZaehlerSpeichern()
        - ZaehlerLaden()

- Mahlvorgang:
    - Attribute:
        - Mahlvorgangsdauer: int
        - VerstricheneZeit: int

    - Methoden: 
        - StartAnfragen()
        - MahldauerWarten()

- DrehzahlRegler:
    - Attribute:
        - Drehzahl: int

    - Methoden
        - SetDrehzahl()

- IOHandler:
    - Attribute: 
        - Puffergroesse: int

    - Methoden:
        - BohnenmengeZeigen()
        - MahlgradZeigen()
        - WartungZeigen()
        - DrehzahlZeigen()
        - TextEingabe()
        - ZahlEingabe()
        - MenueZeigen()

### Traceability: 

[Traceability-Matrix.PDF](/docs/Traceability-Matrix.pdf)

### Klassendiagramm:

[UML-Klassendiagramm.pdf](/docs/reference/UML_Klassendiagramm.pdf)

### Sequenzdiagramm:

[Sequenzdiagramm.pdf](/docs/reference/Sequenzdiagramm.pdf)

### Kommunikationsdiagramm:

[Kommunikationsdiagramm.pdf](/docs/reference/Kommunikationsdiagramm.pdf)