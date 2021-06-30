import sys

N,K = map(int, sys.stdin.readline().split());

arr = list(map(int, sys.stdin.readline().split()));

l=0;

m = {};

mx = 0;

for r in range(len(arr)) :
    if((arr[r] in m) == False) : m[arr[r]] = 0;
    m[arr[r]] += 1;

    if(m[arr[r]] > K) :
        target = arr[r];
        while(m[target] > K) :
            m[arr[l]] -= 1;
            l += 1;
    
    mx = max(mx, r-l+1);

print(mx);

