soln to A open 2021

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
template<class T> void DBGpair(T a, string s = "") {return;}
template <class T> void DBGvec(vector<T> &a){}
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

struct bit 
{
    vector<long long> tree;
    bit(int n) {tree = vector<long long>(n + 5, 0);}

    long long rsq(int idx) 
    {
        long long sum = 0; 
        while(idx > 0)
        {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum; 
    }

    long long rsq(int a, int b) // 0 based indexing range query on [a, b]
    {
        a++; b++;
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); 
    }

    void upd(int idx, int val) // 0 based indexing point update
    {
        idx++;
        while(idx < (int) tree.size() - 1)
        {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }
};

int p[200005];

void solve()
{
    int n; cin >> n;
    vi a(n); 
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vvi pos(n + 1);
    for(int i = 0; i < n; i++) pos[a[i]].pb(i);

    ll ans = 0;
    vii queries;
    for(int i = 0; i < n; i++)
    {
        int last = lower_bound(all(pos[a[i]]), i) - pos[a[i]].begin() - 1;
        int curr = 0;
        if(last >= 0) curr = pos[a[i]][last];
        if(a[curr] == a[i]) curr++;
        if(curr < i) queries.pb(mp(curr, i));
    }

    memset(p, -1, sizeof(p));
    bit tree(n);
    int x = 0, q = queries.size();
    for(int i = 0; i < n; i++)
    {
        if(p[a[i]] != -1) tree.upd(p[a[i]], -1);
        p[a[i]] = i;
        tree.upd(i, 1);
        while(x < q && queries[x].second == i) ans += tree.rsq(queries[x].first, queries[x].second - 1), x++;
    }

    cout << ans << endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    // cin >> t;

    for(int i = 1; i <= t; i++) solve();

    return 0;
}
