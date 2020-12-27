import sys
import Queue
input = sys.stdin.readline

def main() :
    N = int(input())

    q = Queue.queue()

    for i in range(N) :
        cmd = input().strip()
        if cmd == "empty" :
            if q.empty() :
                print(1)
            else : 
                print(0)
        elif cmd == "size" :
            print(q.qsize())
        elif cmd == "pop" :
            if q.get()

main()