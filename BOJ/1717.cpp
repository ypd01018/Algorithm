#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,parent[1'000'010],a,b;


void init()
{
    for(int i=0;i<n+1;++i)
    {
        parent[i]=i;
    }
}

int find(int a)
{
    if(parent[a]==a) return a;
    else return parent[a]=find(parent[a]);
}

void uni(int a, int b)
{
    int root_a = find(a);
    int root_b = find(b);
    parent[root_a] = root_b; 
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    init();
    for(int i=0;i<m;i++)
    {
        int cmd; cin >> cmd >> a >> b;
        if(!cmd)
        {
            uni(a,b);
        }
        else
        {
            if(find(a)==find(b)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        
    }
}


/*
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1
*/