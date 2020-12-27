#include<iostream>
#include<algorithm>
#define endl "\n"
using namespace std;
int N;
pair<int,int> arr[100'002];
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first<b.first) return true;
    else if(a.first>b.first) return false;
    else
    {
        if(a.second<b.second) return true;
        else return false;
    }
    
}
int main()
{
    ios::sync_with_stdio
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i].first >> arr[i].second;
    sort(arr,arr+N,cmp);
    for(int i=0;i<N;i++) cout << arr[i].first <<' '<< arr[i].second << endl;
}