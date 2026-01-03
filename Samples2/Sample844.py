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
    a.sort()
    x = a.count(200)
    y = a.count(100)
    if(x%2==0):
        if(y%2==0):
            t=0
        else:
            t=1
    else:
        if(y%2==0 and y>=2):
            t=0
        else:
            t=1
    
    print("YNEOS"[t::2])
    
    
solve()