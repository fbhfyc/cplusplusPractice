#pragma once

#include <string>
#include <fstream>
#include <iostream>
using namespace std;


namespace yazi {
namespace utility {
     
#define debug(format,...)\
	Logger::instance()->log(Logger:DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__);
#define info(format,...)\
	Logger::instance()->log(Logger:INFO, __FILE__, __LINE__, format, ##__VA_ARGS__);
#define error(format,...)\
	Logger::instance()->log(Logger:ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__);
#define warn(format,...)\
	Logger::instance()->log(Logger:WARN, __FILE__, __LINE__, format, ##__VA_ARGS__);
#define fatel(format,...)\
	Logger::instance()->log(Logger:FATEL, __FILE__, __LINE__, format, ##__VA_ARGS__);
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

	     void set_max(int bytes)
	     {
		     m_max = bytes;
	     }



        private:
            Logger();
            ~Logger();
	     void rotate();
        
        private:
             string   m_filename;
             ofstream m_fout;
	     int      m_max;
	     int      m_len;
             static const char* s_level[LEVEL_COUNT];

        private:
            static Logger* m_instance;

    };


}
}
