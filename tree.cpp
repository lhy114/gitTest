#include<iostream>
#define lc id<<1
#define rc id<<1|1
typedef long long ll;
using namespace std;
const int N = 1e5+10;

ll a[N];

struct node{
    int l,r;
    ll lazy,val;
}tr[N<<2];

void pushdown(int id){
    //将节点id的lazy标签传递给孩子节点
    tr[lc].lazy += tr[id].lazy;
    tr[rc].lazy += tr[id].lazy;
    tr[lc].val += 1ll*tr[id].lazy*(tr[lc].r-tr[lc].l+1);
    tr[rc].val += 1ll*tr[id].lazy*(tr[rc].r-tr[rc].l+1);
    tr[id].lazy = 0;
}

void pushup(int id){
    tr[id].val = tr[lc].val+tr[rc].val;
}

void build(int id,int l,int r){
    tr[id] = {l,r,0,0};
    if(l==r){
        tr[id].val = a[l];
        return;
    }
    int mid = (l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(id);
}

ll query(int id,int L,int R){
    //查询[L,R]区间的值
    int l = tr[id].l, r = tr[id].r;
    if(l>R||r<L) return 0;
    if(l>=L&&r<=R) return tr[id].val;
    
    //查询
    pushdown(id);
    return query(lc,L,R)+query(rc,L,R);
}

void update(int id,int add,int L,int R){
    int l = tr[id].l, r = tr[id].r;
    if(l>R||r<L) return;
    if(l>=L&&r<=R){
        tr[id].lazy += add;
        tr[id].val += 1ll*(r-l+1)*add;
        return;
    }

    pushdown(id);
    update(lc,add,L,R);
    update(rc,add,L,R);
    pushup(id);
}

int main(){
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    while(t--){
        int op,l,r,k;
        cin>>op;
        if(op==1){
            cin>>l>>k;
            update(1,k,l,l);
        }else if(op==2){
            cin>>l>>r;
            cout<<query(1,l,r)<<endl;
        }
    }
    return 0;
}