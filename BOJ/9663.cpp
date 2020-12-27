#include<iostream>
#define endl "\n"

using namespace std;

int N,issued1[20] = {0}, issued2[40] = {0}, issued3[40] = {0}, n=0,k=0;

void queen(int a);

int main()
{
    cin >>N;
    queen(0);
    cout << n;
}

void queen(int a)
{
    if(k == N)
    {
        n++;
        return ;
    }
    
    for(int i=0 ; i < N ; i++)
    {
        if( !issued1[i] && !issued2[a+i] && !issued3[a-i+N+1] ) 
        {
            issued1[i] = issued2[a+i]= issued3[a-i+N+1]=1;
            k++;
            queen(a+1);
            issued1[i] = issued2[a+i]= issued3[a-i+N+1]=0;
            k--;
        }
    }
}