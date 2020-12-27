#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T,alp[1001],check[1001],cnt,tot,mn=INT_MAX,alp_total;
string a;
void alp_n()
{
    alp_total=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i] <= 'N') alp[i]=a[i]-'A';
        else alp[i]= 'Z'-a[i]+1;

        if(!alp[i]) check[i]=1;
        else cnt++; 
        
        alp_total += alp[i];
    }    
}
int pre_idx(int idx)
{
    if(idx==0) return a.size()-1;
    else return idx-1; 
}
int nxt_idx(int idx)
{
    if(idx==a.size()-1) return 0;
    else return idx+1;
}
void go(int idx,int move)
{
    cout << idx <<'('<<cnt<<')'<<' ';
    int origin_check = check[idx],origin_cnt=cnt,origin_tot=tot,origin_alp_total = alp_total;
    tot++;
    if(!check[idx])
    {
        check[idx]=1;
        tot += alp[idx];
        cnt--;
        alp_total -= alp[idx];
    }

    if(!cnt)
    {
        //cout << tot << endl;
        mn = min(tot,mn); exit(0);
        check[idx]=origin_check; cnt = origin_cnt; tot = origin_tot; alp_total = origin_alp_total;
        return;
    }

    if(tot<mn && tot+origin_alp_total<mn && move < 2*a.size())
    {
        go(pre_idx(idx),move+1); go(nxt_idx(idx),move+1);
    }

    check[idx]=origin_check; cnt = origin_cnt; tot = origin_tot;alp_total = origin_alp_total;
}
void init()
{
    tot=cnt=0;
    memset(check,0,sizeof(check));
    alp_n();
    check[0]=1;
    tot+= alp[0];
    if(alp[0]) cnt--;
    mn=alp_total + a.size()-1;
    alp_total -= alp[0];
}
void sol()
{
    cin >> a;
    init();
    go(pre_idx(0),1); go(nxt_idx(0),1);

    cout << mn << endl;

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> T;
    for(int i=0;i<T;i++)
    {
        sol();
    }
}