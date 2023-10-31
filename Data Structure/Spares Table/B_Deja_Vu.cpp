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
		int N , M ; cin >> N >> M ;
        vector<int>A(N) ;
        for(int i = 0 ; i < N ; i ++) cin >> A[i] ;
        int last = 31 ; 
        vector<int>pref(32,0) ;
        for(int i = 0 ; i < M ; i ++){
            int val ; cin >> val ;
            if(val >= last) continue ;
            last = val ;
            pref[val] = (1LL << val) ;
        }
        for(int i = 1 ; i < 32 ; i ++) pref[i] += pref[i - 1] ;
        for(int i = 0 ; i < N ; i ++){
            int lastOne = log2(A[i] & -A[i]) + 1 ;
            A[i] += pref[lastOne - 1] ;
        }
        for(int i = 0 ; i < N ; i ++) cout << A[i] << " \n"[i + 1 == N] ;
	}
	return 0;
}