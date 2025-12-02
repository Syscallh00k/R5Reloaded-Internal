#ifndef sdk_h
#define sdk_h

#include "../Utils/utils.h"

#include "CodeCallBack/CodeCallBack.h"
#include "Surface/surface.h"

namespace Legend {
	namespace SDK {
		uintptr_t local_player;

		std::mutex listMTX;
		std::vector<uintptr_t> player_list;
	}
}
#endif