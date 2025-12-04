#pragma once

#include "Bohnenmanager.hpp"
#include "DrehzahlRegler.hpp"
#include "Wartungsmanager.hpp"
#include "IOHandler.hpp"

class Mahlvorgang{
private:
  long long Mahlvorgangsdauer;
  long long VerstricheneZeit;

  Bohnenmanager& bm;
  Wartungsmanager& wm;
  DrehzahlRegler dr;
  IOHandler* io;

public:
    Mahlvorgang(Bohnenmanager& bm_, Wartungsmanager& wm_);

  ~Mahlvorgang() {}

  bool StartAnfragen(int dauer, int drehzahl);
  void MahldauerWarten();
};