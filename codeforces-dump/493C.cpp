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
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define pf push_front
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define rep(i, begin, end) for(int i = begin; i < end; i++)
#define brep(i, end, begin) for(int i = end; i > begin; i--)
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

bool cmp()
{
    return 0;
}

void solve()
{
    int n; cin >> n; vl a(n); rep(i, 0, n) cin >> a[i];
    int m; cin >> m; vl b(m); rep(i, 0, m) cin >> b[i];
    sort(all(a)); sort(all(b));
    ll d = 0;
    ll scorea = 0, scoreb = 0, mxdiff = -1e17, fina = 0, finb = 0;
    int ptra = 0;
    rep(i, 0, n) 
    {
        scorea += (a[i] <= d? 2 : 3);
        if(a[i] <= d) ptra = i;
    }
    rep(i, 0, m) scoreb += (b[i] <= d? 2 : 3);
    mxdiff = max(mxdiff, scorea - scoreb);
    fina = scorea; finb = scoreb;
    rep(i, 0, m)
    {
        d = b[i];
        scoreb--;
        if(ptra < n)
        {
            while(a[ptra] <= d)
            {
                scorea--;
                ptra++;
                if(ptra == n) break;
            }
        }
        if(scorea - scoreb > mxdiff)
        {
            mxdiff = scorea - scoreb;
            fina = scorea;
            finb = scoreb;
        }
    }
    cout << fina << ":" << finb << endl;
}

int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
