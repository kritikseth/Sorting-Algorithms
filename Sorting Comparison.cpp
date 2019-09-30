//
//  Sorting Comparison.cpp
//  Sorting C++
//
//  Created by Kritik Seth on 26/09/19.
//  Copyright © 2019 Kritik Seth. All rights reserved.
//
#include "Sorting Comparison.hpp"
#include<iostream>
#include<ctime>

using namespace std;

int merge_steps = 0, quick_steps = 0;

class Sort
{
private:
    int size;
    int * selectarray;
    int * insertarray;
    int * mergearray;
    int * shellarray;
    int * quickarray;
public:
    Sort(int size)
    {
        this->size = size;
        selectarray = new int[this->size];
        insertarray = new int[this->size];
        mergearray = new int[this->size];
        shellarray = new int[this->size];
        quickarray = new int[this->size];
    }
    void makeArrays()
    {
        srand(time(NULL));
        int rnum, i;
        for(i=0;i<size;i++)
        {
            rnum = rand() % 1000 + 1;
            selectarray[i] = rnum;
            insertarray[i] = rnum;
            mergearray[i] = rnum;
            shellarray[i] = rnum;
            quickarray[i] = rnum;
        }
    }
    void swap(int *x, int *y)
    {
        *x = *x + *y;
        *y = *x - *y;
        *x = *x - *y;
    }
    int usingSelection()
    {
        int i, j, min, steps = 0;
        for (i=0;i<size-1;i++)
        {
            min = i;
            for (j=i+1;j<size;j++)
            {
                if (selectarray[j]<selectarray[min])
                    min = j;
                steps++;
            }
            swap(&selectarray[min], &selectarray[i]);
        }
        return steps;
    }
    int usingInsertion()
    {
        int i, store, j, steps = 0;
        for (i=1;i<size;i++)
        {
            store = insertarray[i];
            j = i - 1;
            while (j>=0 && insertarray[j]>store)
            {
                insertarray[j+1] = insertarray[j];
                j = j - 1;
                steps++;
            }
            insertarray[j+1] = store;
        }
        return steps;
    }
    void merge(int l, int m, int h)
    {
        int i = l, j = m + 1, k = l, a;
        int tarray[size];
        for(a=l;a<=h;a++)
        {
            if(i>m)
                tarray[k++] = mergearray[j++];
            else if(j>h)
                tarray[k++] = mergearray[i++];
            else if(mergearray[i] < mergearray[j])
                tarray[k++] = mergearray[i++];
            else
                tarray[k++] = mergearray[j++];
            merge_steps++;
        }
        for(a=l;a<=h;a++)
            mergearray[a] = tarray[a];
    }
    void usingMerge(int l, int h)
    {
        int mid;
        if(l<h)
        {
            mid = (l + h) / 2;
            usingMerge(l,mid);
            usingMerge(mid+1,h);
            merge(l,mid,h);
        }
    }
    int usingShell()
    {
        int i, j, interval = 1, store, steps = 0;
        while(interval < (size))
            interval = interval * 3 + 1;
        while(interval>0)
        {
            for(i=interval;i<size;i++)
            {
                store = shellarray[i];
                j = i - interval;
                while(j>=0 && shellarray[j]>store)
                {
                    shellarray[j + interval] = shellarray[j];
                    j = j - interval;
                    steps++;
                }
                shellarray[j + interval] = store;
            }
            interval = (interval - 1) / 3;
        }
        return steps;
    }
    int Partition(int low, int high)
    {
        int i = low, j = high + 1, temp;
        while(1)
        {1
            while(quickarray[++i]<quickarray[low])
            {
                if(i==high)
                    break;
            }
            while(quickarray[--j]>quickarray[low])
            {
                if(j==low)
                    break;
            }
            if(i>=j)
                break;
            temp = quickarray[i];
            quickarray[i] = quickarray[j];
            quickarray[j] = temp;
            quick_steps++;
        }
        temp = quickarray[low];
        quickarray[low] = quickarray[j];
        quickarray[j] = temp;
        quick_steps++;
        return j;
    }
    
    void usingQuick(int low, int high)
    {
        if(low>=high)
            return;
        int i = Partition(low, high);
        usingQuick(low, i-1);
        usingQuick(i+1, high);
    }

};

int main()
{
    int size, i;
    unsigned long int insertion_steps = 0, selection_steps = 0, shell_steps = 0, count;
    double insertion_time = 0.0, selection_time = 0.0, shell_time = 0.0, merge_time = 0.0, quick_time = 0.0;
    clock_t start, end;
    cout << "What is the size of array: ";
    cin >> size;
    cout << "How many times do you want to sort: ";
    cin >> count;
    Sort sort(size);
    for(i=0;i<count;i++)
    {
        sort.makeArrays();
        start = clock();
        selection_steps += sort.usingSelection();
        end = clock();
        selection_time += double(end - start);
        start = clock();
        insertion_steps += sort.usingInsertion();
        end = clock();
        insertion_time += double(end - start);
        start = clock();
        sort.usingMerge(0,size-1);
        end = clock();
        merge_time += double(end - start);
        start = clock();
        shell_steps += sort.usingShell();
        end = clock();
        shell_time += double(end - start);
        start = clock();
        sort.usingQuick(0,size-1);
        end = clock();
        quick_time += double(end - start);
    }
    cout << endl << "Selection Sort: " << endl;
    cout << "\t\t Time taken: " << selection_time << endl << "\t\t Average steps: " << selection_steps/count << endl;
    cout << endl << "Insertion Sort: " << endl;
    cout << "\t\t Time taken: " << insertion_time << endl << "\t\t Average steps: " << insertion_steps/count << endl;
    cout << endl << "Merge Sort: " << endl;
    cout << "\t\t Time taken: " << merge_time << endl << "\t\t Average steps: " << merge_steps/count << endl;
    cout << endl << "Shell Sort: " << endl;
    cout << "\t\t Time taken: " << shell_time << endl << "\t\t Average steps: " << shell_steps/count << endl;
    cout << endl << "Quick Sort: " << endl;
    cout << "\t\t Time taken: " << quick_time << endl << "\t\t Average steps: " << quick_steps/count << endl;
    makeTable(selection_time,insertion_time,merge_time,shell_time,quick_time);
    cout << endl << "Regards," << endl << "Kritik Seth\nJ043\n\n";
    sort.~Sort();
}
//KRITIK SETH
//J043

