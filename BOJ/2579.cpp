#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int N,stair[303];
unsigned long long score[303][2];
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> stair[i];
    }
    if(N==1) 
    {
        cout << stair[0];
        return 0;
    }
    score[0][0]=stair[0];
    score[0][1]=0;
    score[1][0]=stair[1];
    score[1][1]=stair[0]+stair[1];

    for(int i=2;i<N;i++)
    {
        score[i][0] = stair[i] + max(score[i-2][0],score[i-2][1]);
        score[i][1] = stair[i] + score[i-1][0] ;
    }

    cout << max(score[N-1][0],score[N-1][1]);


}