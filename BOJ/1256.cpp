#include<bits/stdc++.h>
#define endl "\n"
#define MAX 102
#define ll long long 
using namespace std;
int n_a,n_z,K;
double mat[MAX][MAX];
vector<char> v;

void make()
{
    for(int i=0;i<MAX;i++)
    {
        mat[i][0]=1;
    }
    mat[0][1] = 1;  

    for(int i=1;i<MAX;i++)
    {
        for(int j=1;j<i+2;j++)
        {   
            mat[i][j] = (mat[i-1][j] +mat[i-1][j-1]);
            if(mat[i][j]<0) cout << "this:" << mat[i][j] << endl; // 오버플로우 나서 0보다 작아지면 출력
        }
    }
}


int main()
{
    cin >>n_a >> n_z >> K;


}