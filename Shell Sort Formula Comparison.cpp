//
//  Shell Sort Formula Comparison.cpp
//  Sorting C++
//
//  Created by Kritik Seth on 23/09/19.
//  Copyright © 2019 Kritik Seth. All rights reserved.
//
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

class ShellSort
{
private:
    int * knutharray;
    int * hibbardarray;
    int * tokudaarray;
    int * dividearray;
    int * mergearray;
    int size;
public:
    ShellSort(int size)
    {
        this->size = size;
        knutharray = new int[this->size];
        hibbardarray = new int[this->size];
        tokudaarray = new int[this->size];
        dividearray = new int[this->size];
    }
    void makeArrays()
    {
        srand(time(NULL));
        int rnum, i;
        for(i=0;i<size;i++)
        {
            rnum = rand();
            knutharray[i] = rnum;
            hibbardarray[i] = rnum;
            tokudaarray[i] = rnum;
            dividearray[i] = rnum;
        }
    }
    int usingKnuth()
    {
        int i, j, value, h = 1, k, steps = 0;
        for(k=0;h<size;k++)
            h = (pow(3,k) - 1) / 2; //Knuth's Increment (alternate: h = 3 * h + 1)
        k -= 2;
        for(;k>0;k--)
        {
            h = (pow(3,k) - 1) / 2;
            for(i=h;i<size;i++)
            {
                value = knutharray[i];
                j = i - h;
                while(j >= 0 && value < knutharray[j]) //Ascending
                {
                    knutharray[j+h] = knutharray[j];
                    j -= h;
                    steps++;
                }
                knutharray[j+h] = value;
            }
        }
        return steps;
    }
    int usingHibbard()
    {
        int i, j, value, h = 1, k, steps = 0;
        for(k=0;h<size;k++)
            h = pow(2,k) - 1; //Hibbard's Increment
        k -= 2;
        for(;k>0;k--)
        {
            h = pow(2,k) - 1;
            for(i=h;i<size;i++)
            {
                value = hibbardarray[i];
                j = i - h;
                while(j >= 0 && value < hibbardarray[j]) //Ascending
                {
                    hibbardarray[j+h] = hibbardarray[j];
                    j -= h;
                    steps++;
                }
                hibbardarray[j+h] = value;
            }
        }
        return steps;
    }
    int usingTokuda()
    {
        int i, j, value, h = 1, k, steps = 0;
        for(k=0;h<size;k++)
            h = (9 * pow((9/4), k) - 4) / 5; //Tokuda's Increment
        k -= 2;
        for(;k>=0;k--)
        {
            h = (9 * pow((9/4), k) - 4) / 5;
            for(i=h;i<size;i++)
            {
                value = tokudaarray[i];
                j = i - h;
                while(j >= 0 && value < tokudaarray[j]) //Ascending
                {
                    tokudaarray[j+h] = tokudaarray[j];
                    j -= h;
                    steps++;
                }
                tokudaarray[j+h] = value;
            }
        }
        return steps;
    }
    int usingDivide()
    {
        int i, j, value, h = size / 2, steps = 0;
        for(;h>0;h/=2) //Divide by 2 Technique
        {
            for(i=h;i<size;i++)
            {
                value = dividearray[i];
                j = i - h;
                while(j >= 0 && value < dividearray[j]) //Ascending
                {
                    dividearray[j+h] = dividearray[j];
                    j -= h;
                    steps++;
                }
                dividearray[j+h] = value;
            }
        }
        return steps;
    }
};

int main()
{
    int size, i, count;
    unsigned long int knuth_steps = 0, hibbard_steps = 0, tokuda_steps = 0, divide_steps = 0;
    double knuth_time = 0.0, hibbard_time = 0.0, tokuda_time = 0.0, divide_time = 0.0, ratio;
    clock_t start, end;
    cout << "What is the size of array: ";
    cin >> size;
    cout << "How many times do you want to sort: ";
    cin >> count;
    ShellSort shellsort(size);
    for(i=0;i<count;i++)
    {
        shellsort.makeArrays();
        start = clock();
        knuth_steps += shellsort.usingKnuth();
        end = clock();
        knuth_time += double(end - start);
        start = clock();
        hibbard_steps += shellsort.usingHibbard();
        end = clock();
        hibbard_time += double(end - start);
        start = clock();
        tokuda_steps += shellsort.usingTokuda();
        end = clock();
        tokuda_time += double(end - start);
        start = clock();
        divide_steps += shellsort.usingDivide();
        end = clock();
        divide_time += double(end - start);
    }
    cout << endl << "Shell sort using Knuth's Increment (3^k-1)/2: " << endl;
    cout << "\t\t\t Time taken: " << knuth_time << endl << "\t\t\t Average steps: " << knuth_steps/count << endl;
    cout << endl << "Shell sort using Hibbard's Increment 2^k-1: " << endl;
    cout << "\t\t\t Time taken: " << hibbard_time << endl << "\t\t\t Average steps: " << hibbard_steps/count << endl;
    cout << endl << "Shell sort using Tokuda's Increment (9(9/4)^k-4)/5: " << endl;
    cout << "\t\t\t Time taken: " << tokuda_time << endl << "\t\t\t Average steps: " << tokuda_steps/count << endl;
    cout << endl << "Shell sort using Divide Method size/2: " << endl;
    cout << "\t\t\t Time taken: " << divide_time << endl << "\t\t\t Average steps: " << divide_steps/count << endl << endl;
    cout << endl << "Regards," << endl << "Kritik Seth\nJ043\n\n";
    shellsort.~ShellSort();
}
//KRITIK SETH
//J043

