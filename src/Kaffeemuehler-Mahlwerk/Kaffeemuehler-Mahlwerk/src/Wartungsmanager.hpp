#pragma once

#include "IOHandler.hpp"
#include "Dateimanager.hpp"

class Wartungsmanager{
private:
  int anzahlMahlvorgaenge;
  const int warnGrenzwert = 5;
  bool wartungFaellig;
  DateiManager dm;
  IOHandler* io;

public:
  Wartungsmanager();
  ~Wartungsmanager();

  void ZaehlerInkrementieren();
  void ZaehlerZuruecksetzen();
  bool WartungFragen();

  int GetZaehler();
};