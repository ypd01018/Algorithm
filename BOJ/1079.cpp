#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,arr[20],mat[20][20],cnt,mx,turn,eunjin;
bool die[20];
void day()
{
    int mx_val=0,die_people;
    for(int i=0;i<N;i++)
    {
        if(die[i]) continue;
        if(arr[i]>mx_val)
        {
            die_people = i;
            mx_val = arr[i];
        }
    }
    die[die_people]=true;
    cnt--;
}
void go()
{
    int cnt_pre_orign = cnt; bool die_pre_origin[20]; memcpy(die_pre_origin,die,sizeof(die));
    if(cnt%2) day();
    if(die[eunjin] || (!die[eunjin]&&cnt==1))
    {
        mx = max(turn,mx); memcpy(die,die_pre_origin,sizeof(die));
        cnt=cnt_pre_orign;
        return;
    }
    turn++;
    int origin[20][20],arr_origin[20],cnt_origin; bool die_origin[20]; 
    cnt_origin = cnt; memcpy(die_origin,die,sizeof(die)); memcpy(origin,mat,sizeof(mat)); memcpy(arr_origin,arr,sizeof(arr));
    for(int i=0;i<N;i++)
    {
        if(die[i] || i==eunjin) continue;
        die[i]=true; cnt--;
        for(int j=0;j<N;j++) arr[j] += mat[i][j];
        go();
        cnt=cnt_origin; memcpy(die,die_origin,sizeof(die)); memcpy(mat,origin,sizeof(mat)); memcpy(arr,arr_origin,sizeof(arr));
    }
    turn--;
    memcpy(die,die_pre_origin,sizeof(die)); cnt = cnt_pre_orign;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N; cnt = N;
    for(int i=0;i<N;i++) cin >> arr[i];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> mat[i][j];
        }
    }
    cin >> eunjin;
    go();
    cout << mx;
}