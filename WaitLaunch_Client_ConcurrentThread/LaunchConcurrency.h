#pragma once
#include "Framework_ConcurrentQue.h"
#include "LaunchConcurrency_Control.h"
#include "Global_ConcurrentQue.h"

namespace ConcurrentQue
{
    class LaunchConcurrency
    {
    public:
        LaunchConcurrency();
        virtual ~LaunchConcurrency();

        void Thread_Start(unsigned char concurrent_CoreId);
        void Initialise_Control(
            class Global_ConcurrentQue* ptr_Global,
            unsigned char ptr_MyNumImplementedCores
        );
        void Thread_End(unsigned char concurrent_CoreId);

        class LaunchConcurrency_Control* Get_Control_Of_LaunchConcurrency();
        class Global_ConcurrentQue* Get_GlobalForLaunchConcurrency();

    protected:

    private:
        static class Global_ConcurrentQue* ptr_Global;
        static class LaunchConcurrency_Control* ptr_LaunchConcurrency_Control;
    };
}