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
    s = input()
    t = input()
    count = 0;a=0
    for i in range(n):
        if(s[i]=='1' and t[i]=='1'):
            count+=1
    for i in range(n):
        if(s[i]!=t[i]):
            a+=1
    print("YES" if count&1 or (not count&1 and a>0) else "NO")
    
for _ in range(int(input())):
    solve()