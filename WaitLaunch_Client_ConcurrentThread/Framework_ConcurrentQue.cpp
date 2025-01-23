#include "Framework_ConcurrentQue.h"
#include <cstddef>

namespace ConcurrentQue
{
	class LaunchConcurrency* Framework_ConcurrentQue::ptr_LaunchConcurrency = NULL;

	Framework_ConcurrentQue::Framework_ConcurrentQue()
	{
		
	}

	Framework_ConcurrentQue::~Framework_ConcurrentQue()
	{

	}

	void Framework_ConcurrentQue::Request_Wait_Launch_ConcurrentThread(unsigned char concurrent_CoreId)
	{
		ConcurrentQue::Framework_ConcurrentQue::Get_LaunchConcurrency()->Thread_Start(concurrent_CoreId);
	}
	void Framework_ConcurrentQue::ConcurrentThread_End(unsigned char concurrent_CoreId)
	{
		ConcurrentQue::Framework_ConcurrentQue::Get_LaunchConcurrency()->Thread_End(concurrent_CoreId);
	}

	void Framework_ConcurrentQue::Create_ConcurrentQue()
	{
		ptr_LaunchConcurrency = new class ConcurrentQue::LaunchConcurrency();
		while (ptr_LaunchConcurrency == NULL) { /* wait untill created */ }
		ptr_LaunchConcurrency->Initialise_Control(
			ConcurrentQue::Framework_ConcurrentQue::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency(),
			ConcurrentQue::Framework_ConcurrentQue::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->Get_NumCores()
		);
	}

	LaunchConcurrency* Framework_ConcurrentQue::Get_LaunchConcurrency()
	{
		return ptr_LaunchConcurrency;
	}
	__int16 Framework_ConcurrentQue::Get_coreId_To_Launch()
	{
		return ConcurrentQue::Framework_ConcurrentQue::Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_coreId_To_Launch();
	}

	bool Framework_ConcurrentQue::Get_Flag_Active()
	{
		return ConcurrentQue::Framework_ConcurrentQue::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->GetConst_Core_ACTIVE();
	}

	bool Framework_ConcurrentQue::Get_Flag_Idle()
	{
		return ConcurrentQue::Framework_ConcurrentQue::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->GetConst_Core_IDLE();
	}

	bool Framework_ConcurrentQue::Get_State_LaunchBit()
	{
		return ConcurrentQue::Framework_ConcurrentQue::Get_LaunchConcurrency()->Get_Control_Of_LaunchConcurrency()->Get_State_ConcurrentCore(0);
	}

}