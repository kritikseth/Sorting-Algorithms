#include <iostream>
#include <ctime>

using namespace std;

class InsertSort
{
private:
    int size;
    int * Array;
public:
    InsertSort(int size)
    {
        this->size = size;
        Array = new int[this->size];
    }
    void RandomArray() //Generates a random array
    {
        int i;
        for(i=0;i<size;i++)
            Array[i] = rand();
    }
    void UserArray() //Takes User input for array
    {
        int i;
        for(i=0;i<size;i++)
            cin >> Array[i];
    }
    void Sort() //Sorts the array using Insertion Sort
    {
        int i, j, store;
        for(i=1;i<size;i++)
        {
            j = i - 1;
            store = Array[i];
            for(;j>=0 && store<Array[j];j--)
                Array[j+1] = Array[j];
            Array[j+1] = store;
        }
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
    void PrintArray() //Prints the array (can be used for comparison between sorted and unsorted array)
    {
        int i;
        for(i=0;i<size;i++)
            cout << Array[i] << " ";
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    InsertSort i(size);
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
                i.UserArray();
            }
                break;
            case 'b':
            case 'B':
            {
                srand(time(NULL));
                i.RandomArray();
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
    i.Sort();
    if(i.isSorted())
        cout << "Sorting Completed Successfully using Insertion Sort!" << endl << endl;
    i.~InsertSort();
}
