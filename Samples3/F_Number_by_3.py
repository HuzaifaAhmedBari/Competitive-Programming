n = int(input())
a = list(map(float,input().split()))
s=0;c=0
for i in range(1,n+1):
    if(i%3!=0):
        continue
    if(a[i-1]>0):
        s+=a[i-1]
        c+=1
print(f"{c} {s:.2f}")