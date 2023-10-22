/*
*أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
*by : @Tesla .
*/
#include <bits/stdc++.h>
using namespace std;
#define int      	long long
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
            for (int i = 0; i <= n - (1 << j); i++)
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
        }
    }

    T Query(int L, int R) const{
        assert(0 <= L && L <= R && R <= n - 1);
        int lg = 32 - __builtin_clz(R - L + 1) - 1;
        return func(mat[lg][L], mat[lg][R - (1 << lg) + 1]);
    }
};

int32_t main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N ; cin >> N ;
        vector<int>A(N) ;
        for(int i = 0 ; i < N ; i++) cin >> A[i] ;
        SparseTable<int> RMQ(A,[&](int i,int j){return max(i,j) ;}) ;
        int M ; cin >> M ;
        vector<int>mx(N + 1,-1) ;
        for(int i = 0 ; i < M ;i ++){
            int p , s ; cin >> p >> s ;
            mx[s] = max(mx[s],p) ;
        }
        for(int i = N - 1 ; i >= 0 ; i --) mx[i] = max(mx[i],mx[i + 1]) ;
        function<int(int)> solve = [&](int idx)->int{
            if(idx == N) return 0 ;
            int l = idx , r = N - 1 ,ans = -1 ;
            while(l <= r){
                int mid = l + (r - l)/2 ;
                if(RMQ.Query(idx,mid) > mx[mid - idx + 1]) r = mid - 1 ;
                else ans = mid - idx + 1, l = mid + 1;
            }
            if(ans == -1) return 1e9 ;
            else return 1 + solve(idx + ans) ;
        };
        int ans = solve(0) ;
        cout << (ans >= 1e9 ? -1 : ans) << endl ;
    }
	return 0 ;
}
