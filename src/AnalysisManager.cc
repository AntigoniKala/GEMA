#include "AnalysisManager.hh"

AnalysisManager::AnalysisManager()
{
    Analman = G4GenericAnalysisManager::Instance();
    Analman->SetActivation(true);
    Analman->SetNtupleActivation(true);

    if (G4Threading::IsMultithreadedApplication())
        Analman->SetNtupleMerging(true);
}

AnalysisManager::~AnalysisManager()
{
}

void AnalysisManager::BeginOfRunAction()
{
    Analman->OpenFile("Out.csv");
    Analman->CreateH1("Angle_Distribution", "Angle_Distribution", 100, 0, 0.2, "radian");
}

void AnalysisManager::EndOfRunAction()
{
    Analman->Write();
    Analman->CloseFile();
}

void AnalysisManager::angleDist(G4double angle)
{
    G4cout << angle << G4endl;
    Analman->FillH1(0, angle);
}
