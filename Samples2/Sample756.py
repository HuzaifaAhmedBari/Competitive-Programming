#Maqsad Nahi Bhoolna
import math
import bisect
from collections import Counter

def solve():
    n = int(input())
    a = list(map(int,input().split()))
    flag = True
    for x in a:
        c = int(math.sqrt(x))
        if c*c!=x:
            flag=False
            break
    print("NO" if flag == True else "YES")
    
    
    
    
for i in range(int(input())):
    solve()