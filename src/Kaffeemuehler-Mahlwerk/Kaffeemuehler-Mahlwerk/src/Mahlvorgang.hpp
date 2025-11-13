#pragma once

#include "Bohnenmanager.hpp"
#include "DrehzahlRegler.hpp"

class Mahlvorgang{
private:
  int Mahlvorgangsdauer;
  int VerstricheneZeit;

  Bohnenmanager bm;
  DrehzahlRegler dr;

public:
  Mahlvorgang() : Mahlvorgangsdauer(0), VerstricheneZeit(0), bm(), dr() {
  }

  ~Mahlvorgang() {
  }

  bool StartAnfragen(int dauer, int drehzahl);
  void MahldauerWarten();
};