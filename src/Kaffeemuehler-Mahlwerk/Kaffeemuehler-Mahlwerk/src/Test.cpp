#include "Test.hpp"
#include "Bohnenmanager.hpp"
#include "Mahlvorgang.hpp"
#include "DrehzahlRegler.hpp"
#include "Wartungsmanager.hpp"
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
  Wartungsmanager wm = Wartungsmanager();
  Mahlvorgang mv = Mahlvorgang(bm, wm);

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
  Wartungsmanager wm = Wartungsmanager();
  Mahlvorgang mv = Mahlvorgang(bm, wm);
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
  Wartungsmanager wm = Wartungsmanager();
  Mahlvorgang mv = Mahlvorgang(bm, wm);
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
    if(bm.GetSollwert() == 3){
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

void MT4() {
  Mahlgradmanager mm = Mahlgradmanager();
  mm.SetMahlgrad(Mahlgradmanager::MEDIUM);
  if(mm.GetDrehzahl() == 1500){
    std::cout << "-----------------------------------\n";
    std::cout << "MT4: Erfolgreich!\n";
    std::cout << "-----------------------------------\n";
  }
  else{
    std::cout << "-----------------------------------\n";
    std::cout << "MT4: Fehler!\n";
    std::cout << "-----------------------------------\n";
  }
}

void MT5() {
  Wartungsmanager wm = Wartungsmanager();
  wm.ZaehlerInkrementieren();
  wm.ZaehlerZuruecksetzen();
  if(wm.GetZaehler() == 0){
    std::cout << "-----------------------------------\n";
    std::cout << "MT5: Erfolgreich!\n";
    std::cout << "-----------------------------------\n";
  }
  else{
    std::cout << "-----------------------------------\n";
    std::cout << "MT5: Fehler!\n";
    std::cout << "-----------------------------------\n";
  }
}

void MT6() {
  Wartungsmanager wm = Wartungsmanager();
  wm.ZaehlerZuruecksetzen();
  wm.ZaehlerInkrementieren();
  wm.ZaehlerInkrementieren();
  if(wm.GetZaehler() == 2){
    std::cout << "-----------------------------------\n";
    std::cout << "MT6: Erfolgreich!\n";
    std::cout << "-----------------------------------\n";
  }
  else{
    std::cout << "-----------------------------------\n";
    std::cout << "MT6: Fehler!\n";
    std::cout << "-----------------------------------\n";
  }
}

void IT4() {
  Mahlgradmanager mm = Mahlgradmanager();
  Bohnenmanager bm = Bohnenmanager();
  Wartungsmanager wm = Wartungsmanager();
  Mahlvorgang mv = Mahlvorgang(bm, wm);

  mm.SetMahlgrad(Mahlgradmanager::MEDIUM);
  mv.StartAnfragen(bm.GetMahldauer(), mm.GetDrehzahl());

  std::cout << "-----------------------------------\n";
  std::cout << "Drehzahl 1500U/min wird angezeigt? IT4: Erfolgreich : IT4: Fehler\n";
  std::cout << "-----------------------------------\n";
}

void IT5() {
  Mahlgradmanager mm = Mahlgradmanager();
  Bohnenmanager bm = Bohnenmanager();
  Wartungsmanager wm = Wartungsmanager();
  Mahlvorgang mv = Mahlvorgang(bm, wm);

  wm.ZaehlerInkrementieren();
  wm.ZaehlerInkrementieren();
  wm.ZaehlerInkrementieren();
  wm.ZaehlerInkrementieren();
  wm.ZaehlerInkrementieren();
  wm.ZaehlerInkrementieren();

  if(!mv.StartAnfragen(bm.GetMahldauer(), mm.GetDrehzahl())){
    std::cout << "-----------------------------------\n";
    std::cout << "IT5: Erfolgreich!\n";
    std::cout << "-----------------------------------\n";
  }
  else{
    std::cout << "-----------------------------------\n";
    std::cout << "IT5: Fehler!\n";
    std::cout << "-----------------------------------\n";
  }
}

void IT6() {
  IOHandler* io = IOHandler::GetInstanz();
  Mahlgradmanager mm = Mahlgradmanager();
  Bohnenmanager bm = Bohnenmanager();
  Wartungsmanager wm = Wartungsmanager();
  Mahlvorgang mv = Mahlvorgang(bm, wm);

  const char* hauptmenue[] = {
        "1) Bohnenmenge einstellen",
        "2) Mahlgrad einstellen",
        "3) Mahlvorgang starten",
        "4) Wartung quittieren",
        "5) Beenden"
  };

  int laenge = sizeof(hauptmenue) / sizeof(hauptmenue[0]);

  io->MenueZeigen(hauptmenue, laenge);

  int eingabe = 0;
  io->Zahleingabe("->", 1, laenge, eingabe);

  if(eingabe == 4){
    wm.ZaehlerZuruecksetzen();
  }
  else{
    std::cout << "Falsche Eingabe\n";
  }

  if(mv.StartAnfragen(bm.GetMahldauer(), mm.GetDrehzahl())){
    std::cout << "-----------------------------------\n";
    std::cout << "IT6: Erfolgreich!\n";
    std::cout << "-----------------------------------\n";
  }
  else{
    std::cout << "-----------------------------------\n";
    std::cout << "IT6: Fehler!\n";
    std::cout << "-----------------------------------\n";
  }
}


