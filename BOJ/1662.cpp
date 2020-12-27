#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int go(string a)
{
    string ret ="",val="",back="";
    int ret_n=0,val_n=0,back_n=0; 
    int i=0,n=0,mul;
    for(i;i<a.size();i++)
    {
        if(a[i]=='(') 
        {
            n++;
            mul = a[i-1]-'0';
            ret_n--;
            break;
        }
        ret_n++;
    }
    for(i+=1;i<a.size();i++)
    {
        val.push_back(a[i]);
        if(a[i]=='(') n++;
        else if(a[i]==')') n--;
        if(!n) break;
    }
    for(i+=1;i<a.size();i++) back.push_back(a[i]);
    if(back!="") back_n = go(back);
    
    if(val!="")
    {
        val.pop_back();
        val_n = go(val);
        ret_n+=mul*val_n;
    }
    ret_n+=back_n;
    return ret_n;

}
int main()
{
    string a; cin >> a;
    cout << go(a);
}