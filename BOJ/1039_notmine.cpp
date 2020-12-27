#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<set>
#include<vector>
 
#define endl "\n"
#define MAX 1000000 + 1
using namespace std;
 
string Inp;
int K, M;
vector<int> Answer;
 
int Invert(string S)
{
    int Sum = 0;
    for (int i = 0; i < S.length(); i++)
    {
        Sum = Sum + (S[i] - '0');
        if (i != S.length() - 1) Sum = Sum * 10;
    }
    return Sum;
}
 
void Input()
{
    cin >> Inp >> K;
    M = Inp.length();
 
    if (M == 1 || (M == 2 && Invert(Inp) % 10 == 0))
    {
        cout << "-1" << endl;
        exit(0);
    }
}
 
void BFS(string S)
{
    queue<string> Q;
    Q.push(S);
    int Cur_K = 0;
    int Max = 0;
 
    while (Q.empty() == 0 && Cur_K < K)
    {
        int Qs = Q.size();
        set<string> Visit;
 
        for (int q = 0; q < Qs; q++)
        {
            string Cur = Q.front();
            Q.pop();
 
            for (int i = 0; i < M - 1; i++)
            {
                for (int j = i + 1; j < M; j++)
                {
                    if (i == 0 && Cur[j] == '0') continue;
 
                    swap(Cur[i], Cur[j]);
                    if (Visit.find(Cur) == Visit.end())
                    {
                        if (Cur_K == K - 1 && Max < Invert(Cur))
                        {
                            Max = Invert(Cur);
                        }
                        Q.push(Cur);
                        Visit.insert(Cur);
                    }
                    swap(Cur[i], Cur[j]);
                }
            }
        }
        Cur_K++;
    }
 
    if (Cur_K != K) cout << "-1" << endl;
    else cout << Max << endl;
 
}
 
void Solution()
{
    BFS(Inp);
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
