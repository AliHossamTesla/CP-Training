/*
*أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
*by : @Tesla .
*/
#include <bits/stdc++.h>
using namespace std;
#define int      	long long
const int MAXN = 2e5 + 5;
const int MAXK = 20;
int st_sum[MAXN][MAXK];
int st_max[MAXN][MAXK];
int lg[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    auto init1 = [&](){
        lg[1] = 0;
        for (int i = 2; i < MAXN; i++) lg[i] = lg[i / 2] + 1;
    };
    init1();
    while(T--){
        int N ; cin >> N ;
        vector<int>A(N) ;
        bool ok = 1 ;
        for(int i = 0 ; i < N ; i ++) cin >> A[i] ;
        auto init2 = [&](){
            for (int i = 0; i < N; i++) st_max[i][0] = st_sum[i][0] = A[i];
            for (int j = 1; j < MAXK; j++)
                for (int i = 0; i + (1 << j) <= N; i++){
                    st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
                    st_sum[i][j] = (st_sum[i][j - 1] + st_sum[i + (1 << (j - 1))][j - 1]);
                    ok &= (st_max[i][j] >= st_sum[i][j]) ;
                }
        };
        init2() ;
        cout << (ok ? "YES\n" : "NO\n") ;
    }
	return 0 ;
}
