#ifndef UPDATEEACHFRAME_H
#define UPDATEEACHFRAME_H

#include "Component.h"

namespace ge {
	class UpdateEachFrame : Component
	{
		public:
			virtual void update(float delta) = 0;
		protected:
			UpdateEachFrame() {};
			UpdateEachFrame(const UpdateEachFrame&) = delete;
			const UpdateEachFrame& operator=(const UpdateEachFrame&) = delete;
	};
}

#endif

