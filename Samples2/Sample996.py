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
    n,m = map(int,input().split())
    s = input()
    diff = [0]*(n+2)
    a = set()
    for i in range(n):
        if(s[i] in a):
            continue
        a.add(s[i])
        diff[i]+=1
        diff[s.rfind(s[i])+1]-=1
    diff = list(accumulate(diff))
    for i in range(len(diff)):
        if(diff[i]>m):
            print("YES")
            return
    print("NO")
    
solve()