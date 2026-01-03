n = input()
if(n.find('0')==-1):
    n = int(n)
    n+=1
n = str(n)
c = str()
for _ in range(len(n)):
    if(n[_]=='0'):
        c+='1'
    else:
        c+=n[_]
print(c)