#include "Wartungsmanager.hpp"

Wartungsmanager::Wartungsmanager() : anzahlMahlvorgaenge(0), wartungFaellig(false), dm() {
  io = IOHandler::GetInstanz();
  anzahlMahlvorgaenge = dm.ZaehlerLaden();
  wartungFaellig = (anzahlMahlvorgaenge >= warnGrenzwert);
}

Wartungsmanager::~Wartungsmanager() {
  dm.ZaehlerSpeichern(anzahlMahlvorgaenge);
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

int Wartungsmanager::GetZaehler() {
    return anzahlMahlvorgaenge;
}
