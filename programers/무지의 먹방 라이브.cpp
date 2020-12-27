#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
vector<pair<int,int> > v;
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second<b.second) return true;
    else return false;
}

int solution(vector<int> food_times, long long k) 
{
    for(int i=0;i<food_times.size();i++) v.push_back({food_times[i],i});    
    sort(v.begin(),v.end());
    ll tmp=0;
    ll minu=0;
    ll n;
    bool flag = true;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].first-minu==0) continue;
        if(k<=tmp +(v.size()-1-i)*((v[i].first-minu)-1)+v[i].first-minu)
        {
            n = v.size()-i;
            flag = false;
            break;
        }
        tmp += (v.size()-1-i)*((v[i].first-minu)-1)+v[i].first-minu; 
        v[i].first -= minu;
        minu += v[i].first - 1; 
        v[i].first=0;
    }
    if(flag) return -1;
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++) cout << v[i].first << ' '; cout << endl;
    cout << k << endl;
    k -= tmp;
    cout << k <<"   "<< n << endl;

    if(n) k %=n;
    cout << k << endl;
    for(int i=0;i<v.size();i++)
    {
        if(!v[i].first) continue;
        k--;
        if(k<=0)
        for(int j=i+1;j<v.size();j++)
        {
            if(v[j].first) return j+1;
        }
    }
    return -1;
}

int main()
{
    // vector<int> food_times = {3,1,1,1,2,4,3}; 
    // long long k=12;
    vector<int> food_times = {4,3,5,6,2}; 
    long long k=7;
    cout << solution(food_times,k);
}