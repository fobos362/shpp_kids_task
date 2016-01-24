#include <iostream>
using namespace std;

class Elka
{

public:

    static int drawElka(int size)
    {
        int decSize = 0;
        int plusStar = -1;

        for (int i=0; i < size + 1; i++)
        {
            cout<<"\n";

            for (int c = 0; c < size - decSize; c++)
                cout<<" ";

            for (int j = decSize; j > 0; j--)
                cout<<"*";

            for (int b = 0; b < plusStar; b++)
                cout<<"*";

            decSize++;
            plusStar++;
        }

        return (decSize+plusStar) - 2;
    }

    static void drawPalka(int sizeofElka)
    {
        cout<<endl;
        for (int i = 0; i < sizeofElka/2; i++)
            cout<<" ";
        cout<<"*";
    }


    static int askValue(char text[])
    {
        cout<<text;
        int num;
        cin>>num;
        return num;
    }
};

int main()
{
    Elka::drawPalka(Elka::drawElka(Elka::askValue("Enter size of tree, please: ")));
    return 0;
}
