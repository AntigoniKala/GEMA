#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithoutParameter.hh"
#include "G4UIdirectory.hh"

DetectorMessenger::DetectorMessenger(DetectorConstruction *Det)
    : G4UImessenger(), fDetector(Det),
      fTestemDir(0),
      fDetDir(0),
      fAbsMaterCmd(0),
      fAbsThickCmd(0)
{
    fTestemDir = new G4UIdirectory("/testem/");
    fTestemDir->SetGuidance("UI commands specific to this example.");

    fDetDir = new G4UIdirectory("/testem/det/", false);
    fDetDir->SetGuidance("detector construction commands");

    fAbsMaterCmd = new G4UIcmdWithAString("/testem/det/setAbsMat", this);
    fAbsMaterCmd->SetGuidance("Select Material of the Absorber.");
    fAbsMaterCmd->SetParameterName("choice", false);
    fAbsMaterCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    fAbsMaterCmd->SetToBeBroadcasted(false);

    fAbsThickCmd = new G4UIcmdWithADoubleAndUnit("/testem/det/setAbsThick", this);
    fAbsThickCmd->SetGuidance("Set Thickness of the Absorber");
    fAbsThickCmd->SetParameterName("SizeZ", false);
    fAbsThickCmd->SetRange("SizeZ>0.");
    fAbsThickCmd->SetUnitCategory("Length");
    fAbsThickCmd->AvailableForStates(G4State_PreInit, G4State_Idle);
    fAbsThickCmd->SetToBeBroadcasted(false);
}
DetectorMessenger::~DetectorMessenger()
{
    delete fAbsMaterCmd;
    delete fAbsThickCmd;
    delete fDetDir;
    delete fTestemDir;
}

void DetectorMessenger::SetNewValue(G4UIcommand *command, G4String newValue)
{
    if (command == fAbsMaterCmd)
    {
        fDetector->SetAbsorberMaterial(newValue);
    }

    if (command == fAbsThickCmd)
    {
        fDetector->SetAbsorberThickness(fAbsThickCmd->GetNewDoubleValue(newValue));
    }
}
