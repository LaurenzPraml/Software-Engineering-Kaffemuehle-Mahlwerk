#pragma once

#include "IOHandler.hpp"

class Wartungsmanager{
private:
  int anzahlMahlvorgaenge;
  const int warnGrenzwert = 5;
  bool wartungFaellig;
  //TODO: Dateimanager anlegen
  IOHandler* io;

public:
  Wartungsmanager();
  ~Wartungsmanager() {}

  void ZaehlerInkrementieren();
  void ZaehlerZuruecksetzen();
  bool WartungFragen();

  int GetZaehler();
};