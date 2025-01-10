#pragma once
#include "LaunchConcurrency_Control.h"
#include "Global_ConcurrentQue.h"

namespace ConcurrentQue
{
    class LaunchConcurrency
    {
    public:
        LaunchConcurrency();
        virtual ~LaunchConcurrency();

        void Concurrent_Thread_Start(
            //class LaunchConcurrency_Control* ptr_LaunchConcurrency_Control,
            unsigned char* ptr_concurrent_CoreId,
            class Global_ConcurrentQue* ptr_Global,
            unsigned char* ptr_NumImplementedCores

        );
        void Initialise_Control(
            class Global_ConcurrentQue* ptr_Global,
            unsigned char* ptr_MyNumImplementedCores
        );
        void Thread_End(
            //class LaunchConcurrency_Control* ptr_LaunchConcurrency_Control,
            unsigned char* ptr_concurrent_CoreId,
            class Global_ConcurrentQue* ptr_Global
        );
        class LaunchConcurrency_Control* Get_Control_Of_LaunchConcurrency();
        class Global_ConcurrentQue* Get_GlobalForLaunchConcurrency();

    protected:

    private:
        static class Global_ConcurrentQue* ptr_Global;
        static class LaunchConcurrency_Control* ptr_LaunchConcurrency_Control;
    };
}