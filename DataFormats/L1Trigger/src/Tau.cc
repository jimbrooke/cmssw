
#include "DataFormats/L1Trigger/interface/Tau.h"

l1t::Tau::Tau( const LorentzVector& p4,
	       int pt,
	       int eta,
	       int phi,
	       int qual,
	       int iso )
  : L1Candidate(p4, pt, eta, phi, qual,iso)
{

}

l1t::Tau::Tau( const PolarLorentzVector& p4,
	       int pt,
	       int eta,
	       int phi,
	       int qual,
	       int iso )
  : L1Candidate(p4, pt, eta, phi, qual,iso)
{

}

l1t::Tau::~Tau()
{

}

void l1t::Tau::setTowerIEta(short int ieta) {
  towerIEta_ = ieta;
}

void l1t::Tau::setTowerIPhi(short int iphi) {
  towerIPhi_ = iphi;
}

void l1t::Tau::setRawEt(short int et) { 
  rawEt_ = et;
}

void l1t::Tau::setIsoEt(short int et) {
  isoEt_ = et;
}

void l1t::Tau::setNTT(short int ntt) {
  nTT_ = ntt;
}

void l1t::Tau::setHasEM(bool hasEM) {
  hasEM_ = hasEM;
}

void l1t::Tau::setIsMerged(bool isMerged) {
  isMerged_ = isMerged;
}

short int l1t::Tau::towerIEta() {
  return towerIEta_;
}

short int l1t::Tau::towerIPhi() {
  return towerIPhi_;
}

short int l1t::Tau::rawEt() {
  return rawEt_;
}

short int l1t::Tau::isoEt() {
  return isoEt_;
}

short int l1t::Tau::nTT() {
  return nTT_;
}

bool l1t::Tau::hasEM() {
  return hasEM_;
}

bool l1t::Tau::isMerged() {
  return isMerged_;
}

