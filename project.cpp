#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <array>
#include <cmath>
using namespace std;
using std::min;
using std::max;
#define INF 2147483647
enum SPOT_STATE
{
    EMPTY = 0,
    BLACK = 1,
    WHITE = 2
};

int DEPTH = 3;
int chessnum=0;
int player;
int opponent;
int now_score;
int dx[8] = { 0,0,-1,1,1,-1,1,-1};
int dy[8] = { 1,-1,0,0,1,1,-1,-1};
int nextX = 7;
int nextY = 7;
int flag = 0;
int L = INF;
int R = -INF;
int U = INF;
int D = -INF;

const int SIZE = 15;
array<array<int, SIZE>, SIZE> board;


void read_board(std::ifstream& fin)
{
    fin >> player;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            fin >> board[i][j];
            if (board[i][j] != 0)
            {
                flag = 1;
                L = min(L, j);
                R = max(R, j);
                U = min(U, i);
                D = max(D, i);
                chessnum++;
            }
        }
    }
    opponent = 3 - player;
}

int eval(array<array<int, SIZE>, SIZE> b)
{
    int score = 0;
    int patern[3][6];//5//alive4//death4//alive3//death3//alive2
    int prechess, afterchess;
    int Iam = 0, You = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            patern[i][j] = 0;
        }
    }


    for (int i = 0; i <SIZE; i++)
    {
        int nowcolor = b[i][0];
        int num = 1;
        for (int j = 1; j <SIZE; j++)
        {
            if (b[i][j] == nowcolor && nowcolor != EMPTY) num++;
            if (b[i][j] != nowcolor && nowcolor == EMPTY) nowcolor = b[i][j];
            if ((b[i][j] != nowcolor && nowcolor != EMPTY) || (j == SIZE - 1 && nowcolor != EMPTY))
            {
                Iam = nowcolor;
                You = 3 - Iam;
                if (j == SIZE - 1 && b[i][j] == nowcolor)
                {
                    afterchess = You;
                }
                else afterchess = b[i][j];
                prechess = j - num > 0 ? b[i][j - num - 1] : You;
                if (num == 5)
                {
                    patern[Iam][0]++;
                    if(Iam==opponent) return -1000000;
                }
                if (afterchess == EMPTY && prechess == EMPTY)
                {
                    if (num == 4)
                    {
                        patern[Iam][1]++;
                    }
                    else if (num == 3)
                    {
                        patern[Iam][3]++;
                    }
                    else if (num == 2)
                    {
                        patern[Iam][5]++;
                    }
                }
                else if ((afterchess == You && prechess == EMPTY) || (afterchess == EMPTY && prechess == You))
                {
                    if (num == 4)
                    {
                        patern[Iam][2]++;
                    }
                    else if (num == 3)
                    {
                        patern[Iam][4]++;
                    }
                }
                num = 1;
                nowcolor = b[i][j];
            }
        }
    }

    if (patern[opponent][0] > 0) return -1000000;//opponent 5
    for (int j = 0; j <SIZE; j++)
    {
        int nowcolor = b[0][j];
        int num = 1;
        for (int i = 1; i <SIZE; i++)
        {
            if (b[i][j] == nowcolor && nowcolor != EMPTY) num++;
            if (b[i][j] != nowcolor && nowcolor == EMPTY) nowcolor = b[i][j];
            if ((b[i][j] != nowcolor && nowcolor != EMPTY) || (i == SIZE - 1 && nowcolor != EMPTY))
            {
                Iam = nowcolor;
                You = 3 - Iam;
                if (i == SIZE - 1 && b[i][j] == nowcolor)
                {
                    afterchess = You;
                }
                else afterchess = b[i][j];
                prechess = i - num > 0 ? b[i - num - 1][j] : You;
                if (num == 5)
                {
                    patern[Iam][0]++;
                    if(Iam==opponent) return -1000000;
                }
                if (afterchess == EMPTY && prechess == EMPTY)
                {
                    if (num == 4)
                    {
                        patern[Iam][1]++;
                    }
                    else if (num == 3)
                    {
                        patern[Iam][3]++;
                    }
                    else if (num == 2)
                    {
                        patern[Iam][5]++;
                    }
                }
                else if ((afterchess == You && prechess == EMPTY) || (afterchess == EMPTY && prechess == You))
                {
                    if (num == 4)
                    {
                        patern[Iam][2]++;
                    }
                    else if (num == 3)
                    {
                        patern[Iam][4]++;
                    }
                }
                num = 1;
                nowcolor = b[i][j];
            }
        }
    }

    for (int l = 0; l < SIZE; l++)  //RU
    {
        int nowcolor = b[0][l];
        int num = 1;
        for (int i = 1; i < SIZE - l; i++)
        {
            int j = l + i;
            if (b[i][j] == nowcolor && nowcolor != EMPTY) num++;
            if (b[i][j] != nowcolor && nowcolor == EMPTY) nowcolor = b[i][j];
            if ((b[i][j] != nowcolor && nowcolor != EMPTY) || (j == SIZE - 1 && nowcolor != EMPTY))
            {
                Iam = nowcolor;
                You = 3 - Iam;
                if (j == SIZE - 1 && b[i][j] == nowcolor)
                {
                    afterchess = You;
                }
                else afterchess = b[i][j];
                prechess = i - num > 0 ? b[i - num - 1][j - num - 1] : You;
                if (num == 5)
                {
                    patern[Iam][0]++;
                    if(Iam==opponent) return -1000000;
                }
                if (afterchess == EMPTY && prechess == EMPTY)
                {
                    if (num == 4)
                    {
                        patern[Iam][1]++;
                    }
                    else if (num == 3)
                    {
                        patern[Iam][3]++;
                    }
                    else if (num == 2)
                    {
                        patern[Iam][5]++;
                    }
                }
                else if ((afterchess == You && prechess == EMPTY) || (afterchess == EMPTY && prechess == You))
                {
                    if (num == 4)
                    {
                        patern[Iam][2]++;
                    }
                    else if (num == 3)
                    {
                        patern[Iam][4]++;
                    }
                }
                num = 1;
                nowcolor = b[i][j];
            }
        }
    }
    if (patern[opponent][0] > 0) return -1000000;

    for (int l = SIZE - 1; l >= 0; l--)  //LU
    {
        int nowcolor = b[l][0];
        int num = 1;
        for (int i = l - 1; i >= 0; i--)
        {
            int j = l - i;
            if (b[i][j] == nowcolor && nowcolor != EMPTY) num++;
            if (b[i][j] != nowcolor && nowcolor == EMPTY) nowcolor = b[i][j];
            if ((b[i][j] != nowcolor && nowcolor != EMPTY) || (i == 0 && nowcolor != EMPTY))
            {
                Iam = nowcolor;
                You = 3 - Iam;
                if (i == 0 && b[i][j] == nowcolor)
                {
                    afterchess = You;
                }
                else afterchess = b[i][j];
                prechess = j - num > 0 ? b[i + num + 1][j - num - 1] : You;
                if (num == 5)
                {
                    patern[Iam][0]++;
                    if(Iam==opponent) return -1000000;
                }
                if (afterchess == EMPTY && prechess == EMPTY)
                {
                    if (num == 4)
                    {
                        patern[Iam][1]++;
                    }
                    else if (num == 3)
                    {
                        patern[Iam][3]++;
                    }
                    else if (num == 2)
                    {
                        patern[Iam][5]++;
                    }
                }
                else if ((afterchess == You && prechess == EMPTY) || (afterchess == EMPTY && prechess == You))
                {
                    if (num == 4)
                    {
                        patern[Iam][2]++;
                    }
                    else if (num == 3)
                    {
                        patern[Iam][4]++;
                    }
                }
                num = 1;
                nowcolor = b[i][j];
            }
        }
    }
    if (patern[opponent][0] > 0) return -1000000;

    for (int l = 1; l < SIZE; l++)  //LD
    {
        int nowcolor = b[l][0];
        int num = 1;
        for (int i = l + 1; i < SIZE; i++)
        {
            int j = i - l;
            if (b[i][j] == nowcolor && nowcolor != EMPTY) num++;
            if (b[i][j] != nowcolor && nowcolor == EMPTY) nowcolor = b[i][j];
            if ((b[i][j] != nowcolor && nowcolor != EMPTY) || (i == SIZE - 1 && nowcolor != EMPTY))
            {
                Iam = nowcolor;
                You = 3 - Iam;
                if (i == SIZE - 1 && b[i][j] == nowcolor)
                {
                    afterchess = You;
                }
                else afterchess = b[i][j];
                prechess = j - num > 0 ? b[i - num - 1][j - num - 1] : You;
                if (num == 5)
                {
                    patern[Iam][0]++;
                    if(Iam==opponent) return -1000000;
                }
                if (afterchess == EMPTY && prechess == EMPTY)
                {
                    if (num == 4)
                    {
                        patern[Iam][1]++;
                    }
                    else if (num == 3)
                    {
                        patern[Iam][3]++;
                    }
                    else if (num == 2)
                    {
                        patern[Iam][5]++;
                    }
                }
                else if ((afterchess == You && prechess == EMPTY) || (afterchess == EMPTY && prechess == You))
                {
                    if (num == 4)
                    {
                        patern[Iam][2]++;
                    }
                    else if (num == 3)
                    {
                        patern[Iam][4]++;
                    }
                }
                num = 1;
                nowcolor = b[i][j];
            }
        }

    }

    for (int l = 1; l < SIZE; l++)  //RD
    {
        int nowcolor = b[SIZE - 1][l];
        int num = 1;
        for (int i = SIZE - 2; i >= l; i--)
        {
            int j = SIZE + l - i - 1;
            if (b[i][j] == nowcolor && nowcolor != EMPTY) num++;
            if (b[i][j] != nowcolor && nowcolor == EMPTY) nowcolor = b[i][j];
            if ((b[i][j] != nowcolor && nowcolor != EMPTY) || (j == SIZE - 1 && nowcolor != EMPTY))
            {
                Iam = nowcolor;
                You = 3 - Iam;
                if (j == SIZE - 1 && b[i][j] == nowcolor)
                {
                    afterchess = You;
                }
                else afterchess = b[i][j];
                prechess = i + num + 1 < SIZE ? b[i + num + 1][j - num - 1] : You;
                if (num == 5)
                {
                    patern[Iam][0]++;
                    if(Iam==opponent) return -1000000;
                }
                if (afterchess == EMPTY && prechess == EMPTY)
                {
                    if (num == 4)
                    {
                        patern[Iam][1]++;
                    }
                    else if (num == 3)
                    {
                        patern[Iam][3]++;
                    }
                    else if (num == 2)
                    {
                        patern[Iam][5]++;
                    }
                }
                else if ((afterchess == You && prechess == EMPTY) || (afterchess == EMPTY && prechess == You))
                {
                    if (num == 4)
                    {
                        patern[Iam][2]++;
                    }
                    else if (num == 3)
                    {
                        patern[Iam][4]++;
                    }
                }
                num = 1;
                nowcolor = b[i][j];
            }
        }

    }



    //must win score
    if (patern[opponent][0] > 0) return -1000000;
    if (patern[player][0] > 0) return 1000000;//player 5
    if (patern[opponent][1] > 0) return -500000;
    if (patern[player][1] > 0 && patern[opponent][2] == 0) return 500000;//player alive4 && opponent death4=0
    /*if (patern[opponent][2] > 0) return -100000;//opponent death4
    if (patern[player][2] >= 2) return 100000;//player 2death4
    if (patern[opponent][2] == 1 && patern[opponent][3] == 1) return -90000;//opponent death4 alive3
    if (patern[opponent][3] >= 2) return -80000;//opponent 2alive3
    if (patern[player][2] == 1 && patern[player][3] == 1) return 85000;
    if (patern[player][3] >= 2) return 75000;*/

    //normal score
    score = (patern[player][0]*1000005+patern[player][1] * 13005 + patern[player][2] * 6005 + patern[player][3] * 5005 + patern[player][4] * 1005 + patern[player][5] * 105) -
            (patern[opponent][0]*1000005+patern[opponent][1] * 14005 + patern[opponent][2] * 7005 + patern[opponent][3] * 6405 + patern[opponent][4] * 2205 + patern[opponent][5] * 205);
    //cout<<score<<endl;
    return score;
}

bool neighbor(array<array<int, SIZE>, SIZE> b,int x,int y)
{
    for(int d=0;d<8;d++){
        if(x+dx[d]>=0&&x+dx[d]<SIZE&&y+dy[d]>=0&&y+dy[d]<SIZE){
            if(b[x+dx[d]][y+dy[d]]!=EMPTY) return true;
        }
    }
    return false;
}

int alphabeta(array<array<int, SIZE>, SIZE> b, int deep, int alpha, int beta, int who, ofstream& fout)
{
    int value;
    array<array<int, SIZE>, SIZE> tmp = b;
    if (deep == 0)
    {
        value = eval(b);
        cout << value << endl;
        return value;
    }
    if (who == player)  //max
    {
        bool already_found = false;
        value = -INF;
        for (int i = max(0, U - 1); i <= min(SIZE - 1, D + 1); i++)
        {
            for (int j = max(0, L - 1); j <= min(SIZE - 1, R + 1); j++)
            {
                if (b[i][j] == EMPTY&&neighbor(b,i,j))
                {
                    tmp[i][j] = player;
                    int newV = max(value, alphabeta(tmp, deep - 1, alpha, beta, opponent, fout));
                    tmp[i][j] = EMPTY;
                    if (newV > value)
                    {
                        value = newV;
                        nextX = i;
                        nextY = j;
                        if (deep == DEPTH)
                        {
                            fout << nextX << " " << nextY << "\n";
                            fout.flush();
                        }
                    }
                    alpha = max(alpha, value);
                    if (alpha >= beta)
                    {
                        already_found = true;
                        break;
                    }
                }
            }
            if (already_found) break;
        }
        return value;
    }
    else  //min
    {
        bool already_found = false;
        value = INF;
        for (int i = max(0, U - 1); i <= min(SIZE - 1, D + 1); i++)
        {
            for (int j = max(0, L - 1); j <= min(SIZE - 1, R + 1); j++)
            {
                if (b[i][j] == EMPTY&&neighbor(b,i,j))
                {
                    tmp[i][j] = opponent;
                    value = min(value, alphabeta(tmp, deep - 1, alpha, beta, player, fout));
                    tmp[i][j] = EMPTY;
                    beta = min(beta, value);
                    if (alpha >= beta)
                    {
                        already_found = true;
                        break;
                    }
                }
            }
            if (already_found) break;
        }
        return value;
    }
}

void write_valid_spot(std::ofstream& fout)
{
    srand(time(NULL));
    // Keep updating the output until getting killed.
    // Choose a random spot.
    if((R-L+1)*(D-U+1)-chessnum>=20) DEPTH=2;
    if(chessnum>=90) DEPTH=1;//150
    if (flag) now_score = alphabeta(board, DEPTH, INT_MIN, INT_MAX, player, fout);
    fout << nextX << " " << nextY << "\n";
    // Remember to flush the output to ensure the last action is written to file.
    fout.flush();
}

int main(int, char** argv)
{
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);
    read_board(fin);
    write_valid_spot(fout);
    fin.close();
    fout.close();
    return 0;
}
