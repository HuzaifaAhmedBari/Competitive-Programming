#Maqsad Nahi Bhoolna
import sys
import math
import bisect
import heapq
from collections import defaultdict, deque, Counter
from itertools import accumulate, permutations, combinations, product
from functools import reduce
input = sys.stdin.readline

def solve():
    n, m, k = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    sum = []
    i = 0;j = 0
    x = math.lcm(n,m)
    for _ in range(x):
        if(i==n):
            i=0
        if(j==m):
            j=0
        sum.append(min(a[i],b[j]))
        i+=1;j+=1
    for _ in range(1,x):
        sum[_]+=sum[_-1]
    ans = (k//x)*(sum[x-1])
    ans += sum[(k%x)-1]
    print(ans%998244353)
    
    
solve()