#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long N,M,arr[1'000'003],start =0,end_ =0,total,mn_mid;

int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
        start =0;
        end_ = max( end_,arr[i]);
    }
    long long mid;

    while(start <= end_)
    {
        total=0;
        mid = (start+end_)/2;
        for(int i=0;i<N;i++)
        {   
            if(arr[i]-mid>0)
            total += (arr[i]-mid);
        }

        if(total >=M) 
        {   
            if(mid > mn_mid)
            mn_mid = mid;
            start=mid+1;
        }
        else end_ = mid-1;
        //cout << "start:" << start << "  end:" << end_ <<"  mid:"<<mid<<"  total:" << total <<endl;

    }

    cout << mn_mid;

}