#include <bits/stdc++.h>
using namespace std;
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

bool bipartite(vector<vector<edge*>> &graph,int src,vector<int> &visited,int level){
    queue<pair<pair<int,string>,int>> bipartitequeue;
    bipartitequeue.push({{src,to_string(src)},level});
    while(bipartitequeue.size()>0){
        auto t=bipartitequeue.front();
        bipartitequeue.pop();
        auto t_first=t.first;
        int val=t_first.first;
        int new_level=t.second;
        if(visited[val]!=-1){
            if(visited[val]!=new_level)
            return false;
        }
        else
        visited[val]=new_level;
        for(edge* ed:graph[val]){
            if(visited[ed->nbr]==-1)
            bipartitequeue.push({{ed->nbr,t_first.second+to_string(ed->nbr)},new_level+1});
        }
    }
    return true;
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
	vector<int> visited(v,-1);
	bool bipartitecomponent;
	for(int i=0;i<v;i++){
	    if(visited[i]==-1){
	    bipartitecomponent=bipartite(graph,i,visited,0);
	    if(bipartitecomponent==false){
	        cout<<"false"<<endl;
	        return 0;
	    }
	}
	}
	cout<<"true"<<endl;
	
	return 0;
}
