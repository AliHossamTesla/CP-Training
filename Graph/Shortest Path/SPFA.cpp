/*
 * Description : SPFA to find the shortest path (improvement of Bellman - Ford Algorithm)
 * and can detect negative cycle .
 * source : @Tesla.
 * Verification : https://open.kattis.com/problems/shortestpath3
 */
#define x first
#define y second
using pi = pair<int,int> ;
vector<vector<pi>>adj ;
vector<bool>inNegCycle ;
bool spfa(int s,vector<int>& dis){
	int N = dis.size() ;
	dis.assign(N + 1,INF) ;
	inNegCycle.assign(N + 1,0) ;
	vector<int>cnt(N + 1,0) ;
	vector<bool>inQ(N + 1,0) ;
	queue<int>Q ;
	Q.push(s) ;
	dis[s] = 0 ;
	inQ[s] = 1 ;
	while(!Q.empty()){
		int u = Q.front() ;Q.pop() ;
		inQ[u] = 0 ;
		for(auto [v,w] : adj[u]){
			if(chkmin(dis[v],dis[u] + w) and !inQ[v]){
				Q.push(v) ;
				inQ[v] = 1 ;
				cnt[v] ++ ;
				if(cnt[v] > N){ // negative cycle
					while(!Q.empty()){
						int u = Q.front() ;Q.pop() ;
						if(inNegCycle[u]) continue;
						inNegCycle[u] = 1 ;
						for(auto [v,w] : adj[u]){
							Q.push(v) ;
						}
					}
					return 0 ;
				}
			}
		}
	}
	return 1 ;
}