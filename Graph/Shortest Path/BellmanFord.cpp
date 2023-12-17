/*
 * Description : Bellman - ford Algorithm
 * Shortest Path w/ negative edge weights + find Negative Cycle if exist .
 * source : @Tesla
 * Verification :
 * 1 - https://cses.fi/problemset/task/1197/
 * 2 - https://open.kattis.com/problems/shortestpath3
 */
struct BellmanFord{
	struct Edge{
		int u , v , w ;
		Edge(){}
		Edge(int a,int b,int c):u(a),v(b),w(c){}
	};
	int N ;
	vector<vector<int>>adj;
	vector<Edge>edges ;
	vector<int>dis,negCycle,p;
	BellmanFord(int N):adj(N + 1),N(N){}
	void add(int u,int v,int w){
		// add new edge
		adj[u].pb(v) ;
		edges.pb(Edge(u,v,w)) ;
	}
	void run(int s){
		p = vector<int>(N + 1, -1);
		dis = vector<int>(N + 1,INF) ;
		// set source = 0 ;
		dis[s] = 0;
		for (int i = 0; i < N; ++i) {
			for (Edge e : edges)
				if (dis[e.u] < INF)
					if (chkmin(dis[e.v],dis[e.u] + e.w))  p[e.v] = e.u;
		}
		// set every negative path to -INF .
		for (Edge e : edges)
			if (dis[e.u] < INF and dis[e.v] > dis[e.u] + e.w)
				genBad(e.v) ;
	}
	void genBad(int u){
		// if x is reachable from negative cycle
		// -> update dists of all vertices which x can go to
		if (dis[u] == -INF) return;
		dis[u] = -INF;
		for(auto v : adj[u]) genBad(v);
	}
	bool searchNegCycle(){
		// find if there is negative cycle :-
		dis = vector<int>(N + 1,0) ;
		p = vector<int>(N + 1, -1);
		int u = -1 ;
		for(int i = 0 ; i < N ; i ++){
			u = -1 ;
			for (Edge e : edges)
				if(chkmin(dis[e.v],dis[e.u] + e.w)) p[e.v] = e.u , u = e.v ;
			if(u == -1) return 0 ;
		}
		// create negative cycle path
		for(int i = 0 ; i < N ; i ++) u = p[u] ;
		negCycle.push_back(u) ;
		while(p[negCycle.back()] != u)
			negCycle.pb(p[negCycle.back()]) ;
		negCycle.push_back(u) ;
		reverse(negCycle.begin(), negCycle.end());
		return 1 ;
	}
};