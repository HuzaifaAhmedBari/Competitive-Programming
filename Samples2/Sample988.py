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
    a=0;b=0
    for i in range(len(s)-1):
        if(s[i]=='0'):
            a+=1
        else:
            b+=1
        if(a==n and b==m):
            print("1")
            return
    a=0;b=0
    for i in range(len(s)-1,0):
        if(s[i]=='0'):
            a+=1
        else:
            b+=1
        if(a==n and b==m):
            print("1")
            return
    print(2)
    
    
solve()