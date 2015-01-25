//Samuel Spry
//ss049913@ohio.edu
//swspry@gmail.com
//
//CS 3610 Project #1
//8 queens
//Uses addition of coordinates of a queen to find
//solutions to the n-queen problem
//
//  1 2 3 4 5
//1 2 3 4 5 6
//2 3 4 5 6 7
//3 4 5 6 7 8
//4 5 6 7 8 9
//5 6 7 8 9 10
//
//Every diagonal has the same sum of its x & y coordinates


#include <iostream>
#include <unordered_set>
#include <cstdlib>
#include <chrono>

using namespace std;

const unsigned int NUMBER_QUEENS = 8;
const unsigned int ROWS = 100;
const unsigned int COLS = 100;

int main()
{
    unordered_set<int> x;
    unordered_set<int> y;
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    int temp;
    int TIMES;
    chrono::system_clock::time_point start_t= chrono::system_clock::now();

    cin >> TIMES;
    for(int times = 0; times < TIMES; ++times)
    {
        for(int i = 0; i < ROWS; ++i)
        {
            for(int j = 0; j < COLS; ++j)
            {
                cin >> temp;
                if(temp == 1)
                {
                    x.insert(j);
                    y.insert(i);
                    diag1.insert(j+i);
                    diag2.insert(abs(j-9)+i);
                }
            }
        }

        if(x.size() < NUMBER_QUEENS || y.size() < NUMBER_QUEENS)
            cout << "No\n";
        else if(diag1.size() < NUMBER_QUEENS || diag2.size() < NUMBER_QUEENS)
            cout << "No\n";
        else
            cout << "Yes\n";

        x.clear();
        y.clear();
        diag1.clear();
        diag2.clear();
    }

    chrono::system_clock::time_point end_t = chrono::system_clock::now();
    chrono::microseconds ms = chrono::duration_cast<chrono::microseconds>(end_t - start_t);
    cout << ms.count() << " microseconds" << endl;
}
