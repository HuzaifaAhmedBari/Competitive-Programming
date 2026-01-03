for _ in range(int(input())):
    s = input()
    a = list(map(int,input().split()))
    z = set(a)
    if(len(z)==1):
        print(s)
    else:
        print(int(s)-1)