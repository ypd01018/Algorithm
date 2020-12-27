#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int N,arr[1003][3],cost[1003][3];
void test()
{
    cout << endl;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<3;i++) cost[0][i]=arr[0][i];

    for(int i=1;i<N;i++)
    {
        for(int j=0;j<3;j++)
        {
            int a,b;
            if(j==0) { a=1;b=2;}
            else if(j==1) {a=0;b=2;}
            else{a=0;b=1;}

            cost[i][j]=arr[i][j]+min(cost[i-1][a],cost[i-1][b]);
        }
    }
    cout << min(min(cost[N-1][0],cost[N-1][1]),cost[N-1][2]);
}