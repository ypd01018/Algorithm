#include<bits/stdc++.h>
#define endl "\n"

using namespace std;
int K,mx;
string N;
queue<pair<string,int>> q;
bool check[100'000'500];
//map<int,bool> check;
 

void BFS()
{
    int k_check=0;
    while(!q.empty())
    {
        int n_k;string num=""; tie(num,n_k) = q.front();
        if(n_k>K+1) break;

        if(k_check!=n_k)
        {
            k_check++;
            memset(check,0,sizeof(check));
           //check.clear();
        }

        if(n_k==K)
        {
            mx =max(mx,atoi(num.c_str()));
            if(!q.empty()) q.pop();
            continue;
        }

        if(!q.empty()) q.pop();
        string tmp="";
        tmp = num;
        for(int i=0;i<tmp.size()-1;i++)
        {
            for(int j=i+1;j<tmp.size();j++)
            {
                if((i==0 && tmp[j]=='0')) continue;
                //cout <<"num:"<<tmp<< " n_k:"<<n_k<< " 1:" << tmp[i] << "  2:" << tmp[j]<<endl;
                swap(tmp[i],tmp[j]);
                int num_ = atoi(tmp.c_str());
                //cout << "num_:" << num_<<endl;
                if(!check[num_])
                {
                    check[num_]=1;
                    q.push({tmp,n_k+1});
                }
            }
        }
    }
    //cout << k_check<<endl;
    if(k_check!=K) 
    {
        cout <<"-1";
        exit(0);
    }
    else cout << mx;

}
int main()
{
    cin >> N >> K;
    q.push({N,0});
    BFS();
    //cout << mx;
    
}