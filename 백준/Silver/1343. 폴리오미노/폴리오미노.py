s = input().split('.')
no_answer = False

for i in range(len(s)):
    sz = len(s[i])
    if sz%2 ==0:
        s[i] = 'AAAA'*(sz//4) + 'BB'*(sz%4 // 2)
    else:
        no_answer = True
answer = '.'.join(s)
if no_answer:
    print(-1)
else:
    print(answer)
