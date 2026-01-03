for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    res = 0
    for i in range(n-1):
        res += max(a[i]-a[i+1],0)
    print(res)