#include "Framework_ConcurrentQue.h"
#include <cstddef>

namespace ConcurrentQue
{
	class LaunchConcurrency* Framework_ConcurrentQue::ptr_LaunchConcurrency = NULL;

	Framework_ConcurrentQue::Framework_ConcurrentQue()
	{
		ptr_LaunchConcurrency = new class ConcurrentQue::LaunchConcurrency();
		while (ptr_LaunchConcurrency == NULL) { /* wait untill created */ }
		ptr_LaunchConcurrency->Initialise_Control(
			ConcurrentQue::Framework_ConcurrentQue::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency(),
			ConcurrentQue::Framework_ConcurrentQue::Get_LaunchConcurrency()->Get_GlobalForLaunchConcurrency()->Get_NumCores()
		);
	}

	Framework_ConcurrentQue::~Framework_ConcurrentQue()
	{

	}

	void Framework_ConcurrentQue::Thread_Start(unsigned char concurrent_CoreId)
	{
		ConcurrentQue::Framework_ConcurrentQue::Get_LaunchConcurrency()->Thread_Start(concurrent_CoreId);
	}

	void Framework_ConcurrentQue::Thread_End(unsigned char concurrent_CoreId)
	{
		ConcurrentQue::Framework_ConcurrentQue::Get_LaunchConcurrency()->Thread_End(concurrent_CoreId);
	}

	LaunchConcurrency* Framework_ConcurrentQue::Get_LaunchConcurrency()
	{
		return ptr_LaunchConcurrency;
	}

}