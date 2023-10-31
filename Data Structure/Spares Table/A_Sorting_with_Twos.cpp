/*
 *أَمْ حَسِبْتُمْ أَن تَدْخُلُوا الْجَنَّةَ وَلَمَّا يَأْتِكُم مَّثَلُ الَّذِينَ خَلَوْا مِن قَبْلِكُم ۖ مَّسَّتْهُمُ الْبَأْسَاءُ وَالضَّرَّاءُ وَزُلْزِلُوا حَتَّىٰ يَقُولَ الرَّسُولُ وَالَّذِينَ آمَنُوا مَعَهُ مَتَىٰ نَصْرُ اللَّهِ ۗ أَلَا إِنَّ نَصْرَ اللَّهِ قَرِيبٌ (214)
 *by : @Tesla .
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define rall(n) n.rbegin(), n.rend()
#define all(n) n.begin(), n.end()
const int MOD = 1e9 + 7;

int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--){
		int N ; cin >> N ;
        vector<int>A(N) ;
        for(int i = 0; i < N ; i ++) cin >> A[i] ;
        bool ok = 1 ;
        for(int i = 0 ; i < N ; i <<= 1){
            for(int j = i + 1; j < (i << 1) ; j ++) ok &= (A[j] >= A[j - 1]) ;
        }
        cout << (ok ? "YES\n" : "NO\n");
	}
	return 0;
}