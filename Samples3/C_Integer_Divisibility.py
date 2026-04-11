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
    n, m = map(int,input().split())
    x = m
    ans = 1
    while(m%n!=0):
        m*=10
        m+=x
        m%=n
        ans+=1
    print(ans)
    
    
    
for _ in range(int(input())):
    print(f"Case {_+1}: ",end="")
    solve()