#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define NMAX 100001
#define KMAX 17 // 2^17 = 131072
int N,M;
vector <int> adj[NMAX], adjv[NMAX];
int depth[NMAX];
int par[KMAX+1][NMAX];
int DMIN[KMAX+1][NMAX], DMAX[KMAX+1][NMAX];

int min(int a, int b){return (a<b)?a:b;}
int max(int a, int b){return (a>b)?a:b;}

int main()
{
    
    scanf("%d",&N);
    for(int i=0;i<=N;i++)
    {
        adj[i].clear();
        adjv[i].clear();
        depth[i]=-1;
        for(int k=0;k<=KMAX;k++)
        {
            DMIN[k][i] = 1000001;
            DMAX[k][i] = 0;
            par[k][i] = 0;
        }
    }
    for(int i=0,f,t,l;i<N-1;i++) 
    {
        scanf("%d %d %d",&f,&t,&l);
        adj[f].push_back(t);
        adjv[f].push_back(l);
        adj[t].push_back(f);
        adjv[t].push_back(l);
    }

    // 1번 노드를 root로 하는 트리 만들기(BFS 방식) 
    // 어떤 노드를 root로 잡아도 풀이에 지장이 없음 => 주어지는 그래프가 Tree이기 때문에 
    queue <int> que;
    que.push(1);
    depth[1]=0; // root의 depth는 0 
    par[0][1]=1; // root의 부모는 root 
    while(!que.empty())
    {
        int node = que.front();
        que.pop();

        int sz = adj[node].size();
        for(int i=0;i<sz;i++)
        {
            int nnode = adj[node][i];
            int len = adjv[node][i];

            if(depth[nnode] == -1) // 아직 방문하지 않은 노드이면  
            {
                depth[nnode] = depth[node]+1; // depth 정보 갱신 
                par[0][nnode] = node; // 한단계 위 부모 정보 갱신 
                DMAX[0][nnode] = len; // 한단계 위까지의 가장 긴 도로 정보 갱신 
                DMIN[0][nnode] = len; // 한단계 위까지의 가장 짧은 도로 정보 갱신 
                que.push(nnode);
            }
        }
    }

    for(int k=1;k<=KMAX;k++)
    {
        for(int n=1;n<=N;n++)
        {
            // n번 노드의 2^k 단계 위의 부모는 
            // n번 노드의 2^(k-1) 단계 위의 있는 노드의 2^(k-1) 단계 위에 있는 노드이다. 
            par[k][n] = par[k-1][par[k-1][n]];

            // n번 노드부터 2^k 단계 위의 부모노드까지중 가장 긴 도로는 아래 두 도로중 긴 도로이다. 
            // 1. n번 노드부터 n번 노드의  2^(k-1) 단계 위의 부모노드 사이에서 가장 긴 도로
            // 2. n번 노드의  2^(k-1) 단계 위의 부모노드부터 n번 노드의 2^(k-1) 단계 위의 부모노드있는 노드의 2^(k-1) 위에 있는 부모노드 사이에서 가장 긴 도로 
            DMAX[k][n] = max(DMAX[k-1][n],DMAX[k-1][par[k-1][n]]);

            // n번 노드부터 2^k 단계 위의 부모노드까지중 가장 짧은 도로는 아래 두 도로중 짧은 도로이다. 
            // 1. n번 노드부터 n번 노드의  2^(k-1) 단계 위의 부모노드 사이에서 가장 짧은 도로
            // 2. n번 노드의  2^(k-1) 단계 위의 부모노드부터 n번 노드의 2^(k-1) 단계 위의 부모노드있는 노드의 2^(k-1) 위에 있는 부모노드 사이에서 가장 짧은 도로 
            DMIN[k][n] = min(DMIN[k-1][n],DMIN[k-1][par[k-1][n]]);
        }

    }

    // M개의 질문의 답을 LCA를 찾으며 구한다. 
    scanf("%d",&M);
    for(int i=0,a,b;i<M;i++)
    {
        scanf("%d %d",&a,&b);
        int minv = 1000001, maxv = -1;

        // 두 도시의 depth가 서로 다를 경우 depth를 맞춰 준다.
        // 맞추면서 지나온 도로중 가장 긴 도로와 가장 짧은 도로 갱신 
        if(depth[a] > depth[b])
        {
            for(int k=KMAX;k>=0;k--)
            {
                while(a!=b && depth[par[k][a]] >= depth[b]) 
                {
                    minv = min(minv,DMIN[k][a]);
                    maxv = max(maxv,DMAX[k][a]);
                    a = par[k][a];
                }
            }
        }
        else if(depth[a] < depth[b])
        {
            for(int k=KMAX;k>=0;k--)
            {
                while(a!=b && depth[par[k][b]] >= depth[a])
                {
                    minv = min(minv,DMIN[k][b]);
                    maxv = max(maxv,DMAX[k][b]);
                    b = par[k][b];
                }
            }
        }

        // 두 도시가 동일하지 않다면 LCA를 찾아 간다.
        // LCA를 찾아가면서 지나온 도로중 가장 긴 도로와 가장 짧은 도로 갱신 
        for(int k=KMAX;k>=0 && a!=b ;k--)
        {
            while(a!=b && par[k][a] != par[k][b])
            {

                minv = min(minv,min(DMIN[k][a],DMIN[k][b]));
                maxv = max(maxv,max(DMAX[k][a],DMAX[k][b]));
                a = par[k][a];
                b = par[k][b];
            }
        }

        if(a!=b) // 두 도시가 동일하지 않다면 LCA는 두 도시의 부모 도시 
        {
            minv = min(minv,min(DMIN[0][a],DMIN[0][b]));
            maxv = max(maxv,max(DMAX[0][a],DMAX[0][b]));
        }
        printf("%d %d\n",minv,maxv);
    }

}