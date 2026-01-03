n, m = map(int,input().split())
a = []
z = set()
for _ in range(n):
    s = input()
    a.append(s)
for j in range(n-m+1):
    for k in range(n-m+1):
        b = str()
        for l in range(j,j+m):
            for o in range(k,k+m):
                b+=a[l][o]
        z.add(b)
print(len(z))