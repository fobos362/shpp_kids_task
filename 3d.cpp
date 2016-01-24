#include <iostream>

using namespace std;

class  OneColomn
{
public:
    static const int SIZE_OF_MASS = 100;

    OneColomn()
    {
        counter = 0;
        for (int i = 0; i<SIZE_OF_MASS; i++)
            mass[i]=1;
    }

    void setMass(int value)
    {
        for (int i = 0; i<value; i++)
        {
            mass[i] = 0;
        }
        counter = value;
    }

    int getValue(int index)
    {
        return mass[index];
    }

    int getMaxValue()
    {
        return counter;
    }


private:
    int mass[SIZE_OF_MASS];
    int counter;
};

class AllColomns
{
public:
    static const int SIZE_OF_MASS = 100;

    AllColomns()
    {
        globalCount = 0;
    }

    void drawColomn()
    {
        int maxValue = getMaxValue();
        for (int i = 0; i < maxValue; i++)
        {
            cout<<endl;
            for (int j = 0; j<globalCount; j++)
            {
                if (mass[j].getValue(i) == 0)
                    cout<<"*";
                else cout<<" ";
            }
        }
    }

    int getMaxValue()
    {
        int maxValue = 0;
        for (int i = 0; i<globalCount; i++)
        {
            if (mass[i].getMaxValue() > maxValue)
                maxValue = mass[i].getMaxValue();
        }
        return maxValue;
    }


    void askValues()
    {
        int value = 0;

        while (value != -1)
        {
            cout<<"Enter stars in colomn: ";
            cin>>value;
            mass[globalCount].setMass(value);
            globalCount++;
        }
    }


private:
    OneColomn mass[SIZE_OF_MASS];
    int globalCount;
};

int main()
{
    AllColomns colomns;
    colomns.askValues();
    colomns.drawColomn();
    return 0;
}
