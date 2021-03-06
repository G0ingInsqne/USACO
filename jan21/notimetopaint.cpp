#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pipii pair<int, pair<int, int>>
#define vvi vector<vector<int>>
#define vii vector<pii>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define vl vector<long long>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define endl "\n"
#define rall(x) (x).rbegin(),(x).rend()
#define DBG1(x) cerr << (#x) << ": " << (x) << endl;
#define DBG2(x, y) cerr << (#x) << " " << (#y) << ": " << (x) << " " << y << endl;
#define DBG3(x, y, z) cerr << (#x) << " " << (#y) << " " << (#z) << ": " << (x) << " " << y << " " << z << endl;
#define DBG4(a, b, c, d) cerr << (#a) << " " << (#b) << " " << (#c) << " " << (#d) << ": " << a << " " << b << " " << c << " " << d << endl;
template<class T> void DBGpair(T a, string s = "") {cerr << s << (s == ""? "" : ": ") <<  a.first << ", " << a.second << endl;}
template <class T> void DBGvec(vector<T> a){for(T i : a) cerr << i << " "; cerr << endl;}

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

void solve()
{
    int n, q; cin >> n >> q;
    vi a(n);
    for(int i = 0; i < n; i++) {char x; cin >> x; a[i] = x - 'A';};

    vi prefsum(n + 1), suffsum(n + 1);
    vi last(26, -1);
    for(int i = 1; i <= n; i++)
    {
        prefsum[i] = prefsum[i - 1];
        if(a[i - 1] > last[a[i - 1]]) prefsum[i]++;
        for(auto &j : last) j = min(j, a[i - 1]);
        last[a[i - 1]] = a[i - 1];
    }
    for(auto &i : last) i = -1;
    for(int i = n - 1; i >= 0; i--)
    {
        suffsum[i] = suffsum[i + 1];
        if(a[i] > last[a[i]]) suffsum[i]++;
        for(auto &j : last) j = min(j, a[i]);
        last[a[i]] = a[i];
    }
    for(int i = 0; i < q; i++)
    {
        int l, r; cin >> l >> r;
        int ans = prefsum[l - 1] + suffsum[r];
        cout << ans << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
