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
    n,q = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    maxed = [0]*n
    maxed[0] = a[0]
    for i in range(1,n):
        maxed[i] = max(maxed[i-1],a[i])
    pre = list(accumulate(a))
    for i,val in enumerate(b):
        if val<maxed[0]:
            print(0,end=" ")
            continue
        elif val>maxed[-1]:
            print(pre[-1],end=" ")
            continue
        d = bisect.bisect_right(maxed,val)
        print(pre[d-1],end=" ")
    
    
    
for _ in range(int(input())):
    solve()
    print()