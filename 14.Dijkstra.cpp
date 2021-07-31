#include <bits/stdc++.h>
using namespace std;
typedef pair<int,pair<int,string>> ppi;
struct edge{
    int nde;
    int nbr;
    int wt;
    edge(int nde,int nbr,int wt){
        this->nde=nde;
        this->nbr=nbr;
        this->wt=wt;
    }
};

void dijkstra(vector<vector<edge*>> &graph,int src,vector<bool> &visited){
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    pq.push({0,{src,to_string(src)}});
    while(pq.size()>0){
        auto t=pq.top();
        pq.pop();
        int curr_vertex=t.second.first;
        string psf=t.second.second;
        int shortestpath=t.first;
        if(visited[curr_vertex]==true)
        continue;
        visited[curr_vertex]=true;
        cout<<curr_vertex<<"via"<<psf<<"@"<<shortestpath<<endl;
        for(edge* ed:graph[curr_vertex]){
            if(visited[ed->nbr]==false){
                pq.push({shortestpath+ed->wt,{ed->nbr,psf+to_string(ed->nbr)}});
            }
        }
        
        
    }
}
int main() {
	// your code goes here
	int v,e;
	cin>>v>>e;
	vector<vector<edge*>> graph(v,vector<edge*>());
	for(int i=0;i<e;i++){
	    int v1,v2,wt;
	    cin>>v1>>v2>>wt;
	    edge* e1=new edge(v1,v2,wt);
	    edge* e2=new edge(v2,v1,wt);
	    graph[v1].push_back(e1);
	    graph[v2].push_back(e2);
	  
	}	 
	int src;
	cin>>src;
	  vector<bool> visited(v,false);
	  dijkstra(graph,src,visited);
	return 0;
}

