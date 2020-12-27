#include<iostream>
#define endl '\n'
#include<list>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> list1;
	list<char>::iterator iter = list1.end();
	list<char>::iterator temp, iter2;
	string input;
	cin >> input;

	for (auto i : input)
	{
		list1.push_back(i);
	}

	int n;
	char cmd, data;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == 'L' && iter != list1.begin()) iter--;
		else if (cmd == 'D' && iter != list1.end()) iter++;
		else if (cmd == 'B' && iter != list1.begin())
		{
			iter--;
			iter=list1.erase(iter);
		}
		else if (cmd == 'P')
		{
			cin >> data;
			iter = list1.insert(iter,data);
			iter++;
		}


	}
	for (iter2 = list1.begin(); iter2 != list1.end(); ++iter2)
	{
		cout << *iter2;
	}
	
}

