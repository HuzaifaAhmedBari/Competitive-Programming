def solve():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    a.sort()
    count = 0
    for i in range(n):
        f = a[i]+k
        l =0;r=n-1
        while(l<=r):
            mid = int(l + (r-l)//2)
            if(a[mid]>f):
                r = mid-1
            elif(a[mid]<f):
                l = mid+1
            else:
                count+=1
                break
    print(count)

solve()