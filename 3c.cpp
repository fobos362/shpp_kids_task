#include <iostream>

using namespace std;

class CentrovanayaHren{
public:
    CentrovanayaHren (){
    counter = 0;
    }

    int setStarPosition(){
        int position;
        cout<<"Enter position: ";
        cin>>position;

        if (position>0){
            positionsOfStars[counter] = position;
            counter++;
            return 0;
        }
        else return -1;
    }

    void vuvestiHren(){

        int maxValue = getMaxValue(positionsOfStars, counter);
        cout<<maxValue;
        for (int i = 0; i<counter; i++){
            cout<<endl;

            for (int j = 0; j < (maxValue - positionsOfStars[i])/2; j++)
                cout<<" ";

                for (int b = 0; b < positionsOfStars[i]; b++)
                    cout<<"*";
        }
    }


    int getMaxValue(int mass[], int sizeOfMass){
        int maxValue = 0;
            for (int i=0; i<sizeOfMass; i++)
                if (mass[i] > maxValue)
                    maxValue = mass[i];
        return maxValue;
    }

private:
    int positionsOfStars[1000];
    int counter;
};

int main()
{
    CentrovanayaHren centrovanayaHren;
    while (centrovanayaHren.setStarPosition()!= -1);
    centrovanayaHren.vuvestiHren();
    return 0;
}
