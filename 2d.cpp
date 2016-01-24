#include <iostream>

using namespace std;

class DrawStar{
public:
         static void drawRectWithDec (int size){
             int decSize = size;
            for (int i=0; i<size; i++){
                    cout<<"\n";
                for (int j=0;j<decSize;j++){
                    cout<<"*";
                }
                decSize--;
            }
        }


        static void drawRectWithInc (int size){
             int decSize = 1;
                for (int i=0; i<size; i++){
                    cout<<"\n";
                for (int j=0;j<decSize;j++){
                    cout<<"*";
                }
                decSize++;
            }
        }

         static void drawRectWithSp (int size){
             int decSize = size;
            for (int i=0; i<size; i++){
                    cout<<"\n";

                    for (int i = 0; i<size - decSize; i++)
                        cout<<" ";

                        for (int j=0;j<decSize;j++)
                            cout<<"*";

                decSize--;
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
    DrawStar::drawRectWithDec(DrawStar::askValue("\nenter:"));
    DrawStar::drawRectWithInc(DrawStar::askValue("\nenter:"));
    DrawStar::drawRectWithSp(DrawStar::askValue("\nenter:"));
    return 0;
}
