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

void spreaddisease(vector<vector<edge*>> &graph,int src,int &count,vector<int> &visited,int given_time){
   queue<pair<int,int>> sq;
   sq.push({src,1});
   while(sq.size()>0){
       auto t=sq.front();
       sq.pop();
       int curr_vertex=t.first;
       int curr_time=t.second;
       if(visited[curr_vertex]!=0){
           continue;
       }
       visited[curr_vertex]=curr_time;
       if(curr_time>given_time)
       break;
      // if(visited[curr_vertex]!=curr_time)
       count++;
       for(edge* ed:graph[curr_vertex]){
           if(visited[ed->nbr]==0)
           sq.push({ed->nbr,curr_time+1});
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
	  int src,given_time;
	  int count=0;
	    cin>>src>>given_time;
	    vector<int> visited(v,0);
	   spreaddisease(graph,src,count,visited,given_time);
	    cout<<count<<endl;
	return 0;
}
