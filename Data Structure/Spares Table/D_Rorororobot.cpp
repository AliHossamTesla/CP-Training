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
	int N , M ; cin >> N >> M ;
	vector<int>A(M,0) ;
	for(int i = 0 ; i < M ; i ++) cin >> A[i] ;
	SparseTable<int> RMQ(A,[&](int i,int j){return max(i,j) ;});
	int Q ; cin >> Q ;
	while(Q--){
		int X_1 , X_2 ,Y_1 , Y_2 , K ; cin >> X_1 >> Y_1 >> X_2 >> Y_2 >> K ;
		Y_1 -- ; Y_2 -- ;
		if(abs(X_1 - X_2) % K != 0 or abs(Y_1 - Y_2) % K != 0){
			cout << "NO\n" ;
			continue ;
		}
		if(Y_1 > Y_2){
			swap(X_1,X_2) ;
			swap(Y_1,Y_2) ;
		}
		int lim = X_1 + (N - X_1)/K * K ;
		cout << (RMQ.Query(Y_1,Y_2) < lim ? "YES\n" : "NO\n") ;
	}
	return 0 ;
}