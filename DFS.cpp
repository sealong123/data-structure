#include<iostream>
using namespace std;
typedef struct edgenode{
    int index;
    int val;
    edgenode *next;
}edgenode;
typedef struct vnode{
    int data;
    edgenode *head;
}vnode,vlist[10000];
void create(vlist list,int e){
    int i,num,val1,ind;
    for(i = 0;i < e;i++){
        scanf("%d%d%d",&num,&ind,&val1);
        edgenode *p = new edgenode;
        p->index = ind;
        p->val = val1;
        p->next = list[num].head->next;
        list[num].head->next =p;
    }
}
void BFS(vlist list,int *visit,int source){
    edgenode *p = list[source].head->next;
    while(p){
        if(!visit[p->index]){
            visit[p->index] = 1;
            printf("%d ",p->index);                     //should change.
            BFS(list,visit,p->index);
        }
        p = p->next;
    }
    return;
}
void totalDFS(vlist list,int *visit,int n){
    int i;
    for(i = 0;i < n;i++){
        if(!visit[i]){
            visit[i] = 1;
            printf("%d ",i);                                  //should change.
            BFS(list,visit,i);
        }
    }
}
int main(void){
    int n,e,i;
    int visit[10000] = {0};
    vlist list;
    scanf("%d%d",&n,&e);
    for(i = 0;i < n;i++){
        list[i].head = new edgenode;
        list[i].head->next = NULL;
        visit[i] = 0;
    }
    create(list,e);
    totalDFS(list,visit,n);
}