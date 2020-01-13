#ifndef UPDATEEACHFRAME_H
#define UPDATEEACHFRAME_H

#include "Component.h"
#include "Scene.h"

namespace ge {
	class UpdateEachFrame : Component
	{
		public:
			virtual void update(float delta) = 0;
		protected:
			UpdateEachFrame() {
			};			
		private:
			const UpdateEachFrame& operator=(const UpdateEachFrame&) = delete;
			UpdateEachFrame(const UpdateEachFrame&) = delete;
	};
}

#endif

