#include <iostream>

using namespace std;

class DoubleEndedQueue
{

public:
    DoubleEndedQueue(int sizeOfArray)
    {
        mArray = new int[sizeOfArray];
        mSizeOfArray = sizeOfArray;
        mContainsOfArray = 0;
        mLastValidIndex = 0;
    }

    ~DoubleEndedQueue()
    {
        delete[] mArray;
    }

    int addLast(int value)
    {
        if (mLastValidIndex<mSizeOfArray)
        {
            mArray[mLastValidIndex] = value;
            mLastValidIndex++;
            mContainsOfArray++;
            return mLastValidIndex;
        }
        else
        {
            cout<<endl<<"out of bounds!";
            return -1;
        }
    }

    int getLast()
    {
        mLastValidIndex--;
        mContainsOfArray--;
        return mArray[mLastValidIndex];
    }

    int addFirst(int value)
    {
        if (mLastValidIndex<mSizeOfArray)
        {
            for (int i = mLastValidIndex; i > -1; i--)
            {
                mArray[i+1] = mArray[i];
            }
            mArray[0] = value;
            mContainsOfArray++;
            mLastValidIndex++;
            return 0;
        }
        else
        {
            cout<<endl<<"out of bounds!";
            return -1;
        };
    }


    int getFirst()
    {
        int firstElement = mArray[0];
        for (int i = 0; i < mLastValidIndex; i++)
        {
            mArray[i] = mArray[i+1];
        }
        mContainsOfArray--;
        mLastValidIndex--;
        return firstElement;
    }


    void showArrayInfo()
    {
        cout<<endl;
        cout<<"Array contains:"<<endl;
        if (mSizeOfArray>0)
            for (int i = 0; i<mContainsOfArray; i++)
                cout<<"["<<mArray[i]<<"]"<<" ";
    }

private:
    int* mArray;
    int mSizeOfArray;
    int mLastValidIndex;
    int mContainsOfArray;
};

int main()
{
    DoubleEndedQueue* doubleEndedQueue = new DoubleEndedQueue(10);

    doubleEndedQueue->addLast(1);
    doubleEndedQueue->addLast(2);
    doubleEndedQueue->addLast(3);
    doubleEndedQueue->addLast(4);
    doubleEndedQueue->addLast(5);
    doubleEndedQueue->addLast(6);
    doubleEndedQueue->addLast(7);
    doubleEndedQueue->addFirst(0);
    doubleEndedQueue->addFirst(-1);

    doubleEndedQueue->showArrayInfo();
    return 0;
}
