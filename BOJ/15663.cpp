#include<iostream>
#define endl "\n"
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k=0;
void nm();
int input[10]={0}, arr[10] = {0};
bool issued[10] ={0},non[10] = {0};
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
        if(input[i] == input[i-1]) non[i] = 1;
    }
    nm();
}

void nm()
{
    if(k == m )
    {
        for(int i = 0 ; i < m ; i++) cout << arr[i] << " " ;
        cout << endl;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        bool flag = false;
        

        if(!issued[i] && !non[i])
        {
                issued[i] = 1;
                arr[k] = input[i];
                if(non[i+1] == 1)
                {
                    non[i+1] = 0;
                    flag = true;
                }
                k++;
                nm();
                issued[i] = 0;
                if(flag == true) non[i+1]= 1; 
                k--;
        }

    }


}