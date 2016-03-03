

#include "DataFormats/L1Trigger/interface/Jet.h"

l1t::Jet::Jet( const LorentzVector& p4,
	       int pt,
	       int eta,
	       int phi,
	       int qual )
  : L1Candidate(p4, pt, eta, phi, qual, 0)
{

}

l1t::Jet::Jet( const PolarLorentzVector& p4,
	       int pt,
	       int eta,
	       int phi,
	       int qual )
  : L1Candidate(p4, pt, eta, phi, qual, 0)
{

}

l1t::Jet::~Jet()
{

}

void l1t::Jet::setTowerIEta(short int ieta) {
  towerIEta_ = ieta;
}

void l1t::Jet::setTowerIPhi(short int iphi) {
  towerIPhi_ = iphi;
}

void l1t::Jet::setSeedEt(short int et) {
  seedEt_ = et;
}

void l1t::Jet::setRawEt(short int et) {
  rawEt_ = et;
}

void l1t::Jet::setPUEt(short int et) {
  puEt_ = et;
}

void l1t::Jet::setPUDonutEt(int i, short int et) {
  if (i>=0 && i<4) puDonutEt_[i] = et;
}

short int l1t::Jet::towerIEta() {
  return towerIEta_;
}

short int l1t::Jet::towerIPhi() {
  return towerIPhi_;
}

short int l1t::Jet::seedEt() {
  return seedEt_;
}

short int l1t::Jet::rawEt() {
  return rawEt_;
}

short int l1t::Jet::puEt() {
  return puEt_;
}

short int l1t::Jet::puDonutEt(int i) {
  if (i>=0 && i<4) return puDonutEt_[i];
  else return 0;
}
