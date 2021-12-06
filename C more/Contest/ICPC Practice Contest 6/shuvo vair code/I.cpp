using namespace std;
#define lll int128_t
#define ll long long
#define int long long
#define FOR(i,a,b) for(ll i=a;i<(ll)b;i++)
#define FORr(i,a,b) for(ll i =a;i>=(ll)b;i--)
#define rep(i,n) FOR(i,0,n)
#define rep1(i,n) FOR(i,1,n)
#define print(arr)  for(auto a: arr) cout << a<< " "; cout << endl;
#define case(i) cout << "Case " << i << ": ";
#define in(a) ll a; cin >> a;
#define inp(arr,n) vector<ll>arr(n); for(auto &a: arr) cin >> a;
#define pb emplace_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define f first
#define vll vector<ll>
#define s second
#define mod   998244353
#define pll pair<ll, ll>
#define set_bit(x, idx) x = x|(1LL<<idx)
ll dx[8] = {0,1,0,-1,1,-1,1,-1};
ll dy[8] = {-1,0,1,0,1,1,-1,-1};
#define toggle_bit(x, idx) x = x^(1LL<<idx)
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define endl "\n"
template<typename T> ostream& operator<<(ostream &os, const multiset<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const set<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define db long double
#ifdef DEBUG
#define ios
#define dbg(...) cerr << __LINE__ << " : " ;cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
#define ok cerr << __LINE__ << " is done " << endl;
#else
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define dbg(...)
#define ok
#endif

 
void solve(int pk);
int32_t main()
{
    ios ;
    ll nn = 1;
    cin >> nn;
    rep(i, nn) solve(i+1);
}
void solve(int tt)
{
    in(n)
    inp(temp, n-1); vector<ll>arr(n);
    arr[0] = 0;
    rep1(i, n){
        arr[i] = arr[i-1] + temp[i-1];
    }
    ll sum_last = 0, sum_for = 0;
    ll pref_last = 0, pref_for = 0;
    vector<ll>ans(n);
    ll jin = 1;
    ll forward = 0, backward = n-1;
    for(int i = 0; i < n; i++){
        if(jin&1){
            ll pore_ase = n-1-backward;
            ll ami = arr[forward]*pore_ase;
            ami = pref_last - ami;
            ans[i] += ami;
            ll age_ase = forward;
            ami = arr[forward]*age_ase;
            ami -= pref_for;
            ans[i] += ami;
            pref_for += arr[forward];
            forward++;
        }
        else{
            ll pore_ase = n-1-backward;
            ll ami = arr[backward]*pore_ase;
            ami = pref_last - ami;
            ans[i] += ami;
            ll age_ase = forward;
            ami = arr[backward]*age_ase;
            ami -= pref_for;
            ans[i] += ami;
            pref_last += arr[backward];
            backward--;
        }
        jin ^= 1;
    }
    rep1(i, n) ans[i] += ans[i-1];
    cout << ans[0];
    for(int i = 1; i < n; i++){
        cout <<" " << ans[i];
    }
    cout << endl;
}