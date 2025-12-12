#include "Dateimanager.hpp"
#include <fstream>

void DateiManager::ZaehlerSpeichern(int zaehler) {
  std::ofstream zaehlerDatei = std::ofstream(Dateipfad, std::ios::out);
  if(zaehlerDatei){
    zaehlerDatei << zaehler;
  }
  zaehlerDatei.close();
}

int DateiManager::ZaehlerLaden() {
  std::ifstream zaehlerDatei = std::ifstream(Dateipfad, std::ios::in);
  int zaehler = 0;
  if(zaehlerDatei){
    zaehlerDatei >> zaehler;
  }
  zaehlerDatei.close();
  return zaehler;
}
