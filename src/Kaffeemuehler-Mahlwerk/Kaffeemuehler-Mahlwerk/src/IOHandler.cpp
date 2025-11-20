#include "IOHandler.hpp"

IOHandler* IOHandler::instanz = nullptr;

IOHandler* IOHandler::GetInstanz() {
  if (instanz == nullptr) {
    instanz = new IOHandler();
  }
  return instanz;
}

void IOHandler::DrehzahlZeigen(int Drehzahl) {
    std::cout << "\n";
  std::cout << "Aktuelle Drehzahl: " << Drehzahl << "U/min\n";
}

void IOHandler::MenueZeigen(const char* Optionen[], int laenge) {
    std::cout << "\n";
  for (int i = 0; i < laenge; i++) {
    std::cout << Optionen[i] << "\n";
  }
}

void IOHandler::TextZeigen(const char* nachricht) {
    std::cout << "\n";
  std::cout << nachricht << "\n";
}

void IOHandler::Pausieren() {
    std::cout << "\n";
  std::cout << "[Enter um zur Eingabe zurueckzukehren]\n";
  getchar();
}

void IOHandler::EingabePufferLeeren() {
  std::cin.ignore(std::numeric_limits<int>::max(), '\n');
}

bool IOHandler::EingabeFehler(const char* nachricht) {
    std::cout << "\n";
  std::cout << nachricht << std::endl;
  std::cout << "Erneut versuchen? [Y/n]";

  std::string eingabe = "x";
  while (1) {
    std::getline(std::cin, eingabe);
    if (eingabe == "n" || eingabe == "N") {
      return false;
    }
    else if (eingabe == "y" || eingabe == "Y" || eingabe == "") {
      return true;
    }
    else {
      std::cout << "Ungueltige Eingabe!" << std::endl;
      std::cout << "Erneut versuchen [Y/n]";
    }
  }
}

int IOHandler::Zahleingabe(const char* nachricht, int min, int max, int& eingabe) {
  bool eingabe_wiederholen = true;
  while (eingabe_wiederholen) {
        std::cout << "\n";
    std::cout << nachricht;
    EingabePuffer = 0;
    std::cin >> EingabePuffer;
    EingabePufferLeeren();

    if (std::cin.fail()) {
      std::cin.clear();
      EingabePufferLeeren();
      eingabe_wiederholen = EingabeFehler("Ungueltige Eingabe!");
    }
    else if (EingabePuffer < (long long)min || EingabePuffer >(long long)max) {
      eingabe_wiederholen = EingabeFehler("Fehler! Der eingegebene Wert liegt ausserhalb erlaubter Grenzen!");
    }
    else {
      eingabe = (int)EingabePuffer;
      return true;
    }
  }
  return false;
}
