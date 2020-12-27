#include<iostream>
#define endl "\n"

using namespace std;
int n,m, arr[10] = {0}, issued[10] = {0}, k = 0;

void nm();

int main()
{
    cin >> n >> m;
    nm();

}

void nm()
{
    if(k == m )
    {
        for(int i = 0 ; i < m ; i ++) cout << arr[i]+1 << " ";
        cout << endl;
        return;
    }
    
    int temp;

    if( k == 0 ) temp = 0;
    else temp = arr[k-1];
    
    for(int i=temp; i < n ; i++)
    {
        if(arr[k-1] <= i) arr[k]=i;
        {
            k++;
            nm();
            k--;
        }
        
    }
}

