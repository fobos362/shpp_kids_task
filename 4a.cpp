#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

class StringLength
{

public:
    static int HowManyWord(char _string[])
    {
        int counter = 0;
        for (int i = 0; i < strlen(_string); i++)
        {
            if (_string[i] == ' ' && _string[i-1]!=' ')
                counter++;
        }
        return counter+1;
    }

    static char* getString()
    {
        char*_string = new char[100];
        cout<<"Enter string: ";
        gets(_string);
        return _string;
    }
};


int main()
{
    cout<<StringLength::HowManyWord(StringLength::getString());
    return 0;
}
