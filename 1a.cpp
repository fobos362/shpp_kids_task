#include <iostream>
using namespace std;

class Calculator
{
public:
    void setVariables()
    {
        cout<<"vvedi 1e chislo:";
        cin>>a;
        cout<<"vvedi 2e chislo:";
        cin>>b;
    }

    int getSum()
    {
        cout<<"summa = "<<a+b;
        return a+b;
    }

private:
    int a,b;
};

int main()
{
    Calculator calculator;
    calculator.setVariables();
    calculator.getSum();

    return 0;
}
