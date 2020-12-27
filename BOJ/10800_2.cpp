#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
struct ball_
{
    int color,size,idx;
    int hap=0,total_hap=0;
};
int N,color[200002],hap;
pair<int,int> pre_size[200002];
vector<ball_> v;
bool cmp(ball_ a, ball_ b){return a.size<b.size;}
bool cmp_idx(ball_ a, ball_ b){return a.idx < b.idx;}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        ball_ ball;
        cin >> ball.color >> ball.size; ball.idx=i;
        v.push_back(ball);
    }
    sort(v.begin(),v.end(),cmp);
    hap = v[0].size;
    color[v[0].color] += v[0].size;
    pre_size[v[0].color] = {v[0].size,0};
    for(int i=1;i<N;i++)
    {
        if(v[i].size>v[i-1].size) v[i].total_hap = hap;
        else v[i].total_hap = v[i-1].total_hap;

        if(v[i].size>v[i-1].size) v[i].hap = hap;
        else v[i].hap = v[i-1].total_hap;

        hap += v[i].size;

        if(pre_size[v[i].color].first==v[i].size) v[i].hap = v[pre_size[v[i].color].second].hap;
        else v[i].hap -= color[v[i].color];

        color[v[i].color] += v[i].size;
        pre_size[v[i].color]={v[i].size,i}; 
    }

    sort(v.begin(),v.end(),cmp_idx);
    for(int i=0;i<N;i++) cout << v[i].hap << endl;
}