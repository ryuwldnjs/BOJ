n = int(input())
x = int(input())
sum = 0
for i in range(x):
    a,b = map(int, input().split())
    sum += a*b
if sum == n:
    print("Yes")
else:
    print("No")
