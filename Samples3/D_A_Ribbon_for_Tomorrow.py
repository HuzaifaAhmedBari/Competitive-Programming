import sys

def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    MOD = 998244353
    maxN = 10**6 + 10
    fact = [1]*maxN
    for i in range(1, maxN):
        fact[i] = fact[i-1]*i % MOD
    inv_fact = [1]*maxN
    inv_fact[maxN-1] = pow(fact[maxN-1], MOD-2, MOD)
    for i in range(maxN-2, -1, -1):
        inv_fact[i] = inv_fact[i+1]*(i+1) % MOD

    def C(n, k):
        if k < 0 or k > n:
            return 0
        return fact[n]*inv_fact[k]%MOD*inv_fact[n-k]%MOD

    out = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        s = data[idx].decode(); idx += 1
        m0 = cnt0 = m1 = cnt1 = 0
        i = 0
        L = len(s)
        while i < L:
            j = i
            ch = s[i]
            while j < L and s[j] == ch:
                j += 1
            length = j - i
            if ch == '0':
                m0 += 1; cnt0 += length
            else:
                m1 += 1; cnt1 += length
            i = j
        w0 = 1 if m0 == 0 else C(cnt0-1, m0-1)
        w1 = 1 if m1 == 0 else C(cnt1-1, m1-1)
        out.append(str((w0*w1) % MOD))
    sys.stdout.write("\n".join(out)+"\n")

main()