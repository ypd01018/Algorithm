#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
map<char,pair<char,char>> mp;
int N;
void DFS(char par)
{
    cout << par;
    char L_child,R_child; tie(L_child,R_child) = mp[par];
    if(L_child!='.') DFS(L_child);
    if(R_child!='.') DFS(R_child);
}
void DFS_2(char par)
{
    char L_child,R_child; tie(L_child,R_child) = mp[par];
    if(L_child!='.') DFS_2(L_child);
    cout << par;
    if(R_child!='.') DFS_2(R_child);
    
}
void DFS_3(char par)
{
    char L_child,R_child; tie(L_child,R_child) = mp[par];
    if(L_child!='.') DFS_3(L_child);
    if(R_child!='.') DFS_3(R_child);
    cout << par;
}
int main()
{
    
    cin >> N;
    for(int i=0;i<N;i++)
    {
        char parent,L_child,R_child; 
        cin >> parent >> L_child >> R_child;
        mp[parent]={L_child,R_child};
    }
    DFS('A');
    cout << endl;
    DFS_2('A');
    cout << endl;
    DFS_3('A');
}