#include<iostream>
#define MaxSize 100
using namespace std;

typedef int ElemType;
typedef struct List
{
    ElemType data[MaxSize];
    int length;
}SqList;

void InitSqList(SqList &L){
    L.length = 0;
}

int GetLength(SqList L){
    return L.length;
}

int LocateElem(SqList L,ElemType e){
    int pos = -1;
    for(int i=0;i<L.length;i++){
        if(L.data[i]==e){
            pos = i;
            break;
        }
    }
    return pos;//pos:-1 没有找到
}

bool GetElem(SqList L,int i,ElemType&e){
    if(i<0||i>=L.length){
        return false;
    }
    e = L.data[i-1];
    return true;
}

bool ListInsert(SqList &L,int i,ElemType e){
    if(i<0||i>L.length)//[0,...,length]的范围
        return false;
    for(int j=L.length;j>=i;j--){
        L.data[j] = L.data[j-1];
    }   
    L.data[i-1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L,int i,ElemType &e){
    if(i<0||i>=L.length){
        return false;
    }

    for(int j=i-1;j<L.length-1;j++){
        L.data[j] = L.data[j+1];
    }   
    L.length--;
    return true;
}

void PrintList(SqList L){
    for(int i=0;i<L.length;i++){
        cout<<L.data[i]<<" ";
    }
    cout<<endl;
}

bool Empty(SqList L){
    if(L.length==0){
        return true;
    }else{
        return false;
    }
}

bool DestroyList(SqList &L){
    free(L.data);
    L.length = 0;
}

int main(){
    SqList L;
    InitSqList(L);
    /**
     * 操作。。。。。
     * 。。。。。。。
     */
    return 0;
}