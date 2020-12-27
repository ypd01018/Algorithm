#include<iostream>
#define endl "\n"

#define y first
#define x second

using namespace std;

int mat[12][12],n,tmp,mx=0,mx_2,cnt=0,arr_cnt=0,arr_2_cnt=0;

pair<int,int> arr[60],arr_2[60];
bool issued1[22] = {0}; // x+y
bool issued2[22] = {0}; // x-y+4
void chess1(int a);
void chess2(int a);

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
                    arr[arr_cnt].first = i;
                    arr[arr_cnt].second = j;
                    arr_cnt++;                
                }
                else
                {
                    arr_2[arr_2_cnt].first = i;
                    arr_2[arr_2_cnt].second = j;
                    arr_2_cnt++;                
                    
                }
                
            }
        }
    }

    chess1(0);
    cnt=0;
    chess2(0);
    cout << mx + mx_2;
}

void chess1(int a)
{

    for(int i = a ; i < arr_cnt ; i++)
    {
        if(!issued1[arr[i].x + arr[i].y] && !issued2[arr[i].x-arr[i].y+n])
        {
            issued1[arr[i].x + arr[i].y] = issued2[arr[i].x-arr[i].y+n] = 1;
            cnt++;
            if(cnt > mx) mx = cnt;

            chess1(a+1); 

            issued1[arr[i].x + arr[i].y] = issued2[arr[i].x-arr[i].y+n] = 0;
            cnt--;

        }
        if( arr_cnt - i + cnt < mx) return;
    }
}

void chess2(int a)
{

    for(int i = a ; i < arr_2_cnt ; i++)
    {
        if(!issued1[arr_2[i].x + arr_2[i].y] && !issued2[arr_2[i].x-arr_2[i].y+n])
        {
            issued1[arr_2[i].x + arr_2[i].y] = issued2[arr_2[i].x-arr_2[i].y+n] = 1;
            cnt++;
            if(cnt > mx_2) mx_2 = cnt;

            chess2(a+1); 

            issued1[arr_2[i].x + arr_2[i].y] = issued2[arr_2[i].x-arr_2[i].y+n] = 0;
            cnt--;

        }
        if( arr_2_cnt - i + cnt < mx_2) return;

    }
}