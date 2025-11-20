#include "Test.hpp"
#include "Bohnenmanager.hpp"
#include "Mahlvorgang.hpp"
#include "DrehzahlRegler.hpp"
#include "IOHandler.hpp"
#include <stdio.h>

void MT1() {
  Bohnenmanager bm = Bohnenmanager();
  bm.SetBohnenmenge(5);
  if(bm.GetMahldauer() == 100){
    std::cout << "-----------------------------------\n";
    std::cout << "MT1: Erfolgreich\n";
    std::cout << "-----------------------------------\n";
  }
  else{
    std::cout << "-----------------------------------\n";
    std::cout << "MT1: Fehler!\n";
    std::cout << "-----------------------------------\n";
  }
}

void MT2() {
  Bohnenmanager bm = Bohnenmanager();
  Mahlvorgang mv = Mahlvorgang(bm);

  bm.TestSetAktuelleMenge(0);
  if(mv.StartAnfragen(bm.GetMahldauer(), 25) == false){
    std::cout << "-----------------------------------\n";
    std::cout << "MT2: Erfolgreich\n";
    std::cout << "-----------------------------------\n";
  }
  else{
    std::cout << "-----------------------------------\n";
    std::cout << "MT2: Fehler!\n";
    std::cout << "-----------------------------------\n";
  }
}

void MT3() {
  DrehzahlRegler dr = DrehzahlRegler();
  dr.SetDrehzahl(15);
  if(dr.TestGetDrehzahl() == 15){
    std::cout << "-----------------------------------\n";
    std::cout << "Drehzahl 15 angezeigt? Ansonsten MT3: Erfolgreich\n";
    std::cout << "-----------------------------------\n";
  }
  else{
    std::cout << "-----------------------------------\n";
    std::cout << "MT3: Fehler!\n";
    std::cout << "-----------------------------------\n";
  }
}

void IT1() {
  Bohnenmanager bm = Bohnenmanager();
  Mahlvorgang mv = Mahlvorgang(bm);
  IOHandler* io = IOHandler::GetInstanz();
  
  bm.TestSetAktuelleMenge(1);
  std::cout << "-----------------------------------\n";
  std::cout << "Wird Drehzahl 25 nach bestaetigen angezeigt? IT1: Erfolgreich : IT1: Fehler\n";
  std::cout << "-----------------------------------\n";
  io->Pausieren();
  mv.StartAnfragen(bm.GetMahldauer(), 25);
}

void IT2() {
  Bohnenmanager bm = Bohnenmanager();
  Mahlvorgang mv = Mahlvorgang(bm);
  IOHandler* io = IOHandler::GetInstanz();

  bm.TestSetAktuelleMenge(1);
  mv.StartAnfragen(bm.GetMahldauer(), 25);
  std::cout << "-----------------------------------\n";
  std::cout << "Wird Drehzahl 0 angezeigt? IT2: Erfolgreich : IT2: Fehler!\n";
  std::cout << "-----------------------------------\n";
}

void IT3() {
  Bohnenmanager bm = Bohnenmanager();
  IOHandler* io = IOHandler::GetInstanz();

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
    if(bm.TestGetSollwert() == 3){
      std::cout << "-----------------------------------\n";
      std::cout << "IT3: Erfolgreich\n";
      std::cout << "-----------------------------------\n";
    }
    else {
      std::cout << "-----------------------------------\n";
      std::cout << "IT3: Fehler!\n";
      std::cout << "-----------------------------------\n";
    }
    break;

  default:
    std::cout << "Falsche Eingabe";
  }
}


