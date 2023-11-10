/**
 * Author: Lucian Bicsi
 * Date: 2017-10-31
 * License: CC0
 * Source: folklore
 * Description: 1-indexed seg-tree. Bounds are inclusive to the left and right. 
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

template<class T>
struct segTree{
    int n;vector<T>t;T init;
    segTree(int _n,T _init){
        n=_n;t.resize(2*n);init=_init;for(auto &tt:t)tt=init;
    }void update(int i,T k){
        i+=n;t[i]=k;
        while(i>1){i>>=1;t[i]=merge(t[i<<1],t[(i<<1)|1]);}
    }T query(int l,int r){
        l+=n;r+=n;T res=init;
        while(l<r){
            if(l&1){res=merge(res,t[l]);l++;}
            if(!(r&1)){res=merge(res,t[r]);r--;}
            l>>=1;r>>=1;
        }if(l==r)res=merge(res,t[l]);
        return res;
    }T merge(T a,T b){
        T res;
        // merge here
        return res;
    }
};

