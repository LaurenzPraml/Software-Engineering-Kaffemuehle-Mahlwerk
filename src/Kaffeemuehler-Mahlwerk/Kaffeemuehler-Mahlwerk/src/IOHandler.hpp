#pragma once

#include <iostream>
#include <string>

class IOHandler {
private:
    long long Inputpuffer;

  static IOHandler* instanz;
  IOHandler() : Inputpuffer(0) {
  }

public:
  IOHandler(const IOHandler& obj) = delete;
  
  static IOHandler* GetInstanz();

  void DrehzahlZeigen(int Drehzahl);
  void MenueZeigen(const char* Optionen[], int laenge);
  void TextZeigen(const char* nachricht);
  void Pausieren();
  void InputpufferLeeren();
  bool InputError(const char* nachricht);
  int Zahleingabe(const char* nachricht, int min, int max, int& input);
};