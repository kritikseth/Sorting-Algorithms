#include <iostream>

using namespace std;

class QuickSort
{
private:
    int size;
    int * Array;
public:
    QuickSort(int size)
    {
        this->size = size;
        Array = new int[this->size];
    }
    void RandomArray()
    {
        int i;
        for(i=0;i<=size;i++)
            Array[i] = rand() % 100 + 1;
    }
    void UserArray()
    {
        int i;
        cout << "Enter the elements of your array:\n";
        for(i=0;i<size;i++)
            cin >> Array[i];
        cout << endl;
    }
    void Swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    int Partition(int low, int high)
    {
        int i = low, j = high + 1, temp;
        while(1)
        {
            while(Array[++i]<Array[low])
            {
                if(i==high)
                    break;
            }
            while(Array[--j]>Array[low])
            {
                if(j==low)
                    break;
            }
            if(i>=j)
                break;
            Swap(&Array[i],&Array[j]);
        }
        Swap(&Array[low],&Array[j]);
        return j;
    }
    void Sort(int low, int high)
    {
        if(low>=high)
            return;
        int i = Partition(low,high);
        Sort(low,i-1);
        Sort(i+1,high);
    }
    bool isSorted()
    {
        int i;
        for(i=0;i<size-1;i++)
        {
            if(Array[i]>Array[i+1])
                return false;
        }
        return true;
    }
    void PrintMyArray()
    {
        int i;
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
    QuickSort q(size);
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
                q.UserArray();
            }
                break;
            case 'b':
            case 'B':
            {
                srand(time(NULL));
                q.RandomArray();
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
    q.Sort(0,size-1);
    if(q.isSorted())
        cout << endl << "Sorting Completed Successfully using Quick Sort!" << endl << endl;
    q.PrintMyArray();
    q.~QuickSort();
}
