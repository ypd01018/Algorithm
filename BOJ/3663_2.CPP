#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T,alp[1001],mn=INT_MAX,alp_total;
string a;
void alp_n()
{
    alp_total=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i] <= 'N') alp[i]=a[i]-'A';
        else alp[i]= 'Z'-a[i]+1;        
        alp_total += alp[i];
    }    
}
void sol()
{
    cin >> a;
    alp_n();
    mn=INT_MAX;
    for(int i=0;i<a.size();i++)
    {
        int j;
        for(j=i+1;j<a.size() && alp[j]==0;j++);
        mn = min(mn, (int)min(2*i+a.size()-j,2*(a.size()-j)+i));        
    }
    cout << mn+alp_total << endl;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> T;
    for(int i=0;i<T;i++) sol();
    
}