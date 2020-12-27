#include<iostream>
#include<cmath>
using namespace std;
int cnt = -1, r, c ;

void func(int arr_size,int x, int y)
{
    if(arr_size == 1)
    {
        cnt++;
        if(y == r && x == c )
        {
            cout << cnt ;
            exit(0);
        }
        return ;
    }
    if(r > y + arr_size/2 || c > x + arr_size/2) cnt = cnt + (arr_size/2)*(arr_size/2);
    else func(arr_size/2, x, y);

    if(r > y + arr_size/2) cnt = cnt + (arr_size/2)*(arr_size/2);
    else func(arr_size/2, x + arr_size/2, y);

    if(r > y + arr_size/2 && c > x + arr_size/2) cnt = cnt + (arr_size/2)*(arr_size/2);
    else func(arr_size/2, x, y + arr_size/2);

    func(arr_size/2, x + arr_size/2, y + arr_size/2);
        


}
int main()
{
    ios::sync_with_stdio(1);
    cin.tie(0);

    int n,arr_size = 2;
    cin >> n >> r >> c;
    func((int)pow(2,n),0,0);
}