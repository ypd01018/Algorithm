#include<bits/stdc++.h>
#define N 0
#define S 1
using namespace std;
deque<int> dq[4];
int k;
pair<bool,int> rotate_true[4];
void rotate(int num,int direct)
{
    if(direct == -1)
    {
        int temp = dq[num].front();
        dq[num].pop_front();
        dq[num].push_back(temp);
    }
    else
    {
        int temp = dq[num].back();
        dq[num].pop_back();
        dq[num].push_front(temp);
    }
    
}


bool left_check(int gear) 
{

    if(gear!=0 && *(dq[gear-1].begin()+2) != *(dq[gear].begin()+6))
    {
        return true;
    }
    return false;
}
bool right_check(int gear)
{
    deque<int>::iterator it = dq[gear].begin();
    for(int i = 0 ; i < 8 ; i++)
    {
        it++;
    }
    it = dq[gear+1].begin();
    for(int i = 0 ; i < 8 ; i++)
    {
        it++;
    }
    if(gear!=3 && *(dq[gear].begin()+2)!=*(dq[gear+1].begin()+6))
    {
        return true;
    }
    return false;
}
int main()
{
    string input;
    for(int  i=0;i<4;i++)
    {
        cin >> input;
        for(int j=0;j<8;j++)
        {
            int tmp = input[j] - 48;
            dq[i].push_back(tmp);
        }   
    }

    deque<int>::iterator iter;


    cin >>k;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<4;j++) 
        {
            rotate_true[j].first=false;
        }
        int gear_num,direct,tmp_dir;
        cin >> gear_num >>direct;
        gear_num--;


        tmp_dir = direct;
        for(int k=gear_num;k>0;k--)//왼쪽으로 확장
        {
            if(!left_check(k)) break; //회전 안하는게 있으면 종료
            tmp_dir*=-1;
            rotate_true[k-1].second = tmp_dir;
            rotate_true[k-1].first=true; 
        }


        tmp_dir = direct;
        for(int k=gear_num;k<3;k++)//오른쪽으로 확장
        {
            if(!right_check(k)) break; // 회전 안하는게 있으면 종료
            tmp_dir*=-1;
            rotate_true[k+1].second=tmp_dir;
            rotate_true[k+1].first=true; 
        }

        rotate(gear_num,direct); // 최초 입력 톱니바퀴 회전
        for(int j=0;j<4;j++)
        {
            if(rotate_true[j].first) rotate(j,rotate_true[j].second);
        }
    }

    int total=0,cal=1;
    for(int i=0;i<4;i++)
    {
        if(dq[i].front())
        {
            total += cal;
        }
        cal *= 2;
    }

    cout << total;

}