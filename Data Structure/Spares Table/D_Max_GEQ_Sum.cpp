/*
 *أَحَسِبَ النَّاسُ أَن يُتْرَكُوا أَن يَقُولُوا آمَنَّا وَهُمْ لَا يُفْتَنُونَ ۝ وَلَقَدْ فَتَنَّا الَّذِينَ مِن قَبْلِهِمْ فَلَيَعْلَمَنَّ اللَّهُ الَّذِينَ صَدَقُوا وَلَيَعْلَمَنَّ الْكَاذِبِينَ ۝
 *by : @Tesla .
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define rall(n) n.rbegin(), n.rend()
#define all(n) n.begin(), n.end()
const int MOD = 1e9 + 7;
template <typename T, class F = function<T(const T &, const T &)>>
class SparseTable
{
public:
    int n;
    vector<vector<T>> mat;
    F func;
    SparseTable(const vector<T> &a, const F &f) : func(f)
    {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++)
        {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++)
            {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T Query(int L, int R) const
    {
        assert(0 <= L && L <= R && R <= n - 1);
        int lg = 32 - __builtin_clz(R - L + 1) - 1;
        return func(mat[lg][L], mat[lg][R - (1 << lg) + 1]);
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        vector<int> pref(N + 1, 0), A(N + 1, 0), nxtLarge(N + 1, N), prevLarge(N + 1, 0);
        stack<int> st;
        for (int i = 1; i <= N; i++)
        {
            cin >> A[i];
            pref[i] = pref[i - 1] + A[i];
            while (!st.empty() and A[st.top()] <= A[i])
            {
                nxtLarge[st.top()] = i - 1;
                st.pop();
            }
            if (!st.empty())
                prevLarge[i] = st.top();
            st.push(i);
        }
        SparseTable<int> prefMN(pref, [&](int i, int j)
                                { return min(i, j); });
        SparseTable<int> prefMX(pref, [&](int i, int j)
                                { return max(i, j); });
        bool ok = 1;
        for (int i = 1; i <= N and ok; i++)
            ok &= (A[i] >= prefMX.Query(i, nxtLarge[i]) - prefMN.Query(prevLarge[i], i - 1));
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
