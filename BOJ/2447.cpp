#include<iostream>

using namespace std;
void draw(int n,int x, int y);
char arr[2200][2200];
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    int n,temp,cnt=1;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            arr[i][j]=' ';    
    
    draw(n,0,0);
    for(int i=0;i<n;i++)
    {    
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j];    
        }
        cout << endl;

    }
    
}

void draw(int n,int x, int y)
{
    if(n == 1)
    {
        arr[y][x]='*';
        return;
    }

    draw(n/3,x,y);
    draw(n/3,x+n/3,y);
    draw(n/3,x+2*(n/3),y);

    draw(n/3,x,y+n/3);
    draw(n/3,x+2*(n/3),y+n/3);
    
    draw(n/3,x,y+2*(n/3));
    draw(n/3,x+n/3,y+2*(n/3));
    draw(n/3,x+2*(n/3),y+2*(n/3));
    
}
