#include<iostream>
#include <unordered_map>
#include<algorithm>
#include<vector>
#define endl "\n"
using namespace std;
int N,mx_color;
pair<int,int> input[200010];
vector<pair<int,int> > color_size[200010];
int find_vol(int color, int vol)
{
    if(color_size[color].empty()) return 0;
    if(color_size[color][0].first>=vol) return 0;
    if(color_size[color][color_size[color].size()-1].first<vol) return color_size[color][color_size[color].size()-1].second;

    int lft = 0, rght = color_size[color].size()-1;
    while(lft<rght)
    {
        int mid = (lft+rght)/2;
        if(color_size[color][mid].first<vol) 
        {
            if(mid+1<color_size[color].size() && color_size[color][mid+1].first>=vol) return color_size[color][mid].second;
            lft = mid+1;
        }
        else rght = mid-1;
    }

    if(color_size[color][lft].first < vol) return color_size[color][lft].second;
    else return 0;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        int color, vol;
        cin >> color >> vol;
        input[i].first = color; input[i].second = vol;
        mx_color = max(mx_color,color);
        color_size[color].push_back({vol,vol});
    }

    for(int i=1;i<=mx_color;i++)
    {
        sort(color_size[i].begin(),color_size[i].end());
        for(int j=0;j<color_size[i].size();j++)
        {
            if(j) color_size[i][j].second+=color_size[i][j-1].second;
        }
    }

    for(int i=0;i<N;i++)
    {
        int color = input[i].first, vol = input[i].second, hap = 0;
        for(int j=1;j<=mx_color;j++)
        {
            if(color == j) continue;
            hap += find_vol(j,vol);
        }
        cout << hap << endl;
    }

    
}