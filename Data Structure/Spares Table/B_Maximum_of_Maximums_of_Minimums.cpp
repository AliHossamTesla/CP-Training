/*
*أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
*by : @Tesla .
*/
#include <bits/stdc++.h>
using namespace std;
#define int      	long long
const int MAXN = 1e5 + 5 ;
const int MAXK = 20 ;
int st[MAXN][MAXK] ;
int lg[MAXN] ;

int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N , K ; cin >> N >> K ;
    vector<int>A(N) ;
    int mx = LLONG_MIN, mn = LLONG_MAX ;
    for(int i = 0 ; i < N ; i ++) cin >> A[i] , mx = max(mx,A[i]),mn = min(mn,A[i]);
    if(K == 1) cout << mn << endl ;
    else if(K > 2) cout << mx << endl ;
    else{
        lg[1] = 0 ;
        for(int i = 2 ; i < MAXN ;i ++) lg[i] = lg[i / 2] + 1 ;
        for(int i = 0 ; i < N ; i ++) st[i][0] = A[i] ;
        for(int j = 1 ; j < MAXK ; j ++)
            for(int i = 0 ; i + (1 << j) <= N ; i ++)
                st[i][j] = min(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]) ;
        int ans = LLONG_MIN ;
        for(int L2 = 1 ; L2 < N ; L2 ++){
            int L1 = 0 , R1 = L2 - 1 , R2 = N - 1 ;
            int i1 = lg[R1 - L1 + 1], i2 = lg[R2 - L2 + 1];
            int cr = max(min(st[L1][i1], st[R1 - (1 << i1) + 1][i1]), min(st[L2][i2], st[R2 - (1 << i2) + 1][i2]));
            ans = max(cr,ans) ;
        }
        cout << ans << endl; 
    }
	return 0 ;
}