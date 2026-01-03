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
    print("Yes" if(any(((n-(x*4))%7==0 and x*4<=n) for x in range(0,30))) else "No")
    
    
    
solve()