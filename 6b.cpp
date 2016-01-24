#include <iostream>

using namespace std;


class EndlessArray
{

public:
    EndlessArray()
    {
        mSizeOfArray = 0;
        mAllocatedMemory = 1;
        mArray = new int[1];
    }

    ~EndlessArray()
    {
        delete[] mArray;
    }

    void add(int value)
    {

        if (mAllocatedMemory == mSizeOfArray)
        {
            mAllocatedMemory*=2;
            createBiggestArray(mAllocatedMemory);
        }

        mArray[mSizeOfArray] = value;
        mSizeOfArray++;
    }

    void add(int value, int index)
    {
        if (index <= mSizeOfArray)
            mArray[index] = value;
        else cout<<endl<<"OutOfBounds! "<<"size = "<<mSizeOfArray<<" index = "<<index;
    }

    int get(int index)
    {
        if (index < mSizeOfArray)
            return mArray[index];
        else cout<<endl<<"OutOfBounds! "<<"size = "<<mSizeOfArray<<" index = "<<index;
    }

    void clearArray()
    {
        delete[] mArray;
        mArray = new int[1];
        mSizeOfArray = 0;
        mAllocatedMemory = 1;
    }

    void showArrayInfo()
    {
        cout<<endl;
        cout<<"Array contains:"<<endl;
        if (mSizeOfArray>0)
            for (int i = 0; i<mSizeOfArray; i++)
                cout<<"["<<mArray[i]<<"]"<<" ";

        cout<<endl<<"memory = "<<mAllocatedMemory<<" size = "<<mSizeOfArray;
    }

private:
    int mSizeOfArray;
    int mAllocatedMemory;
    int* mArray;

    void createBiggestArray(int _size)
    {
        int* biggestArray = new int[_size];

        for (int i = 0; i < mSizeOfArray; i++)
        {
            biggestArray[i] = mArray[i];
        }
        delete[] mArray;
        mArray = biggestArray;
    }

};

int main()
{
    EndlessArray* endlessArray = new EndlessArray;
    endlessArray->add(1);
    endlessArray->add(2);
    endlessArray->add(3);
    endlessArray->add(4);
    endlessArray->add(5);
    endlessArray->add(6);
    endlessArray->add(7);
    endlessArray->add(8);
    endlessArray->add(9);

    endlessArray->showArrayInfo();
    return 0;
}
