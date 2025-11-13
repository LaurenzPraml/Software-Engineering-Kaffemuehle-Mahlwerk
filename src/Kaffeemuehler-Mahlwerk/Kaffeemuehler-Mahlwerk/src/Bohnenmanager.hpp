#pragma once

class Bohnenmanager {
private:
  int BohnenSollwert;
  int AktuelleMenge;

  static int SekundenProTasse;

public:
  Bohnenmanager() : BohnenSollwert(0), AktuelleMenge(0) {
  }

  ~Bohnenmanager() {
  }

  void OeffneZufuhr();
  void SchliesseZufuhr();
  int GetAktuelleMenge();
  void SetBohnenmenge(int Menge);
  int GetMahldauer();
};