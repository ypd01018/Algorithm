    #include<bits/stdc++.h>
    #define endl "\n"
    using namespace std;
    int N,K,visited_0[100'002],visited_1[100'002],sec_0[100'002],sec_1[100'002];
    int mx_sec = INT_MAX;
    queue<pair<int,int>> q;
    void go(int origin,int location,int sec)
    {
        if(location<0 || location>100'000) return;

        if((sec+1)%2==0) 
        {
            //if(!visited_0[location]) q.push({location,sec+1});
            if(sec_0[location]<sec+1)
            {
                q.push({location,sec+1});
                sec_0[location]=sec+1;
                visited_0[location]=0;
            }
            visited_0[location]+=visited_1[origin];
            //cout << "sec:"<<sec << "  location:"<<location <<"  "<< visited_0[location] << endl;
        }
        else
        {
            //if(!visited_1[location]) q.push({location,sec+1});
            if(sec_1[location]<sec+1)
            {
                q.push({location,sec+1});
                sec_1[location]=sec+1;
                visited_1[location]=0;
            }
            visited_1[location]+=visited_0[origin];
            //cout << "sec:"<<sec << "  location:"<<location <<"  "<< visited_1[location] << endl;
        }
    }
    int main()
    {
        ios::sync_with_stdio(0);cin.tie(0);
        cin >> N >> K;
        q.push({N,0});
        //memset(sec_0,-1,sizeof(sec_0)); memset(sec_1,-1,sizeof(sec_1)); 
        visited_0[N]=1; sec_0[N]=0;
        int cache=0;
        while(!q.empty())
        {
            int location=q.front().first, sec=q.front().second; q.pop();
            if(sec>mx_sec) break;
            // if(cache<sec)
            // { 
            //     if(sec%2==0) memset(visited_1,0,sizeof(visited_1));
            //     else  memset(visited_0,0,sizeof(visited_0));
            //     cache= sec;
            // }
            if(location == K) mx_sec=sec;
            
            go(location,location-1,sec);
            if(location>=K) continue; 
            go(location,location+1,sec); go(location,location*2,sec);
        }

        cout <<mx_sec<<endl;
        if(mx_sec%2==0) cout<<visited_0[K];
        else cout << visited_1[K];
    }