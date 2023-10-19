/*
Description : sparce table : https://github.com/AliHossamTesla/CP-Training/tree/main/Data%20Structure/Spares%20Table
by : @tourist
verification : https://codeforces.com/contest/1548/problem/B
*/
template <typename T, class F = function<T(const T &, const T &)>>
class SparseTable{
public:
    int n;
    vector<vector<T>> mat;
    F func;
    SparseTable(const vector<T> &a, const F &f) : func(f){
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++){
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++){
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T Query(int L, int R) const{
        assert(0 <= L && L <= R && R <= n - 1);
        int lg = 32 - __builtin_clz(R - L + 1) - 1;
        return func(mat[lg][L], mat[lg][R - (1 << lg) + 1]);
    }
};