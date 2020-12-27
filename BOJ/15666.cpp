#include<iostream>
#define endl "\n"
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k=0;
void nm(int a);
int input[10]={0}, arr[10] = {0};
bool non[10] = {0};
int main()
{
    int temp;
    cin >> n >> m ;
    for(int i=0;i<n ; i++)
    {
        cin >> temp;
        input[i] = temp;
    }
    sort(input,input+n);
    for(int i = 1 ; i < n ; i++)
    {
        if(input[i] == input[i-1])
        {
            for(int j=i;j<n;j++)
            {
                input[j-1] = input[j];
            }
            n--;
            i--;
        }
    }

    nm(0);
}

void nm(int a)
{
    if(k == m )
    {
        for(int i = 0 ; i < m ; i++) cout << arr[i] << " " ;
        cout << endl;
        return ;
    }
    for(int i=a;i<n;i++)
    {
        bool flag = false;
        arr[k] = input[i];
        k++;
        nm(i);
        k--;

    }


}