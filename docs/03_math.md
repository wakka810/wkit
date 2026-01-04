# 数学関数

このページでは、`wkit.h` の数学関連の関数について説明します。

---

## 目次

- [基本演算](#基本演算)
- [mod演算](#mod演算)
- [拡張ユークリッド互除法](#拡張ユークリッド互除法)
- [中国剰余定理](#中国剰余定理)
- [素数関連](#素数関連)
- [組み合わせ](#組み合わせ)
- [べき乗・平方根](#べき乗平方根)
- [その他](#その他)

---

## 基本演算

### gcd

**概要**: 最大公約数を求める

**シグネチャ**:
```c
ll gcd(ll a, ll b);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| a | ll | 整数1 |
| b | ll | 整数2 |

**戻り値**: gcd(|a|, |b|)

**計算量**: O(log min(a, b))

**使用例**:
```c
ll g = gcd(12, 18);  // 6
ll g2 = gcd(-12, 18);  // 6（負の数も可）
```

---

### gcd_u64

**概要**: 符号なし整数の最大公約数

**シグネチャ**:
```c
ull gcd_u64(ull a, ull b);
```

**計算量**: O(log min(a, b))

---

### lcm

**概要**: 最小公倍数を求める

**シグネチャ**:
```c
ll lcm(ll a, ll b);
```

**戻り値**: lcm(|a|, |b|)。オーバーフロー時は `LLONG_MAX` を返す

**計算量**: O(log min(a, b))

**使用例**:
```c
ll l = lcm(12, 18);  // 36
```

**注意点**:
- 内部で `__int128` を使ってオーバーフローを検出

---

### floor_div

**概要**: 床除算（負の数でも正しく床を取る）

**シグネチャ**:
```c
ll floor_div(ll a, ll b);
```

**戻り値**: floor(a / b)

**計算量**: O(1)

**使用例**:
```c
ll x = floor_div(7, 3);    // 2
ll y = floor_div(-7, 3);   // -3（C言語の / は -2 を返す）
ll z = floor_div(7, -3);   // -3
```

**注意点**:
- C言語の `/` は0に向かって切り捨てるが、この関数は常に負の無限大に向かって切り捨てる

---

### ceil_div

**概要**: 天井除算

**シグネチャ**:
```c
ll ceil_div(ll a, ll b);
```

**戻り値**: ceil(a / b)

**計算量**: O(1)

**使用例**:
```c
ll x = ceil_div(7, 3);   // 3
ll y = ceil_div(-7, 3);  // -2
```

---

### clamp_ll

**概要**: 値を範囲内に収める

**シグネチャ**:
```c
ll clamp_ll(ll x, ll lo, ll hi);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| x | ll | 対象の値 |
| lo | ll | 下限 |
| hi | ll | 上限 |

**戻り値**: max(lo, min(x, hi))

**計算量**: O(1)

**使用例**:
```c
ll y = clamp_ll(15, 0, 10);  // 10
ll z = clamp_ll(-5, 0, 10);  // 0
ll w = clamp_ll(5, 0, 10);   // 5
```

---

## mod演算

### mod_norm

**概要**: 値を [0, m) の範囲に正規化する

**シグネチャ**:
```c
ll mod_norm(ll a, ll m);
```

**戻り値**: a を m で割った余り（常に非負）

**計算量**: O(1)

**使用例**:
```c
ll x = mod_norm(-7, 5);  // 3 （-7 ≡ 3 (mod 5)）
ll y = mod_norm(12, 5);  // 2
```

---

### mod_add

**概要**: mod 上での加算

**シグネチャ**:
```c
ll mod_add(ll a, ll b, ll m);
```

**戻り値**: (a + b) mod m

**計算量**: O(1)

**使用例**:
```c
ll x = mod_add(7, 8, 10);  // 5
```

---

### mod_sub

**概要**: mod 上での減算

**シグネチャ**:
```c
ll mod_sub(ll a, ll b, ll m);
```

**戻り値**: (a - b) mod m （常に非負）

**計算量**: O(1)

**使用例**:
```c
ll x = mod_sub(3, 8, 10);  // 5 （3 - 8 = -5 ≡ 5 (mod 10)）
```

---

### mod_mul

**概要**: mod 上での乗算

**シグネチャ**:
```c
ll mod_mul(ll a, ll b, ll m);
```

**戻り値**: (a * b) mod m

**計算量**: O(1)

**使用例**:
```c
ll x = mod_mul(123456789, 987654321, MOD);
```

**注意点**:
- 内部で `__int128` を使用してオーバーフローを回避

---

### mod_pow

**概要**: mod 上でのべき乗

**シグネチャ**:
```c
ll mod_pow(ll x, ll y, ll m);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| x | ll | 底 |
| y | ll | 指数（非負） |
| m | ll | 法 |

**戻り値**: x^y mod m

**計算量**: O(log y)

**使用例**:
```c
ll x = mod_pow(2, 10, MOD);  // 1024
ll inv = mod_pow(3, MOD - 2, MOD);  // 3 の逆元（MODが素数の場合）
```

---

### modinv

**概要**: mod 上での逆元を求める

**シグネチャ**:
```c
ll modinv(ll a, ll m);
```

**戻り値**: a の逆元 x（ax ≡ 1 (mod m)）。逆元が存在しない場合は -1

**計算量**: O(log m)

**使用例**:
```c
ll inv = modinv(3, MOD);  // 3 の逆元
ll x = mod_mul(6, inv, MOD);  // 6 / 3 = 2
```

**注意点**:
- gcd(a, m) = 1 でないと逆元は存在しない

---

## 拡張ユークリッド互除法

### ext_gcd

**概要**: ax + by = gcd(a, b) となる x, y を求める

**シグネチャ**:
```c
ll ext_gcd(ll a, ll b, ll* x, ll* y);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| a | ll | 整数1 |
| b | ll | 整数2 |
| x | ll* | 解 x を格納するポインタ |
| y | ll* | 解 y を格納するポインタ |

**戻り値**: gcd(a, b)

**計算量**: O(log min(a, b))

**使用例**:
```c
ll x, y;
ll g = ext_gcd(12, 8, &x, &y);
// g = 4, x = 1, y = -1 (12*1 + 8*(-1) = 4)
```

---

## 中国剰余定理

### crt_merge

**概要**: 2つの合同式を1つにマージする

x ≡ r1 (mod m1), x ≡ r2 (mod m2) を満たす x ≡ r (mod m) を求める

**シグネチャ**:
```c
bool crt_merge(ll r1, ll m1, ll r2, ll m2, ll* r, ll* m);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| r1 | ll | 1つ目の剰余 |
| m1 | ll | 1つ目の法 |
| r2 | ll | 2つ目の剰余 |
| m2 | ll | 2つ目の法 |
| r | ll* | 結果の剰余を格納 |
| m | ll* | 結果の法を格納 |

**戻り値**: 解が存在すれば `true`、存在しなければ `false`

**計算量**: O(log min(m1, m2))

**使用例**:
```c
ll r, m;
if (crt_merge(2, 3, 3, 5, &r, &m)) {
    // x ≡ 2 (mod 3) かつ x ≡ 3 (mod 5) → x ≡ 8 (mod 15)
    printf("x ≡ %lld (mod %lld)\n", r, m);
}
```

---

## 素数関連

### is_prime_u64

**概要**: 素数判定（Miller-Rabin法）

**シグネチャ**:
```c
bool is_prime_u64(ull n);
```

**戻り値**: n が素数なら `true`

**計算量**: O(log n)（定数回の冪乗剰余）

**使用例**:
```c
if (is_prime_u64(1000000007)) {
    printf("素数です\n");
}
```

**注意点**:
- 決定的アルゴリズム（64bit以下で正確）

---

### sieve

**概要**: エラトステネスの篩で素数リストを生成

**シグネチャ**:
```c
void sieve(int n);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| n | int | 篩の上限（MAXP以下） |

**計算量**: O(n log log n)

**使用例**:
```c
sieve(1000000);
// is_prime_sieve[i]: i が素数なら 1
// prime_list[0..prime_cnt-1]: 素数のリスト
printf("素数の個数: %d\n", prime_cnt);
```

**グローバル変数**:
- `is_prime_sieve[]`: 素数判定配列
- `prime_list[]`: 素数リスト
- `prime_cnt`: 素数の個数

**注意点**:
- `MAXP`（デフォルト 1000000）がサイズ上限

---

### factor_u64

**概要**: Pollard's rho 法で高速素因数分解

**シグネチャ**:
```c
void factor_u64(ull n, ull* fac, int* cnt);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| n | ull | 素因数分解する数 |
| fac | ull* | 素因数を格納する配列 |
| cnt | int* | 素因数の個数を格納 |

**計算量**: O(n^(1/4)) （期待値）

**使用例**:
```c
ull factors[64];
int cnt;
factor_u64(1234567890123456789ULL, factors, &cnt);
rep(i, cnt) {
    printf("%llu\n", factors[i]);
}
```

**注意点**:
- 素因数は重複を含む（例: 12 → {2, 2, 3}）
- 結果はソート済み

---

### prime_factors

**概要**: 試し割りによる素因数分解（指数付き）

**シグネチャ**:
```c
int prime_factors(ll n, ll* primes, int* exps);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| n | ll | 素因数分解する数 |
| primes | ll* | 素因数を格納する配列 |
| exps | int* | 各素因数の指数を格納 |

**戻り値**: 素因数の種類数

**計算量**: O(√n)

**使用例**:
```c
ll primes[64];
int exps[64];
int cnt = prime_factors(360, primes, exps);
// 360 = 2^3 * 3^2 * 5^1
// primes = {2, 3, 5}, exps = {3, 2, 1}, cnt = 3
rep(i, cnt) {
    printf("%lld^%d ", primes[i], exps[i]);
}
```

---

## 組み合わせ

### comb_init

**概要**: 組み合わせ計算のための前計算（階乗とその逆元）

**シグネチャ**:
```c
void comb_init(int n, ll mod);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| n | int | 前計算する最大値（MAXF以下） |
| mod | ll | 法（素数である必要あり） |

**計算量**: O(n)

**使用例**:
```c
comb_init(200000, MOD);
```

**グローバル変数**:
- `fac[]`: 階乗テーブル
- `ifac[]`: 階乗の逆元テーブル

---

### nCr_mod

**概要**: 二項係数 nCr を mod で計算

**シグネチャ**:
```c
ll nCr_mod(int n, int r, ll mod);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| n | int | 上の数 |
| r | int | 下の数 |
| mod | ll | 法 |

**戻り値**: nCr mod m（r < 0 または r > n なら 0）

**計算量**: O(1)（前計算済みの場合）

**使用例**:
```c
comb_init(200000, MOD);
ll ans = nCr_mod(10, 3, MOD);  // 120
```

**注意点**:
- 事前に `comb_init` が必要
- n が MAXF を超えると 0 を返す

---

### nPr_mod

**概要**: 順列 nPr を mod で計算

**シグネチャ**:
```c
ll nPr_mod(int n, int r, ll mod);
```

**戻り値**: nPr mod m

**計算量**: O(r)

**使用例**:
```c
ll ans = nPr_mod(10, 3, MOD);  // 720
```

---

### nCr_lucas

**概要**: Lucas の定理を使って nCr を計算（n, r が大きい場合）

**シグネチャ**:
```c
ll nCr_lucas(ll n, ll r, ll p);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| n | ll | 上の数（大きくてもOK） |
| r | ll | 下の数 |
| p | ll | 法（小さい素数） |

**戻り値**: nCr mod p

**計算量**: O(p log_p(n))

**使用例**:
```c
ll ans = nCr_lucas(1000000000000LL, 123456789LL, 13);
```

**注意点**:
- p が小さい素数のとき有効

---

### catalan_mod

**概要**: カタラン数を計算

**シグネチャ**:
```c
ll catalan_mod(int n, ll mod);
```

**戻り値**: 第n番カタラン数 mod m

**計算量**: O(1)（前計算済みの場合）

**使用例**:
```c
comb_init(200000, MOD);
ll cat = catalan_mod(5, MOD);  // 42
```

---

## べき乗・平方根

### pow_leq_ull

**概要**: a^e が limit 以下かどうかを判定

**シグネチャ**:
```c
bool pow_leq_ull(ull a, ull e, ull limit);
```

**戻り値**: a^e ≤ limit なら `true`

**計算量**: O(log e)

**使用例**:
```c
if (pow_leq_ull(2, 60, ULLONG_MAX)) {
    printf("2^60 は 64bit に収まる\n");
}
```

---

### pow_u128

**概要**: 128bit整数としてべき乗を計算

**シグネチャ**:
```c
unsigned __int128 pow_u128(ull a, ull e);
```

**戻り値**: a^e（unsigned __int128）

**計算量**: O(log e)

---

### isqrt_u64

**概要**: 整数平方根（floor(√x)）

**シグネチャ**:
```c
ull isqrt_u64(ull x);
```

**戻り値**: floor(√x)

**計算量**: O(log x)

**使用例**:
```c
ull s = isqrt_u64(17);  // 4
```

---

### is_square_u64

**概要**: 完全平方数かどうかを判定

**シグネチャ**:
```c
bool is_square_u64(ull x);
```

**戻り値**: x が完全平方数なら `true`

**計算量**: O(log x)

**使用例**:
```c
if (is_square_u64(144)) {
    printf("144 は完全平方数\n");
}
```

---

## その他

### floor_sum_ll

**概要**: Σ_{i=0}^{n-1} floor((a*i + b) / m) を計算

**シグネチャ**:
```c
ll floor_sum_ll(ll n, ll m, ll a, ll b);
```

**戻り値**: 床関数の総和

**計算量**: O(log m)

**使用例**:
```c
ll sum = floor_sum_ll(10, 3, 2, 1);
// Σ floor((2i+1)/3) for i=0..9
```

---

### euler_phi

**概要**: オイラーのφ関数（n と互いに素な 1≤k≤n の個数）

**シグネチャ**:
```c
ll euler_phi(ll n);
```

**戻り値**: φ(n)

**計算量**: O(√n)

**使用例**:
```c
ll phi = euler_phi(12);  // 4 (1, 5, 7, 11)
```

---

### safe_mul_ll

**概要**: オーバーフローなしで乗算できるか判定して計算

**シグネチャ**:
```c
bool safe_mul_ll(ll a, ll b, ll* r);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| a | ll | 被乗数 |
| b | ll | 乗数 |
| r | ll* | 結果を格納 |

**戻り値**: オーバーフローしなければ `true`

**使用例**:
```c
ll result;
if (safe_mul_ll(1000000000LL, 1000000000LL, &result)) {
    printf("結果: %lld\n", result);
} else {
    printf("オーバーフロー\n");
}
```
