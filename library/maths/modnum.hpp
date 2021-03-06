#pragma once

#include <bits/stdc++.h>
#include "mod.hpp"
#include "mod_inverse.hpp"

using namespace std;

template <typename T, int md>
struct Modnum {
    using M = Modnum;
    T v;
    Modnum(int64_t v_=0) : v(fix(v_)) {}

    T fix(int64_t x) {
        if (x < -md || x > 2 * md) x %= md;
        if (x >= md) x -= md;
        if (x < 0) x += md;
        return x;
    }

    M operator-()    { return M(-v); };
    M operator+(M o) { return M(v + o.v); }
    M operator-(M o) { return M(v - o.v); }
    M operator*(M o) { return M(fix((int64_t) v * o.v)); }
    M operator/(M o) { return *this * modInv(o.v, md); }
    M pow(int64_t x) {
        M a(v);
        M res(1);
        while (x) {
            if (x & 1) res = res * a;
            a = a * a;
            x >>= 1;
        }
        return res;
    }

    friend istream& operator>>(istream& is, M& o) {
        is >> o.v; o.v = o.fix(o.v); return is;
    }
    friend ostream& operator<<(ostream& os, const M& o) {
        return os << o.v;
    }

    friend T abs(const M& m) { if (m.v < 0) return -m.v; return m.v; }
};
