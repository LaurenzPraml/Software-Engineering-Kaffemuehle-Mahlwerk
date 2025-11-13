#include "IOHandler.hpp"

IOHandler* IOHandler::instanz = nullptr;

IOHandler* IOHandler::GetInstanz() {
  if(instanz == nullptr){
    instanz = new IOHandler();
  }
  return instanz;
}
