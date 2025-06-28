#include <bits/stdc++.h>
using namespace std;

int open[4][8]; //開關
char board[4][8]; //翻開棋
char qi[4][8]; //蓋起來的棋

 void print() // 輸出棋盤
 {
    cout << "  ";
    for(int j = 0;j<8;j++)
    {
        cout << j << " ";
    }
    cout << endl;
    cout << " +";
    for(int j = 0;j<15;j++)
    {  
        cout << "-";
    }
    cout << "+\n";
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<18;j++)
        {
            if(j == 0)
            {
                cout << i;
            }
            else if(j % 2 != 0)
            {
                cout << "|";
            }
            else
            {
                if(open[i][j/2-1] == 0) //沒翻開
                {
                    cout << "*";
                }
                else
                {
                    cout << board[i][j/2-1];
                }
            }
        }
        cout << "\n";
        if(i != 3)
        {
            cout << " |";
            for(int j = 0;j<15;j++)
            {  
                cout << "-";
            }
            cout << "|\n";
        }
    }
    cout << " +";
    for(int j = 0;j<15;j++)
    {  
        cout << "-";
    }
    cout << "+\n";

 }


int main()
{
    vector<int> def = {1,2,2,3,3,4,4,5,5,6,6,7,7,7,7,7,11,12,12,13,13,14,14,15,15,16,16,17,17,17,17,17};
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle (def.begin(), def.end(), default_random_engine(seed));
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<8;j++)
        {
            qi[i][j] = def[8*i+j];
        }
    }
    print();



}