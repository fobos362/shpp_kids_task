#include <iostream>
using namespace std;

class Calculator
{

public:
    Calculator()
    {
        a = b = 0;
    }

    void setVariables()
    {
        cout<<"Enter first value: ";
        cin>>a;
        cout<<"Enter second value:";
        cin>>b;
    }

    void printResult()
    {
        int r = getResult(askWhatToDo());
        cout<<"resultat = "<<r;
    }


private:
    int a,b;
    int getResult(int whatDo)
    {
        if (whatDo == 1)
            return a + b;
        else if (whatDo == 2)
            return a - b;
        else
        {
            if (b != 0)
                return a/b;
            else
            {
                cout<<"oh, ne deli na nol!\n";
                return 0;
            }
        }
    }

    int askWhatToDo()
    {
        int whatDo = 0;

        do
        {
            cout<<"wwedi 1 chtob naiti summu, 2 chtobi naiti raznicu, 3 dlya deleniya:";
            cin>>whatDo;
        }
        while
        (whatDo<1 || whatDo>3);

        return whatDo;
    }
};


int main()
{
    Calculator calculator;
    calculator.setVariables();
    calculator.printResult();
    return 0;
}
