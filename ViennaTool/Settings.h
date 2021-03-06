#include "TString.h"

#define kMU          0
#define kEL          1
#define kTAU         2
///////////////////////////////////////////////////
#define selCHAN      kTAU
const int CHAN     = kTAU;
const TString analysis      ="FakeFactor_2016_MSSM_preapproval_dev";
const TString output_folder ="/public/Htautau/FakeRate2016/20170718/";
///////////////////////////////////////////////////
const TString user="whoami";
const Double_t luminosity=35.9; 
const int use_svfit = 0;
const TString ver = "v16";
///////////////////////////////////////////////////
const int inclusive_selection=1; 
const int exclusive_selection=1; 
const int useVV=1;
const int useMVAMET=0;
///////////////////////////////////////////////////
const int DEBUG=1; //set to 1 for additional output
const int ALLPLOTS=1; //set to 1 for PDFs etc
const int DOQCD=1; //set to 1 to include QCD estimate, 0 for w/o; only works for MC
const int DOMC=0; //set to 1 for MC, 0 for data
const int doCuts=0;
const int CALC_SS_SR=0; //default: 0   //0.15<QCD_iso<0.25 for QCD FFs
const int num = 0;
const int doSRHisto = 1;
const int doCRHisto = 1;
///////////////////////////////////////////////////
//steerFF
const int doDebugPlots=1;    //1 to also calculate FF in SR; and do bkg estimate with unweighted FF per sample ->for control plots
const int doCutPlots=1;      //1 to also calculate cut-dependent plots (prong, eta, pt)
const int doSRPlots=0;      //1 to also calculate SR and all-region plots for FF vs default binning and mT (mtll and muiso is always done)
const int doPlotsVsMC=1;    //only works if mc has already run; no impact on sim-only runs
const int applyFF_fromCR=1; //1 for default; 0 for debugging
const int requireGenMatch_whenCalcFF=0; //0 as default
const int useDYFF_forTT=0; //0 as default
const int useWJFF_forDY=0; //1 as default
const int doCalcWeights=1; //calc fractions
const int doTemplateFitForWeights=0; //template fit for fractions, default: 0
const int doCalc=1; //calc FFs
//////////////////////////////////////////////////
const int fit_pT_bins = 1; //use fitted pT bins as input for ff
//////////////////////////////////////////////////
//MUTAU Settings
#if(selCHAN==kMU)
const double fitMin =  30;
const int fitBins  =  470;
const int COINFLIP=1;
const Double_t Pt_cuts_Wjets[]    = {30.,34,39,50,60,75,90,110,140,180,500};
const Double_t Pt_cuts_DY[]       = {30.,40.};
const Double_t Pt_cuts_TT_SR[]    = {30.,32.5,35.,40.,45,50,70,90,115,175,500};
const Double_t Pt_cuts_TT_CR[]    = {30.};
const Double_t Pt_cuts_QCD[]      = {30,35,40,50,70,120,500};
const Double_t Pt_cuts_QCD_AI[]   = {30,35,40,50,75,120,500};
#endif
//////////////////////////////////////////////////
//ETAU Settings
#if(selCHAN==kEL)
const double fitMin =  30;
const int fitBins  =  470;
const int COINFLIP=1;
const Double_t Pt_cuts_Wjets[]    = {30.,35,40,50,60,75,95,120,170,500};
const Double_t Pt_cuts_DY[]       = {30.,40.};
const Double_t Pt_cuts_TT_SR[]    = {30.,32.,34,37.,40,45,50,70,110,160,500};
const Double_t Pt_cuts_TT_CR[]    = {30.};
const Double_t Pt_cuts_QCD[]      = {30,32.5,35,40,50,60,70,80,110,500};
const Double_t Pt_cuts_QCD_AI[]   = {30,35,45,55,80,500};
#endif
//////////////////////////////////////////////////
//TAUTAU Settings
#if(selCHAN==kTAU)
const double fitMin =  40;
const int fitBins  =  460;
const int COINFLIP=0;
const Double_t Pt_cuts_Wjets[]    = {40.,};
const Double_t Pt_cuts_DY[]       = {40.};
const Double_t Pt_cuts_TT_SR[]    = {40.};
const Double_t Pt_cuts_TT_CR[]    = {40.};
const Double_t Pt_cuts_QCD[]      = {40.,42.5,45.,50.,55,60,65,75,95,155};
const Double_t Pt_cuts_QCD_AI[]   = {40,42.5,45,50,60,75,115,180};
#endif
//////////////////////////////////////////////////
const double fitMax = 500;
//////////////////////////////////////////////////
const int NB_MTCORR = 2;
const int USE_FIT_BINS = 0; //1: the mT correction is used for x value -0.5 - +0.5: mT=0-10 etc
//const Double_t FIT_BINS[]={0,10,20,30,40,150};
const Double_t FIT_BINS[] = {0,10,20,30,40,50,60,70,150 };
////const Int_t    p_mt_n=(sizeof(p_mt_v)/sizeof(Double_t)) -1;
//const Int_t MT_FIT_NORM_MIN=40; //fit up to this value; use above to normalize. Original: 70
const unsigned nFIT_BINS = (sizeof(FIT_BINS)/sizeof(Double_t)) -1;
const Double_t PTDM_BINS[] = {0,1,2,3,4,5,6,7,8};
//const Double_t PTDM_BINS[] = {0,1,2,3,4};
const unsigned nPTDM_BINS = (sizeof(PTDM_BINS)/sizeof(Double_t)) -1;
//const Double_t MT_FIT_UP_TO = nFIT_BINS - 1.5; //do not include bin normalised to 1
const Double_t PTDMJET_BINS[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
const unsigned nPTDMJET_BINS = (sizeof(PTDMJET_BINS)/sizeof(Double_t)) -1;
const Double_t MT_FIT_UP_TO = nFIT_BINS - 0.5; //include bin normalised to 1
const Double_t MT_CORR_MAX = 70;

const Double_t DR_LEP_CUT=0.5;
const Double_t LEP_ETA_CUT=2.1;
const Double_t LEP_PT_CUT=10;
const Double_t LEP_ISO_CUT=0.15;
const Double_t LEP_ISO_CUT_ET=0.1; //this is only important for signal electron, for all other selections LEP_ISO_CUT is taken
const Double_t TAU1_ISO_CUT=9; //>9(vtight/tight)
const Double_t DR_TAU_LEP_CUT=0.4;
const Double_t TAU_ETA_CUT=2.3;
const Double_t TAU_PT_CUT=20.;
const Double_t TAU_ETA_CUT_TT=2.1;
const Double_t TAU_PT_CUT_TT=40.;
const Double_t MT_CUT=40;

const Double_t MZ=91.2;
const Double_t QCD_SS_TO_OS=1.06;


//////////////////////////////////////////////////
//extra fit uncertainties
const int useExtraFitUncertainties = 1;
const Double_t QCD_fitErr_dm0njet0_mt = 0.02;
const Double_t QCD_fitErr_dm0njet1_mt = 0.04;
const Double_t QCD_fitErr_dm1njet0_mt = 0.08;
const Double_t QCD_fitErr_dm1njet1_mt = 0.08;
const Double_t W_fitErr_dm0njet0_mt = 0.02;
const Double_t W_fitErr_dm0njet1_mt = 0.02;
const Double_t W_fitErr_dm1njet0_mt = 0.05;
const Double_t W_fitErr_dm1njet1_mt = 0.05;
const Double_t QCD_fitErr_dm0njet0_et = 0.02;
const Double_t QCD_fitErr_dm0njet1_et = 0.04;
const Double_t QCD_fitErr_dm1njet0_et = 0.08;
const Double_t QCD_fitErr_dm1njet1_et = 0.08;
const Double_t W_fitErr_dm0njet0_et = 0.02;
const Double_t W_fitErr_dm0njet1_et = 0.02;
const Double_t W_fitErr_dm1njet0_et = 0.05;
const Double_t W_fitErr_dm1njet1_et = 0.05;
const Double_t QCD_fitErr_dm0njet0_tt = 0.02;
const Double_t QCD_fitErr_dm0njet1_tt = 0.04;
const Double_t QCD_fitErr_dm1njet0_tt = 0.08;
const Double_t QCD_fitErr_dm1njet1_tt = 0.08;
//extra OSSS uncertainties
const int useExtraOSSSuncertainty = 1;
const Double_t OSSSuncertainty_mt = 0.1;
const Double_t OSSSuncertainty_et = 0.1;
const Double_t OSSSuncertainty_tt = 0.1;
//uncertainties for substituting DY FFs
const int useWToDYUncertainty = 1;
const Double_t WToDYUncertainty_mt = 0.05;
const Double_t WToDYUncertainty_et = 0.05;

