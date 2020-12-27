#include<iostream>
#define endl "\n"
#include <queue>
#include<list>
using namespace std;

int mx,rm,temp;
list<int> arr;
int main()
{
    cin >> mx;
    cin >> rm;
    for(int i=1;i<mx+1;i++)
    {
        arr.push_back(i);
    }
    queue<int> q;
    list<int>::iterator iter = arr.begin();
    while(arr.empty()!=1)
    {
        for(int i=0;i<rm-1;i++)
        {
            iter++;
            if(iter==arr.end()) iter=arr.begin(); 
        }
        q.push(*iter);
        iter=arr.erase(iter);
        if(iter==arr.end()) iter=arr.begin();
    }
    cout<< "<";
    while(q.empty()!=1)
    {
        temp=q.front();
        q.pop();
        if(q.empty()!=1) cout << temp<<", ";
        else cout << temp;
        
    }
    cout<< ">";

}