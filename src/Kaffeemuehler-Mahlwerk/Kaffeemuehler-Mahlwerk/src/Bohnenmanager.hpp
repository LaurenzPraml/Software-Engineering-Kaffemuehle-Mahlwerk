#pragma once

#include "IOHandler.hpp"

class Bohnenmanager {
private:
    int BohnenSollwert;
    int AktuelleMenge;
    bool ZufuhrOffen;

    IOHandler* io;

    static int SekundenProTasse;

public:
    Bohnenmanager();

    ~Bohnenmanager() {}

    void OeffneZufuhr();
    void SchliesseZufuhr();
    void VerbraucheBohnen();
    int GetAktuelleMenge();
    void SetBohnenmenge(int Menge);
    int GetMahldauer();
};