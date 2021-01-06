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


const int maxn = 1500 + 5;
int N, K; string strs[maxn];
unordered_map<string, int> s;
 
int main() {
    cin >> N >> K; ll ans = 0; string str;
    rep(i, 1, N) cin>>strs[i], s[strs[i]]=i;
    rep(i, 1, N) {
        rep(j, i+1, N) {
            str.clear();
            rep(k, 0, K-1) {
                if(strs[i][k]==strs[j][k]) str+=strs[i][k];
                else str+='S'+'E'+'T'-strs[i][k]-strs[j][k];
            }
            if(s.count(str) && s[str]>j) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}


