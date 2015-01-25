//Samuel Spry
//swspry@gmail.com
//ss049913@ohio.edu
//
//Checks if a solution to the n-queen problem is valid
//using loops


#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
const int TIMES = 1;

int main()
{
    bool test = true;
    int i;
    int j;
    int board[100][100];
    chrono::system_clock::time_point t0 = chrono::system_clock::now();
    for(int times = 0; times < TIMES; ++times)
    {
        for(int y = 0; y < 100; ++y)
        {
            for(int x = 0; x< 100; ++x)
                cin >> board[x][y];
        }
        test = true;
        for(int y = 0; y < 100 && test; ++y)
        {
            for(int x = 0; x < 100 && test; ++x)
            {
                if(board[x][y]==1)
                {
                    //check column
                    for(int i = y+1; i < 100 && test; ++i)
                    {
                        if(board[x][i] == 1)
                        {
                            cout << "No\n";
                            test = false;
                        }
                    }
                    for(int i= y-1; i>0 && test; --i)
                    {
                        if(board[x][i] == 1)
                        {
                            cout << "No\n";
                            test = false;
                        }
                    }

                    //check row
                    for(int i = x+1; i < 100 && test; ++i)
                    {
                        if(board[i][y] == 1)
                        {
                            cout << "No\n";
                            test = false;
                        }
                    }
                    for(int i = x-1; i > 0 && test; --i)
                    {
                        if(board[i][y] == 1)
                        {
                            cout << "No\n";
                            test = false;
                        }
                    }
                    //check left-right diag
                    i = x+1;
                    j = y-1;
                    while(i > 0 && i < 100 && j > 0 && j < 100 && test)
                    {
                        if(board[i][j] == 1)
                        {
                            cout << "No\n";
                            test = false;
                        }
                        ++i;
                        --j;
                    }
                    i = x-1;
                    j = y+1;
                    while(i > 0 && i < 100 && j > 0 && j < 100 && test)
                    {
                        if(board[i][j] == 1)
                        {
                            cout << "No\n";
                            test = false;
                        }
                        --i;
                        ++j;
                    }
                    //check right-left diag
                    i = x+1;
                    j = y+1;
                    while(i > 0 && i < 100 && j > 0 && j < 100 && test)
                    {
                        if(board[i][j] == 1)
                        {
                            cout << "No\n";
                            test = false;
                        }
                        ++i;
                        ++j;
                    }
                    i = x-1;
                    j = y-1;
                    while(i > 0 && i < 100 && j > 0 && j < 100 && test)
                    {
                        if(board[i][j] == 1)
                        {
                            cout << "No\n";
                            test = false;
                        }
                        --i;
                        --j;
                    }
                }
            }
        }

    if(test)
        cout << "Yes\n";
    }
    chrono::system_clock::time_point t1 = chrono::system_clock::now();
    chrono::microseconds ms = chrono::duration_cast<chrono::microseconds>(t1 - t0);
    cout << ms.count() << "ms\n";

}
