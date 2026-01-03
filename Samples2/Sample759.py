#Maqsad Nahi Bhoolna
import sys
import math
import bisect
import heapq
from collections import defaultdict, deque, Counter
from itertools import accumulate, permutations, combinations, product
from functools import reduce
input = sys.stdin.readline

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
def lcm(a, b):
    return a * b // math.gcd(a, b)
def sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0:2] = [False, False]
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    primes = [i for i, val in enumerate(is_prime) if val]
    return primes, is_prime
    
def solve():
    n = int(input())
    a = list(map(int,input().split()))
    b = [-1]*1001
    ans = -1
    for i,val in enumerate(a):
        b[val] = i+1
    for i in range(1001):
        for j in range(1001):
            if(gcd(i,j)==1 and b[i]!=-1 and b[j]!=-1):
                ans = max(ans,b[i]+b[j])
    print(ans)
    
    
    
for _ in range(int(input())):
    solve()