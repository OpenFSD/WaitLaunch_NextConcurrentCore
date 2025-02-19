#include "ConcurrentQue_Server_LaunchConcurrency.h"
#include <cstddef>

namespace ConcurrentQue
{
    class ConcurrentQue_Server_Global* ConcurrentQue_Server_LaunchConcurrency::ptr_Global = NULL;
    class ConcurrentQue_Server_LaunchConcurrency_Control* ConcurrentQue_Server_LaunchConcurrency::ptr_LaunchConcurrency_Control = NULL;

    ConcurrentQue_Server_LaunchConcurrency::ConcurrentQue_Server_LaunchConcurrency()
    {
        ptr_Global = new class ConcurrentQue_Server_Global();
        ptr_LaunchConcurrency_Control = NULL;
    }

    ConcurrentQue_Server_LaunchConcurrency::~ConcurrentQue_Server_LaunchConcurrency()
    {
        delete ptr_LaunchConcurrency_Control;
    }

    void ConcurrentQue_Server_LaunchConcurrency::Thread_Start(unsigned char concurrent_CoreId)
    {
        class ConcurrentQue::ConcurrentQue_Server_LaunchConcurrency_Control* ptr_LaunchConcurrency_Control = ConcurrentQue::ConcurrentQue_Server_Framework::Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency();
        class ConcurrentQue::ConcurrentQue_Server_Global* ptr_Global = ConcurrentQue::ConcurrentQue_Server_Framework::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency();
        ptr_LaunchConcurrency_Control->LaunchEnable_Request(concurrent_CoreId, ptr_Global);
        ptr_LaunchConcurrency_Control->LaunchQue_Update(ptr_Global->Get_NumCores());
        ptr_LaunchConcurrency_Control->LaunchEnable_SortQue(ptr_Global, ptr_Global->Get_NumCores());
        ptr_LaunchConcurrency_Control->LaunchEnable_Activate(ptr_Global);
        ptr_LaunchConcurrency_Control->LaunchQue_Update(ptr_Global->Get_NumCores());
        ptr_LaunchConcurrency_Control->LaunchEnable_SortQue(ptr_Global, ptr_Global->Get_NumCores());
        ptr_LaunchConcurrency_Control->SetFlag_PraisingLaunch(false);
    }

    void ConcurrentQue_Server_LaunchConcurrency::Initialise_Control(
        class ConcurrentQue::ConcurrentQue_Server_Global* ptr_Global,
        unsigned char ptr_MyNumImplementedCores
    )
    {
        ptr_LaunchConcurrency_Control = new class ConcurrentQue::ConcurrentQue_Server_LaunchConcurrency_Control(ptr_Global, ptr_MyNumImplementedCores);
        while (ptr_LaunchConcurrency_Control == NULL) { /* wait untill created */ }
    }

    void ConcurrentQue_Server_LaunchConcurrency::Thread_End(unsigned char concurrent_CoreId)
    {
        class ConcurrentQue::ConcurrentQue_Server_LaunchConcurrency_Control* ptr_LaunchConcurrency_Control = ConcurrentQue::ConcurrentQue_Server_Framework::Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency();
        class ConcurrentQue::ConcurrentQue_Server_Global* ptr_Global = ConcurrentQue::ConcurrentQue_Server_Framework::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency();
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
            Thread_End(concurrent_CoreId);
        }
    }

    class ConcurrentQue_Server_LaunchConcurrency_Control* ConcurrentQue_Server_LaunchConcurrency::Get_Control_Of_LaunchConcurrency()
    {
        return ptr_LaunchConcurrency_Control;
    }

    ConcurrentQue_Server_Global* ConcurrentQue_Server_LaunchConcurrency::Get_GlobalForLaunchConcurrency()
    {
        return ptr_Global;
    }
}