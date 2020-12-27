#include<iostream>
#define endl "\n"
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k=0;
void nm(int a);
int input[10]={0}, arr[10] = {0};
bool issued[10] = {0};
int main()
{
    cin >> n >> m;

    nm(0);
}

void nm(int a)
{
    if(k == m)
    {
        for(int i=0;i<m;i++) cout << arr[i] + 1<< " ";
        cout << endl;
        return;
    }
    for(int i=a;i<n;i++)
    {
        if(!issued[i])
        {
            arr[k] = i;
            k++;
            issued[i] = 1;
            nm(i+1);
            k--;
            issued[i] = 0;
        }
    }
}