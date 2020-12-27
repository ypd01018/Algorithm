#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int N;
string a[4]={"\"재귀함수가 뭔가요?\"\n",
"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n",
"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n",
"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n"},
b = "라고 답변하였지.\n",
c= "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n",
d="____";

void DFS(int n)
{
    string front = "";
    for(int i=0;i<n;i++) front.append(d);
    for(int i=0;i<4;i++) 
    {
        if(i&&n==N)
        {
            cout << front << c;
            cout << front << b;
            return;
        }
        cout <<front << a[i];
    }
    DFS(n+1);
    cout << front << b;

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    DFS(0);
}