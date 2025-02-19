#include "ConcurrentQue_Client_Framework.h"
#include <cstddef>

namespace ConcurrentQue
{
	class ConcurrentQue_Client_LaunchConcurrency* ConcurrentQue_Client_Framework::ptr_LaunchConcurrency = NULL;

	ConcurrentQue_Client_Framework::ConcurrentQue_Client_Framework()
	{
		
	}

	ConcurrentQue_Client_Framework::~ConcurrentQue_Client_Framework()
	{

	}

	void ConcurrentQue_Client_Framework::Request_Wait_Launch_ConcurrentThread(unsigned char concurrent_CoreId)
	{
		ConcurrentQue::ConcurrentQue_Client_Framework::Get_LaunchConcurrency()->Thread_Start(concurrent_CoreId);
	}
	void ConcurrentQue_Client_Framework::Concurrent_Thread_End(unsigned char concurrent_CoreId)
	{
		ConcurrentQue::ConcurrentQue_Client_Framework::Get_LaunchConcurrency()->Thread_End(concurrent_CoreId);
	}

	void ConcurrentQue_Client_Framework::Create_ConcurrentQue()
	{
		ptr_LaunchConcurrency = new class ConcurrentQue::ConcurrentQue_Client_LaunchConcurrency();
		while (ptr_LaunchConcurrency == NULL) { /* wait untill created */ }
		ptr_LaunchConcurrency->Initialise_Control(
			ConcurrentQue::ConcurrentQue_Client_Framework::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency(),
			ConcurrentQue::ConcurrentQue_Client_Framework::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->Get_NumCores()
		);
	}

	ConcurrentQue_Client_LaunchConcurrency* ConcurrentQue_Client_Framework::Get_LaunchConcurrency()
	{
		return ptr_LaunchConcurrency;
	}
	__int16 ConcurrentQue_Client_Framework::Get_coreId_To_Launch()
	{
		return ConcurrentQue::ConcurrentQue_Client_Framework::Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch();
	}

	bool ConcurrentQue_Client_Framework::Get_Flag_Active()
	{
		return ConcurrentQue::ConcurrentQue_Client_Framework::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->GetConst_Core_ACTIVE();
	}

	bool ConcurrentQue_Client_Framework::Get_Flag_Idle()
	{
		return ConcurrentQue::ConcurrentQue_Client_Framework::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->GetConst_Core_IDLE();
	}

	bool ConcurrentQue_Client_Framework::Get_State_LaunchBit()
	{
		return ConcurrentQue::ConcurrentQue_Client_Framework::Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_State_ConcurrentCore(0);
	}

}