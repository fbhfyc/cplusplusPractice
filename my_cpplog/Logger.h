#include <string>
#include <fstream>
using namespace std;

 namespace yazi {

class Logger {
	public:
	  static Logger* get_instance();

	public:
	  void log(string level,const char* filename, int line,const char* format, ...);

	public:
	  int open(const string & filename);
	  int close();
	  int set_max(int bytes);

	private:
	  Logger();
	  ~Logger();

	  int rotate();

	private:
	  string   m_filename;
	  ofstream m_ofs;
	  int      m_max;
	  int      m_len;

	private:
	  static Logger* m_instance;
};


}
