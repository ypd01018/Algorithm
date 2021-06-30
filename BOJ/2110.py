import sys

N,C = map(int, sys.stdin.readline().split());

arr = [];

for _ in range(N) :
    value = int(sys.stdin.readline().strip());
    arr.append(value);

arr.sort();

l = 1;
r = arr[len(arr)-1];
answer=0;

while(l<=r) :
    mid = int((l+r)/2);
    cnt = 1;
    pre = arr[0]
    for current in arr[1:] :
        if(current - pre >= mid) :
            cnt+=1;
            pre = current;
    
    if(cnt >= C) :
        answer = max(answer, mid)
        l = mid+1;
    else :
        r = mid-1;

print(answer);
