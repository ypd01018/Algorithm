import sys
from collections import deque
priority = {
    '(' : 3,
    ')' : 3,
    '*' : 1,
    '/' : 1,
    '+' : 2,
    '-' : 2
}
def main() :
    a = sys.stdin.readline().rstrip()
    stk = deque()
    for c in a :
        if 'A' <= c and c <= 'Z' :
            print(c,end='')
        elif c == '(' :
            stk.append('(')
        elif c == ')' :
            while len(stk)>0 :
                stk_elem = stk.pop()
                if stk_elem == '(' :
                    break
                else :
                    print(stk_elem,end='')
        else :
            while len(stk) > 0 and priority[stk[-1]] <= priority[c] :
                print(stk.pop(),end='')
            stk.append(c)
    while len(stk) > 0 :
        print(stk.pop(),end='')


main()