#include "Mahlvorgang.hpp"

Mahlvorgang::Mahlvorgang(Bohnenmanager& bm_) : Mahlvorgangsdauer(0), VerstricheneZeit(0), bm(bm_), dr() {
    io = IOHandler::GetInstanz();
}

bool Mahlvorgang::StartAnfragen(int dauer, int drehzahl) {
    if (bm.GetAktuelleMenge() > 0) {
        dr.SetDrehzahl(drehzahl);
        bm.OeffneZufuhr();

        Mahlvorgangsdauer = dauer;
        MahldauerWarten();

        bm.SchliesseZufuhr();
        dr.SetDrehzahl(0);
        bm.VerbraucheBohnen();

        return true;
    }
    else {
        io->TextZeigen("Warnung: Nicht genuegend Bohnen im Oberbehaelter!");
        return false;
    }
}

void Mahlvorgang::MahldauerWarten() {
    VerstricheneZeit = 0;
    while (VerstricheneZeit < Mahlvorgangsdauer*30000000) {
        VerstricheneZeit++;
    }
}