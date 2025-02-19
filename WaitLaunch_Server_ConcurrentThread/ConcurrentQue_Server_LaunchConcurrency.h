#pragma once
#include "ConcurrentQue_Server_Framework.h"
#include "ConcurrentQue_Server_LaunchConcurrency_Control.h"
#include "ConcurrentQue_Server_Global.h"

namespace ConcurrentQue
{
    class ConcurrentQue_Server_LaunchConcurrency
    {
    public:
        ConcurrentQue_Server_LaunchConcurrency();
        virtual ~ConcurrentQue_Server_LaunchConcurrency();

        void Thread_Start(unsigned char concurrent_CoreId);
        void Initialise_Control(
            class ConcurrentQue_Server_Global* ptr_Global,
            unsigned char ptr_MyNumImplementedCores
        );
        void Thread_End(unsigned char concurrent_CoreId);

        class ConcurrentQue_Server_LaunchConcurrency_Control* Get_Control_Of_LaunchConcurrency();
        class ConcurrentQue_Server_Global* Get_GlobalForLaunchConcurrency();

    protected:

    private:
        static class ConcurrentQue_Server_Global* ptr_Global;
        static class ConcurrentQue_Server_LaunchConcurrency_Control* ptr_LaunchConcurrency_Control;
    };
}