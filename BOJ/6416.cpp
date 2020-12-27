#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n_case=0;
    while(1)
    {
        n_case++;
        map<int,int> mp,mp_2;//하나만 쓰는거임 이거저거 시도하다가 여러개 만들고 안지운거
        map<int,vector<int>> tree;//이것도 안씀
        int n_node=0,cnt=0;
        while(1)
        {
            int par,child;
            cin >> par >> child;
            if(par==0 && child==0) break;
            if(par ==-1 && child ==-1) exit(0);
            cnt++;//간선 개수
            tree[par].push_back(child);
            mp_2[par];
            mp_2[child]++;//부모 갯수 근데 이거 안해도 되나바 지금 켜놓은 블로그 부모 개수 안세고 간선 개수만 세던데
            if(!mp[par])//중복확인인데 이게 사실 안해도됨
            {
                mp[par]=1;
                n_node++;
            }
            if(!mp[child])//이것도 안해도됨 어차피 map 쓰면 키값은 중복 허용 안함
            {
                mp[child]=1;
                n_node++;
            }
        }//그럼 노드 개수는 map.size()
        map<int,int>::iterator iter;
        int zero=0;//부모가 0인거의 갯수
        bool flag=true;
        for(iter=mp_2.begin();iter!=mp_2.end();iter++)//노드 전부 순회
        {
            //cout << "node:" <<iter->first << " n_par:" << iter->second << endl;
            if(iter->second==0) zero++;//iter -> second 는 부모의 갯수, 부모의 갯수가 0인애 몇개인지 세려고
            if(iter->second >1 || zero >1 )
            {
                //cout << "Case "<<n_case<<" is not a tree.";
                flag = false;
                break;
            }
        }
        //if(flag) cout << "Case "<<n_case<<" is a tree.";
        //cout << "n_node:" << n_node << "  cnt:" << cnt << endl;
        if(cnt==0 ||( mp.size() - cnt == 1 && flag && zero !=0)) cout << "Case "<<n_case<<" is a tree.";
        else cout << "Case "<<n_case<<" is not a tree.";
        cout << endl;
    }
}