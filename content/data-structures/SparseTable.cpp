/**
 * Author: Me
 * Date: 2025-09-07
 * License: N/A
 * Source: folklore
 * Description: Sparse Table, bounds inclusive to left and right, (overlap queries only)
 * Time: O(1) / O(N\log n)
 * Status: stress-tested
 */
#pragma once
template<class T>
struct SparseTable {
    vector<vector<T>>t;
    int K;
    SparseTable(const vector<T>&a){
        K = 31 - __builtin_clz(sz(a));
        t.resize(K+1, vector<T>(sz(a)));
        for(int i=0;i<sz(a);i++)t[0][i]=a[i];
        for(int k=1;k<=K;k++){
            for(int i=0;i+(1<<k)-1<sz(a);i++){
                t[k][i]=merge(t[k-1][i],t[k-1][i+(1<<(k-1))]);
            }
        }
    }
    T merge(T x, T y){
        return max(x,y);
    }
    T query(int l,int r){
        int k=31-__builtin_clz(r-l+1);
        return merge(t[k][l],t[k][r-(1<<k)+1]);
    }
};
