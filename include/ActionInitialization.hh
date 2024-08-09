#ifndef ActionInitialization_h
#define ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class (from B)

class PhysicsList;

class ActionInitialization : public G4VUserActionInitialization
{
public:
    ActionInitialization();
    ~ActionInitialization() override = default;

    void BuildForMaster() const override;
    void Build() const override;

private:
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif