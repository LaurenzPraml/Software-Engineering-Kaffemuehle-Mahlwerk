#include "DrehzahlRegler.hpp"

DrehzahlRegler::DrehzahlRegler() : Drehzahl(0) {
    io = IOHandler::GetInstanz();
}

void DrehzahlRegler::SetDrehzahl(int Drehzahl_) {
    this->Drehzahl = Drehzahl_;
    io->DrehzahlZeigen(this->Drehzahl);
}

int DrehzahlRegler::TestGetDrehzahl() {
  return this->Drehzahl;
}
