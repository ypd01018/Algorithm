#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,K,arr[55][55],cnt,root[60];
void init()
{
    for(int i=0;i<=N;i++) root[i]=i;
    root[55]=55;
}
int find(int a)
{
    if(root[a]==a) return a;
    else return root[a]=find(root[a]);
}
void uni(int a, int b)
{
    a = find(a);
    b= find(b);
    root[b]=a;
}
int main()
{
    cin >> N >> M >> K;
    init();
    for(int i=0;i<K;i++)
    {
        int a; cin >> a;
        uni(55,a);
    }

    for(int i=0;i<M;i++)
    {
        cin >> arr[i][0];
        for(int j=1;j<=arr[i][0];j++)
        {
            cin >> arr[i][j];
            uni(arr[i][1],arr[i][j]);
        }
    }

    for(int i=0;i<M;i++)
    { 
        bool flag = true;
        for(int j=1;j<=arr[i][0];j++)
        {
            if(find(55) == find(arr[i][j])) {flag = false;}
        }
        if(flag) cnt++;
    }
    cout << cnt;
}