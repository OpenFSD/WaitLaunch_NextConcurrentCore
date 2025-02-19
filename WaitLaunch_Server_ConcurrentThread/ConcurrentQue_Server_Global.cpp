#include "ConcurrentQue_Server_Global.h"
#include <cstddef>

namespace ConcurrentQue
{
    bool ConcurrentQue_Server_Global::flag_core_ACTIVE = NULL;
    bool ConcurrentQue_Server_Global::flag_core_IDLE = NULL;
    unsigned char ConcurrentQue_Server_Global::number_Implemented_Cores = NULL;

    ConcurrentQue_Server_Global::ConcurrentQue_Server_Global()
    {
        flag_core_ACTIVE = bool(true);
        flag_core_IDLE = bool(false);

        number_Implemented_Cores = unsigned char(4);//NUMBER OF CORES
    }

    ConcurrentQue_Server_Global::~ConcurrentQue_Server_Global()
    {

    }

    bool ConcurrentQue_Server_Global::GetConst_Core_ACTIVE()
    {
        return flag_core_ACTIVE;
    }
    bool ConcurrentQue_Server_Global::GetConst_Core_IDLE()
    {
        return flag_core_IDLE;
    }
    unsigned char ConcurrentQue_Server_Global::Get_NumCores()
    {
        return number_Implemented_Cores;
    }
}