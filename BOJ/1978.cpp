#include<iostream>
#define endl "\n"
#include<queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    queue<int> q;
    int temp,size,arr[1001],cnt=0;
    for(int i=0;i<1001;i++) arr[i]=true;
    cin >> size;
    
    for(int i=0;i<size;i++)
    {
        cin >> temp;
        q.push(temp);
    
    }
    arr[1]= false;

    for(int i=2 ; i<1001;i++)
    {
        if(arr[i]==true)
            for(int j=i+1;j<1001;j++)
            {
                if(j%i==0) 
                {
                    arr[j]=false;
                }
            }
    }

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(arr[temp] == true) cnt++;
    }
    cout << cnt;
}