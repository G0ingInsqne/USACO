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

ll aceil(ll num, ll denom)
{
    return (num + denom - 1) / denom;
}

void solve()
{
    int n, m; cin >> n >> m;
    vii a(m);
    for(int i = 0; i < m; i++) cin >> a[i].first >> a[i].second;
    sort(all(a));
    int works = 0;
    for(int fpf = 1; fpf <= 1000; fpf++)
    {
        bool flag = 1;
        for(int i = 0; i < m; i++)
        {
            int rightfloor = aceil(a[i].first, fpf);
            if(rightfloor != a[i].second) {flag = 0; break;}
        }
        if(flag)
        {
            if(works == 0) works = aceil(n, fpf);
            else
            {
                if(aceil(n, fpf) != works)
                {
                    cout << "-1\n"; return;
                }
            }
        }
    }   
    cout << works << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
