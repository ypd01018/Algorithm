N,M,K = map(int,input().split(' '))
arr = []
for i in range(M):
    arr[i].append([]) 
for i in range(M):
    a,b = map(int,input().split(' '))
    arr.insert([a,b])
    print(arr[i][1])
    
