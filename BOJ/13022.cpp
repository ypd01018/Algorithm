#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string a;
int arr[4];
int num(char a)
{
    if(a=='w') return 0;
    else if(a=='o') return 1;
    else if(a=='l') return 2;
    else return 3;
}
bool same_check(int n)
{
    for(int i=1;i<=n;i++) if(!arr[0]||arr[0]!=arr[i]) return false;
    for(int i=n+1;i<4;i++) if(arr[i]) return false;
    return true;
}
int main()
{
    char pre_alp = 'w', alp;
    cin >> a;
    for(int i=0;i<a.size();i++)
    {
        alp = a[i];
        if(alp!=pre_alp)
        {
            if(!same_check(num(pre_alp)))
            {
                cout << 0; return 0;
            }
            if(alp=='w') memset(arr,0,sizeof(arr));
        }
        arr[num(alp)]++;
        pre_alp = alp;
    }
    for(int i=0;i<4;i++)
    {
        if(arr[i] && arr[0]==arr[i]) continue;
        cout << 0; return 0;
    }
    cout << 1;
}
