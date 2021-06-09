#include <iostream>
#include <string>
#include <exception>

using namespace std;

class InvalidConfigurationException:public exception{
    protected:
        int motive, val;
    public:
        InvalidConfigurationException(): motive(0) {};
        InvalidConfigurationException(int m, int v) : motive(m), val(v) {};
        virtual const char* what() const throw(){
            // string str1, str2, str3;
            switch (motive)
            {
            case 1:
                return "Invalid tiles value";
                break;
            
            case 2:
                return "Invalid snakes value";
                break;

            case 3:
                return "Invalid ladders value";
                break;
            
            case 4:
                return "Invalid turns value";
                break;
            
            case 5:
                return "Invalid penalty value";
                break;
            
            case 6:
                return "Invalid reward value";
                break;
            
            default:
                break;
            }
        }
        
}; //myException;