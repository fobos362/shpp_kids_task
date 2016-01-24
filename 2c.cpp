#include <iostream>

using namespace std;

class Rect{
    public:
        static void drawRect (int size){
            for (int i=0; i<size; i++){
                    cout<<"\n";
                for (int j=0;j<size;j++){
                    cout<<"*";
                }
            }
        }

    static int askValue(char text[]){
    cout<<text;
        int num;
        cin>>num;
        return num;
    }

};


int main()
{
  Rect::drawRect(Rect::askValue("Enter size, plese:"));
}
