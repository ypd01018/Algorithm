#include<iostream>
#include<list>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int N,K;
string input;
vector<string> v;
list<char> lst;
set<string> st;
bool cmp(string a,string b)
{
    return a>b;
}
void make_pw()
{
    string a="";
    list<char>::iterator iter; int j=0;
    for(iter=lst.begin();iter!=lst.end();iter++)
    {
        a.push_back(*iter);
        j++;
        if(j%(N/4)) continue;
        if(!st.count(a))
        {
            st.insert(a);
            v.push_back(a);
        }
        a="";
    }
}
int make_ten(string a)
{
    int ten =1,ans=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        int val;
        if('0'<=a[i] && a[i]<='9') val = a[i]-'0';
        else val = a[i]-'A'+10;
        ans += val*ten;
        ten *=16;
    }
    return ans;
}
void sol()
{
    v.clear(); lst.clear(); st.clear();
    cin >> N >> K >> input;
    for(int i=0;i<N;i++) lst.push_back(input[i]);
    for(int i=0;i<N/4;i++)
    {
        make_pw();
        lst.push_front(lst.back()); lst.pop_back();
    }
    sort(v.begin(),v.end(),cmp);
    cout << make_ten(v[K-1]) << endl;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case << ' ';
        sol();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}