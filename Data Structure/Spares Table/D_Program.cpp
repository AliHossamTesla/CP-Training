/*
*أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
*by : @Tesla .
*/
#include <bits/stdc++.h>
using namespace std;
#define int      	long long
#define pb       	push_back
#define rall(n)  	n.rbegin(), n.rend()
#define all(n)   	n.begin(), n.end()
const int MOD = 1e9 + 7 ;
template <typename T, class F = function<T(const T &, const T &)>>
class SparseTable{
public:
	int n;
	vector<vector<T>> mat;
	F func;
	SparseTable(const vector<T> &a, const F &f) : func(f){
		n = static_cast<int>(a.size());
		int max_log = 32 - __builtin_clz(n);
		mat.resize(max_log);
		mat[0] = a;
		for (int j = 1; j < max_log; j++){
			mat[j].resize(n - (1 << j) + 1);
			for (int i = 0; i <= n - (1 << j); i++){
				mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	T Query(int L, int R) const{
		assert(0 <= L && L <= R && R <= n - 1);
		int lg = 32 - __builtin_clz(R - L + 1) - 1;
		return func(mat[lg][L], mat[lg][R - (1 << lg) + 1]);
	}
};
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--){
		int N , M ; cin >> N >> M ;
		string s; cin >> s ;
		s = "#" + s ;
		vector<int>pref(N + 2,0) ;
		for(int i = 1 ; i <= N ; i ++){
			if(s[i] == '+') pref[i] = 1 ;
			else pref[i] = -1 ;
			pref[i] += pref[i - 1] ;
		}
		SparseTable<int>MX(pref,[&](int i,int j){return max(i,j) ;}) ;
		SparseTable<int>MN(pref,[&](int i,int j){return min(i,j) ;}) ;
		vector<int>mn(N + 2,0),mx(N + 2,0) ;
		for(int i = N ; i >= 1 ; i --){
			mn[i] = min(0LL,mn[i + 1]) ;
			mx[i] = max(0LL,mx[i + 1]) ;
			if(s[i] == '+') mn[i] ++ , mx[i] ++ ;
			else mn[i] -- , mx[i] -- ;
		}
		while(M --){
			int L , R ; cin >> L >> R ;
			int l = min(MN.Query(0,L - 1),pref[L - 1] + mn[R + 1]) ;
			int r = max(MX.Query(0,L - 1),pref[L - 1] + mx[R + 1]);
			cout << r - l + 1 << endl ;
		}
	}
	return 0 ;
}