import sys
sys.setrecursionlimit(3000)

mat = []
visit = [[0 for i in range(60)] for j in range(60)]
dy = [-1,0,1,0]
dx = [0,1,0,-1]
N = None
M = None

def DFS(y,x,pre_y,pre_x) : 
    global visit
    for i in range(4) :
        ny = y + dy[i]
        nx = x + dx[i]
        if (ny<0 or nx<0 or ny>=N or nx>=M) or (ny == pre_y and nx == pre_x) or (mat[y][x] != mat[ny][nx]):
            continue
        if visit[ny][nx] == 1 :
            return True
        visit[ny][nx] = 1
        flag = DFS(ny,nx,y,x)
        if(flag) : return True
    return False
        



def main() :
    global N,M,visit
    N,M = map(int,input().split())
    for i in range(N) :
        mat.append(input())
    flag = False
    for i in range(N) :
        for j in range(M) :
            if visit[i][j] == 1 : continue
            visit[i][j] = 1
            flag = DFS(i,j,-1,-1)
            if flag : 
                break         
        if flag : break
    if flag : print("Yes")
    else : print("No")

main()