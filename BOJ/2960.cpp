#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int N,K,arr[2003],cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i=2;i<=N;i++)
    {
        if(arr[i]==0)
        {
            cnt++;
            if(cnt == K)
            {
                cout << i;
                return 0;
            }
            for(int j=i*i;j<=N;j+=i)
            {   
                if(arr[j]==0)cnt++;
                if(cnt == K)
                {
                    cout << j;
                    return 0;
                }
                arr[j]++;

            }
        }
    }   
}