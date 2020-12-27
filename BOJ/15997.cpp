#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
unordered_map<string,int> um;
double per[5][5][3],output[5];
int score[5];
double win(int a, int b)
{
    score[a]+=3;
    return per[a][b][0];
}
double draw(int a, int b)
{
    score[a]+=1; score[b]+=1;
    return per[a][b][1];
}
double lose(int a, int b)
{
    score[b]+=3;
    return per[a][b][2];
}
double comb(int a)
{
    int ret = 1;
    for(int i=2;i<=a;i++) ret*=i;
    return double(a-1)/double(ret); 
}
void DFS(int a,int b,double val)
{
    if(a==4) 
    {
        priority_queue<pair<int,int>> pq;
        for(int i=1;i<=4;i++) pq.push({score[i],i});
        vector<pair<int,int>> score_top,semi_top;
        int top_score = pq.top().first,second_score = -1;
        while(!pq.empty())
        {
            int num = pq.top().second, score_idx = pq.top().first; pq.pop();
            if(top_score == score_idx)
            {
                score_top.push_back({num,score_idx});
            }
            else if(semi_top.empty() || semi_top[0].second == score_idx)
            {
                semi_top.push_back({num,score_idx});
            }
            else break;
        }
        if(score_top.size()==1)
        {
            output[score_top[0].first] += val;
            for(int i=0;i<semi_top.size();i++) output[semi_top[i].first]+= val/semi_top.size();    
        }
        else
        {
            double val = comb(score_top.size());
            for(int i=0;i<score_top.size();i++) output[score_top[i].first] += val;
        }
        
        return;
    }
    int paste[5]; memcpy(paste,score,sizeof(score));
    int nxt_a = a,nxt_b = b+1;
    if(nxt_b==5)
    {
        nxt_a = a+1;
        nxt_b = nxt_a+1;
    }
    DFS(nxt_a,nxt_b,val*win(a,b));
    memcpy(score,paste,sizeof(score));
    
    DFS(nxt_a,nxt_b,val*draw(a,b));
    memcpy(score,paste,sizeof(score));
    
    DFS(nxt_a,nxt_b,val*lose(a,b));
    memcpy(score,paste,sizeof(score));
}
int main()
{
    for(int i=1;i<=4;i++)
    {
        string a; cin >> a;
        um[a] = i;
    }
    for(int i=0;i<5;i++)
    {
        string a_name,b_name; cin >> a_name >> b_name;
        int a = um[a_name], b = um[b_name];
        double w,d,l; cin >> w >> d >> l;
        per[a][b][0] = w; per[b][a][0] = 1- w;
        per[a][b][1] = d; per[b][a][1] = 1- d;
        per[a][b][2] = l; per[b][a][2] = 1- l;  
    }
    DFS(1,2,1);
    for(int i=1;i<=4;i++) cout <<  output[i] << ' ';
    double total = 0 ;
    for(int i=1;i<=4;i++) total += output[i];
    cout << total << endl;

}