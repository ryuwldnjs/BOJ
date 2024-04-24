a = "_" + input()
answer = 0
for i in range(1,len(a)):
    answer += 5
    if a[i] != a[i-1]:
        answer += 5
        
print(answer)