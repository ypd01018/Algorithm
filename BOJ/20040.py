import sys

root = [0 for i in range(500002)]

def init(n) :
    for i in range(n) :
        root[i] = i

def find(a) :
    if a == root[a] :
        return a
    else :
        root[a] = find(root[a])
        return root[a]

def uni(a,b) :
    a = find(a)
    b = find(b)
    root[b] = a

def main() :
    N,M = map(int,sys.stdin.readline().rstrip().split())
    init(N)
    for i in range(M) :
        a,b = map(int,sys.stdin.readline().rstrip().split())
        if find(a) == find(b) :
            print(i+1)
            return
        uni(a,b)   
    print(0)

main()