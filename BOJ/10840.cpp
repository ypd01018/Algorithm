#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int mx;
string a,b;
vector<string> v_a, v_b;
void make_part(string a,vector<string> &v)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;i+j<a.size();j++)
        {
            string new_string;
            if(j)
            { 
                new_string = v.back();
                new_string.push_back(a[i+j]);
            }
            else new_string.push_back(a[i]);
            sort(new_string.begin(),new_string.end());
            v.push_back(new_string);
        }
    }
    sort(v.begin(),v.end());    
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;
    make_part(a,v_a); make_part(b,v_b);
    for(int i=0;i<v_a.size();i++)
    {
        string val = v_a[i];
        int s = 0, e = v_b.size();
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(v_b[mid]==val)
            {
                mx = max(mx,(int)val.size());
                break;
            }
            else if(v_b[mid] < val) s = mid+1;
            else e = mid-1;
        }
    }
    cout << mx;
}