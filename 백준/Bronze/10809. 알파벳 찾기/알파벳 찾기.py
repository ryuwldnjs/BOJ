a = [0]*26
dict = {}
for c in "abcdefghijklmnopqrstuvwxyz":
    dict[c] = -1

s = input()
for i in range(len(s)):
    if dict[s[i]] == -1:
        dict[s[i]] = i
for key in dict:
    print(dict[key], end=' ')
