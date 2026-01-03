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
    a = input()
    if(a.count('B')==0):
        print(0)
        return
    print(a.rfind('B')-a.find('B')+1)
    
    
    
    
for _ in range(int(input())):
    solve()