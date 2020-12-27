#include<iostream>
#include<algorithm>
#define endl "\n"
using namespace std;
int N,a[52],b[52],tot;
bool cmp(int a, int b)
{
    if(a>b) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> a[i];
    for(int i=0;i<N;i++) cin >> b[i];
    sort(a,a+N); sort(b,b+N,cmp);
    for(int i=0;i<N;i++) tot+=a[i]*b[i];
    cout <<tot;
}