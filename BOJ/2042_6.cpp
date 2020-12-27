#include<bits/stdc++.h>
#define endl "\n"
#define ll long long 
using namespace std;
ll N,M,K,arr[1000010],tree[4*1000010];
ll init(int start, int end, int node)
{
    if(start==end) return tree[node] = arr[start];
    int mid = (start+end)/2;
    return tree[node] = init(start,mid,node*2) + init(mid+1,end,node*2+1);
}
ll sum(int start, int end, int node, int lft, int rght)
{
    if(lft>end || rght<start) return 0;
    if(lft <= start && end<=rght) return tree[node];
    int mid = (start+end)/2;
    return sum(start,mid,node*2,lft,rght) + sum(mid+1,end,node*2+1,lft,rght);
}
void update(int start,int end,int node,int index,ll diff)
{
    if(index<start || index>end) return;
    tree[node] += diff;
    if(start == end) return;
    int mid = (start+end)/2;
    update(start,mid,node*2,index,diff);
    update(mid+1,end,node*2+1,index,diff);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++) cin >> arr[i];
    init(1,N,1);
    for(int i=0;i<M+K;i++)
    {
        ll a,b,c; cin >> a >> b >> c;
        if(a==1)
        {
            update(1,N,1,b,c-arr[b]);
            arr[b]=c;
        }
        else if(a==2)
        {
            cout << sum(1,N,1,b,c) << endl;
        }
    }
}