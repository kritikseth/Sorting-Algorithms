#include <iostream>
#include <ctime>

using namespace std;

class MergeSort
{
private:
    int size;
    int * Array;
public:
    MergeSort(int size)
    {
        this->size = size;
        Array = new int[this->size];
    }
    void Merge(int l, int m, int h)
    {
        int i = l, j = m + 1, k = l, a;
        int tarray[size];
        for(a=l;a<=h;a++)
        {
            if(i>m)
                tarray[k++] = Array[j++];
            else if(j>h)
                tarray[k++] = Array[i++];
            else if(Array[i] < Array[j])
                tarray[k++] = Array[i++];
            else
                tarray[k++] = Array[j++];
        }
        for(a=l;a<=h;a++)
            Array[a] = tarray[a];
    }
    void Sort(int l, int h)
    {
        int mid;
        if(l<h)
        {
            mid = (l + h) / 2;
            Sort(l,mid);
            Sort(mid+1,h);
            Merge(l,mid,h);
        }
    }
    void RandomArray()
    {
        int i;
        for(i=0;i<size;i++)
            Array[i] = rand();
    }
    void UserArray()
    {
        int i;
        cout << "Enter the elements of your array:\n";
        for(i=0;i<size;i++)
            cin >> Array[i];
        cout << endl;
    }
    bool isSorted() //Checks if the array is sorted
    {
        int i;
        for(i=0;i<size-1;i++)
        {
            if(Array[i]>Array[i+1])
                return false;
        }
        return true;
    }
    void PrintArray()
    {
        int i;
        cout << endl << endl;
        for(i=0;i<size;i++)
            cout << Array[i] << " ";
        cout << endl << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    MergeSort m(size);
    char choice;
    cout << "\nA)Enter array manually.\nB)Generate a random array\n\n";
    do
    {
        cin >> choice;
        switch(choice)
        {
            case 'a':
            case 'A':
            {
                m.UserArray();
            }
                break;
            case 'b':
            case 'B':
            {
                srand(time(NULL));
                m.RandomArray();
            }
                break;
            default:
            {
                cout << "\nInvalid choice, Please enter again!\n";
                cout << "\nA)Enter array manually.\nB)Generate a random array\n\n";
            }
                break;
        }
    }
    while(choice!='a' && choice!='A' && choice!='b' && choice!='B');
    m.Sort(0,size-1);
    if(m.isSorted())
        cout << endl << "Sorting Completed Successfully using Merge Sort (Recursive)!" << endl << endl;
    m.~MergeSort();
}
