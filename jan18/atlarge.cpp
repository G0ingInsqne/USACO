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

vvi adj;
vi dp;
int n;

int pre(int curr, int par)
{
    int spath = 1e9;
    for(auto adjnode : adj[curr])
    {
        if(adjnode == par) continue;
        spath = min(spath, pre(adjnode, curr) + 1);
    }
    return(dp[curr] = (spath == 1e9? 0 : spath));
}

int ans = 0;
void dfs(int curr, int par, int dep)
{
    if(dp[curr] > dep)
    {
        for(auto adjnode : adj[curr])
        {
            if(adjnode == par) continue;
            dfs(adjnode, curr, dep + 1);
        }
    }
    else
    {
        ans++; return;
    }
}

void solve()
{   
    setIO("atlarge");
    int k; cin >> n >> k; k--;
    dp.rsz(n); adj.rsz(n);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dp[k] = pre(k, -1);
    DBGvec(dp);
    dfs(k, -1, 0);
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
