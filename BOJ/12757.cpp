#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
map<int,int> m;
int N,M,K,key,value;
void query_1()
{
    cin >> key >> value;
    if(m[key]) return;
    m[key] = value;
//     map<int,int>::iterator iter = m.begin();
//     for(iter;iter!=m.end();iter++) cout <<'('<<iter->first << ',' << iter->second << ')' << ' ';cout << endl;
 }
int get_key(int key)
{
    map<int,int>::iterator iter = m.find(key);
    if(iter!=m.end()) return iter->first;
    iter = m.lower_bound(key);
    if(iter == m.begin())
    {
        if(abs(key - iter->first) > K) return -1;
        return iter->first;
    }
    else if(iter == m.end())
    {
        iter--;
        if(abs(key - iter->first) > K) return -1;
        return iter -> first; 
    }
    else
    {
        int key_1 = iter->first, value_1 = iter->second;
        iter--;
        int key_2 = iter->first, value_2 = iter->second;
        int dis_1 = abs(key_1 - key), dis_2 = abs(key_2-key);
        if(dis_1<=K && dis_2 <=K)
        {
            if(dis_1<dis_2) return key_1;
            else if(dis_1>dis_2) return key_2;
            else return -1;
        }
        else if(dis_1<=K) return key_1;
        else if(dis_2<=K) return key_2;
        else return -1;
    }
}
void query_2()
{
    cin >> key >> value;
    int new_key = get_key(key);
    if(new_key<0) return;
    m[new_key] = value;
    // map<int,int>::iterator iter = m.begin();
    // for(iter;iter!=m.end();iter++) cout <<'('<<iter->first << ',' << iter->second << ')' << ' ';cout << endl;

}
int query_3()
{
    // map<int,int>::iterator iter_ = m.begin();
    // for(iter_;iter_!=m.end();iter_++) cout <<'('<<iter_->first << ',' << iter_->second << ')' << ' ';cout << endl;
    // cout << "query_3:";
    cin >> key;
    map<int,int>::iterator iter = m.find(key);
    if(iter!=m.end()) return iter->second;
    iter = m.lower_bound(key);
    if(iter == m.begin())
    {
        if(abs(key - iter->first) > K) return -1;
        return iter->second;
    }
    else if(iter == m.end())
    {
        iter--;
        if(abs(key - iter->first) > K) return -1;
        return iter -> second; 
    }
    else
    {
        int key_1 = iter->first, value_1 = iter->second;
        iter--;
        int key_2 = iter->first, value_2 = iter->second;
        int dis_1 = abs(key_1 - key), dis_2 = abs(key_2-key);
        if(dis_1<=K && dis_2 <=K)
        {
            if(dis_1<dis_2) return value_1;
            else if(dis_1>dis_2) return value_2;
            else return -2;
        }
        else if(dis_1<=K) return value_1;
        else if(dis_2<=K) return value_2;
        else return -1;
    }
    
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0;i<N;i++)
    {
        cin >> key >> value;
        m[key] = value;
    }
    for(int i=0;i<M;i++)
    {
        int a; cin >> a;
        if(a==1) query_1();
        else if(a==2) query_2();
        else 
        {
            int val = query_3();
            if(val<-1) cout << "?\n";
            else cout << val << endl;
        }
    }
}