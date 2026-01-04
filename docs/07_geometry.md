# 幾何

このページでは、`wkit.h` の幾何関連関数について説明します。

---

## 目次

- [点の操作](#点の操作)
- [内積・外積](#内積外積)
- [向き判定](#向き判定)
- [凸包](#凸包)
- [距離](#距離)
- [多角形](#多角形)

---

## 点の操作

### PointLL 構造体

```c
typedef struct { ll x, y; } PointLL;
```

整数座標の2次元点を表す構造体。

---

### pt_add

**概要**: 点の加算

**シグネチャ**:
```c
PointLL pt_add(PointLL a, PointLL b);
```

**戻り値**: (a.x + b.x, a.y + b.y)

**計算量**: O(1)

**使用例**:
```c
PointLL a = {1, 2};
PointLL b = {3, 4};
PointLL c = pt_add(a, b);  // {4, 6}
```

---

### pt_sub

**概要**: 点の減算（ベクトル差）

**シグネチャ**:
```c
PointLL pt_sub(PointLL a, PointLL b);
```

**戻り値**: (a.x - b.x, a.y - b.y)

**計算量**: O(1)

**使用例**:
```c
PointLL a = {5, 7};
PointLL b = {2, 3};
PointLL v = pt_sub(a, b);  // {3, 4}（aからbへのベクトル）
```

---

## 内積・外積

### dot128

**概要**: 2つのベクトルの内積（128bit精度）

**シグネチャ**:
```c
__int128 dot128(PointLL a, PointLL b);
```

**戻り値**: a.x * b.x + a.y * b.y

**計算量**: O(1)

**使用例**:
```c
PointLL a = {3, 4};
PointLL b = {1, 0};
__int128 d = dot128(a, b);  // 3
```

**注意点**:
- オーバーフロー対策のため `__int128` を使用

---

### cross128

**概要**: 2つのベクトルの外積（128bit精度）

**シグネチャ**:
```c
__int128 cross128(PointLL a, PointLL b);
```

**戻り値**: a.x * b.y - a.y * b.x

**計算量**: O(1)

**使用例**:
```c
PointLL a = {1, 0};
PointLL b = {0, 1};
__int128 c = cross128(a, b);  // 1（反時計回り）
```

**注意点**:
- 正: b は a の反時計回り側
- 負: b は a の時計回り側
- 0: a と b は平行

---

### cross3

**概要**: 3点で作るベクトルの外積

**シグネチャ**:
```c
__int128 cross3(PointLL a, PointLL b, PointLL c);
```

**戻り値**: cross(b - a, c - a)

**計算量**: O(1)

**使用例**:
```c
PointLL a = {0, 0};
PointLL b = {1, 0};
PointLL c = {0, 1};
__int128 area2 = cross3(a, b, c);  // 1
// 三角形の面積 = |area2| / 2
```

---

## 向き判定

### ccw

**概要**: 3点の位置関係（Counter-Clockwise）を判定

**シグネチャ**:
```c
int ccw(PointLL a, PointLL b, PointLL c);
```

**戻り値**:
- `1`: a → b → c が反時計回り
- `-1`: a → b → c が時計回り
- `0`: 3点が一直線上

**計算量**: O(1)

**使用例**:
```c
PointLL a = {0, 0};
PointLL b = {1, 0};
PointLL c = {0, 1};

int dir = ccw(a, b, c);
if (dir == 1) printf("反時計回り\n");
else if (dir == -1) printf("時計回り\n");
else printf("一直線上\n");
```

---

## 凸包

### convex_hull

**概要**: 点集合の凸包を求める

**シグネチャ**:
```c
int convex_hull(PointLL* pts, int n, PointLL* hull);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| pts | PointLL* | 入力点の配列（**破壊される**） |
| n | int | 点の数 |
| hull | PointLL* | 凸包の頂点を格納する配列 |

**戻り値**: 凸包の頂点数

**計算量**: O(n²)（ソート部分を改善すればO(n log n)）

**使用例**:
```c
PointLL pts[] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}, {0.5, 0.5}};
PointLL hull[10];
int k = convex_hull(pts, 5, hull);
// k = 4, hull = [{0,0}, {1,0}, {1,1}, {0,1}]（反時計回り）
```

**注意点**:
- 入力配列 `pts` はソートにより**内容が変更される**
- 凸包の頂点は反時計回りで格納
- 同一直線上の点は含まない

---

## 距離

### manhattan

**概要**: 2点間のマンハッタン距離

**シグネチャ**:
```c
ll manhattan(PointLL a, PointLL b);
```

**戻り値**: |a.x - b.x| + |a.y - b.y|

**計算量**: O(1)

**使用例**:
```c
PointLL a = {1, 2};
PointLL b = {4, 6};
ll dist = manhattan(a, b);  // 7
```

---

### euclidean

**概要**: 2点間のユークリッド距離

**シグネチャ**:
```c
double euclidean(PointLL a, PointLL b);
```

**戻り値**: sqrt((a.x - b.x)² + (a.y - b.y)²)

**計算量**: O(1)

**使用例**:
```c
PointLL a = {0, 0};
PointLL b = {3, 4};
double dist = euclidean(a, b);  // 5.0
```

---

## 多角形

### geo_poly_area2

**概要**: 多角形の面積の2倍を計算

**シグネチャ**:
```c
ll geo_poly_area2(PointLL* p, int n);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| p | PointLL* | 多角形の頂点（順番に詰めて） |
| n | int | 頂点数 |

**戻り値**: 多角形の面積 × 2（符号なし）

**計算量**: O(n)

**使用例**:
```c
PointLL triangle[] = {{0, 0}, {4, 0}, {0, 3}};
ll area2 = geo_poly_area2(triangle, 3);  // 12
// 実際の面積 = 12 / 2 = 6
```

**注意点**:
- 頂点は時計回りでも反時計回りでもOK（絶対値を返す）
- 整数精度で計算するため、2倍の値を返す

---

### geo_pt_in_poly

**概要**: 点が多角形の内部にあるか判定

**シグネチャ**:
```c
int geo_pt_in_poly(PointLL* p, int n, PointLL q);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| p | PointLL* | 多角形の頂点 |
| n | int | 頂点数 |
| q | PointLL | 判定する点 |

**戻り値**:
- `1`: 内部
- `0`: 外部

**計算量**: O(n)

**使用例**:
```c
PointLL poly[] = {{0, 0}, {4, 0}, {4, 3}, {0, 3}};
PointLL q1 = {2, 1};
PointLL q2 = {5, 5};

if (geo_pt_in_poly(poly, 4, q1)) {
    printf("q1 は内部\n");
}
if (!geo_pt_in_poly(poly, 4, q2)) {
    printf("q2 は外部\n");
}
```

**注意点**:
- 辺上の点の判定は実装依存（Winding Number法ベース）

---

## 典型的な使用パターン

### 三角形の面積

```c
PointLL a = {0, 0}, b = {3, 0}, c = {0, 4};
ll area2 = ABS(cross3(a, b, c));
// 面積 = area2 / 2 = 6
printf("面積: %lld.%d\n", area2 / 2, area2 % 2 ? 5 : 0);
```

### 線分の交差判定

```c
// 線分 AB と 線分 CD が交差するか
bool segments_intersect(PointLL a, PointLL b, PointLL c, PointLL d) {
    int d1 = ccw(a, b, c);
    int d2 = ccw(a, b, d);
    int d3 = ccw(c, d, a);
    int d4 = ccw(c, d, b);
    
    if (d1 * d2 < 0 && d3 * d4 < 0) return true;
    // 端点が相手の線分上にある場合は別途処理が必要
    return false;
}
```

### 凸包の周長

```c
PointLL pts[MAXN], hull[MAXN];
// pts に点を格納
int k = convex_hull(pts, n, hull);

double perimeter = 0;
for (int i = 0; i < k; i++) {
    perimeter += euclidean(hull[i], hull[(i + 1) % k]);
}
printf("周長: %.10f\n", perimeter);
```

---

## グリッド操作

幾何と関連して、グリッド操作用の定数も定義されています。

### 4方向

```c
static const int dx4[] = {0, 1, 0, -1};
static const int dy4[] = {1, 0, -1, 0};
// 右、下、左、上
```

### 8方向

```c
static const int dx8[] = {0, 1, 1, 1, 0, -1, -1, -1};
static const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1};
// 右、右下、下、左下、左、左上、上、右上
```

### IN_GRID

**概要**: 座標がグリッド内かどうか判定

```c
#define IN_GRID(r, c, H, W) ((r) >= 0 && (r) < (H) && (c) >= 0 && (c) < (W))
```

**使用例**:
```c
rep(d, 4) {
    int nr = r + dx4[d];
    int nc = c + dy4[d];
    if (IN_GRID(nr, nc, H, W)) {
        // (nr, nc) はグリッド内
    }
}
```

### grid_idx

**概要**: 2次元座標を1次元インデックスに変換

```c
int grid_idx(int r, int c, int W);  // r * W + c
```
