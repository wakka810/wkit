# グラフアルゴリズム

このページでは、`wkit.h` のグラフ関連関数について説明します。

---

## 目次

- [グラフ構築（静的）](#グラフ構築静的)
- [グラフ構築（動的）](#グラフ構築動的)
- [探索](#探索)
- [最短路](#最短路)
- [木の操作](#木の操作)
- [最小全域木](#最小全域木)
- [トポロジカルソート](#トポロジカルソート)
- [強連結成分分解](#強連結成分分解)
- [2-SAT](#2-sat)
- [最大流](#最大流)
- [最小費用流](#最小費用流)
- [その他](#その他)

---

## グラフ構築（静的）

グローバル配列を使った隣接リスト表現。`MAXN` 頂点、`MAXM` 辺まで対応。

### グローバル変数

```c
static int graph_head[MAXN];     // 頂点の最初の辺
static int graph_to[MAXM];       // 辺の行き先
static ll graph_w[MAXM];         // 辺の重み
static int graph_nxt[MAXM];      // 次の辺
static int graph_edge_cnt;       // 辺の総数
static int indegree[MAXN];       // 入次数
```

---

### graph_init

**概要**: グラフを初期化

**シグネチャ**:
```c
void graph_init(int n);
```

**計算量**: O(n)

**使用例**:
```c
int n = fast_read_int();
int m = fast_read_int();
graph_init(n);
```

---

### add_edge

**概要**: 有向辺を追加

**シグネチャ**:
```c
void add_edge(int u, int v, ll w);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| u | int | 始点 |
| v | int | 終点 |
| w | ll | 重み |

**計算量**: O(1)

**使用例**:
```c
add_edge(0, 1, 10);  // 0 → 1、重み10
```

---

### add_undirected_edge

**概要**: 無向辺を追加（双方向の有向辺2本を追加）

**シグネチャ**:
```c
void add_undirected_edge(int u, int v, ll w);
```

**計算量**: O(1)

**使用例**:
```c
add_undirected_edge(0, 1, 10);  // 0 ↔ 1
```

---

### 辺の走査パターン

```c
for (int e = graph_head[u]; e != -1; e = graph_nxt[e]) {
    int v = graph_to[e];
    ll w = graph_w[e];
    // u → v（重み w）の辺を処理
}
```

---

## グラフ構築（動的）

メモリを動的に確保するグラフ構造体。サイズが事前にわからない場合に使用。

### 構造体

```c
typedef struct {
    int n, m, mcap;
    int *head, *to, *nxt, *indeg;
    ll *w;
} Graph;
```

---

### graphd_init

**概要**: 動的グラフを初期化

**シグネチャ**:
```c
void graphd_init(Graph* g, int n, int mcap);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| g | Graph* | グラフ構造体 |
| n | int | 頂点数 |
| mcap | int | 初期辺容量 |

**使用例**:
```c
Graph g;
graphd_init(&g, 100000, 200000);
```

---

### graphd_add_edge / graphd_add_undirected

**概要**: 有向辺/無向辺を追加

**シグネチャ**:
```c
void graphd_add_edge(Graph* g, int u, int v, ll w);
void graphd_add_undirected(Graph* g, int u, int v, ll w);
```

**計算量**: O(1) 償却

---

### graphd_free

**概要**: グラフのメモリを解放

**シグネチャ**:
```c
void graphd_free(Graph* g);
```

---

## 探索

### bfs

**概要**: 幅優先探索で到達可能な頂点をマーク

**シグネチャ**:
```c
void bfs(int start, int n);
```

**計算量**: O(V + E)

**グローバル変数**:
- `visited[]`: 訪問済みなら 1

**使用例**:
```c
bfs(0, n);
if (visited[5]) {
    printf("頂点5に到達可能\n");
}
```

---

### bfs_dist

**概要**: BFSで各頂点への最短距離を求める（重みなし）

**シグネチャ**:
```c
void bfs_dist(int start, int n);
```

**計算量**: O(V + E)

**グローバル変数**:
- `dist_arr[]`: 各頂点への距離（到達不能なら INFLL）

**使用例**:
```c
bfs_dist(0, n);
printf("頂点0から頂点5への距離: %lld\n", dist_arr[5]);
```

---

### dfs_iter

**概要**: 深さ優先探索（スタックを使った非再帰版）

**シグネチャ**:
```c
void dfs_iter(int start, int n);
```

**計算量**: O(V + E)

**グローバル変数**:
- `visited[]`: 訪問済みなら 1

---

### bfs01

**概要**: 0-1 BFS（辺の重みが0または1の最短路）

**シグネチャ**:
```c
void bfs01(int start, int n);
```

**計算量**: O(V + E)

**グローバル変数**:
- `dist_arr[]`: 各頂点への最短距離

**使用例**:
```c
// 重み0と重み1の辺が混在するグラフ
bfs01(0, n);
```

---

## 最短路

### dijkstra

**概要**: ダイクストラ法で単一始点最短路を求める

**シグネチャ**:
```c
void dijkstra(int start, int n);
```

**計算量**: O((V + E) log V)

**グローバル変数**:
- `dist_arr[]`: 各頂点への最短距離

**使用例**:
```c
graph_init(n);
rep(i, m) {
    int u = fast_read_int() - 1;
    int v = fast_read_int() - 1;
    ll w = fast_read_long();
    add_edge(u, v, w);
}
dijkstra(0, n);
printf("頂点0から頂点n-1への最短距離: %lld\n", dist_arr[n - 1]);
```

**注意点**:
- 負の重みは不可

---

### bellman_ford

**概要**: ベルマンフォード法（負の重みも可、負閉路検出）

**シグネチャ**:
```c
bool bellman_ford(int n, BFEdge* edges, int m, int s, ll* dist);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| n | int | 頂点数 |
| edges | BFEdge* | 辺の配列 |
| m | int | 辺数 |
| s | int | 始点 |
| dist | ll* | 距離を格納する配列 |

**戻り値**: 負閉路がなければ `true`

**計算量**: O(VE)

**使用例**:
```c
typedef struct { int u, v; ll w; } BFEdge;

BFEdge edges[100000];
// edges を構築
ll dist[MAXN];
if (!bellman_ford(n, edges, m, 0, dist)) {
    printf("負閉路が存在\n");
}
```

---

### floyd_warshall

**概要**: ワーシャルフロイド法（全点対最短路）

**シグネチャ**:
```c
void floyd_warshall(int n);
```

**計算量**: O(V³)

**グローバル変数**:
- `fw_dist[i][j]`: i から j への最短距離

**使用例**:
```c
fw_init(n);  // 初期化
fw_dist[0][1] = 10;  // 辺を追加
fw_dist[1][2] = 20;
floyd_warshall(n);
printf("0から2への最短距離: %lld\n", fw_dist[0][2]);
```

**注意点**:
- `FW_MAX`（デフォルト500）が頂点数上限

---

## 木の操作

### lca_build

**概要**: LCA（最近共通祖先）のためのダブリング前計算

**シグネチャ**:
```c
void lca_build(int root, int n);
```

**計算量**: O(n log n)

**グローバル変数**:
- `lca_up[k][v]`: v の 2^k 個上の祖先
- `lca_depth[v]`: v の深さ

**使用例**:
```c
graph_init(n);
// 木を構築（無向辺）
lca_build(0, n);  // 根を0とする
```

---

### lca

**概要**: 2頂点の最近共通祖先を求める

**シグネチャ**:
```c
int lca(int a, int b);
```

**戻り値**: a と b の LCA

**計算量**: O(log n)

**使用例**:
```c
int ancestor = lca(5, 8);
```

---

### dist_tree_edges

**概要**: 木上の2頂点間の辺の数を返す

**シグネチャ**:
```c
int dist_tree_edges(int a, int b);
```

**計算量**: O(log n)

---

### tree_diameter_bfs

**概要**: 木の直径（最遠頂点対の距離）を求める

**シグネチャ**:
```c
ll tree_diameter_bfs(int n, int* u, int* v);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| n | int | 頂点数 |
| u | int* | 直径の端点1を格納（NULLでも可） |
| v | int* | 直径の端点2を格納（NULLでも可） |

**戻り値**: 木の直径（辺数）

**計算量**: O(V + E)

---

### euler_tour_build

**概要**: オイラーツアーを構築

**シグネチャ**:
```c
void euler_tour_build(int root, int n);
```

**グローバル変数**:
- `et_in[v]`: v がオイラーツアーに最初に現れるインデックス
- `et_out[v]`: v の部分木の終わりのインデックス

**使用例**:
```c
euler_tour_build(0, n);
// 頂点 v の部分木は et_order[et_in[v] .. et_out[v]-1]
```

---

### HL分解

**概要**: Heavy-Light Decomposition

**構造体**:
```c
typedef struct {
    int *parent, *depth, *heavy, *head, *pos, *subsz;
    int n, pos_cur;
} HLD;
```

**関数群**:
```c
void hld_init(HLD* h, Graph* g, int root);  // 初期化
void hld_free(HLD* h);                       // メモリ解放
int hld_lca(const HLD* h, int u, int v);    // LCA を求める
```

**計算量**: 初期化 O(n)、LCA O(log n)

---

## 最小全域木

### kruskal

**概要**: クラスカル法で最小全域木を構築

**シグネチャ**:
```c
int kruskal(int n, Edge* edges, int m, ll* total);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| n | int | 頂点数 |
| edges | Edge* | 辺の配列 |
| m | int | 辺数 |
| total | ll* | 最小全域木の総重みを格納（NULLでも可） |

**戻り値**: 使用した辺の数

**計算量**: O(E log E)

**使用例**:
```c
Edge edges[MAXM];
rep(i, m) {
    edges[i].u = fast_read_int() - 1;
    edges[i].v = fast_read_int() - 1;
    edges[i].w = fast_read_long();
}
ll total;
kruskal(n, edges, m, &total);
printf("最小全域木の重み: %lld\n", total);
```

---

## トポロジカルソート

### topo_sort_copy

**概要**: トポロジカルソートを行う

**シグネチャ**:
```c
int topo_sort_copy(int n, int* out);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| n | int | 頂点数 |
| out | int* | ソート結果を格納する配列 |

**戻り値**: ソートした頂点数（n より小さければ閉路あり）

**計算量**: O(V + E)

**使用例**:
```c
int order[MAXN];
int cnt = topo_sort_copy(n, order);
if (cnt < n) {
    printf("閉路が存在\n");
}
```

---

## 強連結成分分解

### scc_kosaraju

**概要**: Kosaraju法で強連結成分分解

**シグネチャ**:
```c
int scc_kosaraju(const Graph* g, int* comp);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| g | const Graph* | 入力グラフ |
| comp | int* | 各頂点の所属コンポーネント番号を格納 |

**戻り値**: 強連結成分の数

**計算量**: O(V + E)

**使用例**:
```c
Graph g;
graphd_init(&g, n, m);
// 辺を追加
int comp[MAXN];
int num_scc = scc_kosaraju(&g, comp);
```

**注意点**:
- `comp[v]` はトポロジカル順に番号付け（0が最初）

---

## 2-SAT

**概要**: 2-SAT 問題を解く

### 構造体

```c
typedef struct {
    int n;
    Graph g;
} TwoSAT;
```

---

### twosat_init

**概要**: 2-SAT を初期化

**シグネチャ**:
```c
void twosat_init(TwoSAT* ts, int n, int mcap_clauses);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| ts | TwoSAT* | 2-SAT 構造体 |
| n | int | 変数の数 |
| mcap_clauses | int | 節の初期容量 |

---

### twosat_add_or

**概要**: 節 (a_val ∨ b_val) を追加

**シグネチャ**:
```c
void twosat_add_or(TwoSAT* ts, int a, bool aval, int b, bool bval);
```

**使用例**:
```c
// x_0 ∨ x_1 （x_0 = true または x_1 = true）
twosat_add_or(&ts, 0, true, 1, true);

// ¬x_0 ∨ x_2 （x_0 = false または x_2 = true）
twosat_add_or(&ts, 0, false, 2, true);
```

---

### twosat_add_imp

**概要**: 含意 (a_val → b_val) を追加

**シグネチャ**:
```c
void twosat_add_imp(TwoSAT* ts, int a, bool aval, int b, bool bval);
```

---

### twosat_set_var

**概要**: 変数の値を固定

**シグネチャ**:
```c
void twosat_set_var(TwoSAT* ts, int a, bool aval);
```

---

### twosat_solve

**概要**: 充足可能か判定し、解を求める

**シグネチャ**:
```c
bool twosat_solve(TwoSAT* ts, unsigned char* assign01);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| ts | TwoSAT* | 2-SAT 構造体 |
| assign01 | unsigned char* | 各変数の値を格納（NULL でも可） |

**戻り値**: 充足可能なら `true`

**使用例**:
```c
TwoSAT ts;
twosat_init(&ts, 3, 10);
twosat_add_or(&ts, 0, true, 1, true);
twosat_add_or(&ts, 0, false, 2, true);

unsigned char ans[3];
if (twosat_solve(&ts, ans)) {
    rep(i, 3) printf("x%d = %d\n", i, ans[i]);
}
twosat_free(&ts);
```

---

## 最大流

### Dinic法

**構造体**:
```c
typedef struct {
    int n, m, mcap;
    int *head, *to, *nxt, *rev;
    ll *cap;
    int *level, *it;
} Dinic;
```

---

### dinic_init

**概要**: Dinic 構造体を初期化

**シグネチャ**:
```c
void dinic_init(Dinic* f, int n, int mcap);
```

---

### dinic_add_edge

**概要**: 辺を追加

**シグネチャ**:
```c
void dinic_add_edge(Dinic* f, int fr, int to, ll cap);
```

---

### dinic_max_flow

**概要**: 最大流を求める

**シグネチャ**:
```c
ll dinic_max_flow(Dinic* f, int s, int t, ll lim);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| f | Dinic* | Dinic 構造体 |
| s | int | ソース |
| t | int | シンク |
| lim | ll | 流量の上限 |

**戻り値**: 最大流量

**計算量**: O(V² E)

**使用例**:
```c
Dinic f;
dinic_init(&f, n, m * 2);
rep(i, m) {
    int u = fast_read_int() - 1;
    int v = fast_read_int() - 1;
    ll c = fast_read_long();
    dinic_add_edge(&f, u, v, c);
}
ll max_flow = dinic_max_flow(&f, 0, n - 1, INFLL);
dinic_free(&f);
```

---

## 最小費用流

### MCMF 構造体

```c
typedef struct {
    int n, m, mcap;
    int *head, *to, *nxt, *rev;
    ll *cap, *cost, *pot, *dist;
    int *pv_v, *pv_e;
} MCMF;
```

---

### mcmf_init

**概要**: MCMF 構造体を初期化

**シグネチャ**:
```c
void mcmf_init(MCMF* f, int n, int mcap);
```

---

### mcmf_add_edge

**概要**: 辺を追加

**シグネチャ**:
```c
void mcmf_add_edge(MCMF* f, int fr, int to, ll cap, ll cost);
```

---

### mcmf_min_cost_flow

**概要**: 最小費用流を求める

**シグネチャ**:
```c
void mcmf_min_cost_flow(MCMF* f, int s, int t, ll maxf, ll* flow_out, ll* cost_out);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| f | MCMF* | MCMF 構造体 |
| s | int | ソース |
| t | int | シンク |
| maxf | ll | 流したい流量の上限 |
| flow_out | ll* | 実際に流れた流量を格納 |
| cost_out | ll* | 最小費用を格納 |

**計算量**: O(F V E log V)（F は流量）

---

## その他

### is_bipartite

**概要**: 二部グラフかどうか判定

**シグネチャ**:
```c
bool is_bipartite(int start, int n);
```

**グローバル変数**:
- `bip_color[]`: 各頂点の色（0 または 1）

---

### find_articulation_points

**概要**: 関節点を求める

**シグネチャ**:
```c
int find_articulation_points(int n, int* ap);
```

**戻り値**: 関節点の数

---

### find_bridges

**概要**: 橋を求める

**シグネチャ**:
```c
int find_bridges(int n);
```

**グローバル変数**:
- `bridge_u[]`, `bridge_v[]`: 橋の端点
- `bridge_cnt`: 橋の数

**注意点**:
- 無向グラフの辺は `add_undirected_edge` で追加（偶数・奇数ペアで管理）

---

### has_cycle_directed

**概要**: 有向グラフに閉路があるか判定

**シグネチャ**:
```c
bool has_cycle_directed(int n);
```

**戻り値**: 閉路があれば `true`
