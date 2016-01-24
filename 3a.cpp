#include <iostream>
#include <stdio.h>

using namespace std;

class School
{

public:

    void setNumber (int number)
    {
        this->number = number;
    }

    int getNumber ()
    {
        return number;
    }

private:
    int number;
};

class SchoolUtils
{

public:
    static const int SIZE_OF_MASS = 10;

    void enterNubers(int sizeOfMass)
    {
        for (int i = 0; i < sizeOfMass; i++)
        {
            schools[i].setNumber(askValue(i+1));
        }
    }

    void askOurSchool()
    {
        cout<<endl<<"Enter number of your school: ";
        int ourSchoolNumber;
        cin>>ourSchoolNumber;
        ourSchool.setNumber(ourSchoolNumber);
    }

    bool isContainsSchool()
    {
        for (int i=0; i<SIZE_OF_MASS; i++)
        {
            if (schools[i].getNumber() == ourSchool.getNumber()) return true;
        }
        return false;
    }

    void getResult(bool isContains)
    {
        if (isContains) cout<<"I know your school!";
        else cout<<"Sorry, I don't know your school(";
    }


    int askValue(int number)
    {
        printf("Enter number of %d school: ", number);
        int num;
        cin>>num;
        return num;
    }
private:
    School schools[SIZE_OF_MASS];
    School ourSchool;
};



int main()
{
    SchoolUtils schoolUtils;
    schoolUtils.enterNubers(schoolUtils.SIZE_OF_MASS);
    schoolUtils.askOurSchool();
    schoolUtils.getResult(schoolUtils.isContainsSchool());
    return 0;
}
