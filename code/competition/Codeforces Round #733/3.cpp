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
const int maxn = 110000;
int a[maxn],ans[maxn];
void work()
{
    int n;
    cin>>n;
    set<int> s;
    // cout<<"asdasddsdas"<<endl;
    for(int i=1;i<=n;i++)
        cin>>a[i],s.insert(i),ans[i]=-1;
    int aa=0;
    for(int i=1;i<=n;i++){
        if(s.count(a[i])){
            s.erase(a[i]);
            ans[i]=a[i];
            aa++;
        }
    }
    vector<int> tmp;
    for(auto i:s)
        tmp.push_back(i);
    for(int i=0;i<tmp.size();i++)
        cout<<tmp[i]<<' ';
    cout<<endl;
    while(1){
        random_shuffle(tmp.begin(),tmp.end());
        int flag=0;
        int tail=0;
        for(int i=1;i<=n;i++){
            if(ans[i]==-1){
                if(tmp[tail]==i){
                    flag=1;
                    break;
                }else tail++;
            }
        }
        // cout<<"flag="<<flag<<' '<<tail<<endl;
        if(!flag){
            tail=0;
            for(int i=1;i<=n;i++){
                if(ans[i]==-1){
                    ans[i]=tmp[tail++];
                }
            }
            break;
        }
    }
    cout<<aa<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}
signed main()
{
   #ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif
std::ios::sync_with_stdio(false);
cin.tie(NULL);
int t = 1;
cin>>t;
while (t--)
{
work();
}
return 0;
}