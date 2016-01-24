#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

class StringLength
{

public:
    static const int STRING_SIZE = 100;
    static const int BIGGEST_WORD_SIZE = 30;

    static void setBiggestWord(char first[], char second[], int wordSize, int wordBegin)
    {
        strncpy(first, second + wordBegin, wordSize);
        first[strlen(first)] = '\0';
    }

    static void showBiggestWord(char _string[])
    {
        cout<<endl<<_string<<endl<<"Size = "<< strlen(_string);
        delete[] _string;
    }

    static char* biggestWord(char _string[])
    {
        char *biggestWord = new char[BIGGEST_WORD_SIZE];
        int wordStart = 0;
        int wordEnd = 0;
        int wordSize = 0;

        deleteTokens(_string);
        for (int i = 0; i < strlen(_string); i++)
        {

            if (_string[i] == ' ' && (_string[i-1] != ' ' || _string[i+1] != ' '  ))
            {
                wordStart = wordEnd;
                wordEnd = i;
                if (wordSize < wordEnd - wordStart)
                {
                    if (wordStart!=0)
                        wordStart++;
                    wordSize = (wordEnd - wordStart);
                    setBiggestWord(biggestWord, _string, wordSize, wordStart);
                }
            }
        }
        if (strlen(_string) - wordEnd > wordSize)
        {
            setBiggestWord(biggestWord, _string, strlen(_string) - wordEnd, wordEnd+1);
        }
        delete[] _string;
        return biggestWord;
    }

    static char* getString()
    {
        char*_string = new char[STRING_SIZE];
        cout<<"Enter string: ";
        gets(_string);
        return _string;
    }
private:

    static void deleteTokens(char* _string)
    {
        for (int i = 0; i<strlen(_string); i++)
        {
            if (_string[i] < 65 || _string[i] >90 && _string[i]<97 || _string[i] > 122)
                _string[i] = ' ';
        }
    }
};


int main()
{
    StringLength::showBiggestWord(StringLength::biggestWord(StringLength::getString()));
    return 0;
}
