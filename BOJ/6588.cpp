#include<bits/stdc++.h>
#define endl "\n"
#define MAX 1'000'003 
using namespace std;
int n,arr[MAX];
//vector<int> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    arr[0]=arr[1]=1;
    for(int i=2;i<MAX;i++)
    {
        if(!arr[i])
        {
            //v.push_back(i);
            for(long long j = i+i ; j<MAX ;j+=i)
            {
                arr[j]++;
            }
        }
    }
    
    while(1)
    {
        cin >> n;
        if(!n) break;

        int total=0;
        bool flag=false;
        //for(int i=0; i<v.size();i++)
        for(int i=2;i<MAX;i++)
        {
            if(arr[i]==0 && !arr[n-i]) 
            {
                cout << n << " = " << i << " + " <<n-i << endl;
                break;
            }
        }
    }

}