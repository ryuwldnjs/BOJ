a = [i for i in range(101)]

n,m = map(int,input().split())
for i in range(m):
    i,j = map(int,input().split())
    [a[i],a[j]] = [a[j], a[i]]

for x in a[1:n+1]:
    print(x,end=" ")
