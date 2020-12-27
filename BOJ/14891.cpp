#include<bits/stdc++.h>
#define N 0
#define S 1
using namespace std;
deque<int> dq[4];
int k;
void rotate(int num,int direct)
{
    if(direct == -1)
    {
        int temp = dq[num].front();
        dq[num].push_back(temp);
    }
    else
    {
        int temp = dq[num].back();
        dq[num].push_front(temp);
    }
    
}
int left_gear(int a)
{
    if(a == 0 ) return 3;
    else return a-1;
}
int right_gear(int a)
{
    if(a == 3) return 0;
    else return a+1;
}
void magnetic_rotate(int gear,int direct)
{
    int left =left_gear(gear), right = right_gear(gear); 

}
int main()
{
    for(int  i=0;i<4;i++)
    {
        for(int j=0;j<8;j++)
        {
            int tmp;
            cin >> tmp;
            scanf("%1d",&tmp);
            dq[i].push_back(tmp);
        }   
    }

    cin >>k;
    for(int i=0;i<k;i++)
    {
        int gear_num,direct;
        cin >> gear_num >>direct;
        
        rotate(gear_num,direct);



    }
}