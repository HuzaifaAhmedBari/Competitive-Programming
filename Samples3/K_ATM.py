x, y = map(float,input().split())
x = int(x)
if(x%5!=0):
    print(f"{y:.2f}")
    exit(0)
if(x+0.50<=y):
    print(f"{y-x-0.50:.2f}")
else:
    print(f"{y:.2f}")