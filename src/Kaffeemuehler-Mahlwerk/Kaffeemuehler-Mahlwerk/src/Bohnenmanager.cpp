#include "Bohnenmanager.hpp"

int Bohnenmanager::SekundenProTasse = 20;

void Bohnenmanager::SetBohnenmenge(int Menge){
  this->BohnenSollwert = Menge;
}

int Bohnenmanager::GetMahldauer(){
  return this->BohnenSollwert * Bohnenmanager::SekundenProTasse;
}