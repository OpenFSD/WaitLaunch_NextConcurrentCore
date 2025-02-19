#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "ConcurrentQue_Server_LaunchConcurrency.h"

namespace ConcurrentQue
{
    class ConcurrentQue_Server_Framework
    {
    public:
        ConcurrentQue_Server_Framework();
        virtual ~ConcurrentQue_Server_Framework();
        static void Request_Wait_Launch_ConcurrentThread(unsigned char concurrent_CoreId);
        static void Concurrent_Thread_End(unsigned char concurrent_CoreId);

        static void Create_ConcurrentQue();
        static class ConcurrentQue_Server_LaunchConcurrency* Get_LaunchConcurrency();
        
        static __int16 Get_coreId_To_Launch();
        static bool Get_Flag_Active();
        static bool Get_Flag_Idle();
        static bool Get_State_LaunchBit();

    protected:

    private:
        static class ConcurrentQue_Server_LaunchConcurrency* ptr_LaunchConcurrency;
    };
}