import sys
sys.setrecursionlimit(3000)

visit = [[0 for i in range(51)] for j in range(51)]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def reset_visit():
    for i in range(51) :
        for j in range(51) :
            visit[i][j] = 0


def DFS(y, x, preY, preX):
    for i in range(4) :
            ny = y + dy[i]
            nx = x + dx[i]
            if ny == preY and nx == preX : 
                continue
            if visit[ny] == 1 and visit[nx] == 1 :
                return True
            res = DFS(ny,nx,y,x)
            if(res) :
                return True
            return False



N, M = map(int, input().split())

print(N)
print(M)
mat = []
for i in range(N):
    arr = input()
    mat.append(arr)
ans = "No"
for i in range(N):
    flag = False
    for j in range(M):
        if visit[i][j] == 0:
            res = DFS(i, j, -1, -1)
            if res == True :
                ans = "Yes"
                flag = True
                break
            reset_visit()
    if flag == True :
        break
print(ans)
