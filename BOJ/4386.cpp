#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,root[102];
pair<double,double> star[102];
vector<pair<double,pair<int,int>>> v;
void init()
{
    for(int i=0;i<n;i++)
    {
        root[i]=i;
    }
}
int find(int a)
{
    if(a==root[a]) return a;
    else return root[a]=find(root[a]);
}
void uni(int a, int b)
{
    a=root[a];
    b=root[b];
    root[b]=a;
}
int main()
{
    cin >> n;
    init();
    for(int i=0;i<n;i++) cin >> star[i].first >> star[i].second;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            double val = sqrt(((star[i].first-star[j].first)*(star[i].first-star[j].first))+((star[i].second-star[j].second)*(star[i].second-star[j].second)));
            v.push_back({val,{i,j}});
        }
    }
    sort(v.begin(),v.end());
    int cnt=0; double tot=0;
    for(int i=0;i<v.size();i++)
    {
        int a,b; tie(a,b)=v[i].second;
        if(find(a)!=find(b))
        {
            tot += v[i].first;
            uni(a,b);
            cnt++;
        }
        if(cnt == n-1) break;
    }
    cout << fixed;
    cout.precision(2);
    cout << tot;

    
}