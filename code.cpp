// Kruskal's algorithm 
#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int> graph[],int V,stack<int> &st,int s,vector<bool> &vis)
{
    vis[s] = true;
    for(int i:graph[s])
    {
        if(vis[i] == false)
        {
            DFS(graph,V,st,i,vis);
        }
    }
    //cout<<s<<" ";
    st.push(s);
}
void DFS(vector<int> graph1[],int V,int s,vector<bool> &visited)
{
    visited[s] = true;
    for(int i : graph1[s])
    {
        if(visited[i]  == false)
        {
            DFS(graph1,V,i,visited);
        }
    }
}
int main()
{
    vector<int> graph[5];
    int a,b;
    while(cin>>a>>b)
    {
        graph[a].push_back(b);
    }
    stack<int> st;
    vector<bool> vis(5,false);
    // apply the DFS on the graph and store in the stack the vectex which has no unvisited neighbore
    // store the vertices on the basis of their finish time
    DFS(graph,5,st,0,vis);
    vector<int> graph1[5];
    // reverse the edges in the graph
    for(int i=0;i<5;i++)
    {
        for(int j:graph[i])
        {
            graph1[j].push_back(i);
        }
    }
    int c=0;
    // pop one by one vertices from the stack and then apply DFS again 
    vector<bool> visited(5,false);
    while(st.empty() == false)
    {
        int i = st.top();
        st.pop();
        
        if(visited[i] == false)
        {
            c++;
            DFS(graph1,5,i,visited);
        }
    }
    cout<<c;
}
