#ifndef DetectorMessenger_h
#define DetectorMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class DetectorConstruction;
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithAnInteger;
class G4UIcmdWithADoubleAndUnit;
class G4UIcmdWithoutParameter;

class DetectorMessenger : public G4UImessenger
{
public:
    DetectorMessenger(DetectorConstruction *);
    ~DetectorMessenger();

    void SetNewValue(G4UIcommand *, G4String) override;

private:
    DetectorConstruction *fDetector;

    G4UIdirectory *fTestemDir;
    G4UIdirectory *fDetDir;

    G4UIcmdWithAString *fAbsMaterCmd;
    G4UIcmdWithADoubleAndUnit *fAbsThickCmd;
};

#endif
