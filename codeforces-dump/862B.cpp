#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vb vector<bool>
#define vl vector<long long>
#define vi vector<int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pf push_front
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()

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

template <class T> void printvec(vector<T> a)
{
    for(T i : a) cout << i << " ";
    cout << endl;
}

bool cmp()
{
    return 0;
}
set<int> red, blue;
vb v; vector<set<int>> adj;

void dfs(int node, bool curr)
{
    if(curr == 0) red.insert(node);
    else blue.insert(node);
    for(int adjnode : adj[node])
    {
        if(v[adjnode]) continue;
        v[adjnode] = 1;
        dfs(adjnode, !curr);
    }
}

void solve()
{
    int n; cin >> n;
    adj.resize(n);
    v.resize(n);
    rep(i, 0, n - 1)
    {
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }   
    dfs(0, 0);
    cout << (red.size() - 1) * (blue.size() - 1);
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    while(t-- > 0) solve();
}
