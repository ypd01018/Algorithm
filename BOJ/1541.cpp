#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
string a;
int total,tmp,val;
bool flag=true;
int main()
{
    cin >> a;
    for(int i=0;i<=a.size();i++)
    {
        if(i==a.size() || a[i]=='-')
        {
            tmp += val;
            if(flag) total+= tmp;
            else total -= tmp;
            flag = false;
            tmp=val=0;
        }
        else if(a[i]=='+')
        {
            tmp += val;
            val=0;
        }
        else
        {
            val *=10;
            val += a[i]-'0';
        }
        //cout << "total:" << total << " tmp:" << tmp << " val:" << val << endl;
    }
    cout << total;
}