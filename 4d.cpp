#include <iostream>
#include <cstring>
#include <stdio.h>
#include <vector>

using namespace std;

class CharCounter
{
public:
    CharCounter()
    {
        mChar = '\0';
        mCounter = 0;
    }

    void setChar(char c)
    {
        mChar = c;
    }

    char getChar()
    {
        return mChar;
    }

    int getCounter()
    {
        return mCounter;
    }

    int incCounter()
    {
        mCounter++;
    }

private:
    char mChar;
    int mCounter;
};


class StringUtils
{

public:

    static bool isVectorContains(vector<CharCounter>& _vector, char& _char)
    {
        for (int i = 0; i<_vector.size(); i++)
        {
            CharCounter toVectorCounter = _vector.at(i);
            if (toVectorCounter.getChar()==_char)
                return true;
        }
        return false;
    }


    static void consideredChars(vector<CharCounter>& _vector, char _string[])
    {
        for (int i = 0; i<strlen(_string); i++)
        {
            char _char = toupper(_string[i]);
            CharCounter toVectorCounter;
            toVectorCounter.setChar(_char);
            if (!isVectorContains(_vector, _char))
                _vector.push_back(toVectorCounter);
        }

        for (int i = 0; i<strlen(_string); i++)
        {
            for (int j = 0; j<_vector.size(); j++)
            {
                CharCounter* charCounter = &_vector.at(j);
                if (charCounter->getChar()==toupper(_string[i]))
                {
                    charCounter->incCounter();
                }
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

    Data()
    {
        mString = new char[SIZE_OF_STRING];
        mVectorCharCounter = new vector<CharCounter>;
    }

    ~Data()
    {
        delete[] mString;
        delete mVectorCharCounter;
    }


    void setString()
    {
        gets(mString);
    }

    char* getString()
    {
        return mString;
    }

    vector <CharCounter>* getCharVector()
    {
        return mVectorCharCounter;
    }

    void show_vector()
    {
        for (int i = 0; i<mVectorCharCounter->size(); i++)
        {
            CharCounter charCounter = mVectorCharCounter->at(i);
            cout<<endl<<charCounter.getChar()<<" - "<<charCounter.getCounter();
        }
    }

private:
    char* mString;
    vector <CharCounter>* mVectorCharCounter;

};


int main()
{
    Data data;
    data.setString();
    StringUtils::consideredChars(*data.getCharVector(), data.getString());
    data.show_vector();
    return 0;
}
