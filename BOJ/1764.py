import sys

N,M = map(int, sys.stdin.readline().split());

s = {};

arr = [];

for i in range(N) :
    value = sys.stdin.readline().strip();
    s[value] = 0;

for i in range(M) :
    value = sys.stdin.readline().strip()
    if(value in s) :
        arr.append(value);

arr.sort();

print(len(arr));
print('\n'.join(arr));