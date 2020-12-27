#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
bool check[100000003];
int n,k,visited[300],k_my;
int arr[300];
int ans[300],cnt;
void sol()
{
    if(k_my == k)
    {
        int tot=0;
        for(int i=k-1;i>-1;i--)
        {
            if(ans[i]<10) tot *=10;
            else tot *= 100;
            tot += ans[i];
        }
        if(!check[tot]) 
        {
            cnt++;
            check[tot]=1;
        }
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            ans[k_my] = arr[i];
            visited[i]=1;
            k_my++;
            sol();
            visited[i]=0;
            k_my--;
        }
    }
}

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    sol();
    cout << cnt;

}