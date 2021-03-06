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

void solve()
{
    vi primes = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int n; cin >> n; vi a(n); rep(i, 0, n) cin >> a[i];
    vi ans(n);
    int curr = 1;
    rep(i, 1, 12)
    {
        bool flag = 0;
        rep(j, 0, n)
        {
            if(ans[j] != 0) continue;
            if(a[j] % primes[i] == 0)      
            {
                ans[j] = curr;
                flag = 1;
            } 
        }
        if(flag) curr++;
        flag = 0;
    }
    
    cout << curr - 1 << endl;
    printvec(ans);
}

int main()
{
    fastio

    int t = 1;
    cin >> t;

    while(t-- > 0) solve();
}
