n = int(input())
dp = [0]*(1001)

dp[1] = dp[3] = 1

for i in range(4, n+1):
    if dp[i-1]==0 or dp[i-3]==0:
        dp[i] = 1;

if dp[n] == 1:
    print('SK')
else:
    print('CY')
