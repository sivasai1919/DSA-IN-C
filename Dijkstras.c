#include<stdio.h>
#include<stdbool.h>
#define INF 9999
int cost[50][50];
int min(int dist[],int v,bool visited[]){
        int min = INF;
        int min_index = -1;
        for(int i=0;i<v;i++){
            if(!visited[i] && dist[i]<min){
                min = dist[i];
                min_index = i;
            }
        }
        return min_index;
    }
    
   
void Dijkstras(int v,int s) {
    
    int dist[v];
    bool visited[v] ;
    
    for(int i=0;i<v;i++){
        dist[i] = cost[s][i];
        
    }
    visited[s] = true;
    
    
    int k,w;
    for(k=0;k<v;k++){
        int u = min(dist,v,visited);
        visited[u] = true;
        for(w=0;w<v;w++){
            if(!visited[w] && dist[u]+cost[u][w] < dist[w]){
                dist[w] = dist[u]+cost[u][w];
            }
        }
    }
    for(int i=0;i<v;i++){
        if(dist[i] == INF ){
            printf("INF");
           }
           else {
               printf("%2d",dist[i]);
           }
           }
        }
    

int main(){
    int v;
    printf("enter no of vertices");
    scanf("%d",&v);
    int s;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            scanf("%d,%d",&cost[i][j]);
        }
    }
    printf("Enter the source vertex");
    scanf("%d",&s);
    Dijkstras(v,s);
    
    }
