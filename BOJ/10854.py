import sys

input = sys.stdin.readline

def main() :
    N = int(input())
    q = []
    for i in range(N) :
        cmd = input().strip()
        if cmd == "pop" :
            if not q :
                print(-1)
            else :
                print(q.pop(0))
        elif cmd == "size" :
            print(len(q))
        elif cmd == "empty" :
            if not q :
                print(1)
            else :
                print(0)
        elif cmd == "front" :
            if not q :
                print(-1)
            else :
                print(q[0])
        elif cmd == "back" :
            if not q :
                print(-1)
            else :
                print(q[-1])
        else :
            num = cmd.split()[1]
            q.append(num)

    
main()