#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
long long T,cnt;
int n,m,A[1003],B[1003];
vector<long long> v_a,v_b;
int main()
{
    cin >> T >> n;
    for(int i=0;i<n;i++) 
    {
        cin >> A[i];
    }
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> B[i];
    }

    for(int i=0;i<n;i++)
    {
        long long sum_a = A[i];
        v_a.push_back(sum_a);
        for(int j=i+1;j<n;j++)
        {
            sum_a += A[j];
            v_a.push_back(sum_a);
        }
    }
    for(int i=0;i<m;i++)
    {
        long long sum_b=B[i];
        v_b.push_back(sum_b);
        for(int j=i+1;j<m;j++)
        {
            sum_b +=B[j];
            v_b.push_back(sum_b);
        }
    }    
    sort(v_b.begin(),v_b.end());

    for(int i=0;i<v_a.size();i++)
    {
        int dif = T-v_a[i];
        int upper = upper_bound(v_b.begin(),v_b.end(),dif)-v_b.begin();
        int lower = lower_bound(v_b.begin(),v_b.end(),dif)-v_b.begin();
        if(v_a[i]+v_b[lower]==T) 
        {
            cnt += upper - lower;
            //cout << "v_a:" << v_a[i] <<"  v_b:"<<*lower_bound(v_b.begin(),v_b.end(),dif)<< " upper:" 
            //<< upper_bound(v_b.begin(),v_b.end(),dif)-v_b.begin() << "  lower:" << lower_bound(v_b.begin(),v_b.end(),dif)-v_b.begin() << endl;
        }
    }

    cout << cnt;



}