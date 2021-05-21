#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
     int data;
     Node *next;

}*front=NULL,*rear=NULL;
void enqueue(int x)
{
 Node *t;
 t=new Node;
 if(t==NULL)
 cout<<"Queue is FUll\n";
 else
 {
 t->data=x;
 t->next=NULL;
 if(front==NULL)
 front=rear=t;
 else
 {
 rear->next=t;
 rear=t;
 }
 }

}
int dequeue()
{
 int x=-1;
 Node* t;

 if(front==NULL)
 cout<<"Queue is Empty\n";
 else
 {
 x=front->data;
 t=front;
 front=front->next;
 delete(t);
 }
 return x;
}
int Empty()
{
 return front==NULL;
}

void BFS(int G[][7],int i,int n){
    int visited[7]={0};
    cout<<i;
    visited[i]=1;
    enqueue(i);
    while(!Empty()){
        i=dequeue();
        for(int j=1;j<n;j++){
            if(G[i][j]==1 && visited[j]==0){
                enqueue(j);
                cout<<j;
                visited[j]=1;
            }
        }
    }
}

int main(){
    int G[7][7]={{0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,1,0,0,1,0,0},
    {0,1,0,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}};
    BFS(G,4,7);
    return 0;
}