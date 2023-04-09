from collections import Counter

n = int(input())
arr = list(map(int, input().split()))
gap = [[0 for j in range(n)] for i in range(n)]
MAX = -1

#i번째 원소 기준으로 공차d를 구한 후 최빈값의 등장 횟수를 기록
for i in range(n):
    d = []
    for j in range(n):
        if i!=j :
            d.append((arr[j] - arr[i]) / (j-i))
      #  else :
       #     d.append(0)
    #print(d)
    MAX = max(MAX, Counter(d).most_common(1)[0][1])
    #print(MAX)

print(n - MAX - 1)
