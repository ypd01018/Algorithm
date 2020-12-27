#include<iostream>
#define endl "\n"
#include<list>
using namespace std;

int n,m;

void nm(int* arr,int* issued, int k);

int main()
{
    cin >> n >> m;
    int arr[10], issued[10];
    for( int i = 0 ; i < 10 ; i++)
    {
        arr[i]=issued[i]=0;
    }
    nm(arr,issued,0);


    

}

void nm(int* arr,int* issued, int k)
{
    if(k==m)
    {
        for(int i=0;i< m ;i++) cout << arr[i] + 1 << " ";
        cout << endl;
        return;
    }

    for( int i = 0 ; i < n ; i++)
    {
        if(!issued[i])
        {
            arr[k] = i;
            issued[i] = 1;
            nm(arr, issued, k+1);
            issued[i] = 0 ;
        }
    }
}
