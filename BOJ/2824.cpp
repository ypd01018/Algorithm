#include<bits/stdc++.h>
#define endl "\n"
#define ll long long 
using namespace std;
int MOD = 1000000000;
int n,num;
ll answer=1;
vector<int> A,B;
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        A.push_back(num);
    }
    int mx_idx = A.size();
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        B.push_back(num);
        for(int j=0;j<mx_idx;j++)
        {
            if(B[i]==1) break;
            if(A[j]==1) continue;
            int d = gcd(max(B[i],A[j]),min(B[i],A[j]));
            answer = answer * d;
            A[j] /= d;
            B[i] /=d;

            if(answer > MOD)
            {
                answer = answer%MOD + MOD;
            }
        }
    }
    //string ans = NULL;
    string ans = to_string(answer);
    if(answer > MOD)
    {
        ans = ans.substr(1,ans.length());
    }
    cout << ans;

}