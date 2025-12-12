#include "Mahlvorgang.hpp"

Mahlvorgang::Mahlvorgang(Bohnenmanager& bm_, Wartungsmanager& wm_) : Mahlvorgangsdauer(0), VerstricheneZeit(0), bm(bm_), dr(), wm(wm_) {
  io = IOHandler::GetInstanz();
}

bool Mahlvorgang::StartAnfragen(int dauer, int drehzahl) {
  if (bm.GetAktuelleMenge() <= 0) {
    io->TextZeigen("Warnung: Nicht genuegend Bohnen im Oberbehaelter!\a");
    io->Pausieren();
    return false;
  }

  if (wm.WartungFragen()) {
    io->TextZeigen("Warnung: Fuehren Sie die Wartung durch, bevor Sie einen Vorgang starten!\a");
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

  io->TextZeigen("Mahlvorgang abgeschlossen!\a");
  io->Pausieren();
  return true;
}

void Mahlvorgang::MahldauerWarten() {
  VerstricheneZeit = 0;
  long long Wartezeit = Mahlvorgangsdauer * 3000;
  while (VerstricheneZeit < Wartezeit) {
    VerstricheneZeit++;
    std::cout << "\r";
    std::cout << (int)(((double)VerstricheneZeit * 100.0f) / (double)Wartezeit) << "%\r";
  }
}