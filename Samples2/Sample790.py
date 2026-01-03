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
    n,l,r = map(int,input().split())
    cur = 0
    for _ in range(n):
        a,b = map(int,input().split())
        if(a<=l and b>=r):
            cur+=1
    print(cur)
    
    
    
solve()