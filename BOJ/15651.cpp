#include<iostream>
#define endl "\n"
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k=0;
void nm();
int input[10]={0}, arr[10] = {0};
int main()
{
    cin >> n >> m;

    nm();
}

void nm()
{
    if(k == m)
    {
        for(int i=0;i<m;i++) cout << arr[i] + 1<< " ";
        cout << endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        arr[k] = i;
        k++;
        nm();
        k--;
    }
}