#include "IOHandler.hpp"

IOHandler* IOHandler::instanz = nullptr;

IOHandler* IOHandler::GetInstanz() {
    if (instanz == nullptr) {
        instanz = new IOHandler();
    }
    return instanz;
}

void IOHandler::DrehzahlZeigen(int Drehzahl) {
    std::cout << "Aktuelle Drehzahl: " << Drehzahl << "U/min\n";
}

void IOHandler::MenueZeigen(const char* Optionen[], int laenge) {
    for (int i = 0; i < laenge; i++) {
        std::cout << Optionen[i] << "\n";
    }
}

void IOHandler::TextZeigen(const char* nachricht) {
    std::cout << nachricht << "\n";
}

void IOHandler::Pausieren() {
    std::cout << "[Enter um zur Eingabe zurueckzukehren]\n";
}

void IOHandler::InputpufferLeeren() {
    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

bool IOHandler::InputError(const char* nachricht) {
    std::cout << nachricht << std::endl;
    std::cout << "Erneut versuchen? [Y/n]";

    std::string input = "x";
    while (1) {
        std::getline(std::cin, input);
        if (input == "n" || input == "N") {
            return false;
        }
        else if (input == "y" || input == "Y" || input == "") {
            return true;
        }
        else {
            std::cout << "Ungueltige Eingabe!" << std::endl;
            std::cout << "Erneut versuchen [Y/n]";
        }
    }
}

int IOHandler::Zahleingabe(const char* nachricht, int min, int max, int& input) {
    bool eingabe_wiederholen = true;
    while (eingabe_wiederholen) {
        std::cout << nachricht;
        Inputpuffer = 0;
        std::cin >> Inputpuffer;
        InputpufferLeeren();

        if (std::cin.fail()) {
            std::cin.clear();
            InputpufferLeeren();
            eingabe_wiederholen = InputError("Ungueltige Eingabe!");
        }
        else if (Inputpuffer < (long long)min || Inputpuffer >(long long)max) {
            eingabe_wiederholen = InputError("Fehler! Der eingegebene Wert liegt ausserhalb erlaubter Grenzen!");
        }
        else {
            input = (int)Inputpuffer;
            return true;
        }
    }
    return false;
}
