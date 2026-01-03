import math
def solve():
    n,m = map(int,input().split())
    s = [input() for i in range (n)]
    dp = [[math.inf]*m for i in range(n)]
    for i in range(n):
        cur = -1
        for j in range(m):
            if(s[i][j]=='1'):
                cur = j
            if(cur==-1):
                continue
            dp[i][j] = min(dp[i][j],j-cur)
        count = m-cur-1
        for j in range(m):
            count+=1
            if(cur==-1):
                continue
            dp[i][j] = min(dp[i][j],count)
        cur = -1
        for j in range(m-1,-1,-1):
            if(s[i][j]=='1'):
                cur = j
            if(cur==-1):
                continue
            dp[i][j] = min(dp[i][j],cur-j)
        count = cur
        for j in range(m-1,-1,-1):
            count+=1
            if(cur==-1):
                continue
            dp[i][j] = min(dp[i][j],count)
    for i in range(n):
        if math.inf in dp[i]:
            print(-1)
            return
    ans = math.inf
    for i in range(m):
        temp = 0
        for j in range(n):
            temp+=dp[j][i]
        ans = min(ans,temp)
    print(ans)

solve()