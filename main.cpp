#include <iostream>
#include "cmath"
#include "cstring"

typedef long long ll;
using namespace std;
#define N 100001
ll gcd(ll x, ll y) {
    return x % y ? gcd(y, x % y) : y;
}

void exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    ll tp = x;
    x = y;
    y = tp - a / b * y;
}

ll qpow(ll a, ll n, ll mod) {
    if (n == 0)
        return 1;
    else if (n % 2 == 1)
        return qpow(a, n - 1, mod) * a % mod;
    else {
        ll temp = qpow(a, n / 2, mod) % mod;
        return temp * temp % mod;
    }
}

int main() {
    ll p, q, e, n, fi, d, tmp, x, y;
    char a[N], c[N];
    ll b[N];
    p = 49529, q = 49531;
    printf("p:%lld\nq:%lld\n", p, q);
    n = p * q;
    fi = (p - 1) * (q - 1);
    e = max(p, q) + 2000;
    if (!e % 2)++e;
    for (;; e += 2) {
        if (gcd(fi, e) == 1) {
            break;
        }
    }
    cout << "e:" << e << endl;
    exgcd(e, fi, d, tmp);
    if (d < 0)d += fi;
    printf("请输入消息：\n");
    gets(a);
    for (int i = 0; i < strlen(a); i++) {
        x = (ll) a[i];
        y = qpow(x, e, n);
        b[i] = y;
    }
    for (int i = 0; i < strlen(a); i++) {
        y = b[i];
        x = qpow(y, d, n);
        c[i] = x;
    }
    cout << "加密后消息：\n";
    for (int i = 0; i < strlen(a); i++) {
        printf("%lld", b[i]);
    }
    cout << "\n解密后消息：\n";
    for (int i = 0; i < strlen(c); i++) {
        printf("%c", c[i]);
    }
    return 0;
}
