#include "Mahlwerk.hpp"

Mahlwerk::Mahlwerk() : bm(), mv(bm) {
    io = IOHandler::GetInstanz();
}

void Mahlwerk::StartVorgang() {
    while (1) {

        const char* hauptmenue[] = {
            "1) Bohnenmenge einstellen",
            "2) Mahlvorgang starten",
            "3) Beenden"
        };

        int laenge = sizeof(hauptmenue) / sizeof(hauptmenue[0]);
        io->MenueZeigen(hauptmenue, laenge);

        int eingabe = 0;
        io->Zahleingabe("->", 1, laenge, eingabe);

        switch (eingabe) {
        case 1:
            io->Zahleingabe("Geben Sie die gewuenschte Anzahl an Tassen (im Bereich 1 bis 7) ein: ", 1, 7, eingabe);
            bm.SetBohnenmenge(eingabe);
            break;

        case 2:
            if (!mv.StartAnfragen(bm.GetMahldauer(), 10)) { //Aktuell noch mit Literal für Drehzahl
                io->TextZeigen("Warnung: Start nicht erfolgreich!");
            }
            else {
                io->TextZeigen("Mahlvorgang erfolgreich durchgefuehrt!");
            }
            break;

        case 3:
            return;
        }
    }
}
