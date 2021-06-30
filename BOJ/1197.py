import sys
import heapq

sys.setrecursionlimit(10000000);

root = [i for i in range(10010)];

pq = [];

def find(a) :
    # print(' ' + str(a) + ',' + str(root[a]));
    if(a == root[a]) : return a;
    else :
        root[a] = find(root[a]);
        return root[a];

def uni(a,b) :
    a = find(a);
    b = find(b);

    root[b] = a;

V, E = map(int, input().split())

for i in range(E) :
    a,b,d = map(int, input().split());
    heapq.heappush(pq,[d,a,b]);

answer = 0;
cnt = 0;
while(len(pq)>0) :
    d,a,b = heapq.heappop(pq);

    if(find(a) == find(b)) : continue;

    answer += d;
    cnt += 1;
    uni(a,b);

    if(cnt == V-1) : break;

print(answer);



