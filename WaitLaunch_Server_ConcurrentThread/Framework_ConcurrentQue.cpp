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

	LaunchConcurrency* Framework_ConcurrentQue::Get_LaunchConcurrency()
	{
		return ptr_LaunchConcurrency;
	}

}