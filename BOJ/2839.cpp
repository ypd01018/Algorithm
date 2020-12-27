#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,cnt;
bool go(int thr)
{
    for(int i=thr;i<=N;i+=5)
    {
        if(i==N)
        {
            //cout << "thr:" << thr << " " << "five:" << (N-thr)<<endl;
            cout<<(thr/3)+(N-thr)/5;
            return true;
        }
    }
    return false;
}
int main()
{
    cin >> N;
    for(int i=0;i<=N;i+=3)
    {
        if(go(i))
        {
            return 0;
        }
    }
    cout << -1;
    
}