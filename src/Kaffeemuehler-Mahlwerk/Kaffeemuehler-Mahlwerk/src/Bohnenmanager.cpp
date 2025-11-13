#include "Bohnenmanager.hpp"

int Bohnenmanager::SekundenProTasse = 20;

Bohnenmanager::Bohnenmanager() : BohnenSollwert(0), AktuelleMenge(10), ZufuhrOffen(false) {
    io = IOHandler::GetInstanz();
}

void Bohnenmanager::OeffneZufuhr() {
    ZufuhrOffen = true;
}

void Bohnenmanager::SchliesseZufuhr() {
    ZufuhrOffen = false;
}

void Bohnenmanager::VerbraucheBohnen() {
    AktuelleMenge--;
}

int Bohnenmanager::GetAktuelleMenge() {
    return AktuelleMenge;
}

void Bohnenmanager::SetBohnenmenge(int Menge) {
    this->BohnenSollwert = Menge;
}

int Bohnenmanager::GetMahldauer() {
    return this->BohnenSollwert * Bohnenmanager::SekundenProTasse;
}