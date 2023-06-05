#include <stdio.h>
#include<stdbool.h>
#define CAPACITY 100

int graph[100][100];
int ourQueue[CAPACITY];
int front = 0, rear = -1, totalItem = 0;

bool isFull(){
    if(totalItem == CAPACITY){
        return true;
    }
    return false;
}
bool isEmpty(){
    if(totalItem == 0){
        return true;
    }
    return false;
}
void enqueue(int item){
    if(isFull()){
        printf("Sorry, the Queue is full.\n");
        return;
    }
    rear = (rear + 1) % CAPACITY;
    ourQueue[rear] = item;
    totalItem++;
}

int dequeue(){
    if(isEmpty()){
        printf("Sorry, the Queue is empty.\n");
        return -1;
    }
    int frontItem = ourQueue[front];
    ourQueue[front] = -1;
    front = (front + 1) % CAPACITY;
    totalItem--;
    return frontItem;
}

void bfs(int ver,int edge)
{
    int visit[100],v;
    printf("\nEnter the initial vertex to start the DFS traversal with: ");
    scanf("%d", &v);
    printf("\nThe DFS traversal on the given graph is : \n");
    printf("%d\t",v);

    for(int i=1;i<ver;i++)
    {
        for(int j=100;j>=0;j--)//
        {
            if(graph[v][j]==1&& visit[j]!=1)
            {
                visit[j]=1;
                enqueue(j);

            }
        }
        //v=q.front();
        v = dequeue();
        printf("%d\t",v);
    }
}
int main()
{
    int edg,ver,st,en;
    printf("Enter no of vertices:\n");
    scanf("%d",&ver);
    printf("Enter no of edges:");
    scanf("%d",&edg);
    for(int i=0; i<edg;i++)
    {
        printf("Enter the start and end vertex of the edges: \n");
        scanf("%d %d",&st,&en);
        graph[st][en]=1;
    }
    bfs(ver,edg);
}