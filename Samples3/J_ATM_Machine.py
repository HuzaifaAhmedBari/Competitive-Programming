for _ in range(int(input())):
    n, m = map(int,input().split())
    a = list(map(int,input().split()))
    for i in range(n):
        if(m>=a[i]):
            print("1",end="")
            m-=a[i]
        else:
            print("0",end="")
    print()