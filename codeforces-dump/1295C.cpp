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
    for(T i : a) cerr << i << " ";
    cerr << endl;
}

bool cmp()
{
    return 0;
}

void solve()
{
    string s, t; int sl, tl; cin >> s >> t; sl = s.size(); tl = t.size();

    map<char, set<int>> m;
    rep(i, 0, sl)
    {
        m[s[i]].insert(i);
    }
    int moves = 0, last = -1;
    int i = 0;
    while(true)
    {
        if(i >= tl) break;
        char curr = t[i];
        if(m.find(curr) == m.end()) {cout << -1 << endl; return;}
        if(m[curr].upper_bound(last) != m[curr].end())
        {
            last = *m[curr].upper_bound(last);
            i++;
        }
        else 
        {
            moves++;
            last = -1;
        }
    }
    cout << moves + (last == -1? 0 : 1) << endl;
}

int main()
{
    fastio

    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
