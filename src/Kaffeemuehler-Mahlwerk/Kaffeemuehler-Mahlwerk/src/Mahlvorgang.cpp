#include "Mahlvorgang.hpp"

bool Mahlvorgang::StartAnfragen(int dauer, int drehzahl) {
  if (bm.GetAktuelleMenge() > 0) {
    dr.SetDrehzahl(drehzahl);
    bm.OeffneZufuhr();

    Mahlvorgangsdauer = dauer;
    MahldauerWarten();

    bm.SchliesseZufuhr();
    dr.SetDrehzahl(0);

    return true;
  }
  else {
    return false;
  }
}

void Mahlvorgang::MahldauerWarten() {
  VerstricheneZeit = 0;
  while(VerstricheneZeit < Mahlvorgangsdauer){
    VerstricheneZeit++;
  }
}