for _ in range(0,1):
    n,x,y = map(int,input().split())
    a = list(map(int,input().split()))
    sum = sum(a)
    ax = min(a)*y
    bx = max(a)*x
    if(ax<bx):
        print(-1)
        exit(0)
    w = ax
    ans = ((w*n)-(x*sum))
    z = y-x
    d = ans//z
    if(ans%z!=0 or ans<=0):
        print(-1)
    else:
        print(d)