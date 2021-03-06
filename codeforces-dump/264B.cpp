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

ll gcd(ll a, ll b)
{
    return __gcd(a, b);
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

bool cmp()
{
    return 0;
}


const int maxn=1e5+10;
 
int dp[maxn],arr[maxn],n,a,maxi=1,lm=1,dv[maxn];
 
void solve()
{
    cin>>n;
     for(int i=1;i<=n;i++)
     {
            cin>>a;
            for(int j=1;j*j<=a;j++)
            {
                if(a%j==0)
                {
                   dp[i]=max(dp[i],dp[dv[a/j]]+1);
                   if(j>1)
                   {
                       dp[i]=max(dp[i],dp[dv[j]]+1);
                   }
                   maxi=max(maxi,dp[i]);
                   dv[j]=dv[a/j]=i;
                }
            }
        
     }
    
    cout<<maxi<<endl;
    
}


int main()
{
    fastio

    int t = 1;
    //cin >> t;

    for(int i = 1; i <= t; i++) solve();
}
