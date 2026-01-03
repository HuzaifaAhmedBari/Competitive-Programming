n = int(input())
a = input()
b = input()
print(sum(a[i]!=b[i] for i in range(n)))