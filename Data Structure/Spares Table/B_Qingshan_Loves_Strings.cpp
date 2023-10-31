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
        int N , M ; cin >> N >> M ;
        string s , t ; cin >> s >> t ;
        int ok = 1 ,bad = 1 ;
        for(int i = 1 ; i < M  ; i ++) if(t[i] == t[i - 1]) ok = 0 ;
        if(t[0] != t.back()) ok = 0 ;
        for(int i = 1 ; i < N ; i ++){
            if(s[i] == s[i - 1]){
                if(ok and s[i - 1] != t[0]) ;
                else{
                    bad = 0;
                    break ;
                }
            }
        }
        cout << (bad ? "Yes\n" : "No\n") ; 
    }
	return 0 ;
}