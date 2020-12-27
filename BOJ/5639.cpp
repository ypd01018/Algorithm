#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
map<int,pair<int,int>> m;
void maketree(int par,int input)
{
    if(input > par)//input이 par보다 크면
    {
        if(m[par].second==0) m[par].second =input;
        else maketree(m[par].second,input); 
    }
    else // input이 par보다 작으면
    {
        if(m[par].first==0) m[par].first =input;
        else maketree(m[par].first,input); 
    }
    
}
void DFS(int root)
{
    int L_child,R_child; tie(L_child,R_child) = m[root];
    if(L_child!=0) DFS(L_child);
    if(R_child!=0) DFS(R_child);
    cout << root <<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string in;
    int root,num;
    map<int,pair<int,int>>::iterator iter;
    bool flag = true;
    while (scanf("%d", &num) == 1)
    {
        //if(in=="d") break;
        if(flag) 
        {
            root = num;
            flag=false;
        }
        if(!m.size()) m[num];
        else
        {
            iter = m.begin();
            maketree(root,num);
        }
    }
    DFS(root);


}