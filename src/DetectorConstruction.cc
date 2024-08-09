#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4Material.hh"
#include "G4PVPlacement.hh"
#include "G4UniformMagField.hh"

#include "G4GeometryManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4SolidStore.hh"

#include "G4NistManager.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"

#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

#include "G4AutoDelete.hh"
#include "G4GlobalMagFieldMessenger.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
    : G4VUserDetectorConstruction()

{
    // default parameter values of the calorimeter
    fAbsorberThickness = 440.0 * nm;
    fAbsorberSizeXY = 1. * cm;
    fWorldSize = 1.5 * cm;

    // materials
    DefineMaterials();
    SetWorldMaterial("G4_Galactic");
    SetAbsorberMaterial("G4_C");

    fDetectorMessenger = new DetectorMessenger(this);
}

DetectorConstruction::~DetectorConstruction()
{
    delete fDetectorMessenger;
}

void DetectorConstruction::DefineMaterials()
{
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume *DetectorConstruction::Construct()
{
    if (nullptr != fPhysiWorld)
    {
        return fPhysiWorld;
    }
    // World
    //
    fSolidWorld = new G4Box("World",                                         // its name
                            fWorldSize / 2, fWorldSize / 2, fWorldSize / 2); // its size

    fLogicWorld = new G4LogicalVolume(fSolidWorld,    // its solid
                                      fWorldMaterial, // its material
                                      "World");       // its name

    fPhysiWorld = new G4PVPlacement(0,                         // no rotation
                                    G4ThreeVector(0., 0., 0.), // at (0,0,0)
                                    fLogicWorld,               // its logical volume
                                    "World",                   // its name
                                    0,                         // its mother  volume
                                    false,                     // no boolean operation
                                    0);                        // copy number

    // Absorber
    //
    fSolidAbsorber = new G4Box("Absorber",
                               fAbsorberSizeXY / 2, fAbsorberSizeXY / 2, fAbsorberThickness / 2);

    fLogicAbsorber = new G4LogicalVolume(fSolidAbsorber,    // its solid
                                         fAbsorberMaterial, // its material
                                         "Absorber");       // its name

    fPhysiAbsorber = new G4PVPlacement(0,                                            // no rotation
                                       G4ThreeVector(0, 0., fAbsorberThickness / 2), // its position
                                       fLogicAbsorber,                               // its logical volume
                                       "Absorber",                                   // its name
                                       fLogicWorld,                                  // its mother
                                       false,                                        // no boulean operat
                                       0);                                           // copy number

    return fPhysiWorld;
}

void DetectorConstruction::SetAbsorberMaterial(const G4String &materialChoice)
{
    // search the material by its name
    G4Material *pttoMaterial =
        G4NistManager::Instance()->FindOrBuildMaterial(materialChoice);

    if (pttoMaterial && fAbsorberMaterial != pttoMaterial)
    {
        fAbsorberMaterial = pttoMaterial;
        if (fLogicAbsorber)
        {
            fLogicAbsorber->SetMaterial(fAbsorberMaterial);
        }
        G4RunManager::GetRunManager()->PhysicsHasBeenModified();
    }
}

void DetectorConstruction::SetWorldMaterial(const G4String &materialChoice)
{
    // search the material by its name
    G4Material *pttoMaterial =
        G4NistManager::Instance()->FindOrBuildMaterial(materialChoice);

    if (pttoMaterial && fWorldMaterial != pttoMaterial)
    {
        fWorldMaterial = pttoMaterial;
        if (fLogicWorld)
        {
            fLogicWorld->SetMaterial(fWorldMaterial);
        }
        G4RunManager::GetRunManager()->PhysicsHasBeenModified();
    }
}

void DetectorConstruction::SetAbsorberThickness(G4double val)
{
    fAbsorberThickness = val;
    ChangeGeometry();
}

void DetectorConstruction::ConstructSDandField()
{
}

void DetectorConstruction::ChangeGeometry()
{
    fSolidWorld->SetXHalfLength(fWorldSize * 0.5);
    fSolidWorld->SetYHalfLength(fWorldSize * 0.5);
    fSolidWorld->SetZHalfLength(fWorldSize * 0.5);

    fSolidAbsorber->SetXHalfLength(fAbsorberSizeXY * 0.5);
    fSolidAbsorber->SetYHalfLength(fAbsorberSizeXY * 0.5);
    fSolidAbsorber->SetZHalfLength(fAbsorberThickness * 0.5);
}
