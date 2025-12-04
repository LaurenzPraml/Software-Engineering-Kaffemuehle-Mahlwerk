| ID  |                         Beschreibung                         |               Vorbedingung               |                    Aktion                     |        gewünschtes Ergebnis        |
| :-: | :----------------------------------------------------------: | :--------------------------------------: | :-------------------------------------------: | :--------------------------------: |
| MT4 |        Mahlgrad wird korrekt in Drehzahl umgewandelt         |    Mahlgrad wurde auf medium gesetzt     |         GetDrehzahl() wird aufgerufen         | GetDrehzahl() liefert 1500U/min an |
| MT5 |        Zurücksetzen des Zählers funktioniert korrekt         |      Zähler besitzt einen Wert != 0      |    ZaehlerZuruecksetzen() wird aufgerufen     |     Zähler besitzt den Wert 0      |
| MT6 |         Die Anzahl an Vorgängen wird korrekt erfasst         |        Zähler wurde zurückgesetzt        | ZaehlerInkrementieren() wird 2 Mal aufgerufen |       Zähler hat den Wert 2        |
| IT4 |  Eingegebener Mahlgrad wird für Drehzahleinstellung genutzt  |    Mahlgrad wurde auf medium gesetzt     |          Mahlvorgang wird gestartet           |   DrehzahlRegler zeigt 1500U/min   |
| IT5 |     Mahlvorgang wird bei ausstehender Wartung blockiert      | AnzahlMahlvorgaenge ist >= WarnGrenzwert |             Start wird angefragt              |    Start wird nicht ausgeführt     |
| IT6 | Nach Quittierung der Wartung wird Start nicht mehr blockiert |     Wartung wurde im Menü quittiert      |             Start wird angefragt              |   Mahlvorgang wird durchgeführt    |
