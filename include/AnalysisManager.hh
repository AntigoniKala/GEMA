#ifndef AnalysisManager_h
#define AnalysisManager_h 1

#include "G4GenericAnalysisManager.hh"
#include "G4ThreadLocalSingleton.hh"

class AnalysisManager
{

    friend class G4ThreadLocalSingleton<AnalysisManager>;

public:
    virtual ~AnalysisManager();
    static AnalysisManager *GetInstance()
    {
        static G4ThreadLocalSingleton<AnalysisManager> instance;
        return instance.Instance();
    }

    void BeginOfRunAction();
    void EndOfRunAction();

    void angleDist(G4double angle);

private:
    G4GenericAnalysisManager *Analman = nullptr;
    AnalysisManager();
};

#endif