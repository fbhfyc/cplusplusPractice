#include "Logger.h"
using namespace yazi::utility;

#include <time.h>
#include <iostream>
#include <stdarg.h>

const char* Logger::s_level[] ={
                "DEBUG",
                "INFO",
                "WARN",
                "ERROR",
                "FATAL"
};

Logger::Logger():m_max(0),m_len(0)
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

    const char* fmt = "%s %s %s:%d ";
    int size = snprintf(NULL, 0, fmt, s_level[level], timestamp, __FILE__, __LINE__);
    if (size > 0) {
	    char* buf = new char[size +1];
	    snprintf(buf, size+1, fmt, s_level[level], timestamp, __FILE__, __LINE__);
	    buf[size] = '\0';
	    m_len += size;
	    m_fout << buf;
	    delete(buf);
    }

    va_list arg_ptr;
    va_start(arg_ptr, format);
    size = vsnprintf(NULL, 0, format, arg_ptr);
    va_end(arg_ptr);
    if ( size>0 ) {
	    char* content =new char[size+1];
            va_start(arg_ptr, format);
    	    vsnprintf(content, size + 1, format, arg_ptr);
      	    va_end(arg_ptr);
	    m_len += size;
	    m_fout << content;
	    delete content;
    }

    m_fout << "\n";
    m_fout.flush();

    if (m_len >= m_max && m_max > 0) {
	rotate();
    }
}

void Logger::rotate()
{
	close();
	time_t ticks = time(NULL);
	struct tm* ptm = localtime(&ticks);
	char timestamp[32] = {0};
	strftime(timestamp,sizeof(timestamp), ".%Y-%m-%d_%H-%M-%s", ptm);

	string filename = m_filename + timestamp;
	if (rename(m_filename.c_str(), filename.c_str()) != 0) {
		return;
	}	


	open(m_filename);

}


