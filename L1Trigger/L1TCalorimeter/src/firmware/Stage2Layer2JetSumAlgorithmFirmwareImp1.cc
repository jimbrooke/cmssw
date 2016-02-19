///
/// \class l1t::Stage2Layer2JetSumAlgorithmFirmwareImp1
///
/// \author: Jim Brooke
///
/// Description: first iteration of stage 2 jet algo

#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "L1Trigger/L1TCalorimeter/interface/Stage2Layer2JetSumAlgorithmFirmware.h"
#include "L1Trigger/L1TCalorimeter/interface/CaloTools.h"

l1t::Stage2Layer2JetSumAlgorithmFirmwareImp1::Stage2Layer2JetSumAlgorithmFirmwareImp1(CaloParamsHelper* params) :
  params_(params)
{

  htJetEtMin_  = floor(params_->etSumEtThreshold(1)/params_->jetLsb());
  mhtJetEtMin_ = floor(params_->etSumEtThreshold(3)/params_->jetLsb());

  htJetEtaMax_ = params_->etSumEtaMax(1);
  if (htJetEtaMax_ > CaloTools::kHFEnd) htJetEtaMax_ = CaloTools::kHFEnd;

  mhtJetEtaMax_ = params_->etSumEtaMax(3);
  if (mhtJetEtaMax_ > CaloTools::kHFEnd) mhtJetEtaMax_ = CaloTools::kHFEnd;

  ietaMax_ = htJetEtaMax_ > mhtJetEtaMax_ ? htJetEtaMax_ : mhtJetEtaMax_;

}


l1t::Stage2Layer2JetSumAlgorithmFirmwareImp1::~Stage2Layer2JetSumAlgorithmFirmwareImp1() {


}


void l1t::Stage2Layer2JetSumAlgorithmFirmwareImp1::processEvent(const std::vector<l1t::Jet> & alljets, std::vector<l1t::EtSum> & htsums) 
{


  // etaSide=1 is positive eta, etaSide=-1 is negative eta
  for (int etaSide=1; etaSide>=-1; etaSide-=2) {

    int32_t hx(0), hy(0), ht(0);

    // loop over jets
    for (auto jet : alljets) {

      if (etaSide*jet.hwEta() > 0) {
	
	if (abs(jet.hwEta()) <= htJetEtaMax_ &&
	    jet.hwPt() > htJetEtMin_) {
	  ht += jet.hwPt();
	}

	if (abs(jet.hwEta()) <= mhtJetEtaMax_ &&
	    jet.hwPt() > mhtJetEtMin_) {
	  hx += (int32_t) ( jet.hwPt() * std::trunc ( 511. * cos ( 2 * M_PI * (72 - (jet.hwPhi()-1)) / 72.0 ) )) >> 9;
	  hy += (int32_t) ( jet.hwPt() * std::trunc ( 511. * sin ( 2 * M_PI * (jet.hwPhi()-1) / 72.0 ) )) >> 9;
	}

      }

    }
    
    math::XYZTLorentzVector p4;
    
    l1t::EtSum htSumHt(p4,l1t::EtSum::EtSumType::kTotalHt,ht,0,0,0);
    l1t::EtSum htSumHx(p4,l1t::EtSum::EtSumType::kTotalHtx,hx,0,0,0);
    l1t::EtSum htSumHy(p4,l1t::EtSum::EtSumType::kTotalHty,hy,0,0,0);
    
    htsums.push_back(htSumHt);
    htsums.push_back(htSumHx);
    htsums.push_back(htSumHy);
    
  }
}

