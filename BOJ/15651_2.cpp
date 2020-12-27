#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int arr[10],issued[10];
int N,M;
void func(int k)
{
    if(k==M)
    {
        for(int i=0;i<M;i++)
        {
            cout << arr[i]+1 << " ";
        }
        cout << endl;
        return;
    }

    for(int i=0;i<N;i++)
    {
        {
            arr[k]=i;
            func(k+1);
            
        }
    }

}
int main()
{
    
    cin >> N >> M;
    func(0);
}