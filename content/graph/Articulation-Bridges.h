/**
 * Author: CP-Algorithms(fixed)
 * Date: 2022-08-12
 * License: CC0
 * Source: cpalgorithms
 * Description: finds all articulation points and bridges
 * Time: O(V+E)
 * Usage: init(n, 1);
 * Status: tested
 */

#pragma once

vector<int> tn, lw;
vector<vector<pii>>adj;
int tr;
void dfs(int v, int p = -1) {
    tn[v] = lw[v] = ++tr;
    int ch=0;
    for (auto [to, id] : adj[v]) {
        if (id == p) continue;
        if (tn[to]) {
            lw[v] = min(lw[v], tn[to]);
        } else {
            dfs(to, id);
            lw[v] = min(lw[v], lw[to]);
            ++ch;
            if (lw[to] >= tn[v] && p!=-1){
                // v is articulation point
            }
            if (lw[to] > tn[v]){
                // v, to is bridge
            }
        }
    }
    if(p == -1 && ch > 1){
        // v is articulation point
    }
}

void init(int n, int start = 1) {
    tr = 0;
    tn.resize(start+n);
    lw.resize(start+n);
    for (int i = start; i < start+n; ++i) {
        if (!tn[i])
            dfs(i);
    }
}