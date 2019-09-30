//
//  Sorting Comparison.hpp
//  Sorting C++
//
//  Created by Kritik Seth on 26/09/19.
//  Copyright © 2019 Kritik Seth. All rights reserved.
//
#ifndef Sorting_Comparison_hpp
#define Sorting_Comparison_hpp

#include <iostream>
#include <iomanip>

using namespace std;

void makeTable(double stime, double itime, double mtime, double shell_time, double qtime)
{
    double table[5][5], time[5];
    int i, j;
    cout << endl << endl << endl;
    cout << "\t\t\t\tSelection\t\tInsertion\t\t\t  Merge  \t\t\t  Shell  \t\t\t  Quick  \t\t" << endl;
    cout << "\t\t\t\t  Sort  \t\t  Sort  \t\t\t   Sort  \t\t\t   Sort  \t\t\t   Sort\t\t";
    cout << endl << endl;
    time[0] = stime;
    time[1] = itime;
    time[2] = mtime;
    time[3] = shell_time;
    time[4] = qtime;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            table[i][j] = (time[i] - time[j]) / time[i];
    }
    cout << "Selection\n   Sort\t\t\t ";
    for(i=0;i<5;i++)
    {
        cout << fixed << setprecision(4) << table[0][i] << "\t\t\t  ";
    }
    cout << endl << endl;
    cout << "Insertion\n   Sort\t\t\t";
    for(i=0;i<5;i++)
    {
        cout << fixed << setprecision(4) <<table[1][i] << "\t\t\t  ";
    }
    cout << endl << endl;
    cout << "  Merge\n   Sort\t\t\t";
    for(i=0;i<5;i++)
    {
        cout << fixed << setprecision(4) << table[2][i] << "\t\t\t  ";
    }
    cout << endl << endl;
    cout << "  Shell\n   Sort\t\t\t";
    for(i=0;i<5;i++)
    {
        cout << fixed << setprecision(4) << table[3][i] << "\t\t\t  ";
    }
    cout << endl << endl;
    cout << "  Quick\n   Sort\t\t   ";
    for(i=0;i<5;i++)
    {
        cout << fixed << setprecision(4) <<table[4][i] << "\t\t\t  ";
    }
    cout << endl << endl << endl;
}

#endif /* Sorting_Comparison_hpp */
