# クイックリファレンス

`wkit.h` の全関数・マクロの一覧です。

---

## 型定義

| 型名 | 定義 | 説明 |
|------|------|------|
| `ll` | `long long` | 符号付き64bit整数 |
| `ull` | `unsigned long long` | 符号なし64bit整数 |
| `PairII` | `{int a, b}` | int型のペア |
| `PairIV` | `{int v, ll w}` | 頂点と重み |
| `PairLL` | `{ll a, b}` | ll型のペア |
| `PointLL` | `{ll x, y}` | 2次元座標 |

---

## 定数

| 名前 | 値 | 説明 |
|------|-----|------|
| `INF` | 10^9 | int型の無限大 |
| `INFLL` | 10^18 | ll型の無限大 |
| `MOD` | 10^9+7 | デフォルトmod |
| `M_PI` | 3.14159... | 円周率 |

---

## マクロ

### ループ

| マクロ | 説明 |
|--------|------|
| `rep(i, n)` | i = 0 ~ n-1 |
| `rrep(i, n)` | i = n-1 ~ 0 |
| `REP(i, a, b)` | i = a ~ b |
| `RREP(i, a, b)` | i = a ~ b (逆順) |

### 比較・更新

| マクロ | 説明 |
|--------|------|
| `MIN(a, b)` | min(a, b) |
| `MAX(a, b)` | max(a, b) |
| `ABS(a)` | 絶対値 |
| `SZ(a)` | 配列の要素数 |
| `chmin(a, b)` | a = min(a, b) |
| `chmax(a, b)` | a = max(a, b) |

### ビット操作

| マクロ | 説明 |
|--------|------|
| `BIT(i)` | 1ULL << i |
| `popcount(x)` | 立っているビットの数 |
| `ctzll(x)` | 末尾の0の数 |
| `clzll(x)` | 先頭の0の数 |
| `lowbit_u64(x)` | 最下位ビット |
| `FOR_SUBSET(sub, set)` | 部分集合を列挙 |

### 出力

| マクロ | 説明 |
|--------|------|
| `YESNO(c)` | "YES" / "NO" |
| `YN(c)` | "Yes" / "No" |

---

## 入出力 [→詳細](./02_io.md)

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `cp_init_fastio()` | 高速出力を初期化 | O(1) |
| `fast_read_int()` | int読み込み | O(桁) |
| `fast_read_long()` | ll読み込み | O(桁) |
| `fast_read_ull()` | ull読み込み | O(桁) |
| `fast_read_char()` | 空白以外の1文字 | O(1) |
| `fast_read_token(buf, max)` | トークン読み込み | O(長さ) |
| `fast_read_line(buf, max)` | 1行読み込み | O(長さ) |
| `write_char(c)` | 1文字出力 | O(1) |
| `write_str(s)` | 文字列出力 | O(長さ) |
| `write_ll(x)` | ll出力 | O(桁) |
| `write_ull(x)` | ull出力 | O(桁) |
| `write_ln()` | 改行出力 | O(1) |
| `write_double(x, prec)` | 小数出力 | O(prec) |
| `flush_out()` | バッファをフラッシュ | O(size) |
| `print_arr_int(a, n, sep)` | int配列出力 | O(n) |
| `print_arr_ll(a, n, sep)` | ll配列出力 | O(n) |

---

## 数学 [→詳細](./03_math.md)

### 基本演算

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `gcd(a, b)` | 最大公約数 | O(log min) |
| `lcm(a, b)` | 最小公倍数 | O(log min) |
| `floor_div(a, b)` | 床除算 | O(1) |
| `ceil_div(a, b)` | 天井除算 | O(1) |
| `clamp_ll(x, lo, hi)` | 範囲内に収める | O(1) |

### mod演算

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `mod_norm(a, m)` | 正規化 [0, m) | O(1) |
| `mod_add(a, b, m)` | (a + b) mod m | O(1) |
| `mod_sub(a, b, m)` | (a - b) mod m | O(1) |
| `mod_mul(a, b, m)` | (a * b) mod m | O(1) |
| `mod_pow(x, y, m)` | x^y mod m | O(log y) |
| `modinv(a, m)` | a の逆元 | O(log m) |
| `ext_gcd(a, b, &x, &y)` | 拡張ユークリッド | O(log min) |
| `crt_merge(r1,m1,r2,m2,&r,&m)` | 中国剰余定理 | O(log m) |

### 素数

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `is_prime_u64(n)` | 素数判定 | O(log n) |
| `sieve(n)` | エラトステネスの篩 | O(n log log n) |
| `factor_u64(n, fac, &cnt)` | 素因数分解 | O(n^(1/4)) |
| `prime_factors(n, p, e)` | 素因数分解（指数付き） | O(√n) |

### 組み合わせ

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `comb_init(n, mod)` | 前計算 | O(n) |
| `nCr_mod(n, r, mod)` | 二項係数 | O(1) |
| `nPr_mod(n, r, mod)` | 順列 | O(r) |
| `nCr_lucas(n, r, p)` | Lucas定理 | O(p log n) |
| `catalan_mod(n, mod)` | カタラン数 | O(1) |

### その他

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `isqrt_u64(x)` | 整数平方根 | O(log x) |
| `is_square_u64(x)` | 完全平方数判定 | O(log x) |
| `floor_sum_ll(n, m, a, b)` | 床関数の総和 | O(log m) |
| `euler_phi(n)` | オイラー関数 | O(√n) |

---

## データ構造 [→詳細](./04_data_structures.md)

### Union-Find

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `uf_init(n)` | 初期化 | O(n) |
| `uf_find(a)` | 代表元を返す | O(α(n)) |
| `uf_union(a, b)` | 統合 | O(α(n)) |
| `uf_same(a, b)` | 同グループか | O(α(n)) |
| `uf_comp_size(a)` | グループサイズ | O(α(n)) |

### 重み付き Union-Find

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `wuf_init(n)` | 初期化 | O(n) |
| `wuf_find(x)` | 代表元 | O(α(n)) |
| `wuf_weight(x)` | ポテンシャル | O(α(n)) |
| `wuf_union(x, y, w)` | 差wで統合 | O(α(n)) |
| `wuf_dist(x, y)` | 差を取得 | O(α(n)) |

### Fenwick Tree

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `fenwick_init(n)` | 初期化 | O(n) |
| `fenwick_update(i, d)` | a[i] += d | O(log n) |
| `fenwick_sum(i)` | Σa[1..i] | O(log n) |
| `fenwick_range_sum(l, r)` | Σa[l..r] | O(log n) |
| `fenwick_lower_bound(k)` | 累積和≥kの最小i | O(log n) |

### Segment Tree

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `seg_init(n)` | 初期化 | O(n) |
| `seg_update(idx, val)` | a[idx] = val | O(log n) |
| `seg_query(l, r)` | Σa[l..r] | O(log n) |
| `lseg_init(n)` | 遅延セグ木初期化 | O(n) |
| `lseg_add(l, r, x)` | 区間加算 | O(log n) |
| `lseg_sum(l, r)` | 区間和 | O(log n) |

### その他のデータ構造

| 構造体 | 主な関数 | 用途 |
|--------|----------|------|
| `DequeInt` | `deq_init, push_back, pop_front` | 両端キュー |
| `MinHeap` | `mhe_init, mhe_push, mhe_pop` | 最小ヒープ |
| `MaxHeap` | `mxhe_init, mxhe_push, mxhe_pop` | 最大ヒープ |
| `U64Map` | `u64map_init, put, get, add` | ハッシュマップ |
| `StackInt` | `stk_init, stk_push, stk_pop` | スタック |
| `SparseLLMin` | `sparsellmin_init, query` | Sparse Table |

---

## グラフ [→詳細](./05_graph.md)

### 構築

| 関数 | 説明 |
|------|------|
| `graph_init(n)` | 静的グラフ初期化 |
| `add_edge(u, v, w)` | 有向辺追加 |
| `add_undirected_edge(u, v, w)` | 無向辺追加 |
| `graphd_init(&g, n, mcap)` | 動的グラフ初期化 |

### 探索・最短路

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `bfs(start, n)` | 幅優先探索 | O(V+E) |
| `bfs_dist(start, n)` | 重みなし最短距離 | O(V+E) |
| `dfs_iter(start, n)` | 深さ優先探索 | O(V+E) |
| `bfs01(start, n)` | 0-1 BFS | O(V+E) |
| `dijkstra(start, n)` | ダイクストラ | O((V+E)log V) |
| `bellman_ford(n, edges, m, s, dist)` | 負辺対応 | O(VE) |
| `floyd_warshall(n)` | 全点対 | O(V³) |

### 木

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `lca_build(root, n)` | LCA前処理 | O(n log n) |
| `lca(a, b)` | 最近共通祖先 | O(log n) |
| `dist_tree_edges(a, b)` | 木上の距離 | O(log n) |
| `tree_diameter_bfs(n, &u, &v)` | 木の直径 | O(V+E) |
| `euler_tour_build(root, n)` | オイラーツアー | O(V+E) |

### 高度なアルゴリズム

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `topo_sort_copy(n, out)` | トポロジカルソート | O(V+E) |
| `kruskal(n, edges, m, &total)` | 最小全域木 | O(E log E) |
| `scc_kosaraju(&g, comp)` | 強連結成分 | O(V+E) |
| `twosat_solve(&ts, assign)` | 2-SAT | O(V+E) |
| `dinic_max_flow(&f, s, t, lim)` | 最大流 | O(V²E) |
| `mcmf_min_cost_flow(&f, s, t, maxf, &flow, &cost)` | 最小費用流 | O(FVE log V) |

---

## 文字列 [→詳細](./06_string.md)

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `z_algorithm(s, n, z)` | Z配列 | O(n) |
| `kmp_prefix(s, n, pi)` | KMP失敗関数 | O(n) |
| `manacher_u8(s, n, d1, d2)` | 回文半径 | O(n) |
| `suffix_array_u8(s, n, sa)` | Suffix Array | O(n log n) |
| `lcp_kasai_u8(s, n, sa, lcp)` | LCP配列 | O(n) |
| `rh_init(&rh, s, n)` | Rolling Hash | O(n) |
| `rh_get(&rh, l, r)` | 部分文字列ハッシュ | O(1) |
| `trie_insert(s)` | Trie挿入 | O(\|s\|) |
| `btrie_max_xor(x)` | 最大XOR | O(log MAX) |
| `ac_build(&ac)` | Aho-Corasick構築 | O(Σ\|P\|) |
| `rle_encode(s, n, oc, on)` | ランレングス圧縮 | O(n) |

---

## 幾何 [→詳細](./07_geometry.md)

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `pt_add(a, b)` | 点の加算 | O(1) |
| `pt_sub(a, b)` | 点の減算 | O(1) |
| `dot128(a, b)` | 内積 | O(1) |
| `cross128(a, b)` | 外積 | O(1) |
| `cross3(a, b, c)` | 3点の外積 | O(1) |
| `ccw(a, b, c)` | 向き判定 | O(1) |
| `convex_hull(pts, n, hull)` | 凸包 | O(n²) |
| `manhattan(a, b)` | マンハッタン距離 | O(1) |
| `euclidean(a, b)` | ユークリッド距離 | O(1) |
| `geo_poly_area2(p, n)` | 多角形面積×2 | O(n) |
| `geo_pt_in_poly(p, n, q)` | 点の内外判定 | O(n) |

---

## その他 [→詳細](./08_misc.md)

### 乱数

| 関数 | 説明 |
|------|------|
| `cp_rng_seed(s)` | シード設定 |
| `cp_rng_u64()` | 64bit乱数 |
| `cp_rng_bounded(lim)` | [0, lim) の乱数 |
| `cp_shuffle_int(a, n)` | 配列シャッフル |

### ソート・二分探索

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `sort_int(a, n)` | 昇順ソート | O(n log n) |
| `lower_bound_int(a, n, x)` | x以上の最小位置 | O(log n) |
| `upper_bound_int(a, n, x)` | xより大きい最小位置 | O(log n) |
| `unique_int(a, n)` | 重複除去 | O(n) |
| `compress_int_inplace(a, n)` | 座標圧縮 | O(n log n) |

### 順列・探索

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `next_permutation_int(a, n)` | 次の順列 | O(n) |
| `ternary_search_max(lo, hi, f)` | 凸関数の最大値 | O(log(hi-lo)) |
| `ternary_search_min(lo, hi, f)` | 凸関数の最小値 | O(log(hi-lo)) |

### 列処理

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `lis_len(a, n)` | LIS長 | O(n log n) |
| `inversion_count(a, n)` | 転倒数 | O(n log n) |

### 行列・FFT

| 関数 | 説明 | 計算量 |
|------|------|--------|
| `mat2_pow(a, e, mod)` | 2×2行列累乗 | O(log e) |
| `matn_pow(a, e, mod)` | N×N行列累乗 | O(n³ log e) |
| `fib_mod(n, mod)` | フィボナッチ数 | O(log n) |
| `ntt(a, n, inv)` | 数論変換 | O(n log n) |
| `convolution(a, n, b, m, out)` | 畳み込み | O((n+m) log(n+m)) |

### ビット操作

| 関数 | 説明 |
|------|------|
| `bit_floor_u64(x)` | x以下の最大の2べき |
| `bit_ceil_u64(x)` | x以上の最小の2べき |
| `msb_pos(x)` | 最上位ビット位置 |
| `is_pow2(x)` | 2のべき乗判定 |

### 文字列変換

| 関数 | 説明 |
|------|------|
| `str_to_ll(s)` | 文字列→ll |
| `str_mod(s, m)` | 大きな数のmod |
