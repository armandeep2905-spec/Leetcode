#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
vector<int> rank , parent , size;
public:
   DisjointSet(int n){
    rank.resize(n+1 , 0);
    size.resize(n+1 , 1);
    parent.resize(n+1);
    for(int i = 0 ; i <= n ; i++){
        parent[i] = i ;
    }

   }

   int find_Ult_Parent(int node){
            if(node == parent[node]) 
              return node;
            return parent[node] = find_Ult_Parent(parent[node]); //path compression
   }

   void union_by_rank(int u , int v){
    int ult_u = find_Ult_Parent(u);
    int ult_v = find_Ult_Parent(v);

    if(ult_u == ult_v) return ;
    if(rank[ult_u] < rank[ult_v]) {
        parent[ult_u] = ult_v;
    }
    else if(rank[ult_u] > rank[ult_v]) {
        parent[ult_v] = ult_u;
    }
    else {
        // both have same ranks , so we can join anyway and rank of the parent will increase
        parent[ult_v] = ult_u;
        rank[ult_u]++;
    }
   }


   void union_by_size(int u , int v){
    int ult_u = find_Ult_Parent(u);
    int ult_v = find_Ult_Parent(v);
    if(ult_u == ult_v) return ; // already connected
    if(size[ult_u] < size[ult_v]) {
        parent[ult_u] = ult_v;
        size[ult_v] +=size[ult_u];
    }
    else if(size[ult_u] > size[ult_v]){
        parent[ult_v] = ult_u;
        size[ult_u] += size[ult_v];

    }
    else {
        parent[ult_v] = ult_u;
        size[ult_u] += size[ult_v];
    }

   }
};


int main(){
   DisjointSet ds(7);
   //enter the edges
   ds.union_by_rank(1,2);
   ds.union_by_rank(2,3);
   ds.union_by_rank(4,5);
   ds.union_by_rank(6,7);
   ds.union_by_rank(5,6);
   // check if 3 and 7 belong to the same component or not 
   if(ds.find_Ult_Parent(3) == ds.find_Ult_Parent(7)) cout<<"same";
   else cout<<"not same\n";
   ds.union_by_rank(3,7);
   // checking again after adding edge
   if(ds.find_Ult_Parent(3) == ds.find_Ult_Parent(7)) cout<<"same";
   else cout<<"not same";


}