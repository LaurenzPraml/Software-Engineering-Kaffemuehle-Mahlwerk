#include "Mahlvorgang.hpp"

Mahlvorgang::Mahlvorgang(Bohnenmanager& bm_, Wartungsmanager& wm_) : Mahlvorgangsdauer(0), VerstricheneZeit(0), bm(bm_), dr(), wm(wm_) {
  io = IOHandler::GetInstanz();
}

bool Mahlvorgang::StartAnfragen(int dauer, int drehzahl) {
  if (bm.GetAktuelleMenge() <= 0) {
    io->TextZeigen("Warnung: Nicht genuegend Bohnen im Oberbehaelter!");
    io->Pausieren();
    return false;
  }

  if (wm.WartungFragen()) {
    io->TextZeigen("Warnung: Fuehren Sie die Wartung durch, bevor Sie einen Vorgang starten!");
    io->Pausieren();
    return false;
  }

  dr.SetDrehzahl(drehzahl);
  bm.OeffneZufuhr();

  Mahlvorgangsdauer = dauer;
  MahldauerWarten();

  bm.SchliesseZufuhr();
  dr.SetDrehzahl(0);
  bm.VerbraucheBohnen();
  wm.ZaehlerInkrementieren();
  io->Pausieren();

  return true;
}

void Mahlvorgang::MahldauerWarten() {
  VerstricheneZeit = 0;
  while (VerstricheneZeit < Mahlvorgangsdauer * 30000000) {
    VerstricheneZeit++;
  }
}