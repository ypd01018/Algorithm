import sys

K,N = map(int, sys.stdin.readline().split());

arr = [];

for _ in range(K) :
    value = int(sys.stdin.readline().strip());
    arr.append(value);


l = 1;
r = max(arr);

answer = 0;

while(l <= r) :
    cnt = 0;
    mid = int((l+r)/2);
    for elem in arr :
        cnt += int(elem/mid);
    if(cnt < N) :
        r = mid - 1;
    else :
        answer = max(answer, mid);
        l = mid + 1;

print(answer);