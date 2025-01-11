#pragma once
#include <array>

namespace ConcurrentQue
{
    class Global_ConcurrentQue
    {
    public:
        Global_ConcurrentQue();
        ~Global_ConcurrentQue();
        bool GetConst_Core_IDLE();
        bool GetConst_Core_ACTIVE();
        unsigned char Get_NumCores();

    protected:

    private:
        static bool flag_core_IDLE;
        static bool flag_core_ACTIVE;
        static unsigned char number_Implemented_Cores;
    };
}
