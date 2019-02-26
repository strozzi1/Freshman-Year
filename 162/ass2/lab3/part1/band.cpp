#include "band.h"

band:: band() : m("cain"){


}

musician band::get_musician() const {
	return p;
}

void band::set_musician (const musician &m){
	this ->m=m;
}
