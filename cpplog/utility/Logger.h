#pragma once

#include <string>
#include <fstream>
#include <iostream>
using namespace std;


namespace yazi {
namespace utility {
     
    class Logger
    {
        public:
             enum Level
             {
                DEBUG = 0,
                INFO,
                WARN,
                ERROR,
                FATAL,
                LEVEL_COUNT
             };

        public:
             static Logger* instance();
             void log(Level level, const char* file,int line, const char* format,...);

             void open(const string & filename);
             void close();


        private:
            Logger();
            ~Logger();
        
        private:
             string m_filename;
             ofstream m_fout;
             static const char* s_level[LEVEL_COUNT];

        private:
            static Logger* m_instance;

    };


}
}
