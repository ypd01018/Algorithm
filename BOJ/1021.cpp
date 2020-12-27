#include<iostream>
#define endl "\n"
#include<deque>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int q_size, n,target,left_cnt,right_cnt,sol_cnt=0;
deque<int> dq;
deque<int>::iterator iter;
queue<int> q;    
vector<int> v2;

void one();
void two();
void thr();
void lft();
void rght();
int main()
{
    cin >> q_size;
    cin >> n;
    vector<int> v(q_size,0);

    for(int i=0;i<n;i++)
    {
        cin >> target;
        v[target-1]=i+1;
        v2.push_back(target);
    }

    for(auto i : v)
    {
        dq.push_back(i);
    }

//    while(v2.empty()!=1)
    for(auto i : v2)
    {
        
            left_cnt=dq.size()+1-i;
            right_cnt=i-1;
            if(left_cnt>right_cnt)
            {
                //while(dq.front()!=i)
                for(int j=0;j<right_cnt;j++)
                {
                    two();
                }
            }
            else
            {
                //while(dq.front()!=1)
                for(int j=0;j<left_cnt;j++)
                {
                    thr();
                }
            }
            one();

        
        
    }
    cout << sol_cnt;
}

void one()
{
    dq.pop_front();
    lft();
}

void two()
{
    int temp = dq.front();
    dq.pop_front();
    dq.push_back(temp);
    lft();
    sol_cnt++;
}

void thr()
{
    int temp = dq.back();
    dq.pop_back();
    dq.push_front(temp);
    rght();
    sol_cnt++;
}
void lft()
{
    for(int i=0;i<n;i++)
    {
        if(v2[i]==1) v2[i]=dq.size();
        else v2[i]=v2[i]-1;
    }
}
void rght()
{
    for(int i=0;i<n;i++)
    {
        if(v2[i]==dq.size()) v2[i]=1;
        else v2[i]=v2[i]+1;
    }
    
}