#include <iostream>

using namespace std;

class ListPage
{
public:

    ListPage(int value)
    {
        mValue = new int;
        *mValue = value;
        prevPage = NULL;
        nextPage = NULL;
    }

    ~ListPage()
    {
        delete mValue;
    }

    int* mValue;
    ListPage* prevPage;
    ListPage* nextPage;
};



class LinkedList
{

public:
    LinkedList()
    {
        mSizeOfList = 0;
        mFirstPage = NULL;
        mLastPage = NULL;
    }

    ~LinkedList()
    {
        clearList();
        delete mFirstPage;
    }


    void add(int value)
    {
        ListPage* listPage = new ListPage(value);

        if (mSizeOfList == 0)
        {
            listPage->prevPage = NULL;
            listPage->nextPage = NULL;
            mFirstPage = listPage;
            mLastPage = listPage;
            mSizeOfList++;
        }
        else
        {
            mLastPage->nextPage = listPage;
            listPage->prevPage = mLastPage;
            mLastPage = listPage;
            mSizeOfList++;
        }
    }


    int insertItem(int value, int index)
    {
        if (mFirstPage != NULL)
        {

            if (index==0)
            {
                ListPage* listPage = new ListPage(value);
                listPage->prevPage = mFirstPage;
                listPage->nextPage = mFirstPage->nextPage;
                mFirstPage->nextPage = listPage;
                ListPage* changeLink = listPage;
                mFirstPage = listPage;
                listPage = changeLink;
                mSizeOfList++;
                return 0;
            }

            else if (index == mSizeOfList)
            {
                add(value);
                return 0;
            }

            else if (index > mSizeOfList) return -1;
            int i = 0;

            ListPage* next = mFirstPage;
            while(next->nextPage != NULL)
            {
                ListPage* elem = next;
                if (i==index)
                {
                    ListPage* listPage = new ListPage(value);
                    ListPage* prev = elem->prevPage;

                    prev->nextPage = listPage;
                    elem->prevPage = listPage;

                    listPage->nextPage = elem;
                    listPage->prevPage = prev;
                    mSizeOfList++;
                    return 0;
                };

                next = elem->nextPage;
                i++;
            }
        }
        else add(value);
        return 0;
    }


    int removeItem(int index)
    {
        int i = 0;

        if (mFirstPage != NULL)
        {
            if (index==0)
            {
                ListPage* next = mFirstPage;
                mFirstPage = mFirstPage->nextPage;
                mFirstPage->prevPage = NULL;
                delete next;
                mSizeOfList--;
                return 0;
            }

            else if (index==mSizeOfList-1)
            {
                ListPage* prev = mLastPage;
                mLastPage = mLastPage->prevPage;
                mLastPage->nextPage = NULL;
                delete prev;
                mSizeOfList--;
                return 0;
            }

            ListPage* next = mFirstPage;
            while(next->nextPage != NULL)
            {
                ListPage* elem = next;
                if (i==index)
                {
                    ListPage* nextElem = elem->nextPage;
                    ListPage* prevElem = elem->prevPage;
                    nextElem->prevPage = prevElem;
                    prevElem->nextPage = nextElem;
                    delete elem;
                    mSizeOfList--;
                    return 0;
                };

                next = elem->nextPage;
                i++;
            }
        }
        cout<<"out of bouds!";
        return -1;
    }


    int get(int index)
    {
        int i = 0;

        if (mFirstPage != NULL)
        {
            ListPage* next = mFirstPage;
            while(next->nextPage != NULL)
            {
                ListPage* elem = next;
                int value = *elem->mValue;
                if (i==index) return value;
                next = elem->nextPage;
                i++;
            }
            int value = *next->mValue;

        }
        cout<<"out of bouds!";
        return -1;
    }


    int sizeOfList()
    {
        return mSizeOfList;
    }



    void clearList()
    {
        if (mFirstPage != NULL)
        {
            ListPage* next = mFirstPage;
            while(next->nextPage != NULL)
            {
                ListPage* elem = next;
                next = elem->nextPage;
                delete elem;
            }
            delete next;
            mFirstPage = NULL;
            mSizeOfList = 0;
        }
    }

    void toString()
    {
        if (mFirstPage != NULL)
        {
            ListPage* next = mFirstPage;
            while(next->nextPage != NULL)
            {
                ListPage* elem = next;
                int value = *elem->mValue;
                cout<<endl<<value;
                next = elem->nextPage;
            }
            int value = *next->mValue;
            cout<<endl<<value;
        }
    }

private:
    int mSizeOfList;
    ListPage* mFirstPage;
    ListPage* mLastPage;

};

int main()
{
    LinkedList linkedList;

    for (int i = 0; i<10; i++)
        linkedList.add(i);

    linkedList.insertItem(66, 4);
    linkedList.toString();
    return 0;
}
