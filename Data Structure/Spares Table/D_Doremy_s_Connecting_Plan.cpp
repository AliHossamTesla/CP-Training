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


int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N ,C; cin >> N >> C;
        vector<int>A(N) ;
        for(int i = 0; i < N ; i++) cin >> A[i] ;
        vector<pair<int,int>>B;
        for(int i = 2 ; i <= N ; i ++) B.pb({i*C - A[i - 1],i - 1}) ;
        sort(all(B)) ;
        bool ok = 1 ;
        int cr = A[0];
        for(int i = 1; i < N ; i ++){
            if(cr >= B[i - 1].first) cr += A[B[i - 1].second] ;
            else{
                ok = 0 ;
                break ;
            }
        }
        cout << (ok ? "Yes\n" : "No\n") ;
    }
	return 0 ;
}