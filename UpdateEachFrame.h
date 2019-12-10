#ifndef UPDATEEACHFRAME_H
#define UPDATEEACHFRAME_H

namespace ge {
	class UpdateEachFrame
	{
		public:
			UpdateEachFrame();
			~UpdateEachFrame();
			virtual void Update(float delta) = 0;
	};
}

#endif

