#include "DetectorConstruction.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Material.hh"

DetectorConstruction::DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    G4double worldSize = 1.0 * m;
    G4Material* air = G4Material::GetMaterial("G4_AIR");

    G4Box* solidWorld = new G4Box("World", worldSize, worldSize, worldSize);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, air, "World");
    G4PVPlacement* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0);

    return physWorld;
}