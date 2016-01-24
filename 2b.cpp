#include <iostream>
using namespace std;

class PrintNumbers{
public:
    static void printTo(int to){
        for (int i = 1; i<to+1; i++){
        cout<<i;
            if (i!=to) cout<<", ";
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
    PrintNumbers::printTo(PrintNumbers::askValue("Enter value, please: "));
    return 0;
}
