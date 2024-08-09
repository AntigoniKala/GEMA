#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4Cache.hh"
#include "G4LogicalVolume.hh"
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4Box;
class G4VPhysicalVolume;
class G4Material;
class G4MaterialCutsCouple;
class G4UniformMagField;
class DetectorMessenger;
class G4GlobalMagFieldMessenger;

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
    explicit DetectorConstruction();
    virtual ~DetectorConstruction();

    void SetAbsorberMaterial(const G4String &);
    void SetAbsorberThickness(G4double);

    void SetWorldMaterial(const G4String &);

    G4VPhysicalVolume *Construct() override;
    void ConstructSDandField() override;

    const G4Material *GetAbsorberMaterial() const { return fAbsorberMaterial; };
    G4double GetAbsorberThickness() const { return fAbsorberThickness; };

    const G4VPhysicalVolume *GetAbsorber() const { return fPhysiAbsorber; };

private:
    void DefineMaterials();
    void ChangeGeometry();

    G4Material *fAbsorberMaterial;
    G4double fAbsorberThickness;
    G4double fAbsorberSizeXY;

    G4Material *fWorldMaterial;
    G4double fWorldSize;

    G4Box *fSolidWorld;
    G4LogicalVolume *fLogicWorld;
    G4VPhysicalVolume *fPhysiWorld;

    G4Box *fSolidAbsorber;
    G4LogicalVolume *fLogicAbsorber;
    G4VPhysicalVolume *fPhysiAbsorber;

    DetectorMessenger *fDetectorMessenger;
};

#endif
