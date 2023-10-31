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
        string s ; cin >> s ;
        int l = 0 , r = N - 1 ;
        vector<int>ans ;
        bool bad = 0 ;
        auto notValid = [&](int l,int r)->bool{
            int cnt = 0 ;
            for(int i = l ; i <= r ; i ++) cnt += (s[i] == '1') ;
            return (cnt == 0 or cnt == (r - l + 1)) ;
        };
        while(l <= r){
            if(s[l] != s[r]) l ++ , r -- ;
            else{
                if(notValid(l,r)){
                    bad = 1 ;
                    break ;
                }else if(s[l] == '1'){
                    s = (l == 0 ? "" : s.substr(0,l)) + "01" + s.substr(l) ;
                    ans.pb(l - 1) ;
                    l -- ;
                    r -- ;
                }else{
                    s = s.substr(0, r + 1) + "01" + (r == s.size() - 1 ? "" : s.substr(r));
                    ans.pb(r);
                    l++;
                    r++;
                }
            }
        }
        if(bad) cout << -1 << endl ;
        else{
            cout << ans.size() << endl ;
            for(int i : ans) 
                    cout << i + 1 << " " ;
            cout << endl ;
        }
    }
	return 0 ;
}