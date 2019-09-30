//
//  Shell Sort - Divide by 2.cpp
//  Sorting C++
//
//  Created by Kritik Seth on 23/09/19.
//  Copyright © 2019 Kritik Seth. All rights reserved.
//
#include <iostream>
#include <cmath>

using namespace std;

void ShellSort(int A[], int num)
{
    int i, j, value, h = num / 2;
    while(h>0)
    {
        for(i=h;i<num;i++)
        {
            value = A[i];
            j = i - h;
            while(j >= 0 && value < A[j]) //Ascending
            {
                A[j+h] = A[j];
                j -= h;
            }
            A[j+h] = value;
        }
        h /= 2; //Divide by 2 Technique
    }
}

int main()
{
    int num, i;
    cout << "Enter the number of elements in your array: ";
    cin >> num;
    int A[num];
    cout << "Enter the values of your array:\n";
    for(i=0;i<num;i++)
        cin >> A[i];
    ShellSort(A,num);
    cout << "\nSorting using Shell Sort - Divide by 2 Technique.\n\n";
    for(i=0;i<num;i++)
        cout << A[i] << "\t";
    cout << endl << endl;
}
//Regards
//Kritik Seth
//J043
