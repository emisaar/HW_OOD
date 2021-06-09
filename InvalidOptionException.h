#include <iostream>
#include <string>
#include <exception>

using namespace std;

class InvalidOptionException:public exception{
    public:
        virtual const char* what() const throw(){
            return "Invalid menu choice exceeded";
        }
}myException;
