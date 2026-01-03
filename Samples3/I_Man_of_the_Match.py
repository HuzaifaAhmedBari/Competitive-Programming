for _ in range(int(input())):
    mx = 0;idx=0
    for i in range(1,23):
        x,y = map(int,input().split())
        c = x+(y*20)
        if(c>mx):
            mx = c;idx=i
    print(idx)