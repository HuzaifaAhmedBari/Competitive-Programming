#Maqsad Nahi Bhoolna
import sys
import math
import bisect
import heapq
from collections import defaultdict, deque, Counter
from itertools import accumulate, permutations, combinations, product
from functools import reduce
# input = sys.stdin.readline
def solve():
    n,m = map(int,input().split())
    ans = -1
    if m==1:
        ans = n+n//2
    else: 
        ans = n-n//3
    t = ans
    for i in range(2):
        temp1 = n
        temp2 = ans
        mn = min(n,ans)
        n-=mn
        ans-=mn
        if(i==0):
            if(n==0):
                n+=temp1//2
            if(ans==0):
                ans+=temp2//2
    
    print(t if n==0 and ans==0 else -1)


solve()