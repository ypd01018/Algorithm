#include<iostream>
#define endl "\n"
#include<queue>
#define link first
#define check second
#define x first
#define y second
using namespace std;

int n_com,n_input,a,b,com[200];
pair<bool,bool> arr[200][200];
queue<int> q;
int cnt = -1 ;
void bfs();
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    cin >> n_com >> n_input;

    for(int i = 0 ; i < n_com + 1 ; i++)
    {
        com[i] = false;
        for(int j = 0 ; j < n_com ; j ++)
        {
            arr[i][j].link=false;
        }
    }


    for(int i=0 ;i< n_input; i++)
    {
        cin >> a >>b;
        arr[a][b].link= true;
        arr[b][a].link= true;
    }

    com[1] = true;

    for(int i = 1 ; i< n_com + 1 ; i++)
    {
        if(arr[1][i].link == true) 
        {
            q.push(i);
        }
        if(arr[i][1].link == true) 
        {
            q.push(i);
        }
        
    }
    bfs();


    for(int i = 0 ; i< n_com + 1 ; i++)
    {
        if(com[i] == true) 
        {
            cnt ++;
        }
    }

    cout << cnt << endl;
}

void bfs()
{
    while(!q.empty())
    {  
        auto temp = q.front(); q.pop();
        com[temp] = true;
        for(int i=1 ; i< n_com+1 ; i++)
        {
            if(arr[temp][i].link == 1 && com[i] == false) 
            {
                q.push(i);
            }
            if(arr[i][temp].link == 1 && com[i] == false)
            {
                q.push(i);
            }
        }


    }   
}