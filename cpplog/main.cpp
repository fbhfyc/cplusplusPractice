#include <iostream>
using namespace std;

//#include "/home/fbh/CProject/cplusplusPractice/cpplog/utility/Logger.h"
#include "utility/Logger.h"
using namespace yazi::utility;

int main()
{
    Logger::instance()->open("test.log");
    Logger::instance()->set_max(100);
    for(int i=0; i<100; ++i) {
    	Logger::instance()->log(Logger::DEBUG,__FILE__,__LINE__,"hello world","fbh");
    	Logger::instance()->log(Logger::DEBUG,__FILE__,__LINE__,"hello world : %s","fbh");
    }

   return 0 ;
}
