#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int root;
vector<vector<int>> answer;
struct node_
{
    int y,x,num;
    int lft=-1,rght=-1,parent=-1;
    void make_node(int y_,int x_,int num_)
    {
        y=y_; x=x_; num=num_;
    }
}node[10002];
bool cmp(node_ a, node_ b)
{
    if(a.y>b.y) return true;
    else if(a.y<b.y) return false;
    else
    {
        if(a.x<b.x) return true;
        else return false;
    }
}
void insert(int parent, int child, int &want_loc)
{
    want_loc = child;
    node[child].parent = parent;

}
void find_node(int n,int idx)
{
    if(node[idx].y>node[n].y)
    {
        if(node[idx].x < node[n].x)
        {
            if(node[idx].rght == -1) insert(idx,n,node[idx].rght);
            else find_node(n,node[idx].rght);
        }
        else
        {
            if(node[idx].lft == -1) insert(idx,n,node[idx].lft);
            else find_node(n,node[idx].lft);
        }
    }
    else
    {
        if(idx==node[node[idx].parent].lft) insert(node[idx].parent,n,node[node[idx].parent].lft);
        else insert(node[idx].parent,n,node[node[idx].parent].rght);
        
        if(node[n].x < node[idx].x) insert(n,idx,node[n].rght);
        else insert(n,idx,node[n].lft);
    }
    
}
void go(int n)
{
    answer[0].push_back(node[n].num);
    if(node[n].lft!=-1)go(node[n].lft);
    if(node[n].rght!=-1)go(node[n].rght);
    answer[1].push_back(node[n].num);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    for(int i=0;i<nodeinfo.size();i++) node[i+1].make_node(nodeinfo[i][1],nodeinfo[i][0],i+1);
    sort(node+1,node+nodeinfo.size()+1,cmp);
    for(int i=1;i<nodeinfo.size();i++) find_node(i+1,1);
    answer.resize(2);
    go(1);
    return answer;
}