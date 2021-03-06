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
    setIO("cardgame");
    int n; cin >> n;
    vi ehigh(n / 2), elow(n / 2);
    for(int i = 0; i < n / 2; i++) cin >> ehigh[i];
    for(int i = 0; i < n / 2; i++) cin >> elow[i];
    vb v(2 * n + 1); for(int i : ehigh) v[i] = 1; for(int i : elow) v[i] = 1;
    vi bess;
    for(int i = 1; i <= 2 * n; i++) if(!v[i]) bess.pb(i);
    sort(rall(ehigh)); sort(rall(bess));
    int ptr = 0;
    int ans = 0;
    for(int i = 0; i < n / 2; i++)
    {
        while(ptr < n / 2)
        {
            if(ehigh[ptr] < bess[i]) 
            {
                // cout << ehigh[ptr] << " " << bess[i] << endl;
                ans++;
                ptr++;
                break;
            }
            ptr++;           
        }
    }
    // watch(ans);
    sort(all(bess));
    sort(all(elow));
    ptr = 0;
    for(int i = 0; i < n / 2; i++)
    {
        while(ptr < n / 2)
        {
            if(elow[ptr] > bess[i]) 
            {
                ans++; 
                ptr++; 
                break;
            }
            ptr++;
        }
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
