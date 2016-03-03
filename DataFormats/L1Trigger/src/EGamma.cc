
#include "DataFormats/L1Trigger/interface/EGamma.h"

l1t::EGamma::EGamma( const LorentzVector& p4,
		     int pt,
		     int eta,
		     int phi,
		     int qual,
		     int iso )
  : L1Candidate(p4, pt, eta, phi, qual, iso)
{

}

l1t::EGamma::EGamma( const PolarLorentzVector& p4,
		     int pt,
		     int eta,
		     int phi,
		     int qual,
		     int iso )
  : L1Candidate(p4, pt, eta, phi, qual, iso)
{

}

l1t::EGamma::~EGamma()
{

}

void l1t::EGamma::setTowerIEta(short int ieta) {
  towerIEta_ = ieta;
}

void l1t::EGamma::setTowerIPhi(short int iphi) {
  towerIPhi_ = iphi;
}

void l1t::EGamma::setRawEt(short int et) {
  rawEt_ = et;
}

void l1t::EGamma::setIsoEt(short int et) {
  isoEt_ = et;
}

void l1t::EGamma::setFootprintEt(short int et) {
  footprintEt_ = et;
}

void l1t::EGamma::setNTT(short int ntt) {
  nTT_ = ntt;
}

void l1t::EGamma::setShape(short int s) {
  shape_ = s;
}

short int l1t::EGamma::towerIEta() {
  return towerIEta_;
}

short int l1t::EGamma::towerIPhi() {
  return towerIPhi_;
}

short int l1t::EGamma::rawEt() {
  return rawEt_;
}

short int l1t::EGamma::isoEt() {
  return isoEt_;
}

short int l1t::EGamma::footprintEt() {
  return footprintEt_;
}

short int l1t::EGamma::nTT() {
  return nTT_;
}

short int l1t::EGamma::shape() {
  return shape_;
}
