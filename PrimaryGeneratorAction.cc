#include "PrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4Event.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction() {
    fParticleGun = new G4ParticleGun(1);
    fParticleGun->SetParticleDefinition(G4Neutron::NeutronDefinition());
    fParticleGun->SetParticleEnergy(14 * MeV);
    fParticleGun->SetParticlePosition(G4ThreeVector(0, 0, -1 * m));
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) {
    fParticleGun->GeneratePrimaryVertex(anEvent);
}