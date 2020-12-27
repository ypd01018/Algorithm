#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,S,arr[100'003],mn=100'003,sum,lft,rght,len;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    sum =arr[0];

    while(lft <= rght && rght <N)
    {
        if(sum < S)
        {
            if(++rght<N) sum+=arr[rght];
        }
        else if(sum >=S)
        {
            len = rght - lft +1;
            mn = min(mn,len);
            if(lft<=rght)
            {
                sum -= arr[lft];
                lft++;
            }

        }
    }
    


    if(mn>100'000) cout << 0;
    else cout<< mn;
}