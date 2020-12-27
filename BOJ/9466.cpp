#include<bits/stdc++.h>
#define endl "\n"
#define target first
#define check second
using namespace std;
int T,n,cnt;
pair<int,int> arr[100'003];
bool team[100'003];
void input()
{
    cin >> n;
    int tmp;
    for(int i=1;i<n+1;i++)
    {
        cin >> tmp;
        arr[i].target=tmp;
        arr[i].check=team[i]=0;
    }
    cnt=0;
}
void DFS(int num)
{
    arr[num].check=1;
    int tar = arr[num].target;
    if(!arr[tar].check) DFS(tar);
    else if(!team[tar])
    {
        for(int i = tar;i!=num;i=arr[i].target) cnt++;
        cnt ++;
    }
    team[num] = true;
}
void sol()
{
    for(int i=1;i<n+1;i++)
    {
        if(arr[i].check) continue;
        DFS(i);
    }
}
int main()
{
    cin >> T;
    for(int i=0;i<T;i++)
    {
        input();
        sol();
        cout << n-cnt<<endl;
    }
}