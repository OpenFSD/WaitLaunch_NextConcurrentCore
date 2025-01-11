#include "Global_ConcurrentQue.h"
#include <cstddef>

namespace ConcurrentQue
{
    bool Global_ConcurrentQue::flag_core_ACTIVE = NULL;
    bool Global_ConcurrentQue::flag_core_IDLE = NULL;
    unsigned char Global_ConcurrentQue::number_Implemented_Cores = NULL;

    Global_ConcurrentQue::Global_ConcurrentQue()
    {
        flag_core_ACTIVE = new bool(true);
        flag_core_IDLE = new bool(false);

        number_Implemented_Cores = unsigned char(4);//NUMBER OF CORES
    }

    Global_ConcurrentQue::~Global_ConcurrentQue()
    {

    }

    bool Global_ConcurrentQue::GetConst_Core_ACTIVE()
    {
        return flag_core_ACTIVE;
    }
    bool Global_ConcurrentQue::GetConst_Core_IDLE()
    {
        return flag_core_IDLE;
    }
    unsigned char Global_ConcurrentQue::Get_NumCores()
    {
        return number_Implemented_Cores;
    }
}