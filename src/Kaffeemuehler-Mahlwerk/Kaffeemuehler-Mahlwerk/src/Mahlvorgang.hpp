#pragma once

#include "Bohnenmanager.hpp"
#include "DrehzahlRegler.hpp"
#include "IOHandler.hpp"

class Mahlvorgang{
private:
  long long Mahlvorgangsdauer;
  long long VerstricheneZeit;

  Bohnenmanager bm;
  DrehzahlRegler dr;
  IOHandler* io;

public:
    Mahlvorgang(Bohnenmanager& bm_);

  ~Mahlvorgang() {}

  bool StartAnfragen(int dauer, int drehzahl);
  void MahldauerWarten();
};