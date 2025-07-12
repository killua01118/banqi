#include <bits/stdc++.h>
using namespace std;

int open[4][8]; //開關
int board[4][8]; //翻開棋
int qi[4][8]; //蓋起來的棋
int color[18] = {0,1,1,1,1,1,1,1,0,0,0,2,2,2,2,2,2,2};

 void print() // 輸出棋盤
 {
    int k;
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
                    if(board[i][j/2-1] > 10)
                    {
                        k = board[i][j/2-1] - 10;
                        if(k == 1)cout << "A";
                        else if(k == 2)cout << "B";
                        else if(k == 3)cout << "C";
                        else if(k == 4)cout << "D";
                        else if(k == 5)cout << "E";
                        else if(k == 6)cout << "F";
                        else if(k == 7)cout << "G";
                    }
                    else if(board[i][j/2-1] == 0)
                    {
                        cout << " ";
                    }
                    else
                    {
                        cout << board[i][j/2-1];
                    }
                    
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

 int eat(int x,int y,int a,int b)
 {
    int n,m,count = 0;
    if(board[x][y] > 10)
    {
        n = board[x][y] - 10;
    }
    else
    {
        n = board[x][y];
    }
    if(board[a][b] > 10)
    {
        m = board[a][b] - 10;
    }
    else
    {
        m = board[a][b];
    }
    if(n == 1)//將
    {
        if(m == 1 || m == 2 || m == 3 || m == 4 || m == 5 || m == 6)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    else if(n == 2)//士
    {
        if(m == 2 || m == 3 || m == 4 || m == 5 || m == 6 || m == 7)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(n == 3)//象
    {
        if(m == 3 || m == 4 || m == 5 || m == 6 || m == 7)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(n == 4)//車
    {
        if(m == 4 || m == 5 || m == 6 || m == 7)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(n == 5)//馬
    {
        if(m == 5 || m == 6 || m == 7)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(n == 6)//包
    {
        if(x == a)
        {
            if(y > b)
            {
                for(int i = b+1;i<y;i++)
                {
                    if(board[x][i] != 0)
                    {
                        count += 1;
                    }
                }
            }
            else if(y < b)
            {
                for(int i = y+1;i<b;i++)
                {
                    if(board[x][i] != 0)
                    {
                        count += 1;
                    }
                }
            }
        }
        else if(y == b)
        {
            if(x > a)
            {
                for(int i = a+1;i<x;i++)
                {
                    if(board[i][y] != 0)
                    {
                        count += 1;
                    }
                }
            }
            else if(x < a)
            {
                for(int i = x+1;i<a;i++)
                {
                    if(board[i][y] != 0)
                    {
                        count += 1;
                    }
                }
            }
        }
        if(count == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(n == 7)//卒
    {
        if(m == 1 || m == 7)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
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
    int turn = 1,x,y,a,b,color1,color2,count1 = 0,count2 = 0,sum = 0;
    while(1)
    {
        if(turn % 2 != 0)
        {
            cout << "player 1 (x,y):";
            cin >> x >> y;
            if(turn == 1)
            {
                if(qi[x][y] - 10 < 0)
                {
                    color1 = 1;
                    color2 = 2;
                }
                else
                {
                    color1 = 2;
                    color2 = 1;
                }
            }
            if(open[x][y] == 0)
            {
                open[x][y] = 1;
                board[x][y] = qi[x][y];
                turn += 1;
            }
            else
            {
                if(color[board[x][y]] == color1)
                {
                    cout << "to (x,y):";
                    cin >> a >> b;
                    if(open[a][b] == 0 || color[board[a][b]] == color1)
                    {
                        cout << "error!" << endl;
                        continue;
                    }
                    else
                    {
                        if(board[a][b] == 0 && abs(x-a)+abs(y-b) == 1)
                        {
                            board[a][b] = board[x][y];
                            board[x][y] = 0;
                            turn += 1;
                            sum += 1;
                        }
                        if(color[board[a][b]] == color2)
                        {
                           if(eat(x,y,a,b) == 1)
                           {
                              board[a][b] = board[x][y];
                              open[a][b] = 1;
                              board[x][y] = 0;
                              turn += 1;
                              count1 += 1;
                              sum = 0;
                           }
                           else
                           {
                              cout << "error!" << endl;
                              continue;
                           }
                        }
                    }
                }
                else
                {
                    cout << "error!" << endl;
                    continue;
                }              
            }
        }
        else
        {
            cout << "player 2 (x,y):";
            cin >> x >> y;
            if(open[x][y] == 0)
            {
                open[x][y] = 1;
                board[x][y] = qi[x][y];
                turn += 1;
            }
            else
            {
                if(color[board[x][y]] == color2)
                {
                    cout << "to (x,y):";
                    cin >> a >> b;
                    if(open[a][b] == 0 || color[board[a][b]] == color2)
                    {
                        cout << "error!" << endl;
                        continue;
                    }
                    else
                    {
                        if(board[a][b] == 0 && abs(x-a)+abs(y-b) == 1)
                        {
                            board[a][b] = board[x][y];
                            board[x][y] = 0;
                            turn += 1;
                            sum += 1;
                        }
                        if(color[board[a][b]] == color1)
                        {
                           if(eat(x,y,a,b) == 1)
                           {
                              board[a][b] = board[x][y];
                              open[a][b] = 1;
                              board[x][y] = 0;
                              turn += 1;
                              count2 += 1;
                              sum = 0;
                           }
                           else
                           {
                              cout << "error!" << endl;
                              continue;
                           }
                        }
                    }
                }
                else
                {
                    cout << "error!" << endl;
                    continue;
                }              
            }
        }
        print();
        if(count1 == 16)
        {
            cout << "player 1 win!";
            break;
        }
        if(count2 == 16)
        {
            cout << "player 2 win!";
        }
        if(sum == 50)
        {
            cout << "tie";
        }
    }



}