#include "bits/stdc++.h"
 
using namespace std;
 
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define vii vector<pii>
#define vll vector<pll>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vl vector<long long>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define rsz resize
 
#ifdef Etherite_Local
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}
#else
#define DBG1(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG4(a, b, c, d)
#define DBGpair(x, y)
#define DBGvec(x)
#endif
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
const int MOD = 1e9 + 7; //998244353
const ll INF = 1e9;
 
void setIO(string filename) 
{
    if(fopen((filename + ".in").c_str(), "r"))
    {
        freopen((filename + ".in").c_str(), "r", stdin);
        freopen((filename + ".out").c_str(), "w", stdout);
    }
}

long long binpow(long long a, long long b, long long m = 1e9 + 7) 
{
    a %= m;
    long long res = 1;
    while(b > 0) 
    {
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
void solve()
{
    setIO("spainting");
    ll n, m, k; cin >> n >> m >> k;

    vl dp(n + 1);
    ll sum = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i < k)
        {
            dp[i] = binpow(m, i);
            sum += dp[i];
            sum %= MOD;
            continue;
        }
        sum -= dp[i - k];
        if(sum < 0) sum += MOD;
        dp[i] = (m - 1) * sum;
        dp[i] %= MOD;
        sum += dp[i];
        sum %= MOD;
    }
    ll ans = binpow(m, n) - dp[n];
    if(ans < 0) ans += MOD;
    cout << ans << endl;
    DBGvec(dp);
}
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t = 1;
    // cin >> t;
 
    for(int i = 1; i <= t; i++) solve();
 
    return 0;
}