#include "PhysicsList.hh"
#include "G4ParticleDefinition.hh"
#include "G4ProcessManager.hh"
#include "G4Neutron.hh"
#include "G4Gamma.hh"
#include "G4Alpha.hh"
#include "G4Electron.hh"
#include "G4Decay.hh"
#include "G4HadronElasticProcess.hh"
#include "G4NeutronInelasticProcess.hh"
#include "G4IonTable.hh"

PhysicsList::PhysicsList() : G4VUserPhysicsList() {}

void PhysicsList::ConstructParticle() {
    G4Neutron::NeutronDefinition();
    G4Gamma::GammaDefinition();
    G4Alpha::AlphaDefinition();
    G4Electron::ElectronDefinition();
    G4IonTable::GetIonTable()->GetIon(92, 238, 0);
}

void PhysicsList::ConstructProcess() {
    AddTransportation();
    G4ProcessManager* pManager = G4Neutron::Neutron()->GetProcessManager();
    pManager->AddProcess(new G4NeutronInelasticProcess());
    pManager->AddProcess(new G4HadronElasticProcess());
    G4ProcessManager* alphaManager = G4Alpha::Alpha()->GetProcessManager();
    alphaManager->AddProcess(new G4Decay());
    G4ProcessManager* electronManager = G4Electron::Electron()->GetProcessManager();
    electronManager->AddProcess(new G4Decay());
}

void PhysicsList::SetCuts() {
    SetCutValue(1.0 * mm, "gamma");
    SetCutValue(1.0 * mm, "e-");
    SetCutValue(1.0 * mm, "neutron");
    SetCutValue(1.0 * mm, "alpha");
}