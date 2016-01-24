#include <iostream>

using namespace std;

class Zarplata
{
    static const int BIG_MONEY = 1000000;
    static const int SMALL_MONEY = 1000;

public:
    Zarplata()
    {
        zarplata = 0;
    };

    void setZarplata()
    {
        cout<<"kakaya u tebya zarplata?";
        cin>>zarplata;
    }

    void getResult()
    {
        if (zarplata > BIG_MONEY)
            cout<<"ti millioner!";
        else if (zarplata<SMALL_MONEY)
            cout<<"ti beden!";
        else cout<<"ti norm))";
    }

private:
    int zarplata;
};

int main()
{
    Zarplata zarplata;
    zarplata.setZarplata();
    zarplata.getResult();
    return 0;
}
