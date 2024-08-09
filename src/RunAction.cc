#include "RunAction.hh"
#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "StepMax.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include "G4ios.hh"

#include "Randomize.hh"

RunAction::RunAction() : G4UserRunAction()
{
    Analman = AnalysisManager::GetInstance();
}

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction(const G4Run *aRun)
{
    Analman->BeginOfRunAction();
}

void RunAction::EndOfRunAction(const G4Run *aRun)
{
    Analman->EndOfRunAction();
}
