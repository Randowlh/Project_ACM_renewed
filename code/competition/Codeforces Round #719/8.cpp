#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std;
#pragma optimize(2)
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define rbset(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
   x=0;char o,f=1;
   while(o=getchar(),o<48)if(o==45)f=-f;
   do x=(x<<3)+(x<<1)+(o^48);
   while(o=getchar(),o>47);
   x*=f;
}
template<class T>inline void wt(T x){
    static int top,stk[105];
    if(x<0)x=-x,putchar('-');
    if(x==0)putchar('0');
    while(x)stk[++top]=x%10,x/=10;
    while(top)putchar(stk[top--]+'0');
}
#define pii(a,b) pair<a,b>
#define X first
#define Y second
#define lowbit(x) (x&-x)
#define MP make_pair
#define pb push_back
#define pt putchar
#define yx_queue priority_queue
#define lson(pos) (pos<<1)
#define rson(pos) (pos<<1|1)
#define y1 code_by_Rand0w
#define yn A_muban_for_ACM
#define j1 it_is just_an_eastegg
#define lr hope_you_will_be_happy_to_see_this
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll llinf = 4223372036854775807;
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const int m1 = 998244353;
const int m2 = 1000001011;
const int pr=233;
const double eps = 1e-7;
const int maxm= 1;
const int maxn = 510000;
map<pair<int,int>,int> M;
void jian(int l,int r,int pos){
    int mid=l + r >> 1;
    if(M.count({l,r}))
    M[{l,r}]--;
    if(l==r)    
        return;
    if(pos<=mid)
        jian(l,mid,pos);
    else
    jian(mid+1,r,pos);
}
void work()
{
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=t;i++){
        int k;
        cin>>k;
        int l=0,r=n-1;
        while(l^r){
            int mid=l+r>>1;
            int tt=0;
            if(!M.count({l,mid})){
                cout<<"? "<<l+1<<' '<<mid+1<<endl;
                cin>>tt;
                tt=mid-l+1-tt;
                M[{l,mid}]=tt;
            }else tt=M[{l,mid}];
            if(tt>=k)
                r=mid;
            else
            {
                k-=tt;  
                l=mid+1;
            }
        }
        cout<<"! "<<l+1<<endl;
        jian(0,(n-1),l);
    }
}
signed main()
{
   #ifndef ONLINE_JUDGE
//    freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t = 1;
//cin>>t;
while (t--)
{
work();
}
return 0;
}