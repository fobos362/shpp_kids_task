#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

class StringUtils
{
    static const int TO_UPPER_VALUE = 32;

public:

    static void toUpperCase(char _string[])
    {
        for (int i = 0; i<strlen(_string); i++)
        {
            if (_string[i]>95 && _string[i]<123)
            {
                _string[i]-=TO_UPPER_VALUE;
            }
        }
    }

    static void showString(char _string[])
    {
        puts(_string);
    }
};


class Data
{
    static const int SIZE_OF_STRING = 100;

public:
    void setString()
    {
        gets(mString);
    }

    char* getString()
    {
        return mString;
    }

private:
    char mString[SIZE_OF_STRING];
};

int main()
{
    Data data;
    data.setString();
    StringUtils::toUpperCase(data.getString());
    StringUtils::showString(data.getString());
    return 0;
}
