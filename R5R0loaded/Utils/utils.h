#ifndef Utils_H
#define Utils_H

#include <Windows.h>
#include <stdio.h>
#include <thread>
#include <string>
#include <shared_mutex>
#include <vector>

#include <MinHook.h>

#include "offsets.h"
#include "memory.h"

namespace Legend {
	namespace Utils {
		uintptr_t process;
		uintptr_t gamesdk;
	}
}

#endif