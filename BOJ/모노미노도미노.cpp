#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N,t,x,y,score;
pair<int,int> green[6][4],blue[6][4];
void print_test();
void print_sec()
{
    cout << "\n--------green--------\n";
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout << green[i][j].second << ' ';
        }cout << endl;
    }
    cout << "--------blue--------\n";
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout << blue[i][j].second << ' ';
        }cout << endl;
    }
    cout << endl;
}
void new_down(bool green_mat,int sec)
{
    pair<int,int> (*mat)[4];int my_x;
    if(green_mat) 
    {
        mat = green; 
        my_x = x;
    }
    else
    {
        mat = blue;
        my_x = y;
    }
    int my_y=0;
    
    if(t==1) 
    {
        for(my_y;my_y<7;my_y++) {if(my_y==6 || mat[my_y][my_x].first) break;}
        my_y--;
        mat[my_y][my_x]={1,sec}; 
    }
    else if(t==3)
    {
        if(green_mat) 
        {
            for(my_y;my_y<7;my_y++) if(my_y==6 ||mat[my_y][my_x].first) break;
            my_y--;
            mat[my_y][my_x]=mat[my_y-1][my_x]={2,sec};
        }
        else 
        {
            for(my_y;my_y<7;my_y++) if(my_y==6 ||mat[my_y][my_x].first || mat[my_y][my_x+1].first) break;
            my_y--;
            mat[my_y][my_x]=mat[my_y][my_x+1]={3,sec};
        }
    }
    else
    {
        if(green_mat) 
        {
            for(my_y;my_y<7;my_y++) if(my_y==6 ||mat[my_y][my_x].first || mat[my_y][my_x+1].first) break;
            my_y--;
            mat[my_y][my_x]=mat[my_y][my_x+1]={3,sec}; 
        }
        else 
        {
            for(my_y;my_y<7;my_y++) if(my_y==6 ||mat[my_y][my_x].first) break;
            my_y--;
            mat[my_y][my_x]=mat[my_y-1][my_x]={2,sec};
        }
    }

}
int get_score(bool green_mat)
{
    pair<int,int> (*mat)[4];
    if(green_mat) mat = green;
    else mat = blue;
    int ret = 0;
    for(int i=2;i<6;i++)
    {
        bool flag = true;
        for(int j=0;j<4;j++)
        {
            if(mat[i][j].first) continue;
            flag = false; 
            break;
        }
        if(!flag) continue;
        for(int j=0;j<4;j++) mat[i][j]={0,0};
        ret++;
    }
    return ret;
}
void blcok_down(int t_,int y,int x,bool green_mat)
{
    pair<int,int> (*mat)[4];
    if(green_mat) mat = green;
    else mat = blue;
    int i,new_x=x;
    if(t_==3 && (x==3||mat[y][x+1]!=mat[y][x])) return;
    if(t_==3) new_x = x+1;
    for(i=1;y+i<6;i++)
    {
        if(y+i==6 || mat[y+i][x].first || mat[y+i][new_x].first) break;
    }
    pair<int,int> val = mat[y][x];
    mat[y][x]={0,0};
    mat[y+i-1][x]=val;
    if(t_==3)
    {
        mat[y][x+1]={0,0};
        mat[y+i-1][x+1]=val;
    }
    else if(t_==2)
    {
        if(val.second != mat[y-1][x].second) return;
        mat[y-1][x]={0,0};
        mat[y+i-2][x]=val;
    }
}
void go_down(bool green_mat)
{
    pair<int,int> (*mat)[4];
    if(green_mat)mat = green;
    else mat = blue;

    for(int i=4;i>=0;i--)
    {
        for(int j=0;j<4;j++)
        {
            if(mat[i][j].first) blcok_down(mat[i][j].first,i,j,green_mat);
        }
    }
}
void check_line(bool green_mat)
{
    pair<int,int> (*mat)[4];
    if(green_mat) mat = green;
    else mat = blue;
    int cnt=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(!mat[i][j].first) continue;
            cnt++; break;
        }
    }
    if(!cnt) return;
    queue<pair<int,int>> q;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i>=2-cnt && i<6-cnt) q.push(mat[i][j]);
            mat[i][j]={0,0};
        }
    }
    for(int i=2;i<6;i++)
    {
        for(int j=0;j<4;j++)
        {
            mat[i][j]=q.front(); q.pop();
        }
    }
}
void go(bool green_mat,int sec)
{
    new_down(green_mat,sec);
    while(1)
    {
        
        int new_score = get_score(green_mat);
        // print_sec();
        if(!new_score) break;
        score += new_score;
        go_down(green_mat);
    }
    check_line(green_mat);
}
void print_test()
{
    cout << "\n--------green--------\n";
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout << green[i][j].first << ' ';
        }cout << endl;
    }
    cout << "--------blue--------\n";
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout << blue[i][j].first << ' ';
        }cout << endl;
    }
    cout << endl;
}

int main()
{
    cin >> N;
    for(int i=1;i<=N;i++) 
    {
        cin>> t>> y >> x;
        go(true,i); go(false,i);
        // print_sec();
    }
    cout << score << endl;
    int cnt_block=0;
    for(int i=2;i<6;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(green[i][j].first) cnt_block++;
            if(blue[i][j].first) cnt_block++;
        }
    }
    cout << cnt_block << endl;
}