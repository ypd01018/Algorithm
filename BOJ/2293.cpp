#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,k,arr[103];
long long mx[2][10'005];
void test()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            cout << mx[i][j]<<" ";
        }
        cout << endl;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n>> k;
    for(int i=0;i<n;i++) 
    {
        cin >> arr[i];
        //
    }
    //mx[0][arr[0]]=1;
    mx[0][0]++;
    for(int i=0;i<=k;i=i+arr[0]) mx[0][i]=1;
    
    for(int i=1;i<n;i++)
    {
        int num = i%2,num_prev = (i+1)%2;
        for(int j=0;j<=k;j++)
        {
            if(j<arr[i])
            {
                mx[num][j]=mx[num_prev][j];
                continue;
            }
            mx[num][j] = mx[num_prev][j] + mx[num][j-arr[i]];

        }
    }

    cout << mx[(n-1)%2][k];

}