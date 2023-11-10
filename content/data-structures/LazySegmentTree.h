/**
 * Author: Simon Lindholm
 * Date: 2016-10-08
 * License: CC0
 * Source: me
 * Description: Segment tree with ability to add or set values of large intervals, and compute range sum of intervals.
 * Can be changed to other things.
 * Time: O(\log N).
 * Status: stress-tested a bit
 */
#pragma once

const int N=1000;
const int L=1024;
vector<int>tree(2*L);
vector<int>lazy(2*L);
void update(int l,int r,int k,int u=1,int ul=1,int ur=N){
    tree[u]+=lazy[u]*(ur-ul+1);
    if(ul!=ur){
        lazy[u<<1]+=lazy[u];
        lazy[(u<<1)|1]+=lazy[u];
    }lazy[u]=0;
    if(ur<l || r<ul)return;
    if(l<=ul && r>=ur){
        tree[u]+=k*(ur-ul+1);
        if(ul!=ur){
            lazy[u<<1]+=k;
            lazy[(u<<1)|1]+=k;
        }return;
    }
    int mid=(ul+ur)/2;
    update(l,r,k,u<<1,ul,mid);
    update(l,r,k,(u<<1)|1,mid+1,ur);
    tree[u]=tree[u<<1]+tree[(u<<1)|1];
}
int query(int l,int r,int u=1,int ul=1,int ur=N){
    tree[u]+=lazy[u]*(ur-ul+1);
    if(ul!=ur){
        lazy[u<<1]+=lazy[u];
        lazy[(u<<1)|1]+=lazy[u];
    }lazy[u]=0;
    if(ur<l || r<ul)return 0;
    if(l<=ul && r>=ur){
        return tree[u];
    }int mid=(ul+ur)/2;
    return query(l,r,u<<1,ul,mid)+query(l,r,(u<<1)|1,mid+1,ur);
}
