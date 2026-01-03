for _ in range(int(input())):
    n = int(input())
    s = input()
    s+='99999'
    a = []
    flag = False
    f = False
    ans = False
    if(s[0]+s[1]+s[2]+s[3]=="2020" or s[n-4]+s[n-3]+s[n-2]+s[n-1]=="2020"):
        ans = True
    if(s[0]=='2'):
        for i in range(1, n):
            if(s[i]=='0' and s[i+1]=='2' and s[i+2]=='0' and i+2==n-1):
                ans = True
        if(s[1]=='0'):
            for i in range(2, n):
                if(s[i]=='2' and s[i+1]=='0' and i+1==n-1):
                    ans = True
            if(s[2]=='2' and s[n-1]=='0'):
                ans = True
    print("YES" if ans else "NO")