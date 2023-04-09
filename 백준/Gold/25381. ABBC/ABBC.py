str = input()
arr = [[] for i in range(3)]
cnt = 0
#각 알파벳별로 위치 기록
for i in range(len(str)):
    if str[i] == 'A':
        arr[0].append(i)
    elif str[i] == 'B':
        arr[1].append(i)
    elif str[i] == 'C':
        arr[2].append(i)


a, b = len(arr[0])-1, len(arr[1])-1
while(a >= 0 and b >= 0) :
    if arr[0][a] < arr[1][b] :
        del arr[1][b]
        b -= 1
        cnt += 1
    a -= 1


b, c = 0, 0
while(b < len(arr[1]) and c < len(arr[2])) :
    if arr[1][b] < arr[2][c] :
        del arr[1][b]
       # b += 1
        cnt += 1
    c += 1

print(cnt)
