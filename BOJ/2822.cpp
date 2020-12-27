#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
pair<int,int> arr[8];
bool cmp1(pair<int,int> a, pair<int,int> b)
{
    if(a.first>b.first) return true;
    else return false;
}
bool cmp2(pair<int,int> a, pair<int,int> b)
{
    if(a.second<b.second) return true;
    else return false;
}
int main()
{
    for(int i=0;i<8;i++)
    {
        int a; cin >> a;
        arr[i]={a,i+1};
    }
    sort(arr,arr+8,cmp1);
    sort(arr,arr+5,cmp2);
    int ans=0;
    for(int i=0;i<5;i++) ans += arr[i].first;
    cout << ans<<endl;
    for(int i=0;i<5;i++) cout << arr[i].second << ' ';

}