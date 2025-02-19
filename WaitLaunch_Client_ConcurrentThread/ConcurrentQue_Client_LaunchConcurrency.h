#pragma once
#include "ConcurrentQue_Client_Framework.h"
#include "ConcurrentQue_Client_LaunchConcurrency_Control.h"
#include "ConcurrentQue_Client_Global.h"

namespace ConcurrentQue
{
    class ConcurrentQue_Client_LaunchConcurrency
    {
    public:
        ConcurrentQue_Client_LaunchConcurrency();
        virtual ~ConcurrentQue_Client_LaunchConcurrency();

        void Thread_Start(unsigned char concurrent_CoreId);
        void Initialise_Control(
            class ConcurrentQue_Client_Global* ptr_Global,
            unsigned char ptr_MyNumImplementedCores
        );
        void Thread_End(unsigned char concurrent_CoreId);

        class ConcurrentQue_Client_LaunchConcurrency_Control* Get_Control_Of_LaunchConcurrency();
        class ConcurrentQue_Client_Global* Get_GlobalForLaunchConcurrency();

    protected:

    private:
        static class ConcurrentQue_Client_Global* ptr_Global;
        static class ConcurrentQue_Client_LaunchConcurrency_Control* ptr_LaunchConcurrency_Control;
    };
}