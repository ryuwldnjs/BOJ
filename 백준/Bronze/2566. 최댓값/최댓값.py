a = [[*map(int,input().split())] for _ in range(9)]
MAX_i,MAX_j = 0,0
for i in range(9):
    for j in range(9):
        if a[i][j] > a[MAX_i][MAX_j]:
            [MAX_i, MAX_j] = i,j
print(a[MAX_i][MAX_j])
print(MAX_i+1, MAX_j+1)
