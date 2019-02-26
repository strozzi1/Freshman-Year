#include "musician.h"

class band {
	private:
		musician m;
	public:
		band();
		musician get_musician() const;
		void set_musician(const patron &);
};
