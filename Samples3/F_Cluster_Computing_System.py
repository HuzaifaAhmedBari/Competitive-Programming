import math
n = int(input())
a = list(map(int,input().split()))
b = list()
b.append(a[0])
for i in range(1,n):
    b.append(math.gcd(a[i],b[-1]))
c = list()
c.append(a[-1])
for i in range(n-2,-1,-1):
    c.append(math.gcd(a[i],c[-1]))
c.reverse()
sum = 0
for i in range(1,n-1):
    sum += min(b[i],c[i])
print(sum+min(b[0],c[0],b[-1],c[-1]))