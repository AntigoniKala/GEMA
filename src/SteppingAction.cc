#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "G4RunManager.hh"
#include "G4Step.hh"
#include "G4StepPoint.hh"
#include "Randomize.hh"
#include "RunAction.hh"

SteppingAction::SteppingAction() : G4UserSteppingAction()
{
    fDetector = static_cast<const DetectorConstruction *>(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fPhysiAbsorber = fDetector->GetAbsorber();
    Analman = AnalysisManager::GetInstance();
}

SteppingAction::~SteppingAction()
{
}

void SteppingAction::UserSteppingAction(const G4Step *step)
{

    G4StepPoint *prePoint = step->GetPreStepPoint();
    G4StepPoint *postPoint = step->GetPostStepPoint();

    auto preVol = prePoint->GetTouchableHandle()->GetVolume();
    auto postVol = postPoint->GetTouchableHandle()->GetVolume();

    if (preVol == fPhysiAbsorber && postVol != fPhysiAbsorber)
    {
        G4ThreeVector mom = postPoint->GetMomentumDirection();
        G4String particleName = step->GetTrack()->GetParticleDefinition()->GetParticleName();
        G4double angle = mom.theta();
        G4cout << preVol->GetName() << " " << postVol->GetName() << " " << angle << " " << particleName << G4endl;
        Analman->angleDist(angle);
    }
}
