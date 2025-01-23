#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "LaunchConcurrency.h"

namespace ConcurrentQue
{
    class Framework_ConcurrentQue
    {
    public:
        Framework_ConcurrentQue();
        virtual ~Framework_ConcurrentQue();
        static void Request_Wait_Launch_ConcurrentThread(unsigned char concurrent_CoreId);
        static void ConcurrentThread_End(unsigned char concurrent_CoreId);

        static void Create_ConcurrentQue();
        static class LaunchConcurrency* Get_LaunchConcurrency();
        
        static __int16 Get_coreId_To_Launch();
        static bool Get_Flag_Active();
        static bool Get_Flag_Idle();
        static bool Get_State_LaunchBit();

    protected:

    private:
        static class LaunchConcurrency* ptr_LaunchConcurrency;
    };
}