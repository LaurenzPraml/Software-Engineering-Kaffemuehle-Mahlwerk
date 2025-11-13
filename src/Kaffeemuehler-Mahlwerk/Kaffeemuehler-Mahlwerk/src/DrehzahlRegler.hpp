#pragma once

class DrehzahlRegler {
private:
  int Drehzahl;

public:
  DrehzahlRegler() : Drehzahl(0) {
  }

  ~DrehzahlRegler(){
  }

  void SetDrehzahl(int Drehzahl);
};