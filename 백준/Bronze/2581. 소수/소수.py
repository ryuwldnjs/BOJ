m=int(input())
n=int(input())

def isPrime(num):
    if num == 1:
        return False
    if num == 2:
        return True
    for i in range(2,num):
        if i*i > num:
            break
        if num%i == 0:
            return False
    return True
ans = []
for i in range(m,n+1):
    if isPrime(i):
        ans.append(i)
if len(ans) == 0:
    print(-1)
else:
    print(sum(ans))
    print(ans[0])
