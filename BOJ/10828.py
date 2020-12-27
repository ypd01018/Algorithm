import sys

input=sys.stdin.readline

def main() :
    stk = []
    N = int(input())
    for i in range(N) :
        action = input().strip()
        if action =='pop' :
            if not stk : 
                print(-1)
            else : 
                print(stk.pop())
        elif action == 'size' : 
            print(len(stk))
        elif action == "empty" :
            if(not stk) :
                print(1)
            else :
                print(0)
        elif action == "top" :
            if(not stk) : 
                print(-1)
            else : print(stk[-1])
        else :
            num = int(action.split()[1])
            stk.append(num)

main()