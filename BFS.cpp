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
	int i,num,ind,val1;
	for(i = 0;i < e;i++){
		scanf("%d%d%d",&num,&ind,&val1);
		edgenode *p = new edgenode;
		p->val = val1;
		p->index = ind;
		p->next = list[num].head->next;
		list[num].head->next = p;
	}
}
void BFS(vlist list,int *visit){
	vlist queue;
	vnode *p;
	edgenode *q;
	int head = -1,tail = -1;
	queue[++tail] = list[0];
	printf("0 ");                                     //改 
	while(head < tail){
		p = &queue[++head];                               //这里跟树的层次遍历需区分！！！定点表中的元素不是指针！！！ 
		q = p->head->next;
		while(q){
			if(visit[q->index] == 0){
				printf("%d ",q->index);                //改 
				visit[q->index] = 1;
				queue[++tail] = list[q->index];
			}
			q = q->next;
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
	}
	create(list,e);
	BFS(list,visit);
}
