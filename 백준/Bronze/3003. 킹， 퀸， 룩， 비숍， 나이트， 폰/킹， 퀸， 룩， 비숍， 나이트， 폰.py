require = [1,1,2,2,2,8]
have = [*map(int, input().split())]

for i in range(6):
    print(require[i] - have[i], end=' ')
