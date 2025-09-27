#ifndef logger_h
#define logger_h

#include <string>
#include <mutex>

using namespace std;

class Logger
{
        static int count;
        static Logger* logger;
        static mutex mtx;
        Logger();
        Logger(const Logger &); 
public:
        static Logger* getLogger(); 
        void Log(string msg);
};


#endif