n = int(input())
arr = list(map(int,input().split()))
cnt1, cnt2 = 0, 0
odd = 0
even = 0
left = 0
for i in range(n): 
    if arr[i] % 2 == 1 :
        cnt1 += i - odd
        odd += 1
    else :
        cnt2 += i - even
        even += 1

print(min(cnt1, cnt2))
