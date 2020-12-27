#include<bits/stdc++.h>
#define endl "\n"
#define MAX 30
using namespace std;
int N;
vector<char> v;

double mat[MAX][MAX];
int fac(int a)
{
    int ret=1,tmp = 0;
    while(tmp!=a)
    {
        tmp++;
        ret *= tmp;
    }
    return ret;
}
void make()
{
    for(int i=0;i<MAX;i++)
    {
        mat[i][0]=1;
    }
    mat[0][1] = 1;

    for(int i=1;i<MAX;i++)
    {
        for(int j=1;j<i+2;j++)
        {   
            mat[i][j] = (mat[i-1][j] +mat[i-1][j-1]);
        }
    }
}


void case1()
{
    int input;
    cin >> input;
    while(1)
    {
        for(int i=N;i>-1;i--)
        {
            int fact = fac(N);
            
        }
    }

    for(int i : v)
    cout << i <<' ';
}
void case2()
{

}
int main()
{
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        v.push_back(i);
    }


    int cmd;
    cin >> cmd;
    switch(cmd)
    {
        case 1:
            case1();
            break;
        case 2:
            case2();
            break;
    }

}
