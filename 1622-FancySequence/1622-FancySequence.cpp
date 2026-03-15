// Last updated: 16/03/2026, 00:02:26
1class Fancy {
2public:
3    const long long MOD = 1e9 + 7;
4    vector<long long> arr;
5    long long mul = 1;
6    long long add = 0;
7
8    long long modPow(long long a, long long b) {
9        long long res = 1;
10        a %= MOD;
11        while (b) {
12            if (b & 1) res = (res * a) % MOD;
13            a = (a * a) % MOD;
14            b >>= 1;
15        }
16        return res;
17    }
18
19    long long modInv(long long x) {
20        return modPow(x, MOD - 2);
21    }
22
23    Fancy() {}
24
25    void append(int val) {
26        long long normalized = ((val - add) % MOD + MOD) % MOD;
27        normalized = (normalized * modInv(mul)) % MOD;
28        arr.push_back(normalized);
29    }
30
31    void addAll(int inc) {
32        add = (add + inc) % MOD;
33    }
34
35    void multAll(int m) {
36        mul = (mul * m) % MOD;
37        add = (add * m) % MOD;
38    }
39
40    int getIndex(int idx) {
41        if (idx >= arr.size()) return -1;
42        return (arr[idx] * mul + add) % MOD;
43    }
44};