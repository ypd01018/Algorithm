#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T,N,parent[200010],node_n[200010];
map<string,int> mp;

void init()
{
    mp.clear();
    for(int i=1;i<=2*N;i++) 
    {
        parent[i]=i;
        node_n[i]=1;
    }
}

int find(int a)
{
    if(a==parent[a]) return a;
    else return parent[a] = find(parent[a]);
}
int uni(int a, int b)
{
    a= find(a);
    b= find(b);
    if(a==b) return node_n[a];

    parent[b]=a;
    node_n[a] += node_n[b];
    node_n[b]=1;

    return node_n[a];

}
void sol()
{
    cin >> N;
    init();
    int no_name=1;
    for(int i=0;i<N;i++)
    {
        string a,b;
        cin >> a >> b;
        if(!mp[a]) mp[a]=no_name++;
        if(!mp[b]) mp[b]=no_name++;
        cout << uni(mp[a],mp[b]) << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int i=0;i<T;i++)
    {
        sol();
    }
}