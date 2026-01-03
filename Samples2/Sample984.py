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
    k,n,m = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    
    mx = -1

    for i in range(n):
        for j in range(m):
            if(a[i]+b[j]<=k and a[i]+b[j]>=mx):
                mx = a[i]+b[j]
    print(mx)
    
solve()