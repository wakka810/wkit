# 文字列アルゴリズム

このページでは、`wkit.h` の文字列関連関数について説明します。

---

## 目次

- [Z-Algorithm](#z-algorithm)
- [KMP法](#kmp法)
- [Manacher法](#manacher法)
- [Suffix Array](#suffix-array)
- [Rolling Hash](#rolling-hash)
- [Trie](#trie)
- [Binary Trie](#binary-trie)
- [Aho-Corasick](#aho-corasick)
- [ランレングス圧縮](#ランレングス圧縮)

---

## Z-Algorithm

文字列の各位置について、その位置から始まる部分文字列と先頭からの最長共通接頭辞の長さを求める。

### z_algorithm

**概要**: Z配列を計算

**シグネチャ**:
```c
void z_algorithm(const char* s, int n, int* z);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| s | const char* | 入力文字列 |
| n | int | 文字列の長さ |
| z | int* | Z配列を格納する配列 |

**計算量**: O(n)

**使用例**:
```c
char s[] = "aabxaab";
int z[10];
z_algorithm(s, 7, z);
// z = [7, 1, 0, 0, 3, 1, 0]
// z[0] = n（定義）
// z[4] = 3（s[4..6] = "aab" が s[0..2] = "aab" と一致）
```

**応用**: パターンマッチング
```c
// T 内での P の出現位置を探す
// S = P + "$" + T を作り、z[i] == len(P) となる位置を探す
char combined[MAXN];
sprintf(combined, "%s$%s", pattern, text);
int len = strlen(combined);
int plen = strlen(pattern);
int z[MAXN];
z_algorithm(combined, len, z);

for (int i = plen + 1; i < len; i++) {
    if (z[i] == plen) {
        printf("位置 %d でマッチ\n", i - plen - 1);
    }
}
```

---

## KMP法

文字列のパターンマッチングを効率的に行うためのアルゴリズム。

### kmp_prefix

**概要**: KMPの失敗関数（prefix関数）を計算

**シグネチャ**:
```c
void kmp_prefix(const char* s, int n, int* pi);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| s | const char* | 入力文字列 |
| n | int | 文字列の長さ |
| pi | int* | prefix配列を格納 |

**計算量**: O(n)

**使用例**:
```c
char s[] = "aabaaab";
int pi[10];
kmp_prefix(s, 7, pi);
// pi = [0, 1, 0, 1, 2, 2, 3]
// pi[i] = s[0..i] の最長の border の長さ
```

**応用**: パターンマッチング
```c
// T 内での P の出現回数を数える
int count_pattern(const char* text, int tlen, const char* pat, int plen) {
    int pi[MAXN];
    kmp_prefix(pat, plen, pi);
    
    int cnt = 0, j = 0;
    for (int i = 0; i < tlen; i++) {
        while (j > 0 && text[i] != pat[j]) j = pi[j - 1];
        if (text[i] == pat[j]) j++;
        if (j == plen) {
            cnt++;
            j = pi[j - 1];
        }
    }
    return cnt;
}
```

---

## Manacher法

文字列の各位置を中心とする最長回文の長さを効率的に求める。

### manacher_u8

**概要**: 各位置での回文半径を計算

**シグネチャ**:
```c
void manacher_u8(const unsigned char* s, int n, int* d1, int* d2);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| s | const unsigned char* | 入力文字列 |
| n | int | 文字列の長さ |
| d1 | int* | 奇数長回文の半径配列 |
| d2 | int* | 偶数長回文の半径配列 |

**計算量**: O(n)

**使用例**:
```c
char s[] = "abcba";
int d1[10], d2[10];
manacher_u8((unsigned char*)s, 5, d1, d2);
// d1[2] = 3（"abcba" 全体が回文、中心がindex 2）
// d1[i]: 位置 i を中心とする奇数長回文の半径（中心を含む）
// d2[i]: 位置 i-1 と i の間を中心とする偶数長回文の半径
```

**注意点**:
- `d1[i]`: s[i-d1[i]+1..i+d1[i]-1] が回文
- `d2[i]`: s[i-d2[i]..i+d2[i]-1] が回文

---

## Suffix Array

文字列の全ての接尾辞をソートした配列。

### suffix_array_u8

**概要**: Suffix Array を構築

**シグネチャ**:
```c
void suffix_array_u8(const unsigned char* s, int n, int* sa);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| s | const unsigned char* | 入力文字列 |
| n | int | 文字列の長さ |
| sa | int* | Suffix Array を格納 |

**計算量**: O(n log n)

**使用例**:
```c
char s[] = "banana";
int sa[10];
suffix_array_u8((unsigned char*)s, 6, sa);
// sa = [5, 3, 1, 0, 4, 2]
// 接尾辞を辞書順にソート:
// sa[0]=5: "a"
// sa[1]=3: "ana"
// sa[2]=1: "anana"
// sa[3]=0: "banana"
// sa[4]=4: "na"
// sa[5]=2: "nana"
```

---

### lcp_kasai_u8

**概要**: LCP配列（隣接接尾辞間の最長共通接頭辞）を計算

**シグネチャ**:
```c
void lcp_kasai_u8(const unsigned char* s, int n, const int* sa, int* lcp);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| s | const unsigned char* | 入力文字列 |
| n | int | 文字列の長さ |
| sa | const int* | Suffix Array |
| lcp | int* | LCP配列を格納（長さ n-1） |

**計算量**: O(n)

**使用例**:
```c
char s[] = "banana";
int sa[10], lcp[10];
suffix_array_u8((unsigned char*)s, 6, sa);
lcp_kasai_u8((unsigned char*)s, 6, sa, lcp);
// lcp[i] = LCP(sa[i], sa[i+1])
// lcp = [1, 3, 0, 0, 2]
// lcp[0]=1: "a" と "ana" の LCP = 1
// lcp[1]=3: "ana" と "anana" の LCP = 3
```

---

## Rolling Hash

文字列の部分文字列のハッシュ値を O(1) で求める。

### 構造体

```c
typedef struct { ull h1, h2; } RHVal;  // ダブルハッシュ

typedef struct {
    int n;
    ull *pw1, *pw2;  // 基数のべき乗
    ull *h1, *h2;    // 累積ハッシュ
} RollingHash;
```

---

### rh_init

**概要**: Rolling Hash を初期化

**シグネチャ**:
```c
void rh_init(RollingHash* rh, const char* s, int n);
```

**計算量**: O(n)

**使用例**:
```c
char s[] = "abcabc";
RollingHash rh;
rh_init(&rh, s, 6);
```

---

### rh_get

**概要**: 部分文字列 s[l..r) のハッシュ値を取得

**シグネチャ**:
```c
RHVal rh_get(const RollingHash* rh, int l, int r);
```

**計算量**: O(1)

**使用例**:
```c
RHVal h1 = rh_get(&rh, 0, 3);  // "abc" のハッシュ
RHVal h2 = rh_get(&rh, 3, 6);  // "abc" のハッシュ
if (rh_eq(h1, h2)) {
    printf("s[0..3) と s[3..6) は同じ\n");
}
```

---

### rh_eq

**概要**: 2つのハッシュ値が等しいか判定

**シグネチャ**:
```c
bool rh_eq(RHVal a, RHVal b);
```

---

### rh_free

**概要**: Rolling Hash のメモリを解放

**シグネチャ**:
```c
void rh_free(RollingHash* rh);
```

---

## Trie

文字列の集合を効率的に管理する木構造。

### グローバル変数

```c
static int trie_ch[TRIE_MAX][26];  // 子ノード
static int trie_cnt[TRIE_MAX];     // 終端数
static int trie_sz;                // ノード数
```

---

### trie_init

**概要**: Trie を初期化

**シグネチャ**:
```c
void trie_init(void);
```

---

### trie_insert

**概要**: 文字列を挿入

**シグネチャ**:
```c
void trie_insert(const char* s);
```

**計算量**: O(|s|)

**使用例**:
```c
trie_init();
trie_insert("apple");
trie_insert("app");
trie_insert("banana");
```

---

### trie_count

**概要**: 文字列の出現回数を取得

**シグネチャ**:
```c
int trie_count(const char* s);
```

**計算量**: O(|s|)

**使用例**:
```c
printf("%d\n", trie_count("app"));  // 1
printf("%d\n", trie_count("ap"));   // 0（完全一致のみ）
```

**注意点**:
- 小文字アルファベットのみ対応（'a' - 'z'）

---

## Binary Trie

整数をビット列として Trie で管理。XOR の最大化に有効。

### グローバル変数

```c
static int btrie_ch[BTRIE_MAX][2];  // 子ノード（0/1）
static int btrie_sz;
```

---

### btrie_init

**概要**: Binary Trie を初期化

**シグネチャ**:
```c
void btrie_init(void);
```

---

### btrie_insert

**概要**: 整数を挿入

**シグネチャ**:
```c
void btrie_insert(ull x);
```

**計算量**: O(BTRIE_LOG)（デフォルト60ビット）

---

### btrie_max_xor

**概要**: 挿入済みの整数の中で x と XOR した結果が最大になるものを求める

**シグネチャ**:
```c
ull btrie_max_xor(ull x);
```

**戻り値**: max(x XOR y) for all inserted y

**計算量**: O(BTRIE_LOG)

**使用例**:
```c
btrie_init();
btrie_insert(3);   // 011
btrie_insert(10);  // 1010
btrie_insert(5);   // 0101

ull result = btrie_max_xor(6);  // 6 = 0110
// 6 XOR 3 = 5, 6 XOR 10 = 12, 6 XOR 5 = 3
// 最大は 12
printf("%llu\n", result);  // 12
```

---

## Aho-Corasick

複数パターンの同時検索を効率的に行うオートマトン。

### 構造体

```c
typedef struct {
    int tr[AC_MAX][26];  // 遷移
    int fail[AC_MAX];    // 失敗関数
    int end[AC_MAX];     // 終端のパターンID
    int sz;              // ノード数
} AhoCorasick;
```

---

### ac_init

**概要**: Aho-Corasick オートマトンを初期化

**シグネチャ**:
```c
void ac_init(AhoCorasick* ac);
```

---

### ac_insert

**概要**: パターンを挿入

**シグネチャ**:
```c
void ac_insert(AhoCorasick* ac, const char* s, int id);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| ac | AhoCorasick* | オートマトン |
| s | const char* | パターン文字列 |
| id | int | パターンID（1以上推奨） |

---

### ac_build

**概要**: 失敗関数を構築

**シグネチャ**:
```c
void ac_build(AhoCorasick* ac);
```

**計算量**: O(Σ|patterns| × 26)

---

### 使用例

```c
AhoCorasick ac;
ac_init(&ac);
ac_insert(&ac, "he", 1);
ac_insert(&ac, "she", 2);
ac_insert(&ac, "his", 3);
ac_insert(&ac, "hers", 4);
ac_build(&ac);

// テキスト "ushers" で検索
char text[] = "ushers";
int state = 0;
for (int i = 0; text[i]; i++) {
    int c = text[i] - 'a';
    state = ac.tr[state][c];
    
    // マッチしたパターンを列挙
    for (int t = state; t; t = ac.fail[t]) {
        if (ac.end[t]) {
            printf("位置 %d でパターン %d がマッチ\n", i, ac.end[t]);
        }
    }
}
// 出力:
// 位置 2 でパターン 2 がマッチ (she)
// 位置 2 でパターン 1 がマッチ (he)
// 位置 5 でパターン 4 がマッチ (hers)
```

---

## ランレングス圧縮

### rle_encode

**概要**: ランレングス圧縮を行う

**シグネチャ**:
```c
int rle_encode(const char* s, int n, char* oc, int* on);
```

**引数**:
| 名前 | 型 | 説明 |
|------|-----|------|
| s | const char* | 入力文字列 |
| n | int | 文字列の長さ |
| oc | char* | 圧縮後の文字を格納 |
| on | int* | 各文字の連続回数を格納 |

**戻り値**: 圧縮後のラン数

**計算量**: O(n)

**使用例**:
```c
char s[] = "aaabbbcc";
char chars[10];
int counts[10];
int k = rle_encode(s, 8, chars, counts);
// k = 3
// chars = ['a', 'b', 'c']
// counts = [3, 3, 2]
rep(i, k) {
    printf("%c: %d回\n", chars[i], counts[i]);
}
```
