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
        int N ; cin >> N ;
        map<int,int>mp ;
        for(int i = 0; i < N; i++){
            int val  ; cin >> val ;
            mp[val] ++ ;
        }
        if(mp.size() == 1){
            cout << "Yes\n" ;
            continue; 
        }
        if(mp.size() >= 3){
            cout << "No\n";
            continue;
        }
        auto it = mp.begin() ; 
        auto it2 = next(it) ;
        if (N & 1 and abs(it->second - it2->second) == 1) cout << "Yes\n" ;
        else if (abs(it->second - it2->second) == 0) cout << "Yes\n";
        else cout << "No\n";
    }
	return 0 ;
}