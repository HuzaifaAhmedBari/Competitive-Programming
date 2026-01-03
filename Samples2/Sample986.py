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
    count = 0;y=0
    flag = False
    for i in range(n):
        if(s[i]=='U'):
            y+=1
        else:
            y-=1
        if(y==0 and flag):
            count+=1
            flag = False
        if(y<0):
            flag = True
    print(count)
    
    
solve()