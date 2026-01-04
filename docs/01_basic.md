# 基本設定・型定義・マクロ

このページでは、`wkit.h` で定義されている基本的な型、定数、マクロについて説明します。

---

## 目次

- [型定義](#型定義)
- [定数](#定数)
- [ループマクロ](#ループマクロ)
- [比較・更新マクロ](#比較更新マクロ)
- [ビット操作](#ビット操作)
- [出力マクロ](#出力マクロ)
- [デバッグマクロ](#デバッグマクロ)
- [コンパイラ属性](#コンパイラ属性)
- [メモリ管理](#メモリ管理)
- [スワップ関数](#スワップ関数)

---

## 型定義

### ll

**概要**: `long long` の別名

```c
typedef long long ll;
```

**使用例**:
```c
ll a = 1000000000000LL;
ll b = fast_read_long();
```

---

### ull

**概要**: `unsigned long long` の別名

```c
typedef unsigned long long ull;
```

**使用例**:
```c
ull x = 18446744073709551615ULL;  // ULLONG_MAX
```

---

### PairII

**概要**: int型のペア

```c
typedef struct { int a, b; } PairII;
```

**使用例**:
```c
PairII p = {3, 5};
printf("%d %d\n", p.a, p.b);
```

---

### PairIV

**概要**: int型のキーとll型の値のペア（主にグラフの頂点と重み用）

```c
typedef struct { int v; ll w; } PairIV;
```

**使用例**:
```c
PairIV edge = {2, 100LL};  // 頂点2、重み100
```

---

### PairLL

**概要**: ll型のペア

```c
typedef struct { ll a, b; } PairLL;
```

---

### PointLL

**概要**: 2次元座標を表す構造体（ll型）

```c
typedef struct { ll x, y; } PointLL;
```

**使用例**:
```c
PointLL p = {10, 20};
PointLL q = {30, 40};
PointLL diff = pt_sub(q, p);  // {20, 20}
```

---

## 定数

### INF

**概要**: int型の無限大として使う値

```c
#define INF 1000000000  // 10^9
```

**注意点**:
- `INF + INF` はオーバーフローしない（約20億 < INT_MAX）
- ヘッダーインクルード前に定義すれば上書き可能

---

### INFLL

**概要**: long long型の無限大として使う値

```c
#define INFLL 1000000000000000000LL  // 10^18
```

**注意点**:
- `INFLL + INFLL` はオーバーフローする可能性あり

---

### MOD

**概要**: mod計算で使うデフォルト値

```c
#define MOD 1000000007LL
```

**注意点**:
- 問題によっては `998244353` が必要な場合あり
- ヘッダーインクルード前に定義すれば上書き可能

---

### M_PI

**概要**: 円周率

```c
#define M_PI 3.141592653589793238462643383279502884
```

---

## ループマクロ

### rep(i, n)

**概要**: `i = 0` から `n-1` までのループ

```c
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
```

**使用例**:
```c
rep(i, 5) {
    printf("%d ", i);  // 0 1 2 3 4
}
```

---

### rrep(i, n)

**概要**: `i = n-1` から `0` までの逆順ループ

```c
#define rrep(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
```

**使用例**:
```c
rrep(i, 5) {
    printf("%d ", i);  // 4 3 2 1 0
}
```

---

### REP(i, a, b)

**概要**: `i = a` から `b` まで（両端含む）のループ

```c
#define REP(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
```

**使用例**:
```c
REP(i, 2, 5) {
    printf("%d ", i);  // 2 3 4 5
}
```

---

### RREP(i, a, b)

**概要**: `i = a` から `b` まで（両端含む）の逆順ループ

```c
#define RREP(i, a, b) for(int i = (int)(a); i >= (int)(b); --i)
```

**使用例**:
```c
RREP(i, 5, 2) {
    printf("%d ", i);  // 5 4 3 2
}
```

---

## 比較・更新マクロ

### MIN(a, b)

**概要**: 2つの値の最小値を返す

```c
#define MIN(a, b) ((a) < (b) ? (a) : (b))
```

**注意点**:
- 引数が複数回評価される可能性あり（副作用に注意）

---

### MAX(a, b)

**概要**: 2つの値の最大値を返す

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
```

---

### ABS(a)

**概要**: 絶対値を返す

```c
#define ABS(a) ((a) < 0 ? -(a) : (a))
```

---

### SZ(a)

**概要**: 配列の要素数を返す

```c
#define SZ(a) ((int)(sizeof(a) / sizeof((a)[0])))
```

**使用例**:
```c
int arr[] = {1, 2, 3, 4, 5};
printf("%d\n", SZ(arr));  // 5
```

**注意点**:
- ポインタには使えない（配列のみ）

---

### chmin(a, b)

**概要**: `a` を `min(a, b)` で更新する

```c
#define chmin(a, b) do { if ((b) < (a)) (a) = (b); } while(0)
```

**使用例**:
```c
int a = 10;
chmin(a, 5);   // a = 5
chmin(a, 20);  // a = 5（変化なし）
```

---

### chmax(a, b)

**概要**: `a` を `max(a, b)` で更新する

```c
#define chmax(a, b) do { if ((b) > (a)) (a) = (b); } while(0)
```

**使用例**:
```c
int a = 10;
chmax(a, 15);  // a = 15
chmax(a, 5);   // a = 15（変化なし）
```

---

## ビット操作

### BIT(i)

**概要**: i番目のビットが立った値を返す（0-indexed）

```c
#define BIT(i) (1ULL << (ull)(i))
```

**使用例**:
```c
ull mask = BIT(0) | BIT(2) | BIT(4);  // 0b10101 = 21
```

---

### popcount(x)

**概要**: 立っているビットの数を数える

```c
#define popcount(x) __builtin_popcountll((ull)(x))
```

**使用例**:
```c
int cnt = popcount(0b1011);  // 3
```

---

### ctzll(x)

**概要**: 末尾の連続する0の数を数える（Count Trailing Zeros）

```c
#define ctzll(x) __builtin_ctzll((ull)(x))
```

**使用例**:
```c
int tz = ctzll(0b1000);  // 3
```

**注意点**:
- `x = 0` の場合は未定義動作

---

### clzll(x)

**概要**: 先頭の連続する0の数を数える（Count Leading Zeros）

```c
#define clzll(x) __builtin_clzll((ull)(x))
```

**使用例**:
```c
int lz = clzll(1ULL);  // 63
```

**注意点**:
- `x = 0` の場合は未定義動作

---

### lowbit_u64(x)

**概要**: 最下位の立っているビットのみを取り出す

```c
#define lowbit_u64(x) ((ull)(x) & (ull)(-(ll)(x)))
```

**使用例**:
```c
ull lb = lowbit_u64(0b1010);  // 0b10 = 2
```

---

### FOR_SUBSET(sub, set)

**概要**: 集合 `set` の全ての部分集合を列挙する

```c
#define FOR_SUBSET(sub, set) for(ull sub = (ull)(set); sub; sub = ((sub - 1ULL) & (ull)(set)))
```

**使用例**:
```c
ull set = 0b111;  // {0, 1, 2}
FOR_SUBSET(sub, set) {
    printf("%llu\n", sub);  // 7, 6, 5, 4, 3, 2, 1
}
```

**計算量**: O(2^k) （kは `set` の立っているビット数）

**注意点**:
- 空集合 `0` は含まれない

---

## 出力マクロ

### YESNO(c)

**概要**: 条件に応じて "YES" または "NO" を出力

```c
#define YESNO(c) puts((c) ? "YES" : "NO")
```

**使用例**:
```c
YESNO(n % 2 == 0);  // 偶数なら "YES"
```

---

### YN(c)

**概要**: 条件に応じて "Yes" または "No" を出力

```c
#define YN(c) puts((c) ? "Yes" : "No")
```

**使用例**:
```c
YN(found);  // found が true なら "Yes"
```

---

## デバッグマクロ

> **注意**: これらのマクロは `-DDEBUG` でコンパイルした場合のみ有効です。

### dump_ll(x)

**概要**: ll型変数の値を標準エラー出力に表示

```c
#define dump_ll(x) fprintf(stderr, "%s = %lld\n", #x, (long long)(x))
```

**使用例**:
```c
ll ans = 42;
dump_ll(ans);  // "ans = 42" を stderr に出力
```

---

### dump_u64(x)

**概要**: ull型変数の値を標準エラー出力に表示

```c
#define dump_u64(x) fprintf(stderr, "%s = %llu\n", #x, (unsigned long long)(x))
```

---

### debugf(...)

**概要**: printf形式でデバッグ出力

```c
#define debugf(...) fprintf(stderr, __VA_ARGS__)
```

**使用例**:
```c
debugf("i = %d, j = %d\n", i, j);
```

---

## コンパイラ属性

### CP_INLINE

**概要**: インライン関数を定義するためのマクロ

```c
#define CP_INLINE static inline
```

---

### CP_FORCEINLINE

**概要**: 強制的にインライン化する（GCC/Clang）

```c
#define CP_FORCEINLINE static inline __attribute__((always_inline))
```

---

### CP_LIKELY(x) / CP_UNLIKELY(x)

**概要**: 分岐予測ヒントを与える

```c
#define CP_LIKELY(x)   __builtin_expect(!!(x), 1)
#define CP_UNLIKELY(x) __builtin_expect(!!(x), 0)
```

**使用例**:
```c
if (CP_UNLIKELY(error)) {
    // エラー処理（まれにしか実行されない）
}
```

---

### CP_UNUSED

**概要**: 未使用変数の警告を抑制

```c
#define CP_UNUSED __attribute__((unused))
```

---

### CP_NORETURN

**概要**: 関数が戻らないことを示す

```c
#define CP_NORETURN __attribute__((noreturn))
```

---

## メモリ管理

### xmalloc

**概要**: メモリ確保に失敗したらプログラムを終了する malloc

```c
void* xmalloc(size_t n);
```

**使用例**:
```c
int* arr = (int*)xmalloc(n * sizeof(int));
```

**注意点**:
- メモリ確保失敗時は "Out of memory" を出力して終了

---

### xcalloc

**概要**: ゼロ初期化付きのメモリ確保

```c
void* xcalloc(size_t n, size_t s);
```

**使用例**:
```c
int* arr = (int*)xcalloc(n, sizeof(int));  // ゼロで初期化される
```

---

### xrealloc

**概要**: メモリ再確保

```c
void* xrealloc(void* p, size_t n);
```

---

## スワップ関数

### cp_swap_int

**概要**: int型の値を交換

```c
void cp_swap_int(int* a, int* b);
```

**使用例**:
```c
int a = 1, b = 2;
cp_swap_int(&a, &b);  // a = 2, b = 1
```

---

### cp_swap_ll

**概要**: ll型の値を交換

```c
void cp_swap_ll(ll* a, ll* b);
```
