#include "Mahlwerk.hpp"

Mahlwerk::Mahlwerk() : bm(), mv(bm, wm), mm(), wm() {
  io = IOHandler::GetInstanz();
}

void Mahlwerk::StartVorgang() {
    const char* hauptmenue[] = {
        "1) Bohnenmenge einstellen",
        "2) Mahlgrad einstellen",
        "3) Mahlvorgang starten",
        "4) Wartung quittieren",
        "5) Beenden"
    };

    int laenge = sizeof(hauptmenue) / sizeof(hauptmenue[0]);

  while (1) {
    io->StatusZeigen(bm.GetAktuelleMenge() <= 0, bm.GetSollwert(), bm.GetAktuelleMenge(), mm.GetMahlgrad(), wm.WartungFragen());
    io->MenueZeigen(hauptmenue, laenge);

    int eingabe = 0;
    io->Zahleingabe("->", 1, laenge, eingabe);

    switch (eingabe) {
    case 1: //Bohnenmene einstellen
      io->Zahleingabe("Geben Sie die gewuenschte Anzahl an Tassen (im Bereich 1 bis 7) ein: ", 1, 7, eingabe);
      bm.SetBohnenmenge(eingabe);
      break;

    case 2: // Mahlgrad einstellen
      io->Zahleingabe("Waehlen Sie einen Mahlgrad. (1)low, (2)medium oder (3)high: ", 1, 3, eingabe);
      if (eingabe == 1) {
        mm.SetMahlgrad(Mahlgradmanager::LOW);
      }
      else if(eingabe == 2){
        mm.SetMahlgrad(Mahlgradmanager::MEDIUM);
      }
      else if(eingabe == 3){
        mm.SetMahlgrad(Mahlgradmanager::HIGH);
      }
      break;

    case 3: // Start anfragen
      if(mv.StartAnfragen(bm.GetMahldauer(), mm.GetDrehzahl())){
        wm.ZaehlerInkrementieren();
      }
      break;

    case 4:
      wm.ZaehlerZuruecksetzen();
      break;

    case 5:
      return;
      break;
    }
  }
}
