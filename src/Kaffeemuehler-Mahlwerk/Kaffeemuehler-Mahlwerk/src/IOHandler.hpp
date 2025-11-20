#pragma once

#include <iostream>
#include <string>

class IOHandler {
private:
    long long EingabePuffer;

  static IOHandler* instanz;
  IOHandler() : EingabePuffer(0) {
  }

  void EingabePufferLeeren();
  bool EingabeFehler(const char* nachricht);

public:
  IOHandler(const IOHandler& obj) = delete;
  
  static IOHandler* GetInstanz();

  void Pausieren();
  void DrehzahlZeigen(int Drehzahl);
  void MenueZeigen(const char* Optionen[], int laenge);
  void TextZeigen(const char* nachricht);
  int Zahleingabe(const char* nachricht, int min, int max, int& eingabe);
};