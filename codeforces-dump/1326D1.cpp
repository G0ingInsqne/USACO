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

bool pal(string s)
{
    int n = s.size();
    rep(i, 0, n)
    {
        if(s[i] != s[n - i - 1]) return 0;
    }
    return 1;
}

void solve()
{
    int n; string s; cin >> s; n = s.size();
    int p1 = 0, p2 = n - 1;
    string s1, s2;
    while(p1 <= p2)
    {
        if(p1 == p2)
        {
            s1 += s[p1];
            break;
        }
        if(s[p1] == s[p2]) 
        {
            s1 += s[p1];
            s2 += s[p2];
            p1++; p2--;
        }
        else
        {
            string c1, c2;
            string l1, l2;
            rep(i, p1, p2)
            {
                c1 += s[i];
                if(pal(c1)) l1 = c1;
            }
            brep(i, p2, p1 - 1)
            {
                c2 += s[i];
                if(pal(c2)) l2 = c2;
            }
            if(l1.size() > l2.size()) s1 += l1;
            else s2 += l2;
            break;
        }
    }
    reverse(all(s2));
    cout << s1 + s2 << endl;
}

int main()
{
    fastio

    int t = 1;
    cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
