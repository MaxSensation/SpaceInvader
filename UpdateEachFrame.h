#ifndef UPDATEEACHFRAME_H
#define UPDATEEACHFRAME_H

namespace ge {
	class UpdateEachFrame
	{
		public:
			UpdateEachFrame();
			~UpdateEachFrame();
			virtual void update(float delta) = 0;
	};
}

#endif

