for _ in range(int(input())):
    n = input()
    a = input()
    print("YES" if a.find('8')!=-1 and len(a)-a.find('8')>=11 else "NO")