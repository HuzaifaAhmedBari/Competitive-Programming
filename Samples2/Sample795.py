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
    print("Yes" if list(map(int,input().split())).count(int(input()))>=1 else "No")
    
    
    
    
solve()