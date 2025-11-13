#pragma once

#include "Bohnenmanager.hpp"
#include "Mahlvorgang.hpp"
#include "IOHandler.hpp"

class Mahlwerk {
private:
    Bohnenmanager bm;
    Mahlvorgang mv;
    IOHandler* io;

public:
    Mahlwerk();

    ~Mahlwerk() {
    }

    void StartVorgang();
};