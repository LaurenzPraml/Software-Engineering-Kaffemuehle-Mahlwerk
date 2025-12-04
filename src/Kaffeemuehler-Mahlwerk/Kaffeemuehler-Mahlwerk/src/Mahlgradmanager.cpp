#include "Mahlgradmanager.hpp"

Mahlgradmanager::Mahlgradmanager() : aktuellerMahlgrad(NONE){
  io = IOHandler::GetInstanz();
}

void Mahlgradmanager::SetMahlgrad(MahlgradOptionen_t mahlgrad) {
  aktuellerMahlgrad = mahlgrad;
}

Mahlgradmanager::MahlgradOptionen_t Mahlgradmanager::GetMahlgrad() {
  return aktuellerMahlgrad;
}

int Mahlgradmanager::GetDrehzahl() {
  switch (aktuellerMahlgrad){
  case NONE:
    return 0;
    break;

  case LOW:
    return 1000;
    break;

  case MEDIUM:
    return 1500;
    break;

  case HIGH:
    return 2000;
    break;

  default:
    return 0;
    break;
  }
}
