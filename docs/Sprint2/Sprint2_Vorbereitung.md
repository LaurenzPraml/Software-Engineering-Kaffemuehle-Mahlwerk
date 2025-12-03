# Sprint 1

Im zweiten Sprint soll der bestehende Stand um die beiden weiteren Kernfunktionalitäten Mahlgradeinstellung und Wartungserinnerung erweitert werden. Hierfür sind gerinfügige Anpassungen am Software-Desigen nötig, außerdem wurden folgende Requirements ausgewählt.

### Umzusetzende Requirements

- 1.2) Der Nutzer muss, nach dem Systemstart, auf einen leeren Oberbehälter hingewiesen werden
- 2.1) Der Mahlgrad muss aus den 3 Optionen ["low", "medium", "high"] gewählt werden können
- 2.2) Der Mahlgrad muss in einen konkreten Drehzahlwert umgewandelt werden ["low" = 1000rpm, "medium" = 1500rpm, "high" = 2000rpm]
- 4.1) Die Drehzahl muss mit dem, vom Nutzer übergebenen Wert, gesteuert werden
- 5.1) Die Anzahl an Mahlvorgängen muss gezählt werden
- 5.3) Eine Wartungserinnerung muss nach 5 Mahlvorgängen angezeigt werden
- 5.4) Die Wartungserinnerung muss nach der Wartung gelöscht werden können
- 5.5) Die Funktion des Mahlwerks muss bei fehlender Wartung deaktiviert werden

### Software Design

- IOHandler:

  - Attribute:

    - Puffergroesse: int

  - Methoden:
    - GetInstanz()
    - BohnenmengeZeigen()
    - MahlgradZeigen()
    - WartungZeigen()
    - DrehzahlZeigen()
    - ZahlEingabe()
    - MenueZeigen()
    - TextZeigen()
    - Pausieren()
    - EingabePufferLeeren()
    - EingabeFehler()

- Wartungsmanager:

  - Attribute:

    - AnzahlMahlvorgaenge: int
    - WarnGrenzwert: int
    - WartungFaellig: bool
    - dm: DateiManager
    - io: IOHandler

  - Methoden:
    - ZaehlerInktementieren()
    - ZaehlerZuruecksetzen()
    - WartungFragen()

- DrehzahlRegler:

  - Attribute:

    - Drehzahl: int
    - io: IOHandler

  - Methoden
    - SetDrehzahl()

- Mahlgradmanager:

  - Attribute:

    - MahlgradOptionen: Enum
    - AktuellerMahlgrad: Enum
    - io: IOHandler

  - Methoden:
    - SetMahlgrad()
    - GetDrehzahl()
