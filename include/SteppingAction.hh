#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "AnalysisManager.hh"
#include "G4UserSteppingAction.hh"
#include "G4VPhysicalVolume.hh"

class DetectorConstruction;
class RunAction;

class SteppingAction : public G4UserSteppingAction
{
public:
    SteppingAction();
    virtual ~SteppingAction();

    virtual void UserSteppingAction(const G4Step *);

private:
    const DetectorConstruction *fDetector = nullptr;
    const G4VPhysicalVolume *fPhysiAbsorber = nullptr;
    AnalysisManager *Analman = nullptr;
};

#endif
