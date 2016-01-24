#include <iostream>

using namespace std;

class Card{

public:
    Card(){
        money = 0;
    }

    void setMoney(int money){
    this->money = money;
    }

    int getMoney(){
    return money;
    }

private:
    int money;
};

class Bancomat{
public:
    static const int SIZE_OF_CARDS = 10;

    void enterData(){
        int cardNumber;
        int money;

        cout<<endl;
        cout<<"vvedi nomer kartochki: ";
        cin>>cardNumber;
        cout<<"skolko polozhit? ";
        cin>>money;

        if (cardNumber<=SIZE_OF_CARDS && cardNumber>0)
            setMoneyToCard(cardNumber-1, money);
            else cout<<"Takoi kartu net v spiske.";

        printAllCards();
    }


private:
    Card cards[SIZE_OF_CARDS];

    void setMoneyToCard(int cardNumber, int money){
            cards[cardNumber].setMoney(money);
    }

    void printAllCards(){
        cout<<endl;
        for (int i=0; i<SIZE_OF_CARDS;i++){
            cout<<" "<<cards[i].getMoney()<<" ";
        }
    }
};

int main()
{
    Bancomat bancomat;
    while(true){
        bancomat.enterData();
    }
    return 0;
}
