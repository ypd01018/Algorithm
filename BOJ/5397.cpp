#include<iostream>
#define endl '\n' 
using namespace std;
#include<list>
#include<string>
int n;
void sol();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        sol();
        cout<<endl;
    }


}

void sol()
{
    int n2;
    string pwd;
    list<char> lst;
    cin >> pwd;
    list<char>::iterator iter= lst.begin();
    for( auto i : pwd)
    {
         switch (i)
         {
             case '<':
                if(iter!=lst.begin()) iter--;
                break;
             case '>':
                if(iter!=lst.end()) iter++;
                break;
             case '-':
                if(iter!=lst.begin() && lst.empty()!=1)
                {
                    iter--;
                    iter=lst.erase(iter);
                }
                break;
             default:
                iter=lst.insert(iter,i);
                iter++;
                break;
         }

    }
    list<char>::iterator temp= lst.begin();

    while(temp!=lst.end())
    {
        cout<<*temp;
        temp++;
    }
}