m,a,b = map(int,input().split())
less = 0
if(a&1 and b&1 and (m-(a//2)-(b//2))<=1):
    less = 1
more = min(a,b)
print(less,more)