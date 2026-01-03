for _ in range(int(input())):
    m,a,b,c = map(int,input().split())
    ans = 0
    a1 =m; a2=m
    ans += min(a1,a)
    a1 = max(0,a1-a)
    ans += min(a2,b)
    a2 = max(0,a2-b)
    ans += min(a1+a2,c)
    print(ans)