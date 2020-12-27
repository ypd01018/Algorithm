#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,cnt,mx=INT_MIN,arr[100];
string input;
vector<int> v;
int calc_len(int a, int b)
{
    int tmp=input[a]-'0';
    for(int i=a+1;i<=b;i+=2)
    {
        char cmd = input[i];
        if(cmd == '+')
        {
            tmp += input[i+1]-'0';
        }
        else if(cmd == '-')
        {
            tmp -= input[i+1]-'0';
        }
        else
        {
            tmp *= input[i+1]-'0';
        }
    }
    return tmp;
}
void calc()
{
    vector<int> v_int;
    vector<char> v_c;
    int v_i=0;
    for(int i=0;i<n;i++)
    {
        if(!(i%2))
        {
            if(v_i<cnt&&arr[v_i]==i)
            {
                v_int.push_back(calc_len(arr[v_i],arr[v_i+1]));
                i=arr[v_i+1];
                v_i+=2;
            }
            else
            {
                v_int.push_back(input[i]-'0');
            }
            
        }
        else
        {
            v_c.push_back(input[i]);
        }   
    }
    int tmp = v_int[0];
    for(int i=0;i<v_c.size();i++)
    {
        char cmd = v_c[i];
        if(cmd == '+')
        {
            tmp += v_int[i+1];
        }
        else if(cmd == '-')
        {
            tmp -= v_int[i+1];
        }
        else
        {
            tmp *= v_int[i+1];
        }
    }
    // cout << "------------------------start----------------------------------"<<endl;
    // for(int i=0;i<cnt;i++) cout << arr[i] <<' '; cout << endl;
    // for(int i=0;i<v_c.size();i++)
    // {
    //     cout << v_int[i] << v_c[i] ;
    // }
    // cout << v_int[v_c.size()] << endl;
    // cout << "hap:" <<tmp<<endl;
    // cout << "------------------------e n d----------------------------------"<<endl;
    mx = max(mx,tmp);
}
void go(int a)
{
    //cout << a << endl;
    if(!(cnt%2))
    {
        calc();
    }

    for(int i=a;i+2<n;i+=2)
    {
    
        arr[cnt]=i;
        cnt++;
        arr[cnt]=i+2;
        cnt++;
        go(i+4);
        cnt--;cnt--;

    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> input;
    go(0);
    cout << mx;
    
}