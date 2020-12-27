#include<iostream>
#define endl "\n"
#include<queue>
using namespace std;

int T,ary_size,a;
deque<char> dq;

void sol();
int main()
{
    cin >> T;
    for(int i=0;i<T;i++)
    {
        while(dq.empty()!=1) dq.pop_back();
        sol();
    }

}

void sol()
{
    int temp=0,flag=true, R_flag=false;
    string cmd,ary;
    cin >> cmd;
    cin >> ary_size;
    cin >> ary;
    char trash;
    for(auto i : ary)
    {
        if( (i > 47) && (i < 58) )
        {
            temp=temp*10;
            temp=temp+i-48;
        }
        else
        {
            if(temp!=0)
            {
                dq.push_back(temp);
            }
            temp=0;
        }
    }
    for(auto i : cmd)
    {
        switch (i)
        {
            case 'R':
                R_flag = !R_flag;
                break;
            case 'D':
                if(dq.empty()==1) flag=false;
                else
                {
                    switch (R_flag)
                    {
                        case false :
                            dq.pop_front();
                            break;
                        case true :
                            dq.pop_back();
                            break;
                        default:
                            break;
                    }
                }
                break;  
            default:
                break;              
        }
    }
    if(flag == false) cout << "error" << endl;
    else
    {
        cout << "[";
        switch (R_flag)
        {
            case false :
                while(dq.empty()!=1)
                {
                    temp= dq.front();
                    cout << temp;
                    dq.pop_front();
                    if(dq.empty()!=1) cout << ",";
                }
                break;
            case true :
                while(dq.empty()!=1)
                {
                    temp= dq.back();
                    cout << temp;
                    dq.pop_back();
                    if(dq.empty()!=1) cout << ",";
                }
                break;
            default :
                break;
        }
        cout << "]"<<endl;

    }


}