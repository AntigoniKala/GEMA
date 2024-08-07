#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "SteppingAction.hh"
#include "TrackingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
ActionInitialization::ActionInitialization(DetectorConstruction *D, PhysicsList *P) : det(D), phys(P)
{
}

void ActionInitialization::BuildForMaster() const
{
    PrimaryGeneratorAction *kin = new PrimaryGeneratorAction(det);
    auto runAction = new RunAction(det, phys, kin);
    SetUserAction(runAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ActionInitialization::Build() const
{
    PrimaryGeneratorAction *kin = new PrimaryGeneratorAction(det);
    RunAction *run = new RunAction(det, phys, kin);
    TrackingAction *track = new TrackingAction(det, run);
    SteppingAction *step = new SteppingAction(det, run);

    SetUserAction(kin);
    SetUserAction(run);
    SetUserAction(track);
    SetUserAction(step);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
