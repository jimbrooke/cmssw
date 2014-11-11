import FWCore.ParameterSet.Config as cms

caloStage2Layer1Digis = cms.EDProducer(
    "l1t::Stage2Layer1Producer",
    verbosity     = cms.int32(2),
    bxFirst       = cms.int32(0),
    bxLast        = cms.int32(0),
    ietaMin       = cms.int32(-32),
    ietaMax       = cms.int32(32),
    iphiMin       = cms.int32(1),
    iphiMax       = cms.int32(72),
    hcalTPVersion = cms.int32(0),
    ecalToken     = cms.InputTag("ecalDigis:EcalTriggerPrimitives"),
    hcalToken     = cms.InputTag("hcalDigis"),
    firmware      = cms.int32(1)
)
