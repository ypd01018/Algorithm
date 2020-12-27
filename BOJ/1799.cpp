#include<iostream>
#define endl "\n"
#include<algorithm>
#define y first
#define x second

using namespace std;

int mat[12][12],n,tmp,mx=0,mx_2,cnt=0,arr_cnt=0,arr_2_cnt=0;

pair<int,int> arr[60][60],arr_2[60][60];
bool issued[60]={0};
bool issued1[22] = {0}; // x+y
bool issued2[22] = {0}; // x-y+4
void chess1(int a,int b);
void chess2(int a,int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            cin >> tmp;

            if(tmp == 1)
            {
                if((i+j)%2==0)
                {
                    arr[i+j][arr_cnt].y = i;
                    arr[i+j][arr_cnt].x = j;
                    arr_cnt++;                
                }
                else
                {
                    arr_2[i+j][arr_2_cnt].y = i;
                    arr_2[i+j][arr_2_cnt].x = j;
                    arr_2_cnt++;                
                    
                }
                
            }
        }
    }
    chess1(0,0);
    cnt=0;
    chess2(0,1);
    cout << mx + mx_2;
}

void chess1(int a, int b)
{
    for(int i = 0 ; i < arr_cnt ; i++)
    {
        if(!issued2[arr[b][i].x-arr[b][i].y+n+1])
        {
            issued1[arr[b][i].x + arr[b][i].y] = issued2[arr[b][i].x-arr[b][i].y+n+1] =  1;
            cnt++;
            mx = max(mx,cnt);

            chess1(0, b+2); 

            issued1[arr[b][i].x + arr[b][i].y] = issued2[arr[b][i].x-arr[b][i].y+n+1] =  0;
            cnt--;

        }
        else
        {
            if(b+2 < 2*(n-1)) chess2(0,b+2);
        }
    }
}

void chess2(int a, int b)
{

    for(int i = 0 ; i < arr_2_cnt ; i++)
    {
        if( (arr_2[b][i].x + arr_2[b][i].y)== b  && !issued2[arr_2[b][i].x-arr_2[b][i].y+n+1])
        {
            issued1[arr_2[b][i].x + arr_2[b][i].y] = issued2[arr_2[b][i].x-arr_2[b][i].y+n+1] =1;
            cnt++;
            mx_2 = max(mx_2,cnt);

            chess2(0,b+2);

            issued1[arr_2[b][i].x + arr_2[b][i].y] = issued2[arr_2[b][i].x-arr_2[b][i].y+n+1] = 0;
            cnt--;

        }
        else
        {
            if(b+2 < 2*(n-1)) chess2(0,b+2);
        }
        

    }
}