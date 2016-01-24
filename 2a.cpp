#include <iostream>
using namespace std;

class Zvezda
{
public:
    void setStars(int stars)
    {
        this->stars = stars;
    };

    int getHowManyStars()
    {
        return stars;
    }

private:
    int stars;
};



class StarUtils
{
public:

    static void showHowManyStars(Zvezda &z)
    {
        for (int i = 0; i<z.getHowManyStars(); i++)
            cout<<" * ";
    };

    static void askAboutStars(Zvezda &z)
    {
        int count;
        cout<<"vvedite colichestvo zvezd: ";
        cin>>count;
        z.setStars(count);
    };
};

int main()
{
    Zvezda* z = new Zvezda;
    StarUtils::askAboutStars(*z);
    StarUtils::showHowManyStars(*z);

    return 0;
}
