#pragma once

#include "IOHandler.hpp"

class Mahlgradmanager{
public:
  typedef enum MahlgradOptionen {
    NONE,
    LOW,
    MEDIUM,
    HIGH
  } MahlgradOptionen_t;

private:
  MahlgradOptionen_t aktuellerMahlgrad;

  IOHandler* io;

public:
  Mahlgradmanager();
  ~Mahlgradmanager() {}

  void SetMahlgrad(MahlgradOptionen_t mahlgrad);
  MahlgradOptionen_t GetMahlgrad();
  int GetDrehzahl();
};