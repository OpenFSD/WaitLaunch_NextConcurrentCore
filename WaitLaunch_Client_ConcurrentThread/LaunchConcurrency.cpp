#include "LaunchConcurrency.h"
#include <cstddef>

namespace ConcurrentQue
{
    class Global_ConcurrentQue* LaunchConcurrency::ptr_Global = NULL;
    class LaunchConcurrency_Control* LaunchConcurrency::ptr_LaunchConcurrency_Control = NULL;

    LaunchConcurrency::LaunchConcurrency()
    {
        ptr_Global = new class Global_ConcurrentQue();
        ptr_LaunchConcurrency_Control = NULL;
    }

    LaunchConcurrency::~LaunchConcurrency()
    {
        delete ptr_LaunchConcurrency_Control;
    }

    void LaunchConcurrency::Concurrent_Thread_Start(
        class ConcurrentQue::LaunchConcurrency_Control* ptr_LaunchConcurrency_Control,
        unsigned char concurrent_CoreId,
        class ConcurrentQue::Global_ConcurrentQue* ptr_Global
    )
    {
        ptr_LaunchConcurrency_Control->LaunchEnable_Request(concurrent_CoreId, ptr_Global);
        ptr_LaunchConcurrency_Control->LaunchQue_Update(ptr_Global->Get_NumCores());
        ptr_LaunchConcurrency_Control->LaunchEnable_SortQue(ptr_Global, ptr_Global->Get_NumCores());
        ptr_LaunchConcurrency_Control->LaunchEnable_Activate(ptr_Global);
        ptr_LaunchConcurrency_Control->LaunchQue_Update(ptr_Global->Get_NumCores());
        ptr_LaunchConcurrency_Control->LaunchEnable_SortQue(ptr_Global, ptr_Global->Get_NumCores());
        ptr_LaunchConcurrency_Control->SetFlag_PraisingLaunch(false);
    }

    void LaunchConcurrency::Initialise_Control(
        class ConcurrentQue::Global_ConcurrentQue* ptr_Global,
        unsigned char ptr_MyNumImplementedCores
    )
    {
        ptr_LaunchConcurrency_Control = new class ConcurrentQue::LaunchConcurrency_Control(ptr_Global, ptr_MyNumImplementedCores);
        while (ptr_LaunchConcurrency_Control == NULL) { /* wait untill created */ }
    }

    void LaunchConcurrency::Thread_End(
        class ConcurrentQue::LaunchConcurrency_Control* ptr_LaunchConcurrency_Control,
        unsigned char concurrent_CoreId,
        class ConcurrentQue::Global_ConcurrentQue* ptr_Global
    )
    {
        while (ptr_LaunchConcurrency_Control->GetFlag_PraisingLaunch() == true)
        {

        }
        ptr_LaunchConcurrency_Control->SetFlag_PraisingLaunch(true);
        ptr_LaunchConcurrency_Control->Set_concurrent_CoreId_Index(ptr_LaunchConcurrency_Control->Get_new_concurrent_CoreId_Index());
        if (ptr_LaunchConcurrency_Control->Get_concurrent_CoreId_Index() == concurrent_CoreId)
        {
            ptr_LaunchConcurrency_Control->SetFlag_ConcurrentCoreState(concurrent_CoreId, ptr_Global->GetConst_Core_IDLE());
        }
        else
        {
            ptr_LaunchConcurrency_Control->Set_new_concurrent_CoreId_Index(ptr_LaunchConcurrency_Control->Get_concurrent_CoreId_Index() + 1);

            if (ptr_LaunchConcurrency_Control->Get_new_concurrent_CoreId_Index() == 3)//NUMBER OF CONCURNT CORES
            {
                ptr_LaunchConcurrency_Control->Set_new_concurrent_CoreId_Index(0);
            }
            ptr_LaunchConcurrency_Control->SetFlag_PraisingLaunch(false);
            Thread_End(
                ptr_LaunchConcurrency_Control,
                concurrent_CoreId,
                ptr_Global
            );
        }
    }

    class LaunchConcurrency_Control* LaunchConcurrency::Get_Control_Of_LaunchConcurrency()
    {
        return ptr_LaunchConcurrency_Control;
    }

    Global_ConcurrentQue* LaunchConcurrency::Get_GlobalForLaunchConcurrency()
    {
        return ptr_Global;
    }
}