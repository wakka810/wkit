# その他ユーティリティ

このページでは、`wkit.h` のその他の便利な関数について説明します。

---

## 目次

- [乱数](#乱数)
- [ソート・二分探索](#ソート二分探索)
- [座標圧縮](#座標圧縮)
- [順列](#順列)
- [三分探索](#三分探索)
- [LIS（最長増加部分列）](#lis)
- [転倒数](#転倒数)
- [行列累乗](#行列累乗)
- [NTT・畳み込み](#ntt畳み込み)
- [ビット操作](#ビット操作)
- [文字列変換](#文字列変換)
- [デバッグ](#デバッグ)

---

## 乱数

XorShift ベースの高速な擬似乱数生成器。

### cp_rng_seed

**概要**: 乱数のシードを設定

**シグネチャ**:
```c
void cp_rng_seed(ull s);
```

**使用例**:
```c
cp_rng_seed(12345ULL);
```

---

### cp_rng_u64

**概要**: 64bit 乱数を生成

**シグネチャ**:
```c
ull cp_rng_u64(void);
```

**計算量**: O(1)

**使用例**:
```c
ull r = cp_rng_u64();
```

---

### cp_rng_bounded

**概要**: [0, lim) の範囲の乱数を生成

**シグネチャ**:
```c
ull cp_rng_bounded(ull lim);
```

**計算量**: O(1) 期待値

**使用例**:
```c
ull r = cp_rng_bounded(100);  // 0 ~ 99
```

---

### cp_shuffle_int / cp_shuffle_ll

**概要**: 配列をシャッフル

**シグネチャ**:
```c
void cp_shuffle_int(int* a, int n);
void cp_shuffle_ll(ll* a, int n);
```

**計算量**: O(n)

**使用例**:
```c
int a[] = {1, 2, 3, 4, 5};
cp_shuffle_int(a, 5);
```

---

## ソート・二分探索

### sort_int / sort_ll

**概要**: 配列を昇順ソート

**シグネチャ**:
```c
void sort_int(int* a, int n);
void sort_ll(ll* a, int n);
```

**計算量**: O(n log n)

**使用例**:
```c
int a[] = {3, 1, 4, 1, 5};
sort_int(a, 5);  // {1, 1, 3, 4, 5}
```

---

### lower_bound_int / lower_bound_ll

**概要**: x 以上の最小の要素のインデックスを返す

**シグネチャ**:
```c
int lower_bound_int(const int* a, int n, int x);
int lower_bound_ll(const ll* a, int n, ll x);
```

**計算量**: O(log n)

**使用例**:
```c
int a[] = {1, 2, 4, 4, 6};
int idx = lower_bound_int(a, 5, 4);  // 2
```

---

### upper_bound_int / upper_bound_ll

**概要**: x より大きい最小の要素のインデックスを返す

**シグネチャ**:
```c
int upper_bound_int(const int* a, int n, int x);
int upper_bound_ll(const ll* a, int n, ll x);
```

**計算量**: O(log n)

**使用例**:
```c
int a[] = {1, 2, 4, 4, 6};
int idx = upper_bound_int(a, 5, 4);  // 4
```

---

### unique_int / unique_ll

**概要**: ソート済み配列から重複を除去

**シグネチャ**:
```c
int unique_int(int* a, int n);
int unique_ll(ll* a, int n);
```

**戻り値**: 重複除去後の要素数

**計算量**: O(n)

**使用例**:
```c
int a[] = {1, 1, 2, 3, 3, 3};
int m = unique_int(a, 6);  // m = 3, a = {1, 2, 3, ...}
```

---

## 座標圧縮

### compress_int_inplace / compress_ll_inplace

**概要**: 配列の要素を座標圧縮（0, 1, 2, ... に変換）

**シグネチャ**:
```c
int compress_int_inplace(int* a, int n);
int compress_ll_inplace(ll* a, int n);
```

**戻り値**: 圧縮後の値の種類数

**計算量**: O(n log n)

**使用例**:
```c
ll a[] = {100, 50, 200, 50, 100};
int m = compress_ll_inplace(a, 5);
// m = 3
// a = {1, 0, 2, 0, 1}
```

---

## 順列

### next_permutation_int

**概要**: 次の辞書順順列を生成

**シグネチャ**:
```c
bool next_permutation_int(int* a, int n);
```

**戻り値**: 次の順列が存在すれば `true`

**計算量**: O(n) 最悪

**使用例**:
```c
int a[] = {0, 1, 2};
do {
    // a を処理
} while (next_permutation_int(a, 3));
// 0,1,2 → 0,2,1 → 1,0,2 → 1,2,0 → 2,0,1 → 2,1,0
```

---

## 三分探索

### ternary_search_max

**概要**: 凸関数の最大値を求める

**シグネチャ**:
```c
ll ternary_search_max(ll lo, ll hi, ll (*f)(ll));
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| lo | ll | 探索範囲の下限 |
| hi | ll | 探索範囲の上限 |
| f | ll (*)(ll) | 評価関数（上に凸） |

**戻り値**: 最大値

**計算量**: O(log(hi - lo))

**使用例**:
```c
ll f(ll x) {
    return -(x - 50) * (x - 50);  // x = 50 で最大
}

ll max_val = ternary_search_max(0, 100, f);
```

---

### ternary_search_min

**概要**: 凸関数の最小値を求める

**シグネチャ**:
```c
ll ternary_search_min(ll lo, ll hi, ll (*f)(ll));
```

**使用例**:
```c
ll f(ll x) {
    return (x - 50) * (x - 50);  // x = 50 で最小
}

ll min_val = ternary_search_min(0, 100, f);
```

---

## LIS

### lis_len

**概要**: 最長増加部分列の長さを求める

**シグネチャ**:
```c
int lis_len(const ll* a, int n);
```

**戻り値**: LIS の長さ

**計算量**: O(n log n)

**使用例**:
```c
ll a[] = {3, 1, 4, 1, 5, 9, 2, 6};
int len = lis_len(a, 8);  // 4（例: 1, 4, 5, 6）
```

---

## 転倒数

### inversion_count

**概要**: 配列の転倒数（i < j かつ a[i] > a[j] となるペアの数）を求める

**シグネチャ**:
```c
ll inversion_count(ll* a, int n);
```

**戻り値**: 転倒数

**計算量**: O(n log n)

**使用例**:
```c
ll a[] = {3, 1, 2};
ll inv = inversion_count(a, 3);  // 2（(3,1), (3,2)）
```

**注意点**:
- 配列 `a` は**破壊される**（ソートされる）

---

## 行列累乗

### 2x2 行列

```c
typedef struct { ll m[2][2]; } Mat2;
```

#### mat2_mul

**概要**: 2x2 行列の積

**シグネチャ**:
```c
Mat2 mat2_mul(Mat2 a, Mat2 b, ll mod);
```

#### mat2_pow

**概要**: 2x2 行列の累乗

**シグネチャ**:
```c
Mat2 mat2_pow(Mat2 a, ll e, ll mod);
```

**計算量**: O(log e)

---

### fib_mod

**概要**: フィボナッチ数を行列累乗で計算

**シグネチャ**:
```c
ll fib_mod(ll n, ll mod);
```

**戻り値**: F(n) mod m

**計算量**: O(log n)

**使用例**:
```c
ll f = fib_mod(1000000000000LL, MOD);
```

---

### N×N 行列

```c
typedef struct { int n; ll** m; } MatN;
```

#### matn_alloc

**概要**: N×N 行列を確保

**シグネチャ**:
```c
MatN matn_alloc(int n);
```

#### matn_mul

**概要**: N×N 行列の積

**シグネチャ**:
```c
MatN matn_mul(MatN a, MatN b, ll mod);
```

**計算量**: O(n³)

#### matn_pow

**概要**: N×N 行列の累乗

**シグネチャ**:
```c
MatN matn_pow(MatN a, ll e, ll mod);
```

**計算量**: O(n³ log e)

#### matn_free

**概要**: 行列のメモリを解放

**シグネチャ**:
```c
void matn_free(MatN* a);
```

---

## NTT・畳み込み

### ntt

**概要**: Number Theoretic Transform（数論変換）

**シグネチャ**:
```c
void ntt(ll* a, int n, int inv);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| a | ll* | 変換する配列 |
| n | int | 配列サイズ（2のべき乗） |
| inv | int | 0: 正変換、1: 逆変換 |

**計算量**: O(n log n)

**注意点**:
- MOD は `NTT_MOD = 998244353`

---

### convolution

**概要**: 多項式の畳み込み（乗算）

**シグネチャ**:
```c
void convolution(const ll* a, int n, const ll* b, int m, ll* out);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| a | const ll* | 多項式 A の係数 |
| n | int | A の項数 |
| b | const ll* | 多項式 B の係数 |
| m | int | B の項数 |
| out | ll* | 結果を格納（サイズ n+m-1 以上） |

**計算量**: O((n+m) log(n+m))

**使用例**:
```c
ll a[] = {1, 2, 3};  // 1 + 2x + 3x²
ll b[] = {4, 5};     // 4 + 5x
ll c[10];
convolution(a, 3, b, 2, c);
// c = {4, 13, 22, 15}  // 4 + 13x + 22x² + 15x³
```

---

## ビット操作

### bit_floor_u64

**概要**: x 以下の最大の2のべき乗

**シグネチャ**:
```c
ull bit_floor_u64(ull x);
```

**使用例**:
```c
ull y = bit_floor_u64(10);  // 8
```

---

### bit_ceil_u64

**概要**: x 以上の最小の2のべき乗

**シグネチャ**:
```c
ull bit_ceil_u64(ull x);
```

**使用例**:
```c
ull y = bit_ceil_u64(10);  // 16
```

---

### bit_reverse_u64

**概要**: 64bitのビット順序を反転

**シグネチャ**:
```c
ull bit_reverse_u64(ull x);
```

---

### msb_pos

**概要**: 最上位ビットの位置

**シグネチャ**:
```c
int msb_pos(ull x);
```

**戻り値**: 最上位ビットの位置（0-indexed）。x=0 なら -1

**使用例**:
```c
int pos = msb_pos(10);  // 3（10 = 0b1010）
```

---

### is_pow2

**概要**: 2のべき乗かどうか判定

**シグネチャ**:
```c
bool is_pow2(ull x);
```

**使用例**:
```c
if (is_pow2(16)) printf("2のべき乗\n");
```

---

### next_pow2

**概要**: x 以上の最小の2のべき乗

**シグネチャ**:
```c
ull next_pow2(ull x);
```

---

## 文字列変換

### str_to_ll

**概要**: 文字列を long long に変換

**シグネチャ**:
```c
ll str_to_ll(const char* s);
```

**使用例**:
```c
ll x = str_to_ll("-12345");  // -12345
```

---

### str_mod

**概要**: 文字列で表された整数を mod で計算

**シグネチャ**:
```c
ll str_mod(const char* s, ll m);
```

**計算量**: O(|s|)

**使用例**:
```c
// 非常に大きな数の mod
ll r = str_mod("123456789012345678901234567890", MOD);
```

---

## デバッグ

> **注意**: これらの関数は `-DDEBUG` でコンパイルした場合のみ有効です。

### dump_arr_int / dump_arr_ll

**概要**: 配列の内容を標準エラー出力に表示

**シグネチャ**:
```c
void dump_arr_int(const char* name, const int* a, int n);
void dump_arr_ll(const char* name, const ll* a, int n);
```

**使用例**:
```c
int a[] = {1, 2, 3, 4, 5};
dump_arr_int("a", a, 5);
// 出力: a = [1, 2, 3, 4, 5]
```

---

### get_time_sec

**概要**: 現在時刻を秒単位で取得（高精度）

**シグネチャ**:
```c
double get_time_sec(void);
```

**使用例**:
```c
double start = get_time_sec();
// 処理
double end = get_time_sec();
fprintf(stderr, "実行時間: %.3f秒\n", end - start);
```

**注意点**:
- `CLOCK_MONOTONIC` を使用
- DEBUG モードでのみ使用可能
