#include <iostream>
using namespace std;

//#include "/home/fbh/CProject/cplusplusPractice/cpplog/utility/Logger.h"
#include "utility/Logger.h"
using namespace yazi::utility;

int main()
{
    Logger::instance()->open("./test.log");
    Logger::instance()->log(Logger::DEBUG,__FILE__,__LINE__,"hello world");
    cout<<"uiuiui"<<endl;

   return 0 ;
}
