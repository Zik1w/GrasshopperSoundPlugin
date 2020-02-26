//
// Fsound.cpp
//
//  Generated on February 26 2020
//  Template created by Peter Gusev on 27 January 2020.
//  Copyright 2013-2019 Regents of the University of California
//

#include "Fsound.h"
#include "logging.hpp"
#include "git-describe.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


// FMOD related headers
#include "FMODBlueprintStatics.h"
#include "fmod_studio.hpp"
#include "fmod.hpp"
#include "fmod_common.h"


#define STRINGIZE_VERSION(v) STRINGIZE_TOKEN(v)
#define STRINGIZE_TOKEN(t) #t
#define PLUGIN_VERSION STRINGIZE_VERSION(GIT_DESCRIBE)

#define MODULE_NAME "Fsound"
#define LOCTEXT_NAMESPACE "FFsoundModule"

void FFsoundModule::StartupModule()
{
    initModule(MODULE_NAME, PLUGIN_VERSION);

    // To log using ReLog plugin, use these macro definitions:
    // DLOG_PLUGIN_ERROR("Error message");
    // DLOG_PLUGIN_WARN("Warning message");
    // DLOG_PLUGIN_INFO("Info message");
    // DLOG_PLUGIN_DEBUG("Debug message");
    // DLOG_PLUGIN_TRACE("Trace message");

    if (IFMODStudioModule::IsAvailable())
    {
        FMOD::Studio::System* StudioSystem = IFMODStudioModule::Get().GetStudioSystem(EFMODSystemContext::Runtime);
        if (StudioSystem)
        {
            // Use it here
            // FFMODEventInstance InstanceWrapper = UFMODBlueprintStatics::PlayEventAtLocation(ThisActor, MyEvent, FTransform(MyLocation), true);
            // FMOD::Studio::EventInstance* Instance = InstanceWrapper.Instance;
            // // Call into FMOD API directly
            // Instance->setVolume(0.5f);
            FMOD::Studio::Bank* masterBank = NULL;
            StudioSystem->loadBankFile("Master Bank.bank", FMOD_STUDIO_LOAD_BANK_NORMAL, &masterBank);

            FMOD::Studio::Bank* stringBank = NULL;
            StudioSystem->loadBankFile("Master Bank.string.bank", FMOD_STUDIO_LOAD_BANK_NORMAL, &stringBank);

            FMOD::Studio::EventDescription* testDescription = NULL;
            FMOD::Studio::EventInstance* testInstance = NULL;
            StudioSystem->getEvent("event:/Test", &testDescription);
            testDescription->createInstance(&testInstance);
            // FMOD_Studio_EventDescription_CreateInstance(TestDescription, &testInstance);
            testInstance->start();
            // FMOD_Studio_EventInstance_Start(testInstance);
        }
    }


    // void *extraDriverData = NULL;
    // Common_Init(&extraDriverData);

    // FMOD::Studio::System* system = NULL;
    // FMOD::Studio::System::create(&system);

    // The example Studio project is authored for 5.1 sound, so set up the system output mode to match
    // FMOD::System* lowLevelSystem = NULL;
    // system->getLowLevelSystem(&lowLevelSystem);
    // lowLevelSystem->setSoftwareFormat(0, FMOD_SPEAKERMODE_5POINT1, 0);

    // system->initialize(32, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, extraDriverData);
    
    // FMOD::Studio::Bank* masterBank = NULL;
    // system->loadBankFile(Common_MediaPath("Master Bank.bank"), FMOD_STUDIO_LOAD_BANK_NORMAL, &masterBank);
    
    // FMOD::Studio::Bank* stringsBank = NULL;
    // system->loadBankFile(Common_MediaPath("Master Bank.strings.bank"), FMOD_STUDIO_LOAD_BANK_NORMAL, &stringsBank);


    // UFMODBlueprintStatics::PlayEvent2D(GetWorld(), TestEvent, true);

    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FFsoundModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FFsoundModule, Fsound)


// /*==============================================================================
// Simple Event Example
// Copyright (c), Firelight Technologies Pty, Ltd 2012-2019.

// This example demonstrates the various ways of playing an event.

// #### Explosion Event ####
// This event is played as a one-shot and released immediately after it has been
// created.

// #### Looping Ambience Event ####
// A single instance is started or stopped based on user input.

// #### Cancel Event ####
// This instance is started and if already playing, restarted.

// ==============================================================================*/
// #include "fmod_studio.h"
// #include "fmod.h"
// #include "common.h"

// int FMOD_Main()
// {
//     void *extraDriverData = NULL;
//     FMOD_STUDIO_SYSTEM* system = NULL;
//     FMOD_SYSTEM* lowLevelSystem = NULL;
//     FMOD_STUDIO_BANK* masterBank = NULL;
//     FMOD_STUDIO_BANK* stringsBank = NULL;
//     FMOD_STUDIO_BANK* sfxBank = NULL;
//     FMOD_STUDIO_EVENTDESCRIPTION* loopingAmbienceDescription = NULL;
//     FMOD_STUDIO_EVENTINSTANCE* loopingAmbienceInstance = NULL;
//     FMOD_STUDIO_EVENTDESCRIPTION* cancelDescription = NULL;
//     FMOD_STUDIO_EVENTINSTANCE* cancelInstance = NULL;
//     FMOD_STUDIO_EVENTDESCRIPTION* explosionDescription = NULL;

//     Common_Init(&extraDriverData);

//     ERRCHECK( FMOD_Studio_System_Create(&system, FMOD_VERSION) );

//     /* The example Studio project is authored for 5.1 sound, so set up the system output mode to match */
//     ERRCHECK( FMOD_Studio_System_GetLowLevelSystem(system, &lowLevelSystem) );
//     ERRCHECK( FMOD_System_SetSoftwareFormat(lowLevelSystem, 0, FMOD_SPEAKERMODE_5POINT1, 0) );

//     ERRCHECK( FMOD_Studio_System_Initialize(system, 1024, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, extraDriverData) );

//     ERRCHECK( FMOD_Studio_System_LoadBankFile(system, Common_MediaPath("Master Bank.bank"), FMOD_STUDIO_LOAD_BANK_NORMAL, &masterBank) );
//     ERRCHECK( FMOD_Studio_System_LoadBankFile(system, Common_MediaPath("Master Bank.strings.bank"), FMOD_STUDIO_LOAD_BANK_NORMAL, &stringsBank) );
//     ERRCHECK( FMOD_Studio_System_LoadBankFile(system, Common_MediaPath("SFX.bank"), FMOD_STUDIO_LOAD_BANK_NORMAL, &sfxBank) );

//     /* Get the Looping Ambience event */
//     ERRCHECK( FMOD_Studio_System_GetEvent(system, "event:/Ambience/Country", &loopingAmbienceDescription) );
//     ERRCHECK( FMOD_Studio_EventDescription_CreateInstance(loopingAmbienceDescription, &loopingAmbienceInstance) );

//     /* Get the 4 Second Surge event */
//     ERRCHECK( FMOD_Studio_System_GetEvent(system, "event:/UI/Cancel", &cancelDescription) );
//     ERRCHECK( FMOD_Studio_EventDescription_CreateInstance(cancelDescription, &cancelInstance) );

//     /* Get the Single Explosion event */
//     ERRCHECK( FMOD_Studio_System_GetEvent(system, "event:/Weapons/Explosion", &explosionDescription) );

//     /* Start loading explosion sample data and keep it in memory */
//     ERRCHECK( FMOD_Studio_EventDescription_LoadSampleData(explosionDescription) );

//     do
//     {
//         Common_Update();
    
//         if (Common_BtnPress(BTN_ACTION1))
//         {
//             /* One-shot event */
//             FMOD_STUDIO_EVENTINSTANCE* eventInstance = NULL;
//             ERRCHECK( FMOD_Studio_EventDescription_CreateInstance(explosionDescription, &eventInstance) );

//             ERRCHECK( FMOD_Studio_EventInstance_Start(eventInstance) );

//             /* Release will clean up the instance when it completes */
//             ERRCHECK( FMOD_Studio_EventInstance_Release(eventInstance) );
//         }

//         if (Common_BtnPress(BTN_ACTION2))
//         {
//             ERRCHECK( FMOD_Studio_EventInstance_Start(loopingAmbienceInstance) );
//         }

//         if (Common_BtnPress(BTN_ACTION3))
//         {
//             ERRCHECK( FMOD_Studio_EventInstance_Stop(loopingAmbienceInstance, FMOD_STUDIO_STOP_IMMEDIATE) );
//         }

//         if (Common_BtnPress(BTN_ACTION4))
//         {
//             /* Calling start on an instance will cause it to restart if it's already playing */
//             ERRCHECK( FMOD_Studio_EventInstance_Start(cancelInstance) );
//         }

//         ERRCHECK( FMOD_Studio_System_Update(system) );

//         Common_Draw("==================================================");
//         Common_Draw("Simple Event Example.");
//         Common_Draw("Copyright (c) Firelight Technologies 2012-2019.");
//         Common_Draw("==================================================");
//         Common_Draw("");
//         Common_Draw("Press %s to fire and forget the explosion", Common_BtnStr(BTN_ACTION1));
//         Common_Draw("Press %s to start the looping ambience", Common_BtnStr(BTN_ACTION2));
//         Common_Draw("Press %s to stop the looping ambience", Common_BtnStr(BTN_ACTION3));
//         Common_Draw("Press %s to start/restart the cancel sound", Common_BtnStr(BTN_ACTION4));
//         Common_Draw("Press %s to quit", Common_BtnStr(BTN_QUIT));

//         Common_Sleep(50);
//     } while (!Common_BtnPress(BTN_QUIT));

//     ERRCHECK( FMOD_Studio_Bank_Unload(sfxBank) );
//     ERRCHECK( FMOD_Studio_Bank_Unload(stringsBank) );
//     ERRCHECK( FMOD_Studio_Bank_Unload(masterBank) );

//     ERRCHECK( FMOD_Studio_System_Release(system) );

//     Common_Close();

//     return 0;
// }
