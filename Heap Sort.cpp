#include <iostream>
#include <ctime>

using namespace std;

class HeapSort
{
private:
    int size, N;
    int * heaptree;
public:
    HeapSort(int size)
    {
        N = 0;
        this->size = size;
        heaptree = new int [this->size];
        heaptree[0] = 0;
    }
    void RandomArray() //Generates a random array
    {
        int i;
        for(i=1;i<size;i++)
            heaptree[i] = rand();
    }
    void swap(int *x, int *y) //Swaps the numbers at given address
    {
        *x = *x + *y;
        *y = *x - *y;
        *x = *x - *y;
    }
    void swim(int index) //Swim Function for Heap Sort
    {
        while (index > 1 && heaptree[index/2] < heaptree[index])
        {
            swap(&heaptree[index/2],&heaptree[index]);
            index /= 2;
        }
    }
    void sink(int index) //Sink Function for Heap Sort
    {
        int i;
        while(index*2<=N)
        {
            i = index * 2;
            if(i<N && heaptree[i]<heaptree[i+1])
                i++;
            if(!(heaptree[index]<heaptree[i]))
                break;
            swap(&heaptree[index], &heaptree[i]);
            index = i;
        }
    }
    void Sort() //Heap Sort
    {
        for(N=1;N<size;N++)
            swim(N);
        while(N>1)
        {
            swap(&heaptree[1], &heaptree[N]);
            N--;
            sink(1);
        }
    }
    bool isSorted() //Checks if the array is sorted
    {
        int i;
        for(i=0;i<size-1;i++)
        {
            if(heaptree[i]>heaptree[i+1])
                return false;
        }
        return true;
    }
};

int main()
{
    int size;
    srand(time(NULL));
    cout << "Enter the size of array: ";
    cin >> size;
    HeapSort h(size+1);
    h.RandomArray();
    h.Sort();
    if(h.isSorted())
        cout << endl << "Sorting Completed Successfully using Heap Sort!" << endl << endl;
    h.~HeapSort();
}
