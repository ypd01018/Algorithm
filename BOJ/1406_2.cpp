#include<iostream>
#define endl "\n"

using namespace std;
const int MX = 1000005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

int insert(int idx, char val);
int erase(int idx);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);
	string input;
	char cmd, data;
	cin >> input;
	int n, iter=0;
	int cnt = 0;
	for (auto i : input)
	{
		insert(cnt, i);
		cnt++;
	}
	while (nxt[iter]!= -1)	
	{
		iter = nxt[iter];
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		switch (cmd)
		{
		case 'L':
			if (pre[iter] != -1) iter = pre[iter];
			break;
		case 'D':
			if (nxt[iter] != -1) iter = nxt[iter];
			break;
		case 'B':
			if(iter!=0) iter=erase(iter);
			break;
		case 'P':
			cin >> data;
			iter=insert(iter, data);
			break;
		default:
			break;
		}


	}
	int curl = nxt[0];

	while (curl != -1)
	{
		cout << dat[curl];
		curl = nxt[curl];
	}

}


int insert(int idx, char val)
{
	dat[unused] = val;
	pre[unused] = idx;
	nxt[unused] = nxt[idx];
	if (nxt[idx] != -1) pre[nxt[idx]] = unused;
	nxt[idx] = unused;
	unused++;
	return nxt[idx];
}



int erase(int idx)
{
	nxt[pre[idx]] = nxt[idx];
	if (nxt[idx] != -1) pre[nxt[idx]] = pre[idx];
	return pre[idx];
}