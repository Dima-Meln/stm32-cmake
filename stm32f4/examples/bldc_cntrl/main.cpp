#include "control.h"

int main() {
  Control cntrl;
  cntrl.setSpeed(100/*rpm*/);
  
  int a = 100000;
  while(1) {
    a--;
    if (a==0) {
      break;
    }
  }
}
