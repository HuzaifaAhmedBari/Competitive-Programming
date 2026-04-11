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
    s = input()
    a = s[-3:]
    print(a)
    if(a=="po"):
        print("FILIPINO")
    elif(s[-4:]=="desu" or s[-4:]=="masu"):
        print("JAPANESE")
    else:
        print("KOREAN")
    
    
    
    
for _ in range(int(input())):
    solve()