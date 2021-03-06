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
#define watch(x) cout << (#x) << " is " << (x) << endl

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

void solve()
{
    setIO("hayfeast");
    ll n, m; cin >> n >> m;
    vector<pll> a(n); for(auto &i : a) cin >> i.first >> i.second;   
    multiset<ll> s;
    int l = 0, r = 0;
    ll sum = 0;
    ll ans = 1e9 + 1;
    while(true)
    {
        if(sum >= m)
        {
            ans = min(ans, *s.rbegin());
            s.erase(s.find(a[l].second));
            sum -= a[l].first;
            l++;
        }
        if(r >= n) break;
        // watch(sum);
        sum += a[r].first;
        s.insert(a[r].second);
        r++;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
