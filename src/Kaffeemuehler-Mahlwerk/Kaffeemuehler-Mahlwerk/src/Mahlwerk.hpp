#pragma once

class Mahlwerk{
private:

public:
  Mahlwerk(){
  }

  ~Mahlwerk(){
  }

  void StartVorgang();
  int StartNutzerinteraktion(const char* Optionen);
};