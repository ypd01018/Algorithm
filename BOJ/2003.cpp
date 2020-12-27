#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long N,M,lft,rght,sum,len,arr[10'003],cnt;
int main()
{
    cin >> N >> M;
    for(long long i=0;i<N;i++) cin >> arr[i];
    sum=arr[0];

    while(lft <=rght && rght <N)
    {
        cout << "sum:" << sum << " lft:"<<lft << "  rght:" << rght << endl;
        if(sum==M) cnt++;
        
        if(sum <= M) //섬이 목표보다 같거나 낮은경우
        {
            rght++;
            if(rght<N) sum += arr[rght];
        }
        else // 섬이 높은경우
        {
            if(lft <= rght)
            {
                sum -=arr[lft];
            }
            if(lft++>rght && lft < N);
            {
                rght=lft;
                sum=arr[lft];
            }
        }
    }
    cout << cnt;
}