#ifndef WKIT_H
#define WKIT_H
#ifndef _WIN32
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>
#include <complex.h>
#include <stddef.h>
#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502884
#endif
#if defined(__GNUC__) || defined(__clang__)
#define CP_INLINE static inline
#define CP_FORCEINLINE static inline __attribute__((always_inline))
#define CP_LIKELY(x) __builtin_expect(!!(x),1)
#define CP_UNLIKELY(x) __builtin_expect(!!(x),0)
#define CP_UNUSED __attribute__((unused))
#define CP_NORETURN __attribute__((noreturn))
#else
#define CP_INLINE static inline
#define CP_FORCEINLINE static inline
#define CP_LIKELY(x) (x)
#define CP_UNLIKELY(x) (x)
#define CP_UNUSED
#define CP_NORETURN
#endif
#ifndef CP_STATIC_ASSERT
#if defined(__STDC_VERSION__) && (__STDC_VERSION__>=201112L)
#define CP_STATIC_ASSERT(cond,msg) _Static_assert((cond),msg)
#else
#define CP_STATIC_ASSERT(cond,msg) typedef char static_assertion_##__LINE__[(cond)?1:-1]
#endif
#endif
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef struct{int a,b;} PairII;
typedef struct{int v; ll w;} PairIV;
typedef struct{ll a,b;} PairLL;
typedef struct{ll x,y;} PointLL;
#ifndef INF
#define INF 1000000000
#endif
#ifndef INFLL
#define INFLL 1000000000000000000LL
#endif
#ifndef MOD
#define MOD 1000000007LL
#endif
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define REP(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define RREP(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define SZ(a) ((int)(sizeof(a)/sizeof((a)[0])))
#define chmin(a,b) do{if((b)<(a))(a)=(b);}while(0)
#define chmax(a,b) do{if((b)>(a))(a)=(b);}while(0)
#define YESNO(c) puts((c)?"YES":"NO")
#define YN(c) puts((c)?"Yes":"No")
#define BIT(i) (1ULL<<(ull)(i))
#ifdef DEBUG
#define dump_ll(x) fprintf(stderr,"%s = %lld\n",#x,(long long)(x))
#define dump_u64(x) fprintf(stderr,"%s = %llu\n",#x,(unsigned long long)(x))
#define debugf(...) fprintf(stderr,__VA_ARGS__)
#else
#define dump_ll(x) ((void)0)
#define dump_u64(x) ((void)0)
#define debugf(...) ((void)0)
#endif
#define popcount(x) __builtin_popcountll((ull)(x))
#define ctzll(x) __builtin_ctzll((ull)(x))
#define clzll(x) __builtin_clzll((ull)(x))
#define lowbit_u64(x) ((ull)(x)&(ull)(-(ll)(x)))
#define FOR_SUBSET(sub,set) for(ull sub=(ull)(set);sub;sub=((sub-1ULL)&(ull)(set)))
CP_INLINE ull bit_floor_u64(ull x){return x?(1ULL<<(63-__builtin_clzll(x))):0ULL;}
CP_INLINE ull bit_ceil_u64(ull x){if(x<=1) return 1; return 1ULL<<(64-__builtin_clzll(x-1));}
CP_NORETURN CP_INLINE void cp_oom(void){fputs("Out of memory\n",stderr);exit(1);} 
CP_INLINE void* xmalloc(size_t n){void* p=malloc(n);if(!p&&n)cp_oom();return p;}
CP_INLINE void* xcalloc(size_t n,size_t s){void* p=calloc(n,s);if(!p&&n&&s)cp_oom();return p;}
CP_INLINE void* xrealloc(void* p,size_t n){void* q=realloc(p,n);if(!q&&n)cp_oom();return q;}
CP_INLINE void cp_swap_int(int*a,int*b){int t=*a;*a=*b;*b=t;}
CP_INLINE void cp_swap_ll(ll*a,ll*b){ll t=*a;*a=*b;*b=t;}
static ull cp_rng_state=88172645463393265ULL;
CP_INLINE void cp_rng_seed(ull s){cp_rng_state=s?s:88172645463393265ULL;}
CP_INLINE ull cp_rng_u64(void){ull x=cp_rng_state;x^=x>>12;x^=x<<25;x^=x>>27;cp_rng_state=x;return x*2685821657736338717ULL;}
CP_INLINE ull cp_rng_bounded(ull lim){if(!lim) return 0; ull x,t=(ull)(-lim)%lim; do{x=cp_rng_u64();}while(x<t); return x%lim;}
CP_INLINE bool fast_read_int2(int*out){int c=getchar_unlocked();int neg=0,x=0;while(c!=EOF&&c!='-'&&(c<'0'||c>'9')) c=getchar_unlocked();if(c==EOF) return false; if(c=='-'){neg=1;c=getchar_unlocked();} while(c!=EOF&&c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar_unlocked();} *out=neg?-x:x; return true;}
CP_INLINE bool fast_read_ll2(ll*out){int c=getchar_unlocked();int neg=0;ll x=0;while(c!=EOF&&c!='-'&&(c<'0'||c>'9')) c=getchar_unlocked();if(c==EOF) return false; if(c=='-'){neg=1;c=getchar_unlocked();} while(c!=EOF&&c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar_unlocked();} *out=neg?-x:x; return true;}
CP_INLINE bool fast_read_ull2(ull*out){int c=getchar_unlocked();ull x=0;while(c!=EOF&&(c<'0'||c>'9')) c=getchar_unlocked();if(c==EOF) return false; while(c!=EOF&&c>='0'&&c<='9'){x=x*10ULL+(ull)(c-'0');c=getchar_unlocked();} *out=x; return true;}
CP_INLINE int fast_read_int(void){int v=0;fast_read_int2(&v);return v;}
CP_INLINE ll fast_read_long(void){ll v=0;fast_read_ll2(&v);return v;}
CP_INLINE ull fast_read_ull(void){ull v=0;fast_read_ull2(&v);return v;}
CP_INLINE int fast_read_char(void){int c; do{c=getchar_unlocked();}while(c!=EOF&&isspace(c)); return c;}
CP_INLINE int fast_read_token(char*buf,int maxlen){int c; do{c=getchar_unlocked();}while(c!=EOF&&isspace(c)); if(c==EOF){if(maxlen>0)buf[0]=0;return 0;} int n=0; while(c!=EOF&&!isspace(c)){if(n+1<maxlen) buf[n++]=(char)c; c=getchar_unlocked();} if(maxlen>0) buf[n]=0; return n;}
CP_INLINE int fast_read_line(char*buf,int maxlen){int c=getchar_unlocked(); if(c==EOF){if(maxlen>0)buf[0]=0;return 0;} int n=0; while(c!=EOF&&c!='\n'){if(n+1<maxlen) buf[n++]=(char)c; c=getchar_unlocked();} if(maxlen>0) buf[n]=0; return n;}
#ifndef CP_NO_FASTIOBUF
#ifndef OUTBUF_SIZE
#define OUTBUF_SIZE (1<<20)
#endif
static char outbuf[OUTBUF_SIZE];
static int outbuf_len=0;
CP_INLINE void flush_out(void){if(outbuf_len){fwrite(outbuf,1,(size_t)outbuf_len,stdout);outbuf_len=0;}}
CP_INLINE void write_char(char c){if(CP_UNLIKELY(outbuf_len>=OUTBUF_SIZE)) flush_out(); outbuf[outbuf_len++]=c;}
CP_INLINE void write_str(const char*s){while(*s) write_char(*s++);} 
CP_INLINE void write_ll(ll x){if(x==0){write_char('0');return;} if(x<0){write_char('-');x=-x;} char b[32];int n=0; while(x){b[n++]=(char)('0'+(x%10));x/=10;} while(n--) write_char(b[n]);}
CP_INLINE void write_ull(ull x){if(x==0){write_char('0');return;} char b[32];int n=0; while(x){b[n++]=(char)('0'+(int)(x%10));x/=10;} while(n--) write_char(b[n]);}
CP_INLINE void write_ln(void){write_char('\n');}
CP_INLINE void cp_init_fastio(void){atexit(flush_out);} 
#else
CP_INLINE void flush_out(void){fflush(stdout);} 
CP_INLINE void write_char(char c){putchar_unlocked(c);} 
CP_INLINE void write_str(const char*s){while(*s) putchar_unlocked(*s++);} 
CP_INLINE void write_ll(ll x){printf("%lld",(long long)x);} 
CP_INLINE void write_ull(ull x){printf("%llu",(unsigned long long)x);} 
CP_INLINE void write_ln(void){putchar_unlocked('\n');} 
CP_INLINE void cp_init_fastio(void){}
#endif
CP_INLINE ll gcd(ll a,ll b){if(a<0)a=-a; if(b<0)b=-b; while(b){ll t=a%b;a=b;b=t;} return a;}
CP_INLINE ull gcd_u64(ull a,ull b){while(b){ull t=a%b;a=b;b=t;} return a;}
CP_INLINE ll lcm(ll a,ll b){if(!a||!b) return 0; ll g=gcd(a,b); __int128 t=(__int128)(a/g)*(__int128)b; if(t>LLONG_MAX) return LLONG_MAX; if(t<LLONG_MIN) return LLONG_MIN; return (ll)t;}
CP_INLINE ll floor_div(ll a,ll b){ll q=a/b; ll r=a%b; if(r!=0 && ((r>0)!=(b>0))) q--; return q;}
CP_INLINE ll ceil_div(ll a,ll b){ll q=a/b; ll r=a%b; if(r!=0 && ((r>0)==(b>0))) q++; return q;}
CP_INLINE ll clamp_ll(ll x,ll lo,ll hi){return x<lo?lo:(x>hi?hi:x);} 
CP_INLINE ll mod_norm(ll a,ll m){a%=m; if(a<0)a+=m; return a;}
CP_INLINE ll mod_add(ll a,ll b,ll m){a=mod_norm(a,m); b=mod_norm(b,m); a+=b; if(a>=m) a-=m; return a;}
CP_INLINE ll mod_sub(ll a,ll b,ll m){a=mod_norm(a,m); b=mod_norm(b,m); a-=b; if(a<0) a+=m; return a;}
CP_INLINE ll mod_mul(ll a,ll b,ll m){return (ll)((__int128)mod_norm(a,m)*(__int128)mod_norm(b,m)%m);} 
CP_INLINE ll mod_pow(ll x,ll y,ll m){ll r=1%m; x=mod_norm(x,m); while(y){if(y&1LL) r=(ll)((__int128)r*x%m); x=(ll)((__int128)x*x%m); y>>=1LL;} return r;}
CP_INLINE ll ext_gcd(ll a,ll b,ll*x,ll*y){if(b==0){*x=1;*y=0;return a;} ll x1,y1; ll g=ext_gcd(b,a%b,&x1,&y1); *x=y1; *y=x1-(a/b)*y1; return g;}
CP_INLINE ll modinv(ll a,ll m){ll x,y; ll g=ext_gcd(a,m,&x,&y); if(g!=1&&g!=-1) return -1; return mod_norm(x,m);} 
CP_INLINE bool crt_merge(ll r1,ll m1,ll r2,ll m2,ll*r,ll*m){ll p,q; ll g=ext_gcd(m1,m2,&p,&q); ll diff=r2-r1; if(diff%g) return false; __int128 l=(__int128)m1/g*(__int128)m2; ll mod=(ll)l; __int128 t=(__int128)diff/g*(__int128)p; ll k=(ll)mod_norm((ll)(t%(m2/g)),(m2/g)); __int128 ans=(__int128)r1+(__int128)m1*k; ll rr=(ll)mod_norm((ll)(ans%mod),mod); *r=rr; *m=mod; return true;}
CP_INLINE bool pow_leq_ull(ull a,ull e,ull limit){unsigned __int128 r=1,base=a,lim=limit; while(e){if(e&1ULL){r*=base; if(r>lim) return false;} e>>=1ULL; if(!e) break; base*=base; if(base>lim) base=lim+1;} return true;}
CP_INLINE unsigned __int128 pow_u128(ull a,ull e){unsigned __int128 r=1,base=a; while(e){if(e&1ULL) r*=base; e>>=1ULL; if(!e) break; base*=base;} return r;}

CP_INLINE ull isqrt_u64(ull x){ull lo=0,hi=(1ULL<<32)+1; while(lo+1<hi){ull mid=lo+(hi-lo)/2; unsigned __int128 sq=(unsigned __int128)mid*mid; if(sq<=x) lo=mid; else hi=mid;} return lo;}
CP_INLINE bool is_square_u64(ull x){ull r=isqrt_u64(x); return (unsigned __int128)r*r==x;}
CP_INLINE int cmp_ll(const void*a,const void*b){ll x=*(const ll*)a,y=*(const ll*)b; return x<y?-1:x>y;}
CP_INLINE int cmp_int(const void*a,const void*b){int x=*(const int*)a,y=*(const int*)b; return x<y?-1:x>y;}
CP_INLINE int cmp_u64(const void*a,const void*b){ull x=*(const ull*)a,y=*(const ull*)b; return x<y?-1:x>y;}
CP_INLINE int lower_bound_ll(const ll*a,int n,ll x){int l=0,r=n; while(l<r){int m=(l+r)>>1; if(a[m]<x) l=m+1; else r=m;} return l;}
CP_INLINE int upper_bound_ll(const ll*a,int n,ll x){int l=0,r=n; while(l<r){int m=(l+r)>>1; if(a[m]<=x) l=m+1; else r=m;} return l;}
CP_INLINE int unique_ll(ll*a,int n){if(n<=0) return 0; int m=1; for(int i=1;i<n;i++) if(a[i]!=a[m-1]) a[m++]=a[i]; return m;}
CP_INLINE int compress_ll_inplace(ll*a,int n){ll*b=(ll*)xmalloc((size_t)n*sizeof(ll)); memcpy(b,a,(size_t)n*sizeof(ll)); qsort(b,(size_t)n,sizeof(ll),cmp_ll); int m=unique_ll(b,n); for(int i=0;i<n;i++) a[i]=(ll)lower_bound_ll(b,m,a[i]); free(b); return m;}
CP_INLINE ull mr_mul_mod_u64(ull a,ull b,ull mod){return (ull)((unsigned __int128)a*b%mod);} 
CP_INLINE ull mr_pow_mod_u64(ull a,ull e,ull mod){ull r=1; while(e){if(e&1ULL) r=mr_mul_mod_u64(r,a,mod); a=mr_mul_mod_u64(a,a,mod); e>>=1ULL;} return r;}
CP_INLINE bool is_prime_u64(ull n){if(n<2) return false; static const ull sp[]={2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL}; for(int i=0;i<SZ(sp);i++){ull p=sp[i]; if(n==p) return true; if(n%p==0) return false;} ull d=n-1,s=0; while((d&1ULL)==0){d>>=1ULL; s++;} static const ull bases[]={2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL}; for(int i=0;i<SZ(bases);i++){ull a=bases[i]%n; if(!a) continue; ull x=mr_pow_mod_u64(a,d,n); if(x==1||x==n-1) continue; bool comp=true; for(ull r=1;r<s;r++){x=mr_mul_mod_u64(x,x,n); if(x==n-1){comp=false;break;}} if(comp) return false;} return true;}
CP_INLINE ull splitmix64_next(ull*x){ull z=(*x+=0x9e3779b97f4a7c15ULL); z=(z^(z>>30))*0xbf58476d1ce4e5b9ULL; z=(z^(z>>27))*0x94d049bb133111ebULL; return z^(z>>31);} 
CP_INLINE ull pollard_rho_f(ull x,ull c,ull mod){return (mr_mul_mod_u64(x,x,mod)+c)%mod;}
CP_INLINE ull pollard_rho(ull n){if(!(n&1ULL)) return 2; if(n%3ULL==0) return 3; static ull seed=88172645463393265ULL; for(;;){ull x=splitmix64_next(&seed)%(n-2)+2; ull y=x; ull c=splitmix64_next(&seed)%(n-1)+1; ull d=1; while(d==1){x=pollard_rho_f(x,c,n); y=pollard_rho_f(pollard_rho_f(y,c,n),c,n); ull diff=x>y?x-y:y-x; d=gcd_u64(diff,n);} if(d!=n) return d;}}
CP_INLINE void factor_u64_rec(ull n,ull*fac,int*cnt){if(n==1) return; if(is_prime_u64(n)){fac[(*cnt)++]=n; return;} ull d=pollard_rho(n); factor_u64_rec(d,fac,cnt); factor_u64_rec(n/d,fac,cnt);} 
CP_INLINE void factor_u64(ull n,ull*fac,int*cnt){*cnt=0; if(n<=1) return; factor_u64_rec(n,fac,cnt); qsort(fac,(size_t)(*cnt),sizeof(ull),cmp_u64);} 
CP_INLINE int prime_factors(ll n,ll*primes,int*exps){int idx=0; if(n<=1) return 0; if(n%2==0){primes[idx]=2;exps[idx]=0; while(n%2==0){exps[idx]++; n/=2;} idx++;} for(ll p=3;p<=n/p;p+=2){if(n%p==0){primes[idx]=p;exps[idx]=0; while(n%p==0){exps[idx]++; n/=p;} idx++;}} if(n>1){primes[idx]=n;exps[idx]=1; idx++;} return idx;}
CP_INLINE void z_algorithm(const char*s,int n,int*z){if(n<=0) return; z[0]=n; int l=0,r=0; for(int i=1;i<n;i++){if(i<=r) z[i]=MIN(r-i+1,z[i-l]); else z[i]=0; while(i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++; if(i+z[i]-1>r){l=i; r=i+z[i]-1;}}}
CP_INLINE void kmp_prefix(const char*s,int n,int*pi){if(n<=0) return; pi[0]=0; for(int i=1;i<n;i++){int j=pi[i-1]; while(j>0&&s[i]!=s[j]) j=pi[j-1]; if(s[i]==s[j]) j++; pi[i]=j;}}
#ifndef MAXP
#define MAXP 1000000
#endif
static char is_prime_sieve[MAXP+1];
static int prime_list[MAXP];
static int prime_cnt;
CP_INLINE void sieve(int n){if(n>MAXP) n=MAXP; for(int i=0;i<=n;i++) is_prime_sieve[i]=1; if(n>=0) is_prime_sieve[0]=0; if(n>=1) is_prime_sieve[1]=0; for(int p=2;(ll)p*p<=n;p++) if(is_prime_sieve[p]) for(int x=p*p;x<=n;x+=p) is_prime_sieve[x]=0; prime_cnt=0; for(int i=2;i<=n;i++) if(is_prime_sieve[i]) prime_list[prime_cnt++]=i;}
#ifndef MAXF
#define MAXF 200000
#endif
static ll fac[MAXF+1],ifac[MAXF+1];
CP_INLINE void comb_init(int n,ll mod){if(n>MAXF) n=MAXF; fac[0]=1%mod; for(int i=1;i<=n;i++) fac[i]=(ll)((__int128)fac[i-1]*i%mod); ifac[n]=mod_pow(fac[n],mod-2,mod); for(int i=n;i>=1;i--) ifac[i-1]=(ll)((__int128)ifac[i]*i%mod);} 
CP_INLINE ll nCr_mod(int n,int r,ll mod){if(r<0||r>n) return 0; if(n>MAXF) return 0; return (ll)(((__int128)fac[n]*ifac[r]%mod)*ifac[n-r]%mod);} 
CP_INLINE PointLL pt_add(PointLL a,PointLL b){PointLL r={a.x+b.x,a.y+b.y}; return r;}
CP_INLINE PointLL pt_sub(PointLL a,PointLL b){PointLL r={a.x-b.x,a.y-b.y}; return r;}
CP_INLINE __int128 dot128(PointLL a,PointLL b){return (__int128)a.x*b.x+(__int128)a.y*b.y;}
CP_INLINE __int128 cross128(PointLL a,PointLL b){return (__int128)a.x*b.y-(__int128)a.y*b.x;}
CP_INLINE __int128 cross3(PointLL a,PointLL b,PointLL c){return cross128(pt_sub(b,a),pt_sub(c,a));}
CP_INLINE void reverse_int(int*a,int l,int r){r--; while(l<r){int t=a[l];a[l]=a[r];a[r]=t;l++;r--;}}
CP_INLINE bool next_permutation_int(int*a,int n){int i=n-2; while(i>=0&&a[i]>=a[i+1]) i--; if(i<0) return false; int j=n-1; while(a[i]>=a[j]) j--; {int t=a[i];a[i]=a[j];a[j]=t;} reverse_int(a,i+1,n); return true;}
#ifndef MAXN
#define MAXN 100000
#endif
static int uf_parent[MAXN];
static int uf_size[MAXN];
CP_INLINE void uf_init(int n){for(int i=0;i<n;i++){uf_parent[i]=i; uf_size[i]=1;}}
CP_INLINE int uf_find(int a){while(uf_parent[a]!=a){uf_parent[a]=uf_parent[uf_parent[a]]; a=uf_parent[a];} return a;}
CP_INLINE int uf_union(int a,int b){a=uf_find(a); b=uf_find(b); if(a==b) return 0; if(uf_size[a]<uf_size[b]){int t=a;a=b;b=t;} uf_parent[b]=a; uf_size[a]+=uf_size[b]; return 1;}
CP_INLINE bool uf_same(int a,int b){return uf_find(a)==uf_find(b);} 
CP_INLINE int uf_comp_size(int a){return uf_size[uf_find(a)];}
static int fenwick_n;
static ll fenwick_bit[MAXN+5];
CP_INLINE void fenwick_init(int n){fenwick_n=n; for(int i=1;i<=n;i++) fenwick_bit[i]=0;}
CP_INLINE void fenwick_update(int i,ll delta){for(;i<=fenwick_n;i+=(int)lowbit_u64(i)) fenwick_bit[i]+=delta;}
CP_INLINE ll fenwick_sum(int i){ll s=0; for(;i>0;i-=(int)lowbit_u64(i)) s+=fenwick_bit[i]; return s;}
CP_INLINE ll fenwick_range_sum(int l,int r){if(r<l) return 0; return fenwick_sum(r)-fenwick_sum(l-1);} 
CP_INLINE int fenwick_lower_bound(ll k){if(k<=0) return 1; ll sum=0; int pos=0; int pw=1; while((pw<<1)<=fenwick_n) pw<<=1; for(int step=pw;step;step>>=1){int nxt=pos+step; if(nxt<=fenwick_n && sum+fenwick_bit[nxt]<k){sum+=fenwick_bit[nxt]; pos=nxt;}} return pos+1;}
static int segN;
static ll segtree[4*MAXN];
CP_INLINE void seg_init(int n){segN=1; while(segN<n) segN<<=1; for(int i=1;i<2*segN;i++) segtree[i]=0;}
CP_INLINE void seg_update(int idx,ll value){idx+=segN; segtree[idx]=value; while(idx>1){idx>>=1; segtree[idx]=segtree[2*idx]+segtree[2*idx+1];}}
CP_INLINE ll seg_query(int l,int r){if(r<l) return 0; ll res=0; l+=segN; r+=segN; r++; while(l<r){if(l&1) res+=segtree[l++]; if(r&1) res+=segtree[--r]; l>>=1; r>>=1;} return res;}
#ifndef MAXM
#define MAXM 200000
#endif
static int graph_head[MAXN];
static int graph_to[MAXM];
static ll graph_w[MAXM];
static int graph_nxt[MAXM];
static int graph_edge_cnt;
static int indegree[MAXN];
CP_INLINE void graph_init(int n){for(int i=0;i<n;i++){graph_head[i]=-1; indegree[i]=0;} graph_edge_cnt=0;}
CP_INLINE void add_edge(int u,int v,ll w){
#ifdef DEBUG
if(graph_edge_cnt>=MAXM){fprintf(stderr,"MAXM exceeded\n");exit(1);} 
#endif
graph_to[graph_edge_cnt]=v; graph_w[graph_edge_cnt]=w; graph_nxt[graph_edge_cnt]=graph_head[u]; graph_head[u]=graph_edge_cnt; graph_edge_cnt++; indegree[v]++;}
CP_INLINE void add_undirected_edge(int u,int v,ll w){add_edge(u,v,w); add_edge(v,u,w);} 
static int q[MAXN];
static char visited[MAXN];
static ll dist_arr[MAXN];
CP_INLINE void bfs(int start,int n){int front=0,back=0; for(int i=0;i<n;i++) visited[i]=0; visited[start]=1; q[back++]=start; while(front<back){int u=q[front++]; for(int e=graph_head[u];e!=-1;e=graph_nxt[e]){int v=graph_to[e]; if(!visited[v]){visited[v]=1; q[back++]=v;}}}}
CP_INLINE void bfs_dist(int start,int n){int front=0,back=0; for(int i=0;i<n;i++) dist_arr[i]=INFLL; dist_arr[start]=0; q[back++]=start; while(front<back){int u=q[front++]; for(int e=graph_head[u];e!=-1;e=graph_nxt[e]){int v=graph_to[e]; if(dist_arr[v]==INFLL){dist_arr[v]=dist_arr[u]+1; q[back++]=v;}}}}
CP_INLINE void dfs_iter(int start,int n){static int st[MAXN]; int top=0; for(int i=0;i<n;i++) visited[i]=0; st[top++]=start; visited[start]=1; while(top){int u=st[--top]; for(int e=graph_head[u];e!=-1;e=graph_nxt[e]){int v=graph_to[e]; if(!visited[v]){visited[v]=1; st[top++]=v;}}}}
typedef struct{int v; ll d;} HeapNode;
#ifndef HEAP_MAX
#define HEAP_MAX (MAXM*2+5)
#endif
static HeapNode heap[HEAP_MAX];
static int heap_size;
CP_INLINE void push_heap(int v,ll d){
#ifdef DEBUG
if(heap_size>=HEAP_MAX){fprintf(stderr,"HEAP_MAX exceeded\n");exit(1);} 
#endif
int i=heap_size++; heap[i].v=v; heap[i].d=d; while(i>0){int p=(i-1)/2; if(heap[p].d<=heap[i].d) break; HeapNode t=heap[i]; heap[i]=heap[p]; heap[p]=t; i=p;}}
CP_INLINE HeapNode pop_heap(void){HeapNode ret=heap[0]; heap[0]=heap[--heap_size]; int i=0; while(1){int l=2*i+1,r=2*i+2,j=i; if(l<heap_size&&heap[l].d<heap[j].d) j=l; if(r<heap_size&&heap[r].d<heap[j].d) j=r; if(j==i) break; HeapNode t=heap[i]; heap[i]=heap[j]; heap[j]=t; i=j;} return ret;}
CP_INLINE void dijkstra(int start,int n){for(int i=0;i<n;i++) dist_arr[i]=INFLL; heap_size=0; dist_arr[start]=0; push_heap(start,0); while(heap_size){HeapNode cur=pop_heap(); int u=cur.v; ll d=cur.d; if(d!=dist_arr[u]) continue; for(int e=graph_head[u];e!=-1;e=graph_nxt[e]){int v=graph_to[e]; ll nd=d+graph_w[e]; if(nd<dist_arr[v]){dist_arr[v]=nd; push_heap(v,nd);}}}}
CP_INLINE void bfs01(int start,int n){static int dq[MAXN*2]; int head=MAXN,tail=MAXN; for(int i=0;i<n;i++) dist_arr[i]=INFLL; dist_arr[start]=0; dq[tail++]=start; while(head<tail){int u=dq[head++]; ll du=dist_arr[u]; for(int e=graph_head[u];e!=-1;e=graph_nxt[e]){int v=graph_to[e]; ll w=graph_w[e]; ll nd=du+w; if(nd<dist_arr[v]){dist_arr[v]=nd; if(w==0) dq[--head]=v; else dq[tail++]=v;}}}}
CP_INLINE int topo_sort_copy(int n,int*out){static int indeg_work[MAXN]; for(int i=0;i<n;i++) indeg_work[i]=indegree[i]; int front=0,back=0; for(int i=0;i<n;i++) if(indeg_work[i]==0) q[back++]=i; int cnt=0; while(front<back){int u=q[front++]; out[cnt++]=u; for(int e=graph_head[u];e!=-1;e=graph_nxt[e]){int v=graph_to[e]; if(--indeg_work[v]==0) q[back++]=v;}} return cnt;}
#ifndef MAXLOG
#define MAXLOG 20
#endif
static int lca_up[MAXLOG][MAXN];
static int lca_depth[MAXN];
CP_INLINE void lca_build(int root,int n){for(int i=0;i<n;i++){lca_depth[i]=-1; lca_up[0][i]=-1;} int front=0,back=0; q[back++]=root; lca_depth[root]=0; while(front<back){int u=q[front++]; for(int e=graph_head[u];e!=-1;e=graph_nxt[e]){int v=graph_to[e]; if(lca_depth[v]!=-1) continue; lca_depth[v]=lca_depth[u]+1; lca_up[0][v]=u; q[back++]=v;}} for(int k=1;k<MAXLOG;k++) for(int v=0;v<n;v++){int p=lca_up[k-1][v]; lca_up[k][v]=(p==-1)?-1:lca_up[k-1][p];}}
CP_INLINE int lca(int a,int b){if(a==-1||b==-1) return -1; if(lca_depth[a]<lca_depth[b]){int t=a;a=b;b=t;} int diff=lca_depth[a]-lca_depth[b]; for(int k=0;k<MAXLOG;k++) if(diff&(1<<k)) a=lca_up[k][a]; if(a==b) return a; for(int k=MAXLOG-1;k>=0;k--) if(lca_up[k][a]!=lca_up[k][b]){a=lca_up[k][a]; b=lca_up[k][b];} return lca_up[0][a];}
CP_INLINE int dist_tree_edges(int a,int b){int c=lca(a,b); return lca_depth[a]+lca_depth[b]-2*lca_depth[c];}
typedef struct{int u,v; ll w;} Edge;
CP_INLINE int cmp_edge_w(const void*pa,const void*pb){const Edge*a=(const Edge*)pa; const Edge*b=(const Edge*)pb; return a->w<b->w?-1:a->w>b->w;}
CP_INLINE int kruskal(int n,Edge*edges,int m,ll*total){qsort(edges,(size_t)m,sizeof(Edge),cmp_edge_w); uf_init(n); ll sum=0; int used=0; for(int i=0;i<m;i++) if(uf_union(edges[i].u,edges[i].v)){sum+=edges[i].w; used++;} if(total) *total=sum; return used;}
typedef struct{ull*keys; ll*vals; int cap,sz;} U64Map;
#define U64MAP_EMPTY (ULLONG_MAX)
CP_INLINE ull hash_u64(ull x){x+=0x9e3779b97f4a7c15ULL; x=(x^(x>>30))*0xbf58476d1ce4e5b9ULL; x=(x^(x>>27))*0x94d049bb133111ebULL; return x^(x>>31);} 
CP_INLINE void u64map_init(U64Map*mp,int init_cap_pow2){int cap=1; while(cap<init_cap_pow2) cap<<=1; mp->cap=cap; mp->sz=0; mp->keys=(ull*)xmalloc((size_t)cap*sizeof(ull)); mp->vals=(ll*)xmalloc((size_t)cap*sizeof(ll)); for(int i=0;i<cap;i++) mp->keys[i]=U64MAP_EMPTY;}
CP_INLINE void u64map_free(U64Map*mp){free(mp->keys); free(mp->vals); mp->keys=NULL; mp->vals=NULL; mp->cap=mp->sz=0;}
CP_INLINE void u64map_rehash(U64Map*mp,int new_cap){U64Map nw; nw.cap=new_cap; nw.sz=0; nw.keys=(ull*)xmalloc((size_t)new_cap*sizeof(ull)); nw.vals=(ll*)xmalloc((size_t)new_cap*sizeof(ll)); for(int i=0;i<new_cap;i++) nw.keys[i]=U64MAP_EMPTY; for(int i=0;i<mp->cap;i++){ull k=mp->keys[i]; if(k==U64MAP_EMPTY) continue; ull h=hash_u64(k); int mask=new_cap-1; int pos=(int)(h&(ull)mask); while(nw.keys[pos]!=U64MAP_EMPTY) pos=(pos+1)&mask; nw.keys[pos]=k; nw.vals[pos]=mp->vals[i]; nw.sz++;} u64map_free(mp); *mp=nw;}
CP_INLINE int u64map_put(U64Map*mp,ull key,ll val){if(key==U64MAP_EMPTY) key--; if((mp->sz*10)>=(mp->cap*7)) u64map_rehash(mp,mp->cap<<1); ull h=hash_u64(key); int mask=mp->cap-1; int pos=(int)(h&(ull)mask); for(;;){ull k=mp->keys[pos]; if(k==U64MAP_EMPTY){mp->keys[pos]=key; mp->vals[pos]=val; mp->sz++; return 1;} if(k==key){mp->vals[pos]=val; return 0;} pos=(pos+1)&mask;}}
CP_INLINE bool u64map_get(const U64Map*mp,ull key,ll*out){if(key==U64MAP_EMPTY) key--; ull h=hash_u64(key); int mask=mp->cap-1; int pos=(int)(h&(ull)mask); for(;;){ull k=mp->keys[pos]; if(k==U64MAP_EMPTY) return false; if(k==key){if(out) *out=mp->vals[pos]; return true;} pos=(pos+1)&mask;}}
CP_INLINE void u64map_add(U64Map*mp,ull key,ll delta){ll cur; if(u64map_get(mp,key,&cur)) u64map_put(mp,key,cur+delta); else u64map_put(mp,key,delta);} 
typedef struct{int*a; int cap,mask,head,tail;} DequeInt;
CP_INLINE int deq_size(const DequeInt*q){return (q->tail-q->head)&q->mask;}
CP_INLINE bool deq_empty(const DequeInt*q){return q->head==q->tail;}
CP_INLINE void deq_init(DequeInt*q,int want){int cap=1,need=want<2?2:want; while(cap<need) cap<<=1; q->cap=cap; q->mask=cap-1; q->a=(int*)xmalloc((size_t)cap*sizeof(int)); q->head=q->tail=0;}
CP_INLINE void deq_free(DequeInt*q){free(q->a); q->a=NULL; q->cap=q->mask=q->head=q->tail=0;}
CP_INLINE void deq_grow(DequeInt*q){int sz=deq_size(q); int ncap=q->cap<<1; int*na=(int*)xmalloc((size_t)ncap*sizeof(int)); for(int i=0;i<sz;i++) na[i]=q->a[(q->head+i)&q->mask]; free(q->a); q->a=na; q->cap=ncap; q->mask=ncap-1; q->head=0; q->tail=sz;}
CP_INLINE void deq_push_back(DequeInt*q,int x){if(((q->tail+1)&q->mask)==q->head) deq_grow(q); q->a[q->tail]=x; q->tail=(q->tail+1)&q->mask;}
CP_INLINE void deq_push_front(DequeInt*q,int x){if(((q->tail+1)&q->mask)==q->head) deq_grow(q); q->head=(q->head-1)&q->mask; q->a[q->head]=x;}
CP_INLINE int deq_pop_front(DequeInt*q){int x=q->a[q->head]; q->head=(q->head+1)&q->mask; return x;}
CP_INLINE int deq_pop_back(DequeInt*q){q->tail=(q->tail-1)&q->mask; return q->a[q->tail];}
typedef struct{HeapNode*a; int sz,cap;} MinHeap;
CP_INLINE void mhe_init(MinHeap*h,int cap){if(cap<1) cap=1; h->cap=cap; h->sz=0; h->a=(HeapNode*)xmalloc((size_t)cap*sizeof(HeapNode));}
CP_INLINE void mhe_free(MinHeap*h){free(h->a); h->a=NULL; h->sz=h->cap=0;}
CP_INLINE bool mhe_empty(const MinHeap*h){return h->sz==0;}
CP_INLINE void mhe_grow(MinHeap*h){h->cap<<=1; h->a=(HeapNode*)xrealloc(h->a,(size_t)h->cap*sizeof(HeapNode));}
CP_INLINE void mhe_push(MinHeap*h,int v,ll d){if(h->sz==h->cap) mhe_grow(h); int i=h->sz++; h->a[i].v=v; h->a[i].d=d; while(i>0){int p=(i-1)>>1; if(h->a[p].d<=h->a[i].d) break; HeapNode t=h->a[i]; h->a[i]=h->a[p]; h->a[p]=t; i=p;}}
CP_INLINE HeapNode mhe_pop(MinHeap*h){HeapNode ret=h->a[0]; h->a[0]=h->a[--h->sz]; int i=0; for(;;){int l=i*2+1,r=i*2+2,m=i; if(l<h->sz&&h->a[l].d<h->a[m].d) m=l; if(r<h->sz&&h->a[r].d<h->a[m].d) m=r; if(m==i) break; HeapNode t=h->a[i]; h->a[i]=h->a[m]; h->a[m]=t; i=m;} return ret;}
typedef struct{int n,m,mcap; int*head,*to,*nxt,*indeg; ll*w;} Graph;
CP_INLINE void graphd_init(Graph*g,int n,int mcap){g->n=n; g->m=0; g->mcap=mcap>0?mcap:4; g->head=(int*)xmalloc((size_t)n*sizeof(int)); g->indeg=(int*)xcalloc((size_t)n,sizeof(int)); for(int i=0;i<n;i++) g->head[i]=-1; g->to=(int*)xmalloc((size_t)g->mcap*sizeof(int)); g->nxt=(int*)xmalloc((size_t)g->mcap*sizeof(int)); g->w=(ll*)xmalloc((size_t)g->mcap*sizeof(ll));}
CP_INLINE void graphd_free(Graph*g){free(g->head); free(g->to); free(g->nxt); free(g->w); free(g->indeg); memset(g,0,sizeof(*g));}
CP_INLINE void graphd_reserve(Graph*g,int need){if(g->mcap>=need) return; while(g->mcap<need) g->mcap<<=1; g->to=(int*)xrealloc(g->to,(size_t)g->mcap*sizeof(int)); g->nxt=(int*)xrealloc(g->nxt,(size_t)g->mcap*sizeof(int)); g->w=(ll*)xrealloc(g->w,(size_t)g->mcap*sizeof(ll));}
CP_INLINE void graphd_add_edge(Graph*g,int u,int v,ll w){if(g->m+1>g->mcap) graphd_reserve(g,g->m+1); int e=g->m++; g->to[e]=v; g->w[e]=w; g->nxt[e]=g->head[u]; g->head[u]=e; g->indeg[v]++;}
CP_INLINE void graphd_add_undirected(Graph*g,int u,int v,ll w){graphd_add_edge(g,u,v,w); graphd_add_edge(g,v,u,w);} 
#ifndef CP_DISABLE_SCC
CP_INLINE int scc_kosaraju(const Graph*g,int*comp){int n=g->n; Graph rg; graphd_init(&rg,n,g->m); for(int u=0;u<n;u++) for(int e=g->head[u];e!=-1;e=g->nxt[e]) graphd_add_edge(&rg,g->to[e],u,0); unsigned char*vis=(unsigned char*)xcalloc((size_t)n,1); int*order=(int*)xmalloc((size_t)n*sizeof(int)); int ord=0; int*st_v=(int*)xmalloc((size_t)n*sizeof(int)); int*st_e=(int*)xmalloc((size_t)n*sizeof(int)); for(int s=0;s<n;s++) if(!vis[s]){int top=0; vis[s]=1; st_v[top]=s; st_e[top]=g->head[s]; top++; while(top){int u=st_v[top-1]; int e=st_e[top-1]; if(e!=-1){st_e[top-1]=g->nxt[e]; int v=g->to[e]; if(!vis[v]){vis[v]=1; st_v[top]=v; st_e[top]=g->head[v]; top++;}} else {order[ord++]=u; top--;}}}; for(int i=0;i<n;i++){comp[i]=-1;} int grp=0; for(int idx=n-1;idx>=0;idx--){int s=order[idx]; if(comp[s]!=-1) continue; int top=0; st_v[top++]=s; comp[s]=grp; while(top){int u=st_v[--top]; for(int e=rg.head[u];e!=-1;e=rg.nxt[e]){int v=rg.to[e]; if(comp[v]==-1){comp[v]=grp; st_v[top++]=v;}}} grp++;}; for(int v=0;v<n;v++){comp[v]=grp-1-comp[v];} free(vis); free(order); free(st_v); free(st_e); graphd_free(&rg); return grp;}
#endif
#if !defined(CP_DISABLE_TWOSAT) && !defined(CP_DISABLE_SCC)
typedef struct{int n; Graph g;} TwoSAT;
CP_INLINE int ts_lit(int var,bool val){return var*2+(val?1:0);} 
CP_INLINE void twosat_init(TwoSAT*ts,int n,int mcap_clauses){ts->n=n; int mcap=(mcap_clauses>0?mcap_clauses:4)*4; graphd_init(&ts->g,2*n,mcap);} 
CP_INLINE void twosat_free(TwoSAT*ts){graphd_free(&ts->g); ts->n=0;} 
CP_INLINE void twosat_add_or(TwoSAT*ts,int a,bool aval,int b,bool bval){int A=ts_lit(a,aval),NA=ts_lit(a,!aval),B=ts_lit(b,bval),NB=ts_lit(b,!bval); graphd_add_edge(&ts->g,NA,B,0); graphd_add_edge(&ts->g,NB,A,0);} 
CP_INLINE void twosat_add_imp(TwoSAT*ts,int a,bool aval,int b,bool bval){twosat_add_or(ts,a,!aval,b,bval);} 
CP_INLINE void twosat_set_var(TwoSAT*ts,int a,bool aval){twosat_add_or(ts,a,aval,a,aval);} 
CP_INLINE bool twosat_solve(TwoSAT*ts,unsigned char*assign01){int N=2*ts->n; int*comp=(int*)xmalloc((size_t)N*sizeof(int)); scc_kosaraju(&ts->g,comp); for(int i=0;i<ts->n;i++) if(comp[2*i]==comp[2*i+1]){free(comp); return false;} if(assign01) for(int i=0;i<ts->n;i++) assign01[i]=(unsigned char)(comp[2*i]<comp[2*i+1]); free(comp); return true;}
#endif
#ifndef CP_DISABLE_MCMF
typedef struct{int n,m,mcap; int*head,*to,*nxt,*rev; ll*cap,*cost,*pot,*dist; int*pv_v,*pv_e;} MCMF;
CP_INLINE void mcmf_init(MCMF*f,int n,int mcap){f->n=n; f->m=0; f->mcap=(mcap>0?mcap:4)*2; f->head=(int*)xmalloc((size_t)n*sizeof(int)); for(int i=0;i<n;i++) f->head[i]=-1; f->to=(int*)xmalloc((size_t)f->mcap*sizeof(int)); f->nxt=(int*)xmalloc((size_t)f->mcap*sizeof(int)); f->rev=(int*)xmalloc((size_t)f->mcap*sizeof(int)); f->cap=(ll*)xmalloc((size_t)f->mcap*sizeof(ll)); f->cost=(ll*)xmalloc((size_t)f->mcap*sizeof(ll)); f->pot=(ll*)xcalloc((size_t)n,sizeof(ll)); f->dist=(ll*)xmalloc((size_t)n*sizeof(ll)); f->pv_v=(int*)xmalloc((size_t)n*sizeof(int)); f->pv_e=(int*)xmalloc((size_t)n*sizeof(int));}
CP_INLINE void mcmf_free(MCMF*f){free(f->head); free(f->to); free(f->nxt); free(f->rev); free(f->cap); free(f->cost); free(f->pot); free(f->dist); free(f->pv_v); free(f->pv_e); memset(f,0,sizeof(*f));}
CP_INLINE void mcmf_reserve(MCMF*f,int need){if(f->mcap>=need) return; while(f->mcap<need) f->mcap<<=1; f->to=(int*)xrealloc(f->to,(size_t)f->mcap*sizeof(int)); f->nxt=(int*)xrealloc(f->nxt,(size_t)f->mcap*sizeof(int)); f->rev=(int*)xrealloc(f->rev,(size_t)f->mcap*sizeof(int)); f->cap=(ll*)xrealloc(f->cap,(size_t)f->mcap*sizeof(ll)); f->cost=(ll*)xrealloc(f->cost,(size_t)f->mcap*sizeof(ll));}
CP_INLINE void mcmf_add_edge(MCMF*f,int fr,int to,ll cap,ll cost){if(f->m+2>f->mcap) mcmf_reserve(f,f->m+2); int e=f->m++, r=f->m++; f->to[e]=to; f->cap[e]=cap; f->cost[e]=cost; f->rev[e]=r; f->nxt[e]=f->head[fr]; f->head[fr]=e; f->to[r]=fr; f->cap[r]=0; f->cost[r]=-cost; f->rev[r]=e; f->nxt[r]=f->head[to]; f->head[to]=r;}
CP_INLINE void mcmf_init_potential_bf(MCMF*f,int s){int n=f->n; for(int i=0;i<n;i++) f->pot[i]=INFLL; f->pot[s]=0; bool upd=true; for(int it=0;it<n&&upd;it++){upd=false; for(int u=0;u<n;u++){if(f->pot[u]==INFLL) continue; for(int e=f->head[u];e!=-1;e=f->nxt[e]){if(f->cap[e]<=0) continue; int v=f->to[e]; ll nd=f->pot[u]+f->cost[e]; if(nd<f->pot[v]){f->pot[v]=nd; upd=true;}}}} for(int i=0;i<n;i++) if(f->pot[i]==INFLL) f->pot[i]=0;}
CP_INLINE bool mcmf_dijkstra(MCMF*f,int s,int t){int n=f->n; for(int i=0;i<n;i++){f->dist[i]=INFLL; f->pv_v[i]=-1; f->pv_e[i]=-1;} MinHeap pq; mhe_init(&pq,8); f->dist[s]=0; mhe_push(&pq,s,0); while(!mhe_empty(&pq)){HeapNode cur=mhe_pop(&pq); int u=cur.v; ll d=cur.d; if(d!=f->dist[u]) continue; for(int e=f->head[u];e!=-1;e=f->nxt[e]){if(f->cap[e]<=0) continue; int v=f->to[e]; ll rc=f->cost[e]+f->pot[u]-f->pot[v]; ll nd=d+rc; if(nd<f->dist[v]){f->dist[v]=nd; f->pv_v[v]=u; f->pv_e[v]=e; mhe_push(&pq,v,nd);}}} mhe_free(&pq); return f->dist[t]<INFLL;}
CP_INLINE void mcmf_min_cost_flow(MCMF*f,int s,int t,ll maxf,ll*flow_out,ll*cost_out){ll flow=0,cost=0; mcmf_init_potential_bf(f,s); while(flow<maxf){if(!mcmf_dijkstra(f,s,t)) break; for(int v=0;v<f->n;v++) if(f->dist[v]<INFLL) f->pot[v]+=f->dist[v]; ll add=maxf-flow; for(int v=t;v!=s;v=f->pv_v[v]){int e=f->pv_e[v]; if(e<0){add=0;break;} if(f->cap[e]<add) add=f->cap[e];} if(add==0) break; for(int v=t;v!=s;v=f->pv_v[v]){int e=f->pv_e[v]; f->cap[e]-=add; f->cap[f->rev[e]]+=add; cost+=add*f->cost[e];} flow+=add;} if(flow_out) *flow_out=flow; if(cost_out) *cost_out=cost;}
#endif
#ifndef CP_DISABLE_MANACHER
CP_INLINE void manacher_u8(const unsigned char*s,int n,int*d1,int*d2){int l=0,r=-1; for(int i=0;i<n;i++){int k=i>r?1:MIN(d1[l+r-i],r-i+1); while(0<=i-k&&i+k<n&&s[i-k]==s[i+k]) k++; d1[i]=k; if(i+k-1>r){l=i-k+1; r=i+k-1;}} l=0; r=-1; for(int i=0;i<n;i++){int k=i>r?0:MIN(d2[l+r-i+1],r-i+1); while(0<=i-k-1&&i+k<n&&s[i-k-1]==s[i+k]) k++; d2[i]=k; if(i+k-1>r){l=i-k; r=i+k-1;}}}
#endif
#ifndef CP_DISABLE_SUFFIXARRAY
CP_INLINE void suffix_array_u8(const unsigned char*s,int n,int*sa){if(n<=0) return; int*rnk=(int*)xmalloc((size_t)n*sizeof(int)); int*tmp=(int*)xmalloc((size_t)n*sizeof(int)); int*sa2=(int*)xmalloc((size_t)n*sizeof(int)); int m=256; int*cnt=(int*)xcalloc((size_t)MAX(m,n),sizeof(int)); for(int i=0;i<n;i++) cnt[s[i]]++; for(int c=1;c<m;c++) cnt[c]+=cnt[c-1]; for(int i=n-1;i>=0;i--) sa[--cnt[s[i]]]=i; int classes=1; tmp[sa[0]]=0; for(int i=1;i<n;i++){if(s[sa[i]]!=s[sa[i-1]]) classes++; tmp[sa[i]]=classes-1;} memcpy(rnk,tmp,(size_t)n*sizeof(int)); for(int k=1;k<n;k<<=1){int p=0; for(int i=n-k;i<n;i++) sa2[p++]=i; for(int i=0;i<n;i++) if(sa[i]>=k) sa2[p++]=sa[i]-k; memset(cnt,0,(size_t)classes*sizeof(int)); for(int i=0;i<n;i++) cnt[rnk[i]]++; for(int c=1;c<classes;c++) cnt[c]+=cnt[c-1]; for(int i=n-1;i>=0;i--){int v=sa2[i]; sa[--cnt[rnk[v]]]=v;} tmp[sa[0]]=0; int cc=1; for(int i=1;i<n;i++){int a=sa[i-1],b=sa[i]; int ra=rnk[a], rb=rnk[b]; int raa=(a+k<n)?rnk[a+k]:-1; int rbb=(b+k<n)?rnk[b+k]:-1; if(ra!=rb||raa!=rbb) cc++; tmp[b]=cc-1;} memcpy(rnk,tmp,(size_t)n*sizeof(int)); classes=cc; if(classes==n) break;} free(rnk); free(tmp); free(sa2); free(cnt);} 
CP_INLINE void lcp_kasai_u8(const unsigned char*s,int n,const int*sa,int*lcp){if(n<=1) return; int*rank=(int*)xmalloc((size_t)n*sizeof(int)); for(int i=0;i<n;i++) rank[sa[i]]=i; int h=0; for(int i=0;i<n;i++){int r=rank[i]; if(r==0) continue; int j=sa[r-1]; while(i+h<n&&j+h<n&&s[i+h]==s[j+h]) h++; lcp[r-1]=h; if(h) h--; } free(rank);} 
#endif
#ifndef CP_DISABLE_SPARSETABLE
typedef struct{int n,K; int*lg; ll*st;} SparseLLMin;
CP_INLINE void sparsellmin_init(SparseLLMin*sp,const ll*a,int n){sp->n=n; sp->lg=(int*)xmalloc((size_t)(n+1)*sizeof(int)); sp->lg[0]=0; if(n>=1) sp->lg[1]=0; for(int i=2;i<=n;i++) sp->lg[i]=sp->lg[i>>1]+1; sp->K=sp->lg[n]; sp->st=(ll*)xmalloc((size_t)(sp->K+1)*(size_t)n*sizeof(ll)); for(int i=0;i<n;i++) sp->st[i]=a[i]; for(int k=1;k<=sp->K;k++){int len=1<<k, half=len>>1; ll*cur=sp->st+(size_t)k*n; ll*prv=sp->st+(size_t)(k-1)*n; for(int i=0;i+len<=n;i++){ll x=prv[i],y=prv[i+half]; cur[i]=x<y?x:y;}}}
CP_INLINE void sparsellmin_free(SparseLLMin*sp){free(sp->lg); free(sp->st); sp->lg=NULL; sp->st=NULL; sp->n=sp->K=0;}
CP_INLINE ll sparsellmin_query(const SparseLLMin*sp,int l,int r){if(r<=l) return INFLL; int len=r-l; int k=sp->lg[len]; ll a=sp->st[(size_t)k*sp->n+l]; ll b=sp->st[(size_t)k*sp->n+(r-(1<<k))]; return a<b?a:b;}
#endif
CP_INLINE ll floor_sum_ll(ll n,ll m,ll a,ll b){__int128 ans=0; while(1){if(a>=m){ans+=(__int128)(n-1)*n/2*(a/m); a%=m;} if(b>=m){ans+=(__int128)n*(b/m); b%=m;} __int128 y=(__int128)a*n+b; if(y<m) break; n=(ll)(y/m); b=(ll)(y%m); ll t=m; m=a; a=t;} return (ll)ans;}
#ifndef CP_DISABLE_DINIC
typedef struct{int n,m,mcap; int*head,*to,*nxt,*rev; ll*cap; int*level,*it;} Dinic;
CP_INLINE void dinic_init(Dinic*f,int n,int mcap){f->n=n; f->m=0; f->mcap=(mcap>0?mcap:4)*2; f->head=(int*)xmalloc((size_t)n*sizeof(int)); for(int i=0;i<n;i++) f->head[i]=-1; f->to=(int*)xmalloc((size_t)f->mcap*sizeof(int)); f->nxt=(int*)xmalloc((size_t)f->mcap*sizeof(int)); f->rev=(int*)xmalloc((size_t)f->mcap*sizeof(int)); f->cap=(ll*)xmalloc((size_t)f->mcap*sizeof(ll)); f->level=(int*)xmalloc((size_t)n*sizeof(int)); f->it=(int*)xmalloc((size_t)n*sizeof(int));}
CP_INLINE void dinic_free(Dinic*f){free(f->head); free(f->to); free(f->nxt); free(f->rev); free(f->cap); free(f->level); free(f->it); memset(f,0,sizeof(*f));}
CP_INLINE void dinic_reserve(Dinic*f,int need){if(f->mcap>=need) return; while(f->mcap<need) f->mcap<<=1; f->to=(int*)xrealloc(f->to,(size_t)f->mcap*sizeof(int)); f->nxt=(int*)xrealloc(f->nxt,(size_t)f->mcap*sizeof(int)); f->rev=(int*)xrealloc(f->rev,(size_t)f->mcap*sizeof(int)); f->cap=(ll*)xrealloc(f->cap,(size_t)f->mcap*sizeof(ll));}
CP_INLINE void dinic_add_edge(Dinic*f,int fr,int to,ll cap){if(f->m+2>f->mcap) dinic_reserve(f,f->m+2); int e=f->m++, r=f->m++; f->to[e]=to; f->cap[e]=cap; f->rev[e]=r; f->nxt[e]=f->head[fr]; f->head[fr]=e; f->to[r]=fr; f->cap[r]=0; f->rev[r]=e; f->nxt[r]=f->head[to]; f->head[to]=r;}
CP_INLINE bool dinic_bfs(Dinic*f,int s,int t){for(int i=0;i<f->n;i++) f->level[i]=-1; static int*qv=NULL; static int qcap=0; if(qcap<f->n){free(qv); qcap=f->n; qv=(int*)xmalloc((size_t)qcap*sizeof(int));} int qh=0,qt=0; f->level[s]=0; qv[qt++]=s; while(qh<qt){int v=qv[qh++]; for(int e=f->head[v];e!=-1;e=f->nxt[e]) if(f->cap[e]>0){int u=f->to[e]; if(f->level[u]==-1){f->level[u]=f->level[v]+1; qv[qt++]=u;}}} return f->level[t]!=-1;}
CP_INLINE ll dinic_dfs(Dinic*f,int v,int t,ll pushed){if(v==t||pushed==0) return pushed; for(int*e=&f->it[v]; *e!=-1; *e=f->nxt[*e]){int id=*e; if(f->cap[id]<=0) continue; int u=f->to[id]; if(f->level[u]!=f->level[v]+1) continue; ll tr=dinic_dfs(f,u,t,pushed<f->cap[id]?pushed:f->cap[id]); if(tr==0) continue; f->cap[id]-=tr; f->cap[f->rev[id]]+=tr; return tr;} return 0;}
CP_INLINE ll dinic_max_flow(Dinic*f,int s,int t,ll lim){ll flow=0; while(flow<lim && dinic_bfs(f,s,t)){for(int i=0;i<f->n;i++) f->it[i]=f->head[i]; while(flow<lim){ll pushed=dinic_dfs(f,s,t,lim-flow); if(!pushed) break; flow+=pushed;}} return flow;}
#endif
CP_INLINE void cp_shuffle_int(int*a,int n){for(int i=n-1;i>0;i--){int j=(int)cp_rng_bounded((ull)(i+1)); int t=a[i];a[i]=a[j];a[j]=t;}}
CP_INLINE void cp_shuffle_ll(ll*a,int n){for(int i=n-1;i>0;i--){int j=(int)cp_rng_bounded((ull)(i+1)); ll t=a[i];a[i]=a[j];a[j]=t;}}
CP_INLINE int lower_bound_int(const int*a,int n,int x){int l=0,r=n;while(l<r){int m=(l+r)>>1;if(a[m]<x)l=m+1;else r=m;}return l;}
CP_INLINE int upper_bound_int(const int*a,int n,int x){int l=0,r=n;while(l<r){int m=(l+r)>>1;if(a[m]<=x)l=m+1;else r=m;}return l;}
CP_INLINE int unique_int(int*a,int n){if(n<=0)return 0;int m=1;for(int i=1;i<n;i++)if(a[i]!=a[m-1])a[m++]=a[i];return m;}
CP_INLINE int compress_int_inplace(int*a,int n){int*b=(int*)xmalloc((size_t)n*sizeof(int));memcpy(b,a,(size_t)n*sizeof(int));qsort(b,(size_t)n,sizeof(int),cmp_int);int m=unique_int(b,n);for(int i=0;i<n;i++)a[i]=lower_bound_int(b,m,a[i]);free(b);return m;}
CP_INLINE ll ternary_search_max(ll lo,ll hi,ll(*f)(ll)){while(hi-lo>2){ll m1=lo+(hi-lo)/3,m2=hi-(hi-lo)/3;if(f(m1)<f(m2))lo=m1;else hi=m2;}ll best=f(lo);for(ll x=lo+1;x<=hi;x++){ll v=f(x);if(v>best)best=v;}return best;}
CP_INLINE ll ternary_search_min(ll lo,ll hi,ll(*f)(ll)){while(hi-lo>2){ll m1=lo+(hi-lo)/3,m2=hi-(hi-lo)/3;if(f(m1)>f(m2))lo=m1;else hi=m2;}ll best=f(lo);for(ll x=lo+1;x<=hi;x++){ll v=f(x);if(v<best)best=v;}return best;}
CP_INLINE ull bit_reverse_u64(ull x){x=((x&0x5555555555555555ULL)<<1)|((x>>1)&0x5555555555555555ULL);x=((x&0x3333333333333333ULL)<<2)|((x>>2)&0x3333333333333333ULL);x=((x&0x0f0f0f0f0f0f0f0fULL)<<4)|((x>>4)&0x0f0f0f0f0f0f0f0fULL);x=((x&0x00ff00ff00ff00ffULL)<<8)|((x>>8)&0x00ff00ff00ff00ffULL);x=((x&0x0000ffff0000ffffULL)<<16)|((x>>16)&0x0000ffff0000ffffULL);return (x<<32)|(x>>32);}
#define RHMOD1 1000000007ULL
#define RHMOD2 998244353ULL
#define RHBASE1 31ULL
#define RHBASE2 37ULL
typedef struct{ull h1,h2;}RHVal;
typedef struct{int n;ull*pw1,*pw2,*h1,*h2;}RollingHash;
CP_INLINE void rh_init(RollingHash*rh,const char*s,int n){rh->n=n;rh->pw1=(ull*)xmalloc((size_t)(n+1)*sizeof(ull));rh->pw2=(ull*)xmalloc((size_t)(n+1)*sizeof(ull));rh->h1=(ull*)xmalloc((size_t)(n+1)*sizeof(ull));rh->h2=(ull*)xmalloc((size_t)(n+1)*sizeof(ull));rh->pw1[0]=rh->pw2[0]=1;rh->h1[0]=rh->h2[0]=0;for(int i=0;i<n;i++){rh->pw1[i+1]=rh->pw1[i]*RHBASE1%RHMOD1;rh->pw2[i+1]=rh->pw2[i]*RHBASE2%RHMOD2;rh->h1[i+1]=(rh->h1[i]*RHBASE1+(ull)(unsigned char)s[i])%RHMOD1;rh->h2[i+1]=(rh->h2[i]*RHBASE2+(ull)(unsigned char)s[i])%RHMOD2;}}
CP_INLINE void rh_free(RollingHash*rh){free(rh->pw1);free(rh->pw2);free(rh->h1);free(rh->h2);}
CP_INLINE RHVal rh_get(const RollingHash*rh,int l,int r){RHVal v;v.h1=(rh->h1[r]+RHMOD1-rh->h1[l]*rh->pw1[r-l]%RHMOD1)%RHMOD1;v.h2=(rh->h2[r]+RHMOD2-rh->h2[l]*rh->pw2[r-l]%RHMOD2)%RHMOD2;return v;}
CP_INLINE bool rh_eq(RHVal a,RHVal b){return a.h1==b.h1&&a.h2==b.h2;}
#ifndef LSEG_MAX
#define LSEG_MAX MAXN
#endif
static int lsegN;
static ll lseg_val[4*LSEG_MAX],lseg_lazy[4*LSEG_MAX];
CP_INLINE void lseg_init(int n){lsegN=1;while(lsegN<n)lsegN<<=1;for(int i=0;i<2*lsegN;i++){lseg_val[i]=0;lseg_lazy[i]=0;}}
CP_INLINE void lseg_push(int k,int len){if(lseg_lazy[k]){lseg_val[k]+=lseg_lazy[k]*(ll)len;if(len>1){lseg_lazy[2*k]+=lseg_lazy[k];lseg_lazy[2*k+1]+=lseg_lazy[k];}lseg_lazy[k]=0;}}
CP_INLINE void lseg_update_range(int k,int l,int r,int a,int b,ll x){lseg_push(k,r-l);if(b<=l||r<=a)return;if(a<=l&&r<=b){lseg_lazy[k]+=x;lseg_push(k,r-l);return;}int m=(l+r)/2;lseg_update_range(2*k,l,m,a,b,x);lseg_update_range(2*k+1,m,r,a,b,x);lseg_val[k]=lseg_val[2*k]+lseg_val[2*k+1];}
CP_INLINE ll lseg_query_range(int k,int l,int r,int a,int b){lseg_push(k,r-l);if(b<=l||r<=a)return 0;if(a<=l&&r<=b)return lseg_val[k];int m=(l+r)/2;return lseg_query_range(2*k,l,m,a,b)+lseg_query_range(2*k+1,m,r,a,b);}
CP_INLINE void lseg_add(int l,int r,ll x){lseg_update_range(1,0,lsegN,l,r,x);}
CP_INLINE ll lseg_sum(int l,int r){return lseg_query_range(1,0,lsegN,l,r);}
static int wuf_par[MAXN];
static ll wuf_diff[MAXN];
CP_INLINE void wuf_init(int n){for(int i=0;i<n;i++){wuf_par[i]=i;wuf_diff[i]=0;}}
CP_INLINE int wuf_find(int x){if(wuf_par[x]==x)return x;int r=wuf_find(wuf_par[x]);wuf_diff[x]+=wuf_diff[wuf_par[x]];wuf_par[x]=r;return r;}
CP_INLINE ll wuf_weight(int x){wuf_find(x);return wuf_diff[x];}
CP_INLINE bool wuf_union(int x,int y,ll w){w+=wuf_weight(x)-wuf_weight(y);int rx=wuf_find(x),ry=wuf_find(y);if(rx==ry)return false;wuf_par[ry]=rx;wuf_diff[ry]=w;return true;}
CP_INLINE ll wuf_dist(int x,int y){return wuf_weight(y)-wuf_weight(x);}
#ifndef CHT_MAX
#define CHT_MAX 200000
#endif
static ll cht_m[CHT_MAX],cht_b[CHT_MAX];
static int cht_head,cht_tail;
CP_INLINE void cht_init(void){cht_head=cht_tail=0;}
CP_INLINE bool cht_bad(__int128 m1,__int128 b1,__int128 m2,__int128 b2,__int128 m3,__int128 b3){return (b3-b1)*(m1-m2)<=(b2-b1)*(m1-m3);}
CP_INLINE void cht_add(ll m,ll b){while(cht_tail-cht_head>=2&&cht_bad(cht_m[cht_tail-2],cht_b[cht_tail-2],cht_m[cht_tail-1],cht_b[cht_tail-1],m,b))cht_tail--;cht_m[cht_tail]=m;cht_b[cht_tail++]=b;}
CP_INLINE ll cht_query(ll x){while(cht_tail-cht_head>=2&&cht_m[cht_head]*x+cht_b[cht_head]>=cht_m[cht_head+1]*x+cht_b[cht_head+1])cht_head++;return cht_m[cht_head]*x+cht_b[cht_head];}
#ifndef TRIE_MAX
#define TRIE_MAX 1000000
#endif
static int trie_ch[TRIE_MAX][26],trie_cnt[TRIE_MAX],trie_sz;
CP_INLINE void trie_init(void){trie_sz=1;memset(trie_ch[0],0,sizeof(trie_ch[0]));trie_cnt[0]=0;}
CP_INLINE void trie_insert(const char*s){int cur=0;for(;*s;s++){int c=(int)(*s-'a');if(!trie_ch[cur][c]){trie_ch[cur][c]=trie_sz;memset(trie_ch[trie_sz],0,sizeof(trie_ch[0]));trie_cnt[trie_sz]=0;trie_sz++;}cur=trie_ch[cur][c];}trie_cnt[cur]++;}
CP_INLINE int trie_count(const char*s){int cur=0;for(;*s;s++){int c=(int)(*s-'a');if(!trie_ch[cur][c])return 0;cur=trie_ch[cur][c];}return trie_cnt[cur];}
#ifndef BTRIE_LOG
#define BTRIE_LOG 60
#endif
#ifndef BTRIE_MAX
#define BTRIE_MAX 6000000
#endif
static int btrie_ch[BTRIE_MAX][2],btrie_sz;
CP_INLINE void btrie_init(void){btrie_sz=1;btrie_ch[0][0]=btrie_ch[0][1]=0;}
CP_INLINE void btrie_insert(ull x){int cur=0;for(int i=BTRIE_LOG-1;i>=0;i--){int b=(int)((x>>i)&1);if(!btrie_ch[cur][b]){btrie_ch[cur][b]=btrie_sz;btrie_ch[btrie_sz][0]=btrie_ch[btrie_sz][1]=0;btrie_sz++;}cur=btrie_ch[cur][b];}}
CP_INLINE ull btrie_max_xor(ull x){ull res=0;int cur=0;for(int i=BTRIE_LOG-1;i>=0;i--){int b=(int)((x>>i)&1);if(btrie_ch[cur][1-b]){res|=(1ULL<<i);cur=btrie_ch[cur][1-b];}else if(btrie_ch[cur][b]){cur=btrie_ch[cur][b];}else break;}return res;}
#ifndef FW_MAX
#define FW_MAX 500
#endif
static ll fw_dist[FW_MAX][FW_MAX];
CP_INLINE void floyd_warshall(int n){for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(fw_dist[i][k]<INFLL&&fw_dist[k][j]<INFLL)chmin(fw_dist[i][j],fw_dist[i][k]+fw_dist[k][j]);}
CP_INLINE void fw_init(int n){for(int i=0;i<n;i++)for(int j=0;j<n;j++)fw_dist[i][j]=(i==j)?0:INFLL;}
typedef struct{int u,v;ll w;}BFEdge;
CP_INLINE bool bellman_ford(int n,BFEdge*edges,int m,int s,ll*dist){for(int i=0;i<n;i++)dist[i]=INFLL;dist[s]=0;for(int i=0;i<n-1;i++)for(int j=0;j<m;j++)if(dist[edges[j].u]<INFLL&&dist[edges[j].u]+edges[j].w<dist[edges[j].v])dist[edges[j].v]=dist[edges[j].u]+edges[j].w;for(int j=0;j<m;j++)if(dist[edges[j].u]<INFLL&&dist[edges[j].u]+edges[j].w<dist[edges[j].v])return false;return true;}
static int et_in[MAXN],et_out[MAXN],et_order[2*MAXN],et_idx;
CP_INLINE void euler_tour_build(int root,int n){et_idx=0;for(int i=0;i<n;i++){et_in[i]=-1;et_out[i]=-1;}int*st=(int*)xmalloc((size_t)n*sizeof(int));int*ei=(int*)xmalloc((size_t)n*sizeof(int));int top=0;st[top]=root;ei[top]=graph_head[root];et_in[root]=et_idx;et_order[et_idx++]=root;top++;while(top){int u=st[top-1];int e=ei[top-1];if(e!=-1){ei[top-1]=graph_nxt[e];int v=graph_to[e];if(et_in[v]==-1){et_in[v]=et_idx;et_order[et_idx++]=v;st[top]=v;ei[top]=graph_head[v];top++;}}else{et_out[u]=et_idx;top--;}}free(st);free(ei);}
CP_INLINE int lis_len(const ll*a,int n){ll*dp=(ll*)xmalloc((size_t)n*sizeof(ll));int len=0;for(int i=0;i<n;i++){int lo=0,hi=len;while(lo<hi){int m=(lo+hi)/2;if(dp[m]<a[i])lo=m+1;else hi=m;}dp[lo]=a[i];if(lo==len)len++;}free(dp);return len;}
typedef struct{ll m[2][2];}Mat2;
CP_INLINE Mat2 mat2_mul(Mat2 a,Mat2 b,ll mod){Mat2 c;for(int i=0;i<2;i++)for(int j=0;j<2;j++){__int128 s=0;for(int k=0;k<2;k++)s+=(__int128)a.m[i][k]*b.m[k][j];c.m[i][j]=(ll)(s%mod);}return c;}
CP_INLINE Mat2 mat2_pow(Mat2 a,ll e,ll mod){Mat2 r;r.m[0][0]=r.m[1][1]=1;r.m[0][1]=r.m[1][0]=0;while(e){if(e&1)r=mat2_mul(r,a,mod);a=mat2_mul(a,a,mod);e>>=1;}return r;}
CP_INLINE ll fib_mod(ll n,ll mod){if(n<=0)return 0;Mat2 a;a.m[0][0]=a.m[0][1]=a.m[1][0]=1;a.m[1][1]=0;Mat2 r=mat2_pow(a,n-1,mod);return r.m[0][0]%mod;}
typedef struct{int n;ll**m;}MatN;
CP_INLINE MatN matn_alloc(int n){MatN a;a.n=n;a.m=(ll**)xmalloc((size_t)n*sizeof(ll*));for(int i=0;i<n;i++)a.m[i]=(ll*)xcalloc((size_t)n,sizeof(ll));return a;}
CP_INLINE void matn_free(MatN*a){for(int i=0;i<a->n;i++)free(a->m[i]);free(a->m);a->m=NULL;a->n=0;}
CP_INLINE MatN matn_mul(MatN a,MatN b,ll mod){int n=a.n;MatN c=matn_alloc(n);for(int i=0;i<n;i++)for(int k=0;k<n;k++)if(a.m[i][k])for(int j=0;j<n;j++)c.m[i][j]=(c.m[i][j]+(__int128)a.m[i][k]*b.m[k][j])%mod;return c;}
CP_INLINE MatN matn_pow(MatN a,ll e,ll mod){int n=a.n;MatN r=matn_alloc(n);for(int i=0;i<n;i++)r.m[i][i]=1;while(e){if(e&1){MatN t=matn_mul(r,a,mod);matn_free(&r);r=t;}MatN t=matn_mul(a,a,mod);matn_free(&a);a=t;e>>=1;}matn_free(&a);return r;}
static const int dx4[]__attribute__((unused))={0,1,0,-1};
static const int dy4[]__attribute__((unused))={1,0,-1,0};
static const int dx8[]__attribute__((unused))={0,1,1,1,0,-1,-1,-1};
static const int dy8[]__attribute__((unused))={1,1,0,-1,-1,-1,0,1};
#define IN_GRID(r,c,H,W) ((r)>=0&&(r)<(H)&&(c)>=0&&(c)<(W))
CP_INLINE int grid_idx(int r,int c,int W){return r*W+c;}
CP_INLINE int msb_pos(ull x){return x?63-__builtin_clzll(x):-1;}
CP_INLINE bool is_pow2(ull x){return x&&!(x&(x-1));}
CP_INLINE ull next_pow2(ull x){if(x<=1)return 1;return 1ULL<<(64-__builtin_clzll(x-1));}
CP_INLINE bool safe_mul_ll(ll a,ll b,ll*r){__int128 t=(__int128)a*b;if(t>LLONG_MAX||t<LLONG_MIN)return false;*r=(ll)t;return true;}
CP_INLINE ll euler_phi(ll n){ll r=n;for(ll p=2;p*p<=n;p++)if(n%p==0){while(n%p==0)n/=p;r-=r/p;}if(n>1)r-=r/n;return r;}
CP_INLINE ll nPr_mod(int n,int r,ll mod){if(r<0||r>n)return 0;ll v=1;for(int i=0;i<r;i++)v=(__int128)v*(n-i)%mod;return v;}
CP_INLINE ll nCr_lucas(ll n,ll r,ll p){if(r<0||r>n)return 0;ll res=1;while(n||r){ll ni=n%p,ri=r%p;if(ri>ni)return 0;ll num=1,den=1;for(ll i=0;i<ri;i++){num=num*(ni-i)%p;den=den*(i+1)%p;}res=res*num%p*mod_pow(den,p-2,p)%p;n/=p;r/=p;}return res;}
CP_INLINE ll catalan_mod(int n,ll mod){return (__int128)nCr_mod(2*n,n,mod)*mod_pow(n+1,mod-2,mod)%mod;}

CP_INLINE ll str_to_ll(const char*s){ll r=0;int neg=0,i=0;if(s[0]=='-'){neg=1;i=1;}for(;s[i];i++)r=r*10+(s[i]-'0');return neg?-r:r;}
CP_INLINE ll str_mod(const char*s,ll m){ll r=0;int i=s[0]=='-'?1:0;for(;s[i];i++)r=(r*10+(s[i]-'0'))%m;return s[0]=='-'?mod_norm(-r,m):r;}
CP_INLINE int rle_encode(const char*s,int n,char*oc,int*on){int k=0;for(int i=0;i<n;){int j=i;while(j<n&&s[j]==s[i])j++;oc[k]=s[i];on[k]=j-i;k++;i=j;}return k;}
typedef struct{int*a;int sz,cap;}StackInt;
CP_INLINE void stk_init(StackInt*s,int c){s->cap=c>0?c:4;s->sz=0;s->a=(int*)xmalloc((size_t)s->cap*sizeof(int));}
CP_INLINE void stk_free(StackInt*s){free(s->a);s->a=NULL;s->sz=s->cap=0;}
CP_INLINE bool stk_empty(const StackInt*s){return s->sz==0;}
CP_INLINE void stk_push(StackInt*s,int x){if(s->sz==s->cap){s->cap<<=1;s->a=(int*)xrealloc(s->a,(size_t)s->cap*sizeof(int));}s->a[s->sz++]=x;}
CP_INLINE int stk_pop(StackInt*s){return s->a[--s->sz];}
CP_INLINE int stk_top(const StackInt*s){return s->a[s->sz-1];}
typedef struct{HeapNode*a;int sz,cap;}MaxHeap;
CP_INLINE void mxhe_init(MaxHeap*h,int c){h->cap=c>0?c:4;h->sz=0;h->a=(HeapNode*)xmalloc((size_t)h->cap*sizeof(HeapNode));}
CP_INLINE void mxhe_free(MaxHeap*h){free(h->a);h->a=NULL;h->sz=h->cap=0;}
CP_INLINE bool mxhe_empty(const MaxHeap*h){return h->sz==0;}
CP_INLINE void mxhe_push(MaxHeap*h,int v,ll d){if(h->sz==h->cap){h->cap<<=1;h->a=(HeapNode*)xrealloc(h->a,(size_t)h->cap*sizeof(HeapNode));}int i=h->sz++;h->a[i].v=v;h->a[i].d=d;while(i>0){int p=(i-1)>>1;if(h->a[p].d>=h->a[i].d)break;HeapNode t=h->a[i];h->a[i]=h->a[p];h->a[p]=t;i=p;}}
CP_INLINE HeapNode mxhe_pop(MaxHeap*h){HeapNode ret=h->a[0];h->a[0]=h->a[--h->sz];int i=0;for(;;){int l=i*2+1,r=i*2+2,m=i;if(l<h->sz&&h->a[l].d>h->a[m].d)m=l;if(r<h->sz&&h->a[r].d>h->a[m].d)m=r;if(m==i)break;HeapNode t=h->a[i];h->a[i]=h->a[m];h->a[m]=t;i=m;}return ret;}
#ifndef MONOQ_MAX
#define MONOQ_MAX MAXN
#endif
static int monoq_deq[MONOQ_MAX],monoq_idx[MONOQ_MAX],monoq_head,monoq_tail;
CP_INLINE void monoq_init(void){monoq_head=monoq_tail=0;}
CP_INLINE void monoq_push_min(int val,int idx){while(monoq_head<monoq_tail&&monoq_deq[monoq_tail-1]>=val)monoq_tail--;monoq_deq[monoq_tail]=val;monoq_idx[monoq_tail++]=idx;}
CP_INLINE void monoq_push_max(int val,int idx){while(monoq_head<monoq_tail&&monoq_deq[monoq_tail-1]<=val)monoq_tail--;monoq_deq[monoq_tail]=val;monoq_idx[monoq_tail++]=idx;}
CP_INLINE void monoq_pop_old(int old_idx){if(monoq_head<monoq_tail&&monoq_idx[monoq_head]<=old_idx)monoq_head++;}
CP_INLINE int monoq_front(void){return monoq_deq[monoq_head];}
static ll merge_tmp[MAXN];
CP_INLINE ll merge_inv_rec(ll*a,int l,int r){if(r-l<=1)return 0;int m=(l+r)/2;ll inv=merge_inv_rec(a,l,m)+merge_inv_rec(a,m,r);int i=l,j=m,k=0;while(i<m&&j<r){if(a[i]<=a[j])merge_tmp[k++]=a[i++];else{merge_tmp[k++]=a[j++];inv+=m-i;}}while(i<m)merge_tmp[k++]=a[i++];while(j<r)merge_tmp[k++]=a[j++];for(int x=0;x<k;x++)a[l+x]=merge_tmp[x];return inv;}
CP_INLINE ll inversion_count(ll*a,int n){return merge_inv_rec(a,0,n);}
CP_INLINE ll tree_diameter_bfs(int n,int*u,int*v){int far=0;bfs_dist(0,n);for(int i=0;i<n;i++)if(dist_arr[i]>dist_arr[far])far=i;if(u)*u=far;bfs_dist(far,n);int far2=0;for(int i=0;i<n;i++)if(dist_arr[i]>dist_arr[far2])far2=i;if(v)*v=far2;return dist_arr[far2];}
static int bip_color[MAXN];
CP_INLINE bool is_bipartite(int start,int n){for(int i=0;i<n;i++)bip_color[i]=-1;int front=0,back=0;q[back++]=start;bip_color[start]=0;while(front<back){int u=q[front++];for(int e=graph_head[u];e!=-1;e=graph_nxt[e]){int v=graph_to[e];if(bip_color[v]==-1){bip_color[v]=1-bip_color[u];q[back++]=v;}else if(bip_color[v]==bip_color[u])return false;}}return true;}
static int low_arr[MAXN],disc_arr[MAXN],ap_parent[MAXN],disc_timer;
static bool is_ap[MAXN];
CP_INLINE void ap_dfs(int u){int children=0;disc_arr[u]=low_arr[u]=disc_timer++;for(int e=graph_head[u];e!=-1;e=graph_nxt[e]){int v=graph_to[e];if(disc_arr[v]==-1){children++;ap_parent[v]=u;ap_dfs(v);chmin(low_arr[u],low_arr[v]);if(ap_parent[u]==-1&&children>1)is_ap[u]=true;if(ap_parent[u]!=-1&&low_arr[v]>=disc_arr[u])is_ap[u]=true;}else if(v!=ap_parent[u])chmin(low_arr[u],disc_arr[v]);}}
CP_INLINE int find_articulation_points(int n,int*ap){for(int i=0;i<n;i++){disc_arr[i]=-1;low_arr[i]=0;ap_parent[i]=-1;is_ap[i]=false;}disc_timer=0;for(int i=0;i<n;i++)if(disc_arr[i]==-1)ap_dfs(i);int cnt=0;for(int i=0;i<n;i++)if(is_ap[i])ap[cnt++]=i;return cnt;}
static int bridge_u[MAXM],bridge_v[MAXM],bridge_cnt;
CP_INLINE void bridge_dfs(int u,int pe){disc_arr[u]=low_arr[u]=disc_timer++;for(int e=graph_head[u];e!=-1;e=graph_nxt[e]){if((e^1)==pe)continue;int v=graph_to[e];if(disc_arr[v]==-1){bridge_dfs(v,e);chmin(low_arr[u],low_arr[v]);if(low_arr[v]>disc_arr[u]){bridge_u[bridge_cnt]=u;bridge_v[bridge_cnt]=v;bridge_cnt++;}}else chmin(low_arr[u],disc_arr[v]);}}
CP_INLINE int find_bridges(int n){for(int i=0;i<n;i++)disc_arr[i]=-1;disc_timer=0;bridge_cnt=0;for(int i=0;i<n;i++)if(disc_arr[i]==-1)bridge_dfs(i,-1);return bridge_cnt;}
static bool cycle_vis[MAXN],cycle_rec[MAXN];
CP_INLINE bool cycle_dfs(int u){cycle_vis[u]=cycle_rec[u]=true;for(int e=graph_head[u];e!=-1;e=graph_nxt[e]){int v=graph_to[e];if(!cycle_vis[v]){if(cycle_dfs(v))return true;}else if(cycle_rec[v])return true;}cycle_rec[u]=false;return false;}
CP_INLINE bool has_cycle_directed(int n){for(int i=0;i<n;i++)cycle_vis[i]=cycle_rec[i]=false;for(int i=0;i<n;i++)if(!cycle_vis[i]&&cycle_dfs(i))return true;return false;}
CP_INLINE int ccw(PointLL a,PointLL b,PointLL c){__int128 v=cross3(a,b,c);return v>0?1:(v<0?-1:0);}
CP_INLINE int convex_hull(PointLL*pts,int n,PointLL*hull){if(n<3)return n;for(int i=1;i<n;i++)if(pts[i].y<pts[0].y||(pts[i].y==pts[0].y&&pts[i].x<pts[0].x)){PointLL t=pts[0];pts[0]=pts[i];pts[i]=t;}PointLL pivot=pts[0];for(int i=1;i<n-1;i++)for(int j=i+1;j<n;j++){int c=ccw(pivot,pts[i],pts[j]);if(c<0||(c==0&&(pts[i].x-pivot.x)*(pts[i].x-pivot.x)+(pts[i].y-pivot.y)*(pts[i].y-pivot.y)>(pts[j].x-pivot.x)*(pts[j].x-pivot.x)+(pts[j].y-pivot.y)*(pts[j].y-pivot.y))){PointLL t=pts[i];pts[i]=pts[j];pts[j]=t;}}int k=0;for(int i=0;i<n;i++){while(k>=2&&ccw(hull[k-2],hull[k-1],pts[i])<=0)k--;hull[k++]=pts[i];}int lower=k;for(int i=n-2;i>=0;i--){while(k>lower&&ccw(hull[k-2],hull[k-1],pts[i])<=0)k--;hull[k++]=pts[i];}return k-1;}
CP_INLINE ll manhattan(PointLL a,PointLL b){return ABS(a.x-b.x)+ABS(a.y-b.y);}
CP_INLINE double euclidean(PointLL a,PointLL b){return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));}
CP_INLINE void print_arr_int(const int*a,int n,char sep){for(int i=0;i<n;i++){if(i)write_char(sep);write_ll(a[i]);}write_ln();}
CP_INLINE void print_arr_ll(const ll*a,int n,char sep){for(int i=0;i<n;i++){if(i)write_char(sep);write_ll(a[i]);}write_ln();}
CP_INLINE void write_double(double x,int prec){if(x<0){write_char('-');x=-x;}ll ip=(ll)x;write_ll(ip);write_char('.');x-=(double)ip;for(int i=0;i<prec;i++)x*=10;write_ll((ll)(x+0.5));}
#ifdef DEBUG
CP_INLINE void dump_arr_int(const char*name,const int*a,int n){fprintf(stderr,"%s = [",name);for(int i=0;i<n;i++)fprintf(stderr,"%s%d",i?", ":"",a[i]);fprintf(stderr,"]\n");}
CP_INLINE void dump_arr_ll(const char*name,const ll*a,int n){fprintf(stderr,"%s = [",name);for(int i=0;i<n;i++)fprintf(stderr,"%s%lld",i?", ":"",(long long)a[i]);fprintf(stderr,"]\n");}
CP_INLINE double get_time_sec(void){struct timespec ts;clock_gettime(CLOCK_MONOTONIC,&ts);return ts.tv_sec+ts.tv_nsec*1e-9;}
#else
#define dump_arr_int(name,a,n) ((void)0)
#define dump_arr_ll(name,a,n) ((void)0)
#endif

CP_INLINE int cp_cmp_int_asc(const void*a,const void*b){return(*(int*)a>*(int*)b)-(*(int*)a<*(int*)b);}
CP_INLINE int cp_cmp_ll_asc(const void*a,const void*b){return(*(ll*)a>*(ll*)b)-(*(ll*)a<*(ll*)b);}
CP_INLINE void sort_int(int*a,int n){qsort(a,n,sizeof(int),cp_cmp_int_asc);}
CP_INLINE void sort_ll(ll*a,int n){qsort(a,n,sizeof(ll),cp_cmp_ll_asc);}
#define NTT_MOD 998244353
#define NTT_G 3
CP_INLINE void ntt(ll*a,int n,int inv){int j=0;for(int i=1;i<n;i++){int bit=n>>1;while(j&bit){j^=bit;bit>>=1;}j^=bit;if(i<j){ll t=a[i];a[i]=a[j];a[j]=t;}}for(int len=2;len<=n;len<<=1){ll wlen=mod_pow(NTT_G,(NTT_MOD-1)/len,NTT_MOD);if(inv){wlen=modinv(wlen,NTT_MOD);}for(int i=0;i<n;i+=len){ll w=1;for(int j=0;j<len/2;j++){ll u=a[i+j],v=a[i+j+len/2]*w%NTT_MOD;a[i+j]=(u+v<NTT_MOD)?u+v:u+v-NTT_MOD;a[i+j+len/2]=(u-v>=0)?u-v:u-v+NTT_MOD;w=w*wlen%NTT_MOD;}}}if(inv){ll ninv=modinv(n,NTT_MOD);for(int i=0;i<n;i++)a[i]=a[i]*ninv%NTT_MOD;}}
CP_INLINE void convolution(const ll*a,int n,const ll*b,int m,ll*out){int sz=1;while(sz<n+m)sz<<=1;ll*fa=(ll*)xcalloc(sz,sizeof(ll));ll*fb=(ll*)xcalloc(sz,sizeof(ll));memcpy(fa,a,n*sizeof(ll));memcpy(fb,b,m*sizeof(ll));ntt(fa,sz,0);ntt(fb,sz,0);for(int i=0;i<sz;i++)fa[i]=fa[i]*fb[i]%NTT_MOD;ntt(fa,sz,1);for(int i=0;i<n+m-1;i++)out[i]=fa[i];free(fa);free(fb);}
typedef struct{int*parent,*depth,*heavy,*head,*pos,*subsz;int n,pos_cur;}HLD;
CP_INLINE void hld_dfs_sz(Graph*g,int u,HLD*h){h->subsz[u]=1;int max_sz=0;for(int e=g->head[u];e!=-1;e=g->nxt[e]){int v=g->to[e];if(v!=h->parent[u]){h->parent[v]=u;h->depth[v]=h->depth[u]+1;hld_dfs_sz(g,v,h);h->subsz[u]+=h->subsz[v];if(h->subsz[v]>max_sz){max_sz=h->subsz[v];h->heavy[u]=v;}}}}
CP_INLINE void hld_dfs_hld(Graph*g,int u,HLD*h){h->pos[u]=h->pos_cur++;if(h->heavy[u]!=-1){h->head[h->heavy[u]]=h->head[u];hld_dfs_hld(g,h->heavy[u],h);}for(int e=g->head[u];e!=-1;e=g->nxt[e]){int v=g->to[e];if(v!=h->parent[u]&&v!=h->heavy[u]){h->head[v]=v;hld_dfs_hld(g,v,h);}}}
CP_INLINE void hld_init(HLD*h,Graph*g,int root){h->n=g->n;h->parent=(int*)xmalloc(h->n*sizeof(int));h->depth=(int*)xmalloc(h->n*sizeof(int));h->heavy=(int*)xcalloc(h->n,sizeof(int));h->head=(int*)xmalloc(h->n*sizeof(int));h->pos=(int*)xmalloc(h->n*sizeof(int));h->subsz=(int*)xmalloc(h->n*sizeof(int));for(int i=0;i<h->n;i++){h->parent[i]=-1;h->heavy[i]=-1;}h->pos_cur=0;h->depth[root]=0;h->head[root]=root;hld_dfs_sz(g,root,h);hld_dfs_hld(g,root,h);}
CP_INLINE void hld_free(HLD*h){free(h->parent);free(h->depth);free(h->heavy);free(h->head);free(h->pos);free(h->subsz);}
CP_INLINE int hld_lca(const HLD*h,int u,int v){while(h->head[u]!=h->head[v]){if(h->depth[h->head[u]]>h->depth[h->head[v]])u=h->parent[h->head[u]];else v=h->parent[h->head[v]];}return h->depth[u]<h->depth[v]?u:v;}
typedef struct TrNode{int pri,sz;ll val,sum,lz;struct TrNode *l,*r;}TrNode;
CP_INLINE int tr_cnt(TrNode*t){return t?t->sz:0;}
CP_INLINE ll tr_sum(TrNode*t){return t?t->sum:0;}
CP_INLINE void tr_upd(TrNode*t){if(t){t->sz=1+tr_cnt(t->l)+tr_cnt(t->r);t->sum=t->val+tr_sum(t->l)+tr_sum(t->r);}}
CP_INLINE void tr_push(TrNode*t){(void)t;}
CP_INLINE void tr_split(TrNode*t,int k,TrNode**l,TrNode**r){if(!t){*l=*r=NULL;return;}tr_push(t);if(k<=tr_cnt(t->l)){tr_split(t->l,k,l,&t->l);*r=t;}else{tr_split(t->r,k-1-tr_cnt(t->l),&t->r,r);*l=t;}tr_upd(t);}
CP_INLINE void tr_merge(TrNode**t,TrNode*l,TrNode*r){if(!l||!r)*t=l?l:r;else if(l->pri>r->pri){tr_push(l);tr_merge(&l->r,l->r,r);*t=l;}else{tr_push(r);tr_merge(&r->l,l,r->l);*t=r;}tr_upd(*t);}
CP_INLINE TrNode*tr_new(ll v){TrNode*n=(TrNode*)xcalloc(1,sizeof(TrNode));n->pri=rand();n->sz=1;n->val=n->sum=v;return n;}
CP_INLINE ll geo_poly_area2(PointLL*p,int n){ll s=0;for(int i=0;i<n;i++)s+=cross128(p[i],p[(i+1)%n]);return ABS(s);}
CP_INLINE int geo_pt_in_poly(PointLL*p,int n,PointLL q){int wn=0;for(int i=0;i<n;i++){if(((p[i].y<=q.y)&&(p[(i+1)%n].y>q.y))||((p[i].y>q.y)&&(p[(i+1)%n].y<=q.y))){double vt=(double)(q.y-p[i].y)/(p[(i+1)%n].y-p[i].y);if(q.x<(p[i].x+vt*(p[(i+1)%n].x-p[i].x)))wn++;}}return wn&1;}
#ifndef AC_MAX
#define AC_MAX 500000
#endif
typedef struct{int tr[AC_MAX][26],fail[AC_MAX],end[AC_MAX],sz;}AhoCorasick;
CP_INLINE void ac_init(AhoCorasick*ac){memset(ac,0,sizeof(*ac));ac->sz=1;}
CP_INLINE void ac_insert(AhoCorasick*ac,const char*s,int id){int u=0;for(;*s;s++){int c=*s-'a';if(!ac->tr[u][c])ac->tr[u][c]=ac->sz++;u=ac->tr[u][c];}ac->end[u]=id;}
CP_INLINE void ac_build(AhoCorasick*ac){int*q=(int*)xmalloc(AC_MAX*sizeof(int));int h=0,t=0;for(int c=0;c<26;c++)if(ac->tr[0][c])q[t++]=ac->tr[0][c];while(h<t){int u=q[h++];for(int c=0;c<26;c++){if(ac->tr[u][c]){ac->fail[ac->tr[u][c]]=ac->tr[ac->fail[u]][c];q[t++]=ac->tr[u][c];}else ac->tr[u][c]=ac->tr[ac->fail[u]][c];}}free(q);}
#endif
