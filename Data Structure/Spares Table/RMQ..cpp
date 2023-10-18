/*
 * Sparse Table
 *أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 *by : @Tesla .
 * verification : https://www.spoj.com/problems/RMQSQ/
*/
#include <bits/stdc++.h>
using namespace std;
#define int      	long long
const int MAXN = 1e5 + 5;
const int K = 20 ;
int st[K][MAXN] ;
int lg[MAXN+1];
int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N ; cin >> N ;
	vector<int>A(N) ;
	for(int i = 0 ; i < N ; i ++) cin >> A[i] ;
	lg[1] = 0;
	for (int i = 2; i <= MAXN; i++)
		lg[i] = lg[i/2] + 1;
	copy(A.begin(),A.end(),st[0]) ;
	for(int i = 1 ; i <= K ; i ++)
		for(int j = 0 ; j + (1 << i) <= N ; j ++)
			st[i][j] = min(st[i - 1][j],st[i - 1][j + (1 << (i - 1))]) ;
	int Q ; cin >> Q ;
	while(Q--){
		int L , R ; cin >> L >> R ;
		int i = lg[R - L + 1] ;
		int ans = min(st[i][L],st[i][R - (1 << i) + 1]) ;
		cout << ans << endl ;
	}
	return 0 ;
}
