# データ構造

このページでは、`wkit.h` で実装されているデータ構造について説明します。

---

## 目次

- [Union-Find](#union-find)
- [重み付き Union-Find](#重み付き-union-find)
- [Fenwick Tree（BIT）](#fenwick-tree)
- [Segment Tree](#segment-tree)
- [遅延 Segment Tree](#遅延-segment-tree)
- [Deque](#deque)
- [MinHeap / MaxHeap](#minheap--maxheap)
- [U64Map（ハッシュマップ）](#u64map)
- [Stack](#stack)
- [単調キュー](#単調キュー)
- [Sparse Table](#sparse-table)
- [Convex Hull Trick](#convex-hull-trick)
- [Treap](#treap)

---

## Union-Find

連結成分の管理、グループの統合・検索を効率的に行うデータ構造。

### グローバル変数

```c
static int uf_parent[MAXN];  // 親の頂点
static int uf_size[MAXN];    // 各連結成分のサイズ
```

---

### uf_init

**概要**: Union-Findを初期化（各頂点が独立）

**シグネチャ**:
```c
void uf_init(int n);
```

**計算量**: O(n)

**使用例**:
```c
uf_init(100000);
```

---

### uf_find

**概要**: 頂点が属するグループの代表元を返す

**シグネチャ**:
```c
int uf_find(int a);
```

**戻り値**: a が属するグループの代表元

**計算量**: O(α(n)) ≈ O(1)

**使用例**:
```c
int root = uf_find(5);
```

---

### uf_union

**概要**: 2つの頂点を同じグループに統合

**シグネチャ**:
```c
int uf_union(int a, int b);
```

**戻り値**: 統合が行われたら 1、すでに同じグループなら 0

**計算量**: O(α(n)) ≈ O(1)

**使用例**:
```c
if (uf_union(1, 2)) {
    printf("統合しました\n");
}
```

---

### uf_same

**概要**: 2つの頂点が同じグループかどうか判定

**シグネチャ**:
```c
bool uf_same(int a, int b);
```

**計算量**: O(α(n))

**使用例**:
```c
if (uf_same(1, 2)) {
    printf("同じグループ\n");
}
```

---

### uf_comp_size

**概要**: 頂点が属するグループのサイズを返す

**シグネチャ**:
```c
int uf_comp_size(int a);
```

**計算量**: O(α(n))

**使用例**:
```c
int size = uf_comp_size(5);
```

---

## 重み付き Union-Find

辺に重みがある Union-Find。2頂点間のポテンシャル差を管理できる。

### グローバル変数

```c
static int wuf_par[MAXN];   // 親
static ll wuf_diff[MAXN];   // 親との差分
```

---

### wuf_init

**概要**: 重み付きUnion-Findを初期化

**シグネチャ**:
```c
void wuf_init(int n);
```

**計算量**: O(n)

---

### wuf_find

**概要**: 代表元を返す（経路圧縮で重みも更新）

**シグネチャ**:
```c
int wuf_find(int x);
```

**計算量**: O(α(n))

---

### wuf_weight

**概要**: 頂点のポテンシャル（代表元からの距離）を返す

**シグネチャ**:
```c
ll wuf_weight(int x);
```

**計算量**: O(α(n))

---

### wuf_union

**概要**: weight(y) - weight(x) = w となるように統合

**シグネチャ**:
```c
bool wuf_union(int x, int y, ll w);
```

**戻り値**: 統合が行われたら `true`

**計算量**: O(α(n))

**使用例**:
```c
// x と y の差が w であることを登録
// potencial[y] - potencial[x] = w
wuf_union(0, 1, 5);  // y[1] - y[0] = 5
wuf_union(1, 2, 3);  // y[2] - y[1] = 3
```

---

### wuf_dist

**概要**: 2頂点間のポテンシャル差を返す

**シグネチャ**:
```c
ll wuf_dist(int x, int y);
```

**戻り値**: weight(y) - weight(x)

**計算量**: O(α(n))

**使用例**:
```c
ll d = wuf_dist(0, 2);  // 8 (= 5 + 3)
```

---

## Fenwick Tree

区間和の更新・取得を効率的に行うデータ構造。BIT (Binary Indexed Tree) とも呼ばれる。

### グローバル変数

```c
static int fenwick_n;
static ll fenwick_bit[MAXN + 5];
```

---

### fenwick_init

**概要**: Fenwick Treeを初期化（全要素0）

**シグネチャ**:
```c
void fenwick_init(int n);
```

**計算量**: O(n)

**使用例**:
```c
fenwick_init(100000);
```

**注意点**:
- インデックスは **1-indexed**

---

### fenwick_update

**概要**: i番目の要素に delta を加算

**シグネチャ**:
```c
void fenwick_update(int i, ll delta);
```

**計算量**: O(log n)

**使用例**:
```c
fenwick_update(5, 10);  // a[5] += 10
```

---

### fenwick_sum

**概要**: 先頭からi番目までの累積和を取得

**シグネチャ**:
```c
ll fenwick_sum(int i);
```

**戻り値**: a[1] + a[2] + ... + a[i]

**計算量**: O(log n)

**使用例**:
```c
ll s = fenwick_sum(10);  // a[1] ~ a[10] の和
```

---

### fenwick_range_sum

**概要**: 区間 [l, r] の和を取得

**シグネチャ**:
```c
ll fenwick_range_sum(int l, int r);
```

**戻り値**: a[l] + ... + a[r]

**計算量**: O(log n)

**使用例**:
```c
ll s = fenwick_range_sum(3, 7);  // a[3] ~ a[7] の和
```

---

### fenwick_lower_bound

**概要**: 累積和が k 以上になる最小のインデックスを返す

**シグネチャ**:
```c
int fenwick_lower_bound(ll k);
```

**戻り値**: 最小の i （a[1] + ... + a[i] >= k）

**計算量**: O(log n)

**注意点**:
- 全要素が非負の場合のみ正しく動作

---

## Segment Tree

区間クエリ（和・最小・最大など）を効率的に処理するデータ構造。

### グローバル変数

```c
static int segN;
static ll segtree[4 * MAXN];
```

---

### seg_init

**概要**: Segment Treeを初期化（全要素0）

**シグネチャ**:
```c
void seg_init(int n);
```

**計算量**: O(n)

**使用例**:
```c
seg_init(100000);
```

**注意点**:
- インデックスは **0-indexed**

---

### seg_update

**概要**: idx番目の要素を value に更新

**シグネチャ**:
```c
void seg_update(int idx, ll value);
```

**計算量**: O(log n)

**使用例**:
```c
seg_update(5, 100);  // a[5] = 100
```

---

### seg_query

**概要**: 区間 [l, r] の和を取得

**シグネチャ**:
```c
ll seg_query(int l, int r);
```

**戻り値**: a[l] + a[l+1] + ... + a[r]

**計算量**: O(log n)

**使用例**:
```c
ll s = seg_query(2, 7);  // a[2] ~ a[7] の和
```

---

## 遅延 Segment Tree

区間更新・区間クエリを効率的に処理するデータ構造。

### グローバル変数

```c
static int lsegN;
static ll lseg_val[4 * LSEG_MAX];
static ll lseg_lazy[4 * LSEG_MAX];
```

---

### lseg_init

**概要**: 遅延Segment Treeを初期化

**シグネチャ**:
```c
void lseg_init(int n);
```

**計算量**: O(n)

---

### lseg_add

**概要**: 区間 [l, r) に x を加算

**シグネチャ**:
```c
void lseg_add(int l, int r, ll x);
```

**計算量**: O(log n)

**使用例**:
```c
lseg_init(100000);
lseg_add(0, 10, 5);  // a[0] ~ a[9] に 5 を加算
```

**注意点**:
- 半開区間 [l, r)

---

### lseg_sum

**概要**: 区間 [l, r) の和を取得

**シグネチャ**:
```c
ll lseg_sum(int l, int r);
```

**計算量**: O(log n)

**使用例**:
```c
ll s = lseg_sum(0, 10);
```

---

## Deque

両端からの追加・削除が O(1) で行えるデータ構造。

### 構造体

```c
typedef struct {
    int* a;
    int cap, mask, head, tail;
} DequeInt;
```

---

### deq_init

**概要**: Dequeを初期化

**シグネチャ**:
```c
void deq_init(DequeInt* q, int want);
```

**使用例**:
```c
DequeInt dq;
deq_init(&dq, 1000);
```

---

### deq_free

**概要**: Dequeのメモリを解放

**シグネチャ**:
```c
void deq_free(DequeInt* q);
```

---

### deq_push_back / deq_push_front

**概要**: 末尾/先頭に要素を追加

**シグネチャ**:
```c
void deq_push_back(DequeInt* q, int x);
void deq_push_front(DequeInt* q, int x);
```

**計算量**: O(1) 償却

---

### deq_pop_back / deq_pop_front

**概要**: 末尾/先頭から要素を取り出す

**シグネチャ**:
```c
int deq_pop_back(DequeInt* q);
int deq_pop_front(DequeInt* q);
```

**計算量**: O(1)

---

### deq_size / deq_empty

**概要**: 要素数の取得/空かどうかの判定

**シグネチャ**:
```c
int deq_size(const DequeInt* q);
bool deq_empty(const DequeInt* q);
```

---

## MinHeap / MaxHeap

最小値/最大値を効率的に取得できるヒープ。

### 構造体

```c
typedef struct { int v; ll d; } HeapNode;
typedef struct { HeapNode* a; int sz, cap; } MinHeap;
typedef struct { HeapNode* a; int sz, cap; } MaxHeap;
```

---

### MinHeap 関数群

```c
void mhe_init(MinHeap* h, int cap);  // 初期化
void mhe_free(MinHeap* h);           // メモリ解放
bool mhe_empty(const MinHeap* h);    // 空かどうか
void mhe_push(MinHeap* h, int v, ll d);  // 追加
HeapNode mhe_pop(MinHeap* h);        // 最小要素を取り出す
```

**計算量**: push/pop ともに O(log n)

**使用例**:
```c
MinHeap pq;
mhe_init(&pq, 100);
mhe_push(&pq, 0, 10);  // v=0, d=10
mhe_push(&pq, 1, 5);   // v=1, d=5
HeapNode min = mhe_pop(&pq);  // v=1, d=5
mhe_free(&pq);
```

---

### MaxHeap 関数群

```c
void mxhe_init(MaxHeap* h, int c);
void mxhe_free(MaxHeap* h);
bool mxhe_empty(const MaxHeap* h);
void mxhe_push(MaxHeap* h, int v, ll d);
HeapNode mxhe_pop(MaxHeap* h);
```

---

## U64Map

64bit整数をキーとするハッシュマップ。

### 構造体

```c
typedef struct {
    ull* keys;
    ll* vals;
    int cap, sz;
} U64Map;
```

---

### u64map_init

**概要**: ハッシュマップを初期化

**シグネチャ**:
```c
void u64map_init(U64Map* mp, int init_cap_pow2);
```

**使用例**:
```c
U64Map mp;
u64map_init(&mp, 16);  // 容量16以上で初期化
```

---

### u64map_put

**概要**: キーに値を設定

**シグネチャ**:
```c
int u64map_put(U64Map* mp, ull key, ll val);
```

**戻り値**: 新規挿入なら 1、更新なら 0

**計算量**: O(1) 償却

**使用例**:
```c
u64map_put(&mp, 123456789ULL, 100);
```

---

### u64map_get

**概要**: キーに対応する値を取得

**シグネチャ**:
```c
bool u64map_get(const U64Map* mp, ull key, ll* out);
```

**戻り値**: キーが存在すれば `true`

**計算量**: O(1) 期待

**使用例**:
```c
ll val;
if (u64map_get(&mp, 123456789ULL, &val)) {
    printf("値: %lld\n", val);
}
```

---

### u64map_add

**概要**: キーの値に delta を加算（存在しなければ delta で初期化）

**シグネチャ**:
```c
void u64map_add(U64Map* mp, ull key, ll delta);
```

**使用例**:
```c
u64map_add(&mp, 100ULL, 1);  // カウンタとして使用
```

---

### u64map_free

**概要**: ハッシュマップのメモリを解放

**シグネチャ**:
```c
void u64map_free(U64Map* mp);
```

---

## Stack

LIFO（後入れ先出し）のスタック。

### 構造体

```c
typedef struct {
    int* a;
    int sz, cap;
} StackInt;
```

---

### Stack 関数群

```c
void stk_init(StackInt* s, int c);   // 初期化
void stk_free(StackInt* s);          // メモリ解放
bool stk_empty(const StackInt* s);   // 空かどうか
void stk_push(StackInt* s, int x);   // 追加
int stk_pop(StackInt* s);            // 取り出し
int stk_top(const StackInt* s);      // 先頭を参照
```

**使用例**:
```c
StackInt st;
stk_init(&st, 100);
stk_push(&st, 1);
stk_push(&st, 2);
printf("%d\n", stk_pop(&st));  // 2
stk_free(&st);
```

---

## 単調キュー

スライディングウィンドウ最小値/最大値を効率的に求めるデータ構造。

### グローバル変数

```c
static int monoq_deq[MONOQ_MAX];   // 値
static int monoq_idx[MONOQ_MAX];   // インデックス
static int monoq_head, monoq_tail;
```

---

### monoq_init

**概要**: 単調キューを初期化

**シグネチャ**:
```c
void monoq_init(void);
```

---

### monoq_push_min / monoq_push_max

**概要**: 値とインデックスを追加（単調性を維持）

**シグネチャ**:
```c
void monoq_push_min(int val, int idx);  // 最小値用
void monoq_push_max(int val, int idx);  // 最大値用
```

---

### monoq_pop_old

**概要**: 古いインデックスの要素を削除

**シグネチャ**:
```c
void monoq_pop_old(int old_idx);
```

---

### monoq_front

**概要**: 現在の最小値/最大値を取得

**シグネチャ**:
```c
int monoq_front(void);
```

**使用例**:
```c
// スライディングウィンドウ最小値
monoq_init();
rep(i, n) {
    monoq_push_min(a[i], i);
    if (i >= k - 1) {
        monoq_pop_old(i - k);  // ウィンドウ外を削除
        printf("%d\n", monoq_front());  // 最小値
    }
}
```

---

## Sparse Table

静的な配列の区間最小値（RMQ）を O(1) で求めるデータ構造。

### 構造体

```c
typedef struct {
    int n, K;
    int* lg;
    ll* st;
} SparseLLMin;
```

---

### sparsellmin_init

**概要**: Sparse Tableを構築

**シグネチャ**:
```c
void sparsellmin_init(SparseLLMin* sp, const ll* a, int n);
```

**計算量**: O(n log n)

**使用例**:
```c
ll a[] = {3, 1, 4, 1, 5, 9, 2, 6};
SparseLLMin sp;
sparsellmin_init(&sp, a, 8);
```

---

### sparsellmin_query

**概要**: 区間 [l, r) の最小値を取得

**シグネチャ**:
```c
ll sparsellmin_query(const SparseLLMin* sp, int l, int r);
```

**計算量**: O(1)

**使用例**:
```c
ll min_val = sparsellmin_query(&sp, 0, 5);  // a[0]~a[4] の最小値
```

---

### sparsellmin_free

**概要**: メモリを解放

**シグネチャ**:
```c
void sparsellmin_free(SparseLLMin* sp);
```

---

## Convex Hull Trick

一次関数の集合に対して、任意の x での最小値を効率的に求める。

### グローバル変数

```c
static ll cht_m[CHT_MAX];  // 傾き
static ll cht_b[CHT_MAX];  // 切片
static int cht_head, cht_tail;
```

---

### cht_init

**概要**: CHT を初期化

**シグネチャ**:
```c
void cht_init(void);
```

---

### cht_add

**概要**: 直線 y = mx + b を追加

**シグネチャ**:
```c
void cht_add(ll m, ll b);
```

**計算量**: O(1) 償却

**注意点**:
- 傾き m は**降順**で追加する必要がある

---

### cht_query

**概要**: x における最小値を取得

**シグネチャ**:
```c
ll cht_query(ll x);
```

**計算量**: O(1) 償却

**注意点**:
- クエリの x は**昇順**で行う必要がある

**使用例**:
```c
cht_init();
cht_add(3, 0);   // y = 3x
cht_add(2, 1);   // y = 2x + 1
cht_add(1, 3);   // y = x + 3

printf("%lld\n", cht_query(0));  // min(0, 1, 3) = 0
printf("%lld\n", cht_query(2));  // min(6, 5, 5) = 5
```

---

## Treap

平衡二分探索木。Split/Merge ベースで実装。

### 構造体

```c
typedef struct TrNode {
    int pri, sz;
    ll val, sum, lz;
    struct TrNode *l, *r;
} TrNode;
```

---

### tr_new

**概要**: 新しいノードを作成

**シグネチャ**:
```c
TrNode* tr_new(ll v);
```

---

### tr_split

**概要**: k番目で木を分割

**シグネチャ**:
```c
void tr_split(TrNode* t, int k, TrNode** l, TrNode** r);
```

---

### tr_merge

**概要**: 2つの木をマージ

**シグネチャ**:
```c
void tr_merge(TrNode** t, TrNode* l, TrNode* r);
```

**使用例**:
```c
TrNode* root = NULL;
TrNode* node1 = tr_new(10);
TrNode* node2 = tr_new(20);
TrNode* node3 = tr_new(30);

tr_merge(&root, node1, node2);
tr_merge(&root, root, node3);
// root は [10, 20, 30] を持つ木
```
