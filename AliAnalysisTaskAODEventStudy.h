#ifndef AliAnalysisTaskAODEventStudy_cxx
#define AliAnalysisTaskAODEventStudy_cxx

// example of an analysis task creating a p_t spectrum
// Authors: Panos Cristakoglou, Jan Fiete Grosse-Oetringhaus, Christian Klein-Boesing

class TH1F;
class THnSparse;
class TList;

class AliAODEvent;
class AliAODHeader;
class AliAODTrack;

class AliEventCuts;
class AliAnalysisTaskAODLMMuMuBasic;
class AliAnalysisTaskAODEventStudy;
class AliPIDResponse;
class AliMultSelection;
class AliEventCuts;
class AliMuonTrackCuts;

#include "AliTHn.h"
#include "AliAnalysisTaskSE.h"
#include "AliAnalysisTaskAODTrackPairUtils.h"

using namespace std;

enum trig4Normalization{
  CINT7,
  CMLL7,
  CMUL7,
  CMSL7,
  CMUL7orCMLL7,
  CMUL7andCMLL7,
  CINT7and0MULor0MLL,
  CINT7and0MSL,
  CMSL7and0MULor0MLL,
  CMSL7and0MLL,
  CMSL7and0MUL
};

class AliAnalysisTaskAODEventStudy : public AliAnalysisTaskSE {
       
 public:

  AliAnalysisTaskAODEventStudy();  
  AliAnalysisTaskAODEventStudy(const char *name);  
  virtual ~AliAnalysisTaskAODEventStudy();

  void setUtils(AliAnalysisTaskAODTrackPairUtils* utils)
  {
    fUtils = utils;
  }
  
  void setMC(bool isMC)
  {
    fIsMC = isMC;
  }

 private:  
  
  virtual void   UserCreateOutputObjects();
  virtual void   UserExec(Option_t *option);
  
  bool Initialize();
  void RunQA();
  void TrackQA();
  void FillTrackQA(int index,AliAODTrack* track);
  void MultiplicityQA();
  void FillMultiplicityQA(int index);

  AliAODEvent                      *fEvent;  
  AliAnalysisTaskAODTrackPairUtils *fUtils;
  
  int fRunNumber;
  
  int fNTrackMatchAll;
  int fNTrackMatchApt;
  int fNTrackMatchLpt;
  int fNTrackMatchHpt;

  bool fIsMC;
  bool fIsCINT7;
  bool fIsCMSL7;
  bool fIsCMSH7;
  bool fIsCMUL7;
  bool fIsCMLL7;
  bool fIs0MSL;
  bool fIs0MSH;
  bool fIs0MUL;
  bool fIs0MLL;
  
  std::map<trig4Normalization,std::string> trig4NormalizationMap;

  std::vector<TH2F*> fHistEvent;  
  std::vector<TH1F*> fHistEvent4RunQA;

  TH1F* fHistNTrackMatchAll[6];
  TH1F* fHistNTrackMatchApt[6];
  TH1F* fHistNTrackMatchLpt[6];
  TH1F* fHistNTrackMatchHpt[6];

  TH1F* fHistMeanPtMatchAll[6];
  TH1F* fHistMeanPtMatchApt[6];
  TH1F* fHistMeanPtMatchLpt[6];
  TH1F* fHistMeanPtMatchHpt[6];

  TH1F* fHistCentrality[6];
  TH2F* fHistCentVtxZ[6];  
  TH2F* fHistEtaPt[6];
  
  TH2F* fHistSPDTrkEta05Centrality[6];
  TH2F* fHistSPDTrkEta10Centrality[6];
  TH2F* fHistSPDTrkEta15Centrality[6];
  TH2F* fHistSPDTrkEta20Centrality[6];
  TH2F* fHistSPDTrkEtaAllCentrality[6];    
  TH2F* fHistSPDTrkSPDClust[6];
  
  TH2F* fHistChV0ACentrality[6];
  TH2F* fHistChV0CCentrality[6];
  TH2F* fHistChV0MCentrality[6];
  
  TH2F* fHistCorrV0MCentrality[6];
  TH2F* fHistCorrV0ACentrality[6];
  TH2F* fHistCorrV0CCentrality[6];
  TH2F* fHistCorrSPDTrkCentrality[6];
  /*
  TH2F* fHistCorrChV0AChV0C[6];
  TH2F* fHistCorrCentSPDTrkV0M[6];
  TH2F* fHistCorrCentSPDTrkV0A[6];
  TH2F* fHistCorrCentSPDTrkV0C[6];
  TH2F* fHistCorrCentV0AV0C[6];
  */
  TH1F* fHistPtMatchAll[6];
  TH1F* fHistPtMatchApt[6];
  TH1F* fHistPtMatchLpt[6];
  TH1F* fHistPtMatchHpt[6];
  
  TH1F* fHistRabs;
  TH2F* fHistTrackChi2[4];
  TH2F* fHistTrigChi2[4];
    
  TH2F* fHistChVtxEta;      

  ClassDef(AliAnalysisTaskAODEventStudy, 1); // example of analysis
};

#endif
