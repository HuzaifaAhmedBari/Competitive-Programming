import bisect
for _ in range(int(input())):
    a, *b = map(int,input().split())
    b.sort()
    z = bisect.bisect_left(b, a)
    print(3-z)