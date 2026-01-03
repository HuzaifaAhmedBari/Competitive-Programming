n = int(input())
a = list(map(int,input().split()))
m = int(input())
b = list(map(int,input().split()))
a = list(dict.fromkeys(a))
a.sort()
a.reverse()
for x in b:
    best = len(a)
    l=0;r=len(a)-1
    if(x)>a[0]:
        print(1)
        continue
    while(l<=r):
        mid = int(l+(r-l)//2)
        if(a[mid]<x):
            r=mid-1
        elif(a[mid]>x):
            l=mid+1
            best = mid+2
        else:
            best = mid+1
            break
    print(best)