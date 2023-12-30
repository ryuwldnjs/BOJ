str = input()
str = str.lower()

cnt = [0]*26
isAnswer = True

for x in str:
    cnt[ord(x) - ord('a')] += 1


idx = 0 # 최댓값의 인덱스
for i in range(1, 26):
    if cnt[idx] < cnt[i]:
        idx = i
        isAnswer = True
    #같은 최댓값이 존재하는 경우
    elif cnt[idx] == cnt[i]:
        isAnswer = False

if isAnswer == False:
    print('?')
else:
    print(chr(idx + ord('A')))
