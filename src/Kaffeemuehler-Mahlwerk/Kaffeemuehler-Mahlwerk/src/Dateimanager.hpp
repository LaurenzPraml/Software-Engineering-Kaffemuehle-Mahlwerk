#pragma once

class DateiManager {
private:
  const char* Dateipfad = "WartungsZaehler.txt";

public:
  DateiManager() {
  }
  ~DateiManager() {
  }

  int ZaehlerLaden();
  void ZaehlerSpeichern(int zaehler);
};