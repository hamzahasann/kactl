/**
 * Author: Lukas Polacek
 * Date: 2009-10-26
 * License: CC0
 * Source: folklore
 * Description: Disjoint-set data structure.
 * Time: $O(\alpha(N))$
 */
#pragma once

struct DSU{
    vector<int> P,S;
    DSU(int n){
        P.resize(n+1);S.resize(n+1,1);
        rep(i,1,n+1)P[i]=i;
    }int find(int u){
        if(u==P[u])return u;
        return P[u]=find(P[u]);
    }int merge(int u,int v){
        u=find(u);v=find(v);
        if(u==v)return 0;
        if(S[u]>S[v])swap(u,v);
        P[u]=v;
        S[v]+=S[u];
        return 1;
    }
};

