#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,arr[102],cal[4],mx=INT_MIN, mn=INT_MAX;
string sign[4] = {"+","-","*","/"};
string want_calc;
vector<string> v;
//+ - * /
int calc()
{
    // cout << "val:";
    // for(int i=0;i<v.size();i++) cout << v[i] << ' '; cout << endl;
    int i=0;
    vector<string> v2;
    while(i<v.size())
    {
        if(v[i]!="*" && v[i]!="/")
        {
            v2.push_back(v[i]);
        }
        else
        {
            string want = v[i];
            int a = atoi(v2.back().c_str()); v2.pop_back();
            int b = atoi(v[++i].c_str());
            int c;
            if(want == "*") c= a*b;
            else c = a/b;
            v2.push_back(to_string(c));
        }
        i++;
    }
    int ret = atoi(v2[0].c_str());
    for(int i=1;i<v2.size();i+=2)
    {
        if(v2[i]=="+") ret += atoi(v2[i+1].c_str());
        else ret -= atoi(v2[i+1].c_str());
    }
    return ret;
}
void go(int a)
{
    
    v.push_back(to_string(arr[a]));
    if(a==N-1)
    {
        int ret = calc();
        mn =min(mn,ret);
        mx =max(mx,ret);
        v.pop_back();
        return;
    }

    for(int i=0;i<4;i++)
    {
        if(cal[i]>0)
        {
            cal[i]--;
            v.push_back(sign[i]);
            go(a+1);
            cal[i]++;
            v.pop_back();
        }
    }
    v.pop_back();
}
int main()
{
    cin >> N;
    for(int i=0;i<N;i++)cin >> arr[i];
    for(int i=0;i<4;i++) cin >> cal[i];
    go(0);
    cout << mx << endl << mn;
    
}