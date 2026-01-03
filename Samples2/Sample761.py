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
    r =[];b=0
    while a:
        a.sort(key=lambda i:i|b)
        r.append(a.pop())
        if b== b|r[-1]:
            break
        b = b|r[-1]
    print(*r,*a)
    
    
    
for _ in range(int(input())):
    solve()