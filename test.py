import itertools

N = 4;
arr = [[1,2],[2,3],[1,4],[3,5],[2,6]];

dis = [[9999 for _ in range(15)] for _ in range(15)];

for i in range(N+1) :
    dis[i][i] = 0;

for elem in arr :
    dis[elem[0]][elem[1]] = 1;
    dis[elem[1]][elem[0]] = 1;

for k in range(1,N+1) :
    for i in range(1,N+1) :
        for j in range(1, N+1) :
            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

sum = 0;

for i in range(1, N+1) :
    for j in range(i+1, N+1) :
        
        sum += dis[i][j];

print(sum);
