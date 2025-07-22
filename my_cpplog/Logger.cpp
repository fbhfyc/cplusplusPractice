#include "Logger.h" 
#include <stdexcept>
#include <stdarg.h>
#include <time.h>
#include <cerrno>   // 提供 errno
#include <cstring>  // 提供 strerror()

using namespace yazi;


          Logger* Logger::m_instance = nullptr;

          int Logger::open(const string & filename)
	  {
		  m_filename = filename;
		  m_ofs.open(filename, ios::app);
		  if (!m_ofs.is_open()) {
			  throw std::logic_error("open err" + filename + std::string(strerror(errno)));
		  }
		  return 0;
		  
	  }
          int Logger::close()
	  {
		  m_ofs.close();
		  return 0;
	  }		  
          int Logger::set_max(int bytes)
          {
		  m_max = bytes;
		  return 0;
          }

	  Logger::Logger():m_max(0),m_len(0)
          {
          }
          Logger::~Logger()
          {
          }

          char cur_time[32]={0};
          char buf[32];

	  void GetTime()
          {
             time_t t;
             struct tm *tmp;

             t = time(NULL);
             tmp = localtime(&t);
             if (tmp == NULL) {
                 perror("localtime");
                 exit(EXIT_FAILURE);
             }

             if (strftime(cur_time, sizeof(cur_time), "%Y.%m.%d-%H:%M:%S - ", tmp) == 0) {
               fprintf(stderr, "strftime returned 0");
               exit(EXIT_FAILURE);
             }

	     return;
	 }

          void Logger::log(string level,const char* filename, int line,const char* format, ...)
	  {
		  GetTime();
		  m_ofs << cur_time;

		  //const char* fmt = "%s:%d";
		  m_ofs << filename << ":" << line << "->";

		  va_list arg_ptr;
		  va_start(arg_ptr, format);
		  int size = vsnprintf(NULL, 0, format, arg_ptr);
	          va_end(arg_ptr);
                  if (size > 0) {
			  char* content = new char[size +1];
			  va_start(arg_ptr,format);
			  vsnprintf(content, size +1, format, arg_ptr);
			  va_end(arg_ptr);
			  m_ofs << content << "\n";
		  }

		  m_ofs.flush();
		  return;
	  }


          int Logger::rotate()
          {
		  return 0;
          }

           Logger* Logger::get_instance()
          {
		  if (m_instance == nullptr) {
			m_instance = new Logger(); 
		  }

		  return m_instance;
          }
