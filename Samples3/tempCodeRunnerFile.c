template <class T>
struct SegTree
{
    int n;
    vector<T> seg, pre, post;
    T ID; // identity element (e.g. 0 for sum, -INF for max)

    SegTree(int n, T id) : n(n), ID(id)
    {
        seg.assign(4 * n, ID);
    }

    SegTree(const vector<T> &a) : n((int)a.size())
    {
        seg.assign(4 * n, 0);
        pre.assign(4 * n, 0);
        post.assign(4 * n, 0);
        build(0, 0, n - 1, a);
    }

    void build(int i, int l, int r, const vector<T> &a)
    {
        if (l == r)
        {
            seg[i] = a[l];
            pre[i] = a[l];
            post[i] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * i + 1, l, m, a);
        build(2 * i + 2, m + 1, r, a);
        seg[i] = (seg[2 * i + 1] + seg[2 * i + 2]);
        pre[i] = max({pre[2 * i + 1], seg[2 * i + 1] + pre[2 * i + 2], seg[2 * i + 1], seg[i]});
        post[i] = max({post[2 * i + 2], seg[2 * i + 2] + post[2 * i + 1], seg[2 * i + 2], seg[i]});
    }
    vector<T> query(int i, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
            return {-INT_MAX, 0, -INT_MAX};
        if (ql <= l && r <= qr)
            return {pre[i], seg[i], post[i]};
        int m = (l + r) / 2;
        vector<T> left = query(2 * i + 1, l, m, ql, qr), right = query(2 * i + 2, m + 1, r, ql, qr);
        vector<T> cur(3);
        cur[1] = left[1] + right[1];
        cur[0] = max(left[0], left[1] + right[0]); 
        cur[2] = max(right[2], right[1] + left[2]); 
        return cur;
        // return op(query(2 * i + 1, l, m, ql, qr),
        //           query(2 * i + 2, m + 1, r, ql, qr));
    }

    vector<T> query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

// Example usage:
// auto op = [](long long a, long long b){ return a + b; };
// SegTree<long long, decltype(op)> st(arr, 0LL, op);
// st.update(2, 5);
// cout << st.query(1, 3) << "\n";
void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    inputv(arr);
    SegTree<int> apna(arr);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        vi ans = apna.query(l - 1, r-1); 
        cout<<*max_element(all(ans))<<endl;
    }
}