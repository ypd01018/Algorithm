import sys

N,M = map(int,sys.stdin.readline().split());

arr = list(map(int,sys.stdin.readline().split()));

l = 0;
r = 2000000000

answer = 0;

while(l<=r) :
    mid = int((l+r)/2);

    sum = 0;

    for elem in arr :
        sum += elem-mid if elem-mid > 0 else 0;
    
    if(sum >= M) :
        answer = mid;
        l = mid+1;
    else :
        r = mid-1;

print(answer);
