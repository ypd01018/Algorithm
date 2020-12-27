import sys
from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

N = M = None


def nxt_fire(mat, fire_q):
    q_size = len(fire_q)
    for i in range(q_size):
        y, x = map(int, fire_q.popleft())
        for n in range(4):
            ny = y + dy[n]
            nx = x + dx[n]
            if ny < 0 or nx < 0 or ny >= M or nx >= N or mat[ny][nx] != '.':
                continue
            mat[ny][nx] = '*'
            fire_q.append([ny, nx])


def BFS(start_y, start_x, mat, fire_q):

    q = deque()
    q.append([0, start_y, start_x])
    sec = -1
    visit = [[0 for i in range(N)] for j in range(M)]
    visit[start_y][start_x] = 1

    while len(q) > 0:
        elem_sec, y, x = q.popleft()
        if elem_sec > sec:
            sec += 1
            nxt_fire(mat, fire_q)
        for n in range(4):
            ny = y + dy[n]
            nx = x + dx[n]
            if(ny < 0 or nx < 0 or ny >= M or nx >= N):
                return elem_sec+1
            if(visit[ny][nx] == 1 or mat[ny][nx] != '.'):
                continue
            visit[ny][nx] = 1
            q.append([int(elem_sec+1), int(ny), int(nx)])

    return "IMPOSSIBLE"


def start():
    global N, M, fire_q, mat
    y = None
    x = None
    fire_q = deque()
    mat = []
    N, M = map(int, sys.stdin.readline().rstrip().split())
    for i in range(M):
        arr_input = sys.stdin.readline().rstrip()
        arr = []
        for j in range(N):
            c = arr_input[j]
            if c == '*' :
                fire_q.append([i, j])
            elif c == '@':
                y = i
                x = j
                c = '.'
            arr.append(c)
        mat.append(arr)
    return BFS(y, x, mat, fire_q)


def main():
    T = int(input())
    for i in range(T):
        print(start())


main()
