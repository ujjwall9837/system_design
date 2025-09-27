#include<iostream>
#include "logger.hpp"

using namespace std;
int Logger::count = 0;
Logger* Logger::logger = nullptr;
std::mutex Logger::mtx;

Logger::Logger()
{
    count++ ;
    cout << "Logger created numer of instance " << count <<  endl;
}

void Logger:: Log(string msg) 
{
    cout << msg << endl;
}

Logger * Logger::getLogger()
{
    mtx.lock();
    if(count < 1)
    {
        logger = new Logger();
        mtx.unlock();
        return logger;
    }
    else
    {
        cout << "Instance already created" << endl;
        mtx.unlock();
        return nullptr;
    }
}