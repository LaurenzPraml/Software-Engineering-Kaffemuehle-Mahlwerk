#pragma once

#include "IOHandler.hpp"

class DrehzahlRegler {
private:
    int Drehzahl;

    IOHandler* io;

public:
    DrehzahlRegler();

    ~DrehzahlRegler() {}

    void SetDrehzahl(int Drehzahl);
    int TestGetDrehzahl();
};