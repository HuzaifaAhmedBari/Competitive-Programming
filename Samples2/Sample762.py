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
    mn = a[0];mx=a[0]
    count=0
    for i,val in enumerate(a):
        if val>mx or val<mn:
            count+=1
        mn=min(mn,val)
        mx=max(mx,val)
    print(count)
    
    
    
solve()