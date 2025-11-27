|  ID  | Beschreibung | Vorbedingung | Aktion | gewünschtes Ergebnis |
|:----:|:------------:|:------------:|:------:|:--------------------:|
| MT1  |Mahldauer wird korrekt berechnet|BohnenSollwert wurde auf 5 gesetzt|GetMahldauer() wird aufgerufen|Methode liefert eine Mahldauer von 100 zurück|
| MT2  |Start wird bei leerem Oberbehälter verweigert|Die aktuelle Menge an Bohnen muss 0 sein|StartAnfragen() muss aufgerufen werden|Der Vorgang darf nicht gestartet werden. Eine Warnung muss angezeigt werden|
| MT3  |Übergebene Drehzahl wird korrekt gespeichert|Es ist kein Mahlvorgang aktiv|SetDrehzahl() wird mit Argument 15 aufgerufen|Eine Drehzahl von 25U/min wird angezeigt|
| IT1  |Mahlvorgang wird korrekt gestartet|Aktuelle Bohnenmenge ist nicht 0. Es ist kein Mahlvorgang aktiv|StartAnfragen() wird aufgerufen mit einer Drehzahl von 25U/min|Drehzahl 25U/min wird zu Beginn angezeigt|
| IT2  |Mahlvorgang wird korrekt beendet|Es ist ein Mahlvorgang aktiv|Mahldauer läuft ab|Drehzahl 0U/min wird angezeigt|
| IT3  |Bohnensollwert wird korrekt gesetzt|Bohnensollwert beträgt 0. Menü wird angezeigt|Nutzer wählt Option 1 und gibt einen Sollwert von 3 ein|Die Eingabe des Bohnensollwerts erfolgt. Eine temporäre Ausgabe zeigt einen Sollwert von 3 an|

### Traceability-Matrix
[Traceability-Matrix.pdf](/docs/Traceability-Matrix.pdf)

### Implementierung der Testcases
[Test.cpp](/src/Kaffeemuehler-Mahlwerk/Kaffeemuehler-Mahlwerk/src/Test.cpp)