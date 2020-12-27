#include<bits/stdc++.h>
#define endl "\n"
typedef long long ll;
using namespace std;
int N,A[4002],B[4002],C[4002],D[4002]; 
ll ans;
vector<int> AB,CD;
int main()
{   
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)cin >> A[i] >> B[i] >> C[i] >> D[i];
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            AB.push_back(A[i]+B[j]);
            CD.push_back(C[i]+D[j]);
        }
    }
    sort(CD.begin(),CD.end());
    for(int i=0;i<AB.size();i++) ans += upper_bound(CD.begin(),CD.end(),-1*AB[i]) - lower_bound(CD.begin(),CD.end(),-1*AB[i]);
    cout << ans;
}