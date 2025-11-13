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

        int input = 0;
        io->Zahleingabe("->", 0, laenge, input);

        switch (input) {
        case 1:
            std::cout << "Option 1 gewaehlt!\n";
            io->Zahleingabe("Geben Sie die gewuenschte Anzahl an Tassen (im Bereich 1 bis 7) ein: ", 1, 7, input);
            bm.SetBohnenmenge(input);
            break;

        case 2:
            std::cout << "Option 2 gewaehlt!\n";
            if (!mv.StartAnfragen(bm.GetMahldauer(), 10)) {
                io->TextZeigen("Warnung: Start nicht erfolgreich!");
            }
            else {
                io->TextZeigen("Mahlvorgang erfolgreich durchgefuehrt!");
            }
            break;

        case 3:
            std::cout << "Option 3 gewaehlt!\n";
            return;
        }
    }
}
