#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int S,check[3000][3000];
struct info
{
    int cnt,sec,clip;
};
queue<info> q;
info make(int a , int b , int c)
{
    info val;
    val.cnt = a;
    val.sec=b;
    val.clip=c;
    return val;
}
int main()
{
    cin >> S;
    q.push(make(1,0,0));
    check[1][0]=1;
    while(!q.empty())
    {
        int cnt= q.front().cnt, sec = q.front().sec, clip = q.front().clip; q.pop();
        if(cnt>=3000) continue;
        if(cnt==S)
        {
            cout << sec;
            break;
        }
        if(!check[cnt][cnt]){ q.push({make(cnt,sec+1,cnt)}); check[cnt][cnt]=1;}
        if(clip && cnt+clip<3000 && !check[cnt+clip][clip]) {q.push({make(cnt+clip,sec+1,clip)}); check[cnt+clip][clip]=1;}
        if(cnt&&!check[cnt-1][clip]){q.push(make(cnt-1,sec+1,clip)); check[cnt-1][clip]=1;}
    }
    
}