#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "SteppingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
ActionInitialization::ActionInitialization()
{
}

void ActionInitialization::BuildForMaster() const
{
    auto runAction = new RunAction();
    SetUserAction(runAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ActionInitialization::Build() const
{
    PrimaryGeneratorAction *kin = new PrimaryGeneratorAction();
    RunAction *run = new RunAction();
    SteppingAction *step = new SteppingAction();

    SetUserAction(kin);
    SetUserAction(run);
    SetUserAction(step);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
