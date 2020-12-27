#include<iostream>
#include<vector>
#include<queue>
#define mp make_tuple
#define endl "\n"
using namespace std;
struct hole_info_str
{
	int x_e, y_e, t;
};
int w, h, n_g, n_hole, arr[50][50], dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 }, time[50][50];
hole_info_str hole_info[50][50];
queue<pair<int, int>> q;
vector<tuple<int, int, int>> v[50][50];
void init()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			time[i][j] = -1;
		}
	}
}

int main()
{
	while (1)
	{
		cin >> w >> h >> n_g;
		if (w == 0 && h == 0) break;

		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n_g; i++)
		{
			int x_g, y_g;
			cin >> x_g >> y_g;
			arr[y_g][x_g] = 1;
		}

		cin >> n_hole;

		for (int i = 0; i < n_hole; i++)
		{
			int x_s, x_e, y_s, y_e, t;
			cin >> x_s >> y_s >> x_e >> y_e >> t;
			arr[y_s][x_s] = 2;
			hole_info[y_s][x_s].x_e = x_e;
			hole_info[y_s][x_s].y_e = y_e;
			hole_info[y_s][x_s].t = t;
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j]==1) continue;
				for (int n = 0; n < 4; n++)
				{
					int ny = i + dy[n], nx = j + dx[n];
					if (ny >= 0 && nx >= 0 && ny < h && nx < w && arr[ny][nx]!=1)
					{
						
					}
				}
			}
		}

	}
}