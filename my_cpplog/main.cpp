#include "Logger.h"
using namespace yazi;

int main()
{

	Logger::get_instance()->open("./test.log");
	Logger::get_instance()->log("info", __FILE__,__LINE__, "hello %s","fbh");

	return 0;
}
