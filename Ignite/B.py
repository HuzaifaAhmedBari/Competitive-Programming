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
    s = input().strip().lower()
    t = input().strip().lower()
    ans = []
    n = int(len(s));k=int(len(t))
    pi = [0]*k
    j = 0
    for i in range(1,k):
        while(j>0 and (not(t[i]==t[j] or t[i]=='?' or t[j]=='?'))):
            j = pi[j-1]
        if(t[i]==t[j] or t[i]=='?' or t[j]=='?'):
            j+=1
        pi[i] = j
    j = 0
    for i in range(n):
        while(j>0 and (not(t[j]=='?' or t[j]==s[i]))):
            j = pi[j-1]
        if(t[j]=='?' or t[j]==s[i]):
            j+=1
        if(j==k):
            ans.append(i - k + 1)
            j = pi[j-1]    
    print(len(ans))
    for x in ans:
        print(x,end=" ")
    print()
solve()