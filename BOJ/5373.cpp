#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
char original[6][3][3]=
{{{'w','w','w'},{'w','w','w'},{'w','w','w'}},
{{'r','r','r'},{'r','r','r'},{'r','r','r'}},
{{'y','y','y'},{'y','y','y'},{'y','y','y'}},
{{'o','o','o'},{'o','o','o'},{'o','o','o'}},
{{'g','g','g'},{'g','g','g'},{'g','g','g'}},
{{'b','b','b'},{'b','b','b'},{'b','b','b'}}};

char cube[6][3][3],cpy[3][3];
int T,N;                                  
//                  {0,0} {0,1} {0,2}                               
//                  {1,0} {1,1} {1,2}                                 
//                  {2,0} {2,1} {2,2}       

//{0,0} {0,1} {0,2} {0,0} {0,1} {0,2} {0,0} {0,1} {0,2}  
//{1,0} {1,1} {1,2} {1,0} {1,1} {1,2} {1,0} {1,1} {1,2} 
//{2,0} {2,1} {2,2} {2,0} {2,1} {2,2} {2,0} {2,1} {2,2} 

//                  {0,0} {0,1} {0,2}                 
//                  {1,0} {1,1} {1,2}                    
//                  {2,0} {2,1} {2,2}                 

//                  {0,0} {0,1} {0,2}                 
//                  {1,0} {1,1} {1,2}                    
//                  {2,0} {2,1} {2,2}          	
pair<int,int> 
u[6][4][3]=
{{{{0,0},{0,1},{0,2}},{{0,0},{0,1},{0,2}},{{2,2},{2,1},{2,0}},{{0,0},{0,1},{0,2}}}, //0 -> 1,5,3,4
{{{0,0},{0,1},{0,2}},{{2,0},{1,0},{0,0}},{{2,2},{2,1},{2,0}},{{0,2},{1,2},{2,2}}},  //1 -> 2,5,0,4
{{{0,0},{0,1},{0,2}},{{2,2},{2,1},{2,0}},{{2,2},{2,1},{2,0}},{{2,2},{2,1},{2,0}}},  //2 -> 3,5,1,4
{{{0,0},{0,1},{0,2}},{{0,2},{1,2},{2,2}},{{2,2},{2,1},{2,0}},{{2,0},{1,0},{0,0}}},  //3 -> 0,5,2,4
{{{2,0},{1,0},{0,0}},{{2,0},{1,0},{0,0}},{{2,0},{1,0},{0,0}},{{2,0},{1,0},{0,0}}},  //4 -> 2,1,0,3
{{{0,2},{1,2},{2,2}},{{0,2},{1,2},{2,2}},{{0,2},{1,2},{2,2}},{{0,2},{1,2},{2,2}}}}; //5 -> 2,3,0,1

int turn[6][4]={{1,5,3,4},{2,5,0,4},{3,5,1,4},{0,5,2,4},{2,1,0,3},{2,3,0,1}};

void rotate_l(int a)
{
    cpy[2][0]=cube[a][0][0];
    cpy[1][0]=cube[a][0][1];
    cpy[0][0]=cube[a][0][2];
    cpy[2][1]=cube[a][1][0];
    cpy[1][1]=cube[a][1][1];
    cpy[0][1]=cube[a][1][2];
    cpy[2][2]=cube[a][2][0];
    cpy[1][2]=cube[a][2][1];
    cpy[0][2]=cube[a][2][2];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cube[a][i][j]=cpy[i][j];
        }
    }

    queue<char> q;
    for(int i=0;i<4;i++)
    {
        int num=turn[a][i];
        for(int j=0;j<3;j++)
        {
            int y,x; tie(y,x) = u[a][i][j];
            q.push(cube[num][y][x]);
        }
    }

    for(int i=0;i<4;i++)
    {
        int num=turn[a][(i+1)%4];
        for(int j=0;j<3;j++)
        {
            int y,x; tie(y,x) = u[a][(i+1)%4][j];
            cube[num][y][x]=q.front(); q.pop();
        }
    }
}
void rotate_r(int a)
{
    cpy[0][2]=cube[a][0][0];
    cpy[1][2]=cube[a][0][1];
    cpy[2][2]=cube[a][0][2];
    cpy[0][1]=cube[a][1][0];
    cpy[1][1]=cube[a][1][1];
    cpy[2][1]=cube[a][1][2];
    cpy[0][0]=cube[a][2][0];
    cpy[1][0]=cube[a][2][1];
    cpy[2][0]=cube[a][2][2];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cube[a][i][j]=cpy[i][j];
        }
    }

    queue<char> q;
    for(int i=3;i>=0;i--)
    {
        int num=turn[a][i];
        for(int j=2;j>=0;j--)
        {
            int y,x; tie(y,x) = u[a][i][j];
            q.push(cube[num][y][x]);
        }
    }

    for(int i=3;i>=0;i--)
    {
        int num;

        if(i-1>=0) num=turn[a][i-1];
        else num=turn[a][3];

        for(int j=2;j>=0;j--)
        {
            int y,x;

            if(i-1>=0) tie(y,x) = u[a][i-1][j];
            else tie(y,x) = u[a][3][j];

            cube[num][y][x]=q.front(); q.pop();
        }
    }

}

void print_test()
{
    cout <<"----------------------------------start---------------------------------" <<endl;
    for(int i=0;i<6;i++)
    {
        cout << i<<endl;
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                cout << "   ";
                if((int)cube[i][j][k]<10) cout << '0' << (int)cube[i][j][k];
                else cout << (int)cube[i][j][k];
                cout <<' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    cout <<"----------------------------------e n d---------------------------------" <<endl;
}
void print_test_2()
{
    cout <<"----------------------------------start---------------------------------" <<endl;
    for(int i=0;i<6;i++)
    {
        cout << i<<endl;
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                cout << cube[i][j][k];
                cout <<' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    cout <<"----------------------------------e n d---------------------------------" <<endl;
}
void print_up()
{
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                cout << cube[0][j][k];
            }
            cout << endl;
        }
}
void for_test()
{
    int cnt=0;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                cube[i][j][k]=(cnt++);
            }
        }
    }
}
void sol()
{
    memcpy(cube,original,sizeof(original));
    //for_test();
    cin >> N;
    for(int i=0;i<N;i++)
    {
        string cmd; cin >> cmd;
        int a;
        if(cmd[0]=='U') a=0;
        else if(cmd[0]=='F') a=1;
        else if(cmd[0]=='D') a=2;
        else if(cmd[0]=='B') a=3;
        else if(cmd[0]=='L') a=4;
        else if(cmd[0]=='R') a=5;

        if(cmd[1]=='+') rotate_r(a);
        else rotate_l(a); 
        //print_test();
        //print_test_2();
    }
    print_up();
}

int main()
{
    cin >> T;
    for(int i=0;i<T;i++)
    {
        sol();
    }
}
