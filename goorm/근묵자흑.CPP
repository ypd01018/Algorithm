#include <iostream>
#include <algorithm>

using namespace std;
int N,K,mn_idx,mn_input = 1e9,mn=1e9;
int main() 
{
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        int a; cin >> a;
        if(mn_input<a) continue;
        mn_input = a;
        mn_idx = i;
    }
    for(int i=mn_idx-(K-1);i<=mn_idx;i++)
    {
        int start_idx = i,end_idx = i+K-1;
        if(start_idx<0) continue;
        int n=1;
        if(start_idx) n += 1+(start_idx-1)/(K-1);
        if(end_idx<N-1) n += 1+(N-2-end_idx)/(K-1);
        mn = min(mn,n);
    }
    cout << mn;
	return 0;
}