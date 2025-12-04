#pragma once

#include "Bohnenmanager.hpp"
#include "Mahlvorgang.hpp"
#include "Mahlgradmanager.hpp"
#include "Wartungsmanager.hpp"
#include "IOHandler.hpp"

class Mahlwerk {
private:
    Bohnenmanager bm;
    Mahlvorgang mv;
    Mahlgradmanager mm;
    Wartungsmanager wm;
    IOHandler* io;

public:
    Mahlwerk();
    ~Mahlwerk() {
    }

    void StartVorgang();
};