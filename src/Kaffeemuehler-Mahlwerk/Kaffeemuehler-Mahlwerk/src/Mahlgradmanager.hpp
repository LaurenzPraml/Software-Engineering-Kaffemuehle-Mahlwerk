#pragma once

class IOHandler;

class Mahlgradmanager{
public:
  enum MahlgradOptionen {
    NONE,
    LOW,
    MEDIUM,
    HIGH
  };

private:
  MahlgradOptionen aktuellerMahlgrad;

  IOHandler* io;

public:
  Mahlgradmanager();
  ~Mahlgradmanager() {}

  void SetMahlgrad(MahlgradOptionen mahlgrad);
  MahlgradOptionen GetMahlgrad();
  int GetDrehzahl();
};