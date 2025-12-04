#include "Mahlgradmanager.hpp"
#include "IOHandler.hpp"

Mahlgradmanager::Mahlgradmanager() : aktuellerMahlgrad(Mahlgradmanager::LOW){
  io = IOHandler::GetInstanz();
}

void Mahlgradmanager::SetMahlgrad(Mahlgradmanager::MahlgradOptionen mahlgrad) {
  aktuellerMahlgrad = mahlgrad;
}

Mahlgradmanager::MahlgradOptionen Mahlgradmanager::GetMahlgrad() {
  return aktuellerMahlgrad;
}

int Mahlgradmanager::GetDrehzahl() {
  switch (aktuellerMahlgrad){
  case Mahlgradmanager::NONE:
    return 0;
    break;

  case Mahlgradmanager::LOW:
    return 1000;
    break;

  case Mahlgradmanager::MEDIUM:
    return 1500;
    break;

  case Mahlgradmanager::HIGH:
    return 2000;
    break;

  default:
    return 0;
    break;
  }
}
