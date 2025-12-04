#include "Wartungsmanager.hpp"

Wartungsmanager::Wartungsmanager() : anzahlMahlvorgaenge(0), wartungFaellig(false) {
  io = IOHandler::GetInstanz();
}

void Wartungsmanager::ZaehlerInkrementieren() {
  anzahlMahlvorgaenge++;
  if(anzahlMahlvorgaenge >= warnGrenzwert){
    wartungFaellig = true;
    io->TextZeigen("Achtung: Sie muessen das Geraet warten!");
  }
}

void Wartungsmanager::ZaehlerZuruecksetzen() {
  anzahlMahlvorgaenge = 0;
  wartungFaellig = false;
}

bool Wartungsmanager::WartungFragen() {
  return wartungFaellig;
}
