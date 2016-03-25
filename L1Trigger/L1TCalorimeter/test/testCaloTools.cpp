

#include "L1Trigger/L1TCalorimeter/interface/CaloTools.h"

int main(int argc, char *argv[]) {

  using namespace l1t;

  // test region map
  for (int ieta=-41; ieta<=41; ++ieta) {

    if ieta==0 continue;

    std::cout << ieta << " : " 
	      << CaloTools::towerEta(ieta) << ", "
	      << CaloTools::regionEta(ieta) << ", "
	      << CaloTools::gtEta(ieta) << std::endl;

  }

  return 0;

}
