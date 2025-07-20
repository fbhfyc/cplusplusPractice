#include "Logger.h"
using namespace yazi::utility;

#include <time.h>
#include <iostream>

const char* Logger::s_level[] ={
                "DEBUG",
                "INFO",
                "WARN",
                "ERROR",
                "FATAL"
};

Logger::Logger()
{

}

Logger::~Logger()
{

}


Logger * Logger::m_instance = nullptr;


 Logger* Logger::instance()
{
    if ( m_instance == nullptr) {
        m_instance = new Logger();
    }
    return m_instance;
}

void Logger::open(const string & filename)
{
    m_fout.open(filename, ios::app);
    if (m_fout.fail()) {
        throw std::logic_error("open err");
    }
}

void Logger::close()
{
    m_fout.close();
}

void Logger::log(Level level, const char* file,int line, const char* format,...)
{
    if (m_fout.fail()) {
         throw std::logic_error("open err");
    }

    time_t ticks= time(NULL);

    struct tm * ptn = localtime(&ticks);
     
    char timestamp[32]={0};
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", ptn);
    std::cout << timestamp << std::endl;
    m_fout << timestamp << std::endl;
}


