#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,Q,root[100'002],dis;
struct bridge_
{
    int num,x1,x2,y;
}bridge[100'002];
struct lange_
{
    int mn,mx;
    int node;
};
vector<lange_> v;
int find(int a)
{
    if(root[a]==a) return a;
    else return root[a] = find(root[a]);
}
void uni(int a, int b)
{
    a = root[a];
    b = root[b];
    root[b] = find(a);
}
bool cmp(bridge_ a, bridge_ b)
{
    if(a.x1 < b.x1) return true;
    else if(a.x1 > b.x1) return false;
    else
    {
        if(a.x2 > b.x2) return true;
        else return false;
    }   
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++) root[i]=i;
    for(int i=1;i<=N;i++)
    {
        bridge[i].num = i;
        cin >> bridge[i].x1 >> bridge[i].x2 >> bridge[i].y;
    }
    sort(bridge+1,bridge+N+1,cmp);
    for(int i=1;i<=N;i++)
    {
        bridge_ a = bridge[i]; bool flag = true;
        for(int j=0;j<v.size();j++)
        {
            if(v[j].mx < a.x1) continue;
            uni(v[j].node,a.num);
            v[j].mx = max(v[j].mx,a.x2);
            flag = false;
            break;
        }
        if(flag)
        {
            lange_ new_lange;
            new_lange.mn = a.x1; new_lange.mx=a.x2; new_lange.node = a.num;
            v.push_back(new_lange);
        }
    }
    // cout << "answer\n";
    while(Q--)
    {
        int a ,b;
        cin >> a >> b;
        cout << (find(a)==find(b)) << endl;
    }


}