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
    ab = False
    bb = False
    d1 = 0;d2=0;d3=0
    for i in range (n):
        a,b,c = map(str,input().split())
        d = Counter(c)
        if(a=='1'):
            d3+=int(b)*len(c)
            if(d['a']<len(c)):
                ab = True
            d1+= d['a']*int(b)
        else:
            if(d['a']<len(c)):
                bb = True
            d2 += d['a']*int(b)
        if bb:
            print("YES")
        elif d3>d2:
            print("NO")
        elif d3==d1 and d1<d2:
            print("YES")
        else:
            print("NO")
    
    
    
for _ in range(int(input())):
    solve()