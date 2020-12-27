import sys
check = [0 for i in range(30)]
dy = [-1,0,1,0]
dx = [0,1,0,-1]
R,C = map(int,sys.stdin.readline().rstrip().split())
mat = []
for i in range(R) :
    a = sys.stdin.readline().rstrip()
    arr = []
    for j in a :
        arr.append(j)
    mat.append(arr)

visit = [[0 for i in range(50)] for j in range(50)]

mx = 0

def DFS(y,x,cnt) :
    global visit,check,mx
    mx = max(mx,cnt)
    # print('y:',y,' x:',x, 'val:',mat[y][x], ' cnt:',cnt)
    for i in range(4) :
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or nx < 0 or ny >= R or nx >= C or visit[ny][nx] == 1 or check[ord(mat[ny][nx])-ord('A')] == 1 :
            continue
        check[ord(mat[ny][nx])-ord('A')] = 1
        visit[ny][nx] - 1
        DFS(ny,nx,cnt+1)
        check[ord(mat[ny][nx]) - ord('A')] = 0
        visit[ny][nx] = 0

def main() :
    visit[0][0] = 1
    check[ord(mat[0][0])-ord('A')] = 1
    DFS(0,0,1)
    print(mx)

main()
