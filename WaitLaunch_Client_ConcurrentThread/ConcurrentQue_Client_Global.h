#pragma once
#include <array>

namespace ConcurrentQue
{
    class ConcurrentQue_Client_Global
    {
    public:
        ConcurrentQue_Client_Global();
        ~ConcurrentQue_Client_Global();
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
