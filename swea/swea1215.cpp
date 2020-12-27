#include<iostream>
#define endl "\n"
using namespace std;

void sol();

int n;
char mat[8][8];
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << "#"<<i+1 << " ";
        sol();
        cout << endl;
    }
}
void sol()
{
    string input;
    int cnt=0;
    bool flag = true;
    char temp[8];
    cin >> n;
    for(int i=0; i<8; i++)
    {
        cin >> input;
        for(int j=0 ; j < 8 ; j++)
        {
            mat[i][j] = input[j];
        }
    }

    if(n == 1)
    {
        cout << "64";
        return;
    }

    for(int i=0; i < 8 ; i++)
    {
        for(int j=0 ; j < 9-n ; j ++)
        {
            for(int k = 0 ; k < n ; k++)
                temp[k] = mat[i][j + k]; 
            for(int k = 0 ; k < n/2 ; k++)
                if(temp[k] != temp[n-1-k]) flag = false;
            if(flag == true) cnt++;
            flag=true;

        }
    }

    for(int i=0; i < 9-n ; i++)
    {
        for(int j=0 ; j < 8 ; j ++)
        {
            for(int k = 0 ; k < n ; k++)
                temp[k] = mat[i + k][j]; 
            for(int k = 0 ; k < n/2 ; k++)
                if(temp[k] != temp[n-1-k]) flag = false;
            if(flag == true) cnt++;
            flag=true;
        }
    }


    cout << cnt;
}
