#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,M,arr[10],non[10],k,ans[10];
bool visited[10];
void nm()
{
    if(k==M)
    {
        for(int i=0;i<k;i++)
        {
            cout << ans[i] <<' ';
        }
        cout << endl;
        return;
    }

    for(int i=0;i<N;i++)
    {
        bool flag =false;
        if(!visited[i] && !non[i])
        {
            visited[i]=1;
            ans[k]=arr[i];
            if(non[i+1]==1)
            {
                non[i+1]=0;
                flag = true;
            }
            k++;
            nm();
            if(flag) non[i+1]=1;
            visited[i]=0;
            k--;
            
        }
    }
    
}
int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+N);
    
    for(int i=1;i<N;i++)
    {
        if(arr[i]==arr[i-1]) non[i]=1;
    }

    nm();
}