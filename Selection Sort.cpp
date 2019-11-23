#include <iostream>
#include <ctime>

using namespace std;

class SelectSort
{
private:
    int size;
    int * Array;
public:
    SelectSort(int size)
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
    void Sort() //Sorts the array using Selection Sort
    {
        int i, j, min, temp;
        for(i=0;i<size-1;i++)
        {
            min = i;
            for(j=i+1;j<size;j++)
            {
                if(Array[j]<Array[min])
                    min = j;
            }
            temp = Array[min];
            Array[min] = Array[i];
            Array[i] = temp;
        }
    }
    bool isSorted() //Checks if the array is sorted
    {
        int i;
        for(i=0;i<size;i++)
        {
            if(Array[i]>Array[i+1])
                return true;
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
    SelectSort s(size);
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
                s.UserArray();
            }
                break;
            case 'b':
            case 'B':
            {
                srand(time(NULL));
                s.RandomArray();
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
    s.Sort();
    if(s.isSorted())
        cout << "Sorting Completed Successfully using Selection Sort!" << endl << endl;
    s.~SelectSort();
}
