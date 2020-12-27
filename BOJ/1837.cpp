#include<bits/stdc++.h>
#define endl "\n"
#define ll long long 
const int MAX=1e6+3;
using namespace std;
ll k,p1,p2;
bool arr[MAX];
string p;
vector<int> v;

bool bad_check(int a)
{
    int ret=0;
    for(int i=0;p[i];i++)
    {
        ret *=10;
        ret += (p[i]-'0');
        ret%=a;
    }
    return ret==0;
}
int main()
{
    cin >> p >> k;
    for(long long i=2;i<MAX;i++)
    {
        if(arr[i]==0)
        {
            v.push_back(i);
            for(int j=i+i;j<MAX;j+=i)
            {
                arr[j]=1;
            }
        }
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>=k) break;
        if(bad_check(v[i]))
        {
            cout << "BAD " << v[i];
            return 0; 
        }
        
    }

    cout << "GOOD";
    

}