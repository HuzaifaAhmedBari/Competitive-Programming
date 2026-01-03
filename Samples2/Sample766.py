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
    n = int(input())
    a = list(map(int,input().split()))
    mx = -math.inf
    ans = 0
    for i,val in enumerate(a):
        ans+=val
        mx = max(mx,ans)
        ans = max(0,ans)
    print(mx)
    
    
solve()