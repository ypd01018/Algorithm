#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,parent[1'000'010],depth[1'000'010];
void init()
{
    for(int i=1;i<=n;i++)
    parent[i]=i;
}
int find(int a)
{
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}
void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if(a==b) return;

    if(depth[a]<depth[b]) parent[a]=b;
    else parent[b]=a;
    if(depth[a]==depth[b]) depth[a]++;
    
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    init();
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >>c;
        if(a==0)
        {
            uni(b,c);
        }
        else
        {
            if(find(b)==find(c)) cout << "YES"<<endl;
            else cout << "NO"<< endl;

        }
        
    }
}