n = int(input())
s = input()
a = set()
a.add((0,0))
x = 0;y = 0
for i in range(n):
    if(s[i]=='R'):
        x+=1
    elif(s[i]=='L'):
        x-=1
    elif(s[i]=='U'):
        y+=1
    else:
        y-=1
    if((x,y) in a):
        print("Yes")
        exit(0)
    a.add((x,y))
print("No")