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
    a, b, n = map(float,input().split())
    z = a/n
    print(2 if z<b and a!=b else 1)
    
    
    
for _ in range(int(input())):
    solve()