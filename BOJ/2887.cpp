#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int root[100010],N;
struct planet
{
    int n,x,y,z;
};
planet plan[100010];

vector<pair<int,pair<int,int>>> v;
void init()
{
    for(int i=0;i<=N;i++)
    {
        root[i]=i;
    }
}
int find(int a)
{
    if(root[a]==a) return a;
    else return root[a]=find(root[a]);
}
void uni(int a, int b)
{
    a = root[a];
    b = root[b];
    root[b] = a;
}
bool comp_x(planet a, planet b)
{
    if(a.x<b.x) return 1;
    else return 0;
}
bool comp_y(planet a, planet b)
{
    if(a.y<b.y) return 1;
    else return 0;
}
bool comp_z(planet a, planet b)
{
    if(a.z<b.z) return 1;
    else return 0;
}
int main()
{
    cin >> N;
    init();
    for(int i=0;i<N;i++)
    {
        plan[i].n=i;
        cin >> plan[i].x >> plan[i].y >> plan[i].z;
    }
    sort(plan,plan+N,comp_x);
    for(int i=0;i<N-1;i++)
    {
        int x = abs(plan[i].x-plan[i+1].x);
        v.push_back({x,{plan[i].n,plan[i+1].n}});
    }
    sort(plan,plan+N,comp_y);
    for(int i=0;i<N-1;i++)
    {
        int y = abs(plan[i].y-plan[i+1].y);
        v.push_back({y,{plan[i].n,plan[i+1].n}});
    }
    sort(plan,plan+N,comp_z);
    for(int i=0;i<N-1;i++)
    {
        int z = abs(plan[i].z-plan[i+1].z);
        v.push_back({z,{plan[i].n,plan[i+1].n}});
    }
    sort(v.begin(),v.end());
    int tot=0,cnt=0;
    for(int i=0;i<v.size();i++)
    {
        int a,b; tie(a,b)=v[i].second;
        if(find(a)!=find(b))
        {
            tot += v[i].first;
            uni(a,b);
            cnt++;
        }

        if(cnt == N-1) break;
    }
    cout << tot;

}