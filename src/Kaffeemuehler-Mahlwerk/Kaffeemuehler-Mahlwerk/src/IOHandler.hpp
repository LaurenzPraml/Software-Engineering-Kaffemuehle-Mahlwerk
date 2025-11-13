#pragma once

class IOHandler {
private:
  int Puffergröße;

  static IOHandler* instanz;
  IOHandler() : Puffergröße(1024) { //TODO: sinnvollen Wert finden
  }

public:
  IOHandler(const IOHandler& obj) = delete;
  
  static IOHandler* GetInstanz();

  void BohnenmengeZeigen(int Bohnenmenge);
  void DrehzahlZeigen(int Drehzahl);
  void MenueZeigen(const char* Optionen);

  // TODO: Input-Fkt. aus "Bibliotheksverwaltung kopieren"
};