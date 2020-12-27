#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,arr[1003],mx[1003],last,mx_val=1,mx_log;
void test()
{
        for(int j=0;j<N;j++)
        {
            cout << mx[j]<<'('<<arr[j]<<')' <<" ";
        }
        cout << endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];

    mx[0]=1;
    for(int i=1;i<N;i++)
    {
        mx[i]=1;        
        for(int j=i;j>-1;j--)
        {
            if(arr[j]<arr[i] && mx[j]>mx[i]-1) 
            {
                mx[i]=mx[j]+1;
            }
        }        
    }
    //test();
    cout << *max_element(mx,mx+N);
}