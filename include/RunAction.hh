#ifndef RunAction_h
#define RunAction_h 1

#include "AnalysisManager.hh"
#include "G4AnalysisManager.hh"
#include "G4UserRunAction.hh"
#include "globals.hh"

class DetectorConstruction;
class PhysicsList;
class PrimaryGeneratorAction;

class G4Run;

class RunAction : public G4UserRunAction
{
public:
    RunAction();
    virtual ~RunAction();

    virtual void BeginOfRunAction(const G4Run *);
    virtual void EndOfRunAction(const G4Run *);

private:
    AnalysisManager *Analman = nullptr;
};

#endif
