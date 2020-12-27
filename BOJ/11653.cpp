#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int N,cnt,arr[10'000'100];
vector<int> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=2;i<=N;i++)
    {
        if(arr[i]==0)
        {
            v.push_back(i);
            for(int j=i*i; j<=N;j+=i)
            {   
                if(j<0 ||j>10'000'005 ) break;
                arr[j]++;
            }
        }
    }

    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++)
    {
        while(N%v[i]==0)
        {
            if(N==v[i]) 
            {
                cout << v[i]<<endl;
                return 0;
            }

            N /= v[i];
            cout << v[i]<<endl;
        }
    }



}