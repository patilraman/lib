#include <iostream>
#include <vector>
//#include <bits/stdc++.h>

#define NOEDGES  -1
#define DEFAULT_WEIGHT 1
#define TEST 1
#define INFINITE -1
using namespace std;

//create_Adj-list

void insertNodeDirectedGraph(vector<vector<int>> &vec, int U, int V, int weight)
{
    vec[U][V] = weight;
}

void insertNodeUnDirectedGraph(vector<vector<int>> &vec, int U, int V, int weight)
{
    vec[U][V] = weight;
    vec[V][U] = weight;
}
void initGraph(int V, int E){
    vector<vector<int>> vec(V,vector<int>(V,NOEDGES));
}
enum class STATE{
    WHITE,
    GRAY,
    BLACK
};

typedef struct {
    int vid;
    STATE color;
    int distance;
    int parent;
}vertex;


void Print_Path(vector<vector<int>> &v, int s, int v)
{
    if (v == s)
    {
        cout<<"->"<<v<<'\n';
    }
    else
    if()
}


void BFS(vector<vector<int>> &v)
{
    int rows = v.size();
    int col = v[0].size();

    for(int i=0;i<rows;i++)
    {
        for(auto &a:v[i])
            cout<<a<<" ";
        cout<<'\n';
    }
    cout<<'\n'<<'\n';

    vector<vertex> Vert(rows,{0,STATE::WHITE,INFINITE,0});//Array to store initialized vertexes
    int i=0;
    for(auto &vtmp: Vert)
        vtmp.vid = i++;

    Vert[0].color = STATE::GRAY;
    Vert[0].distance = 0;
    Vert[0].parent = 0;

    vector<vertex> Q(1,Vert[0]); //queue of vextexes to traverse
    cout<<1<<'\n';
    while(!Q.empty())
    {
        vertex u=Q.front();
        Q.erase(Q.begin());
        //cout<<u.vid+1<<'\n';
        for(int j=0;j<col;j++)
        {
            if(v[u.vid][j])//if edge exists
            {
                if(Vert[j].color == STATE::WHITE)//if not already traversed
                {
                    Vert[j].color = STATE::GRAY;
                    Vert[j].distance = u.distance + 1;
                    Vert[j].parent = u.vid;
                    cout <<j+1<<" ";
                    Q.push_back(Vert[j]);
                }
            }
        }
        cout<<'\n';
        u.color = STATE::BLACK;
    }

    cout<<"distances to each vertex"<<'\n';
    i=0;
    for(auto &v: Vert)
        cout<<"shortest distance to #"<<Vert[i].vid+1<<" dist:"<<Vert[i++].distance<<'\n';
}


int main()
{
    ios::sync_with_stdio(0);
  #if TEST
    vector<vector<int>> v = {
                                {0,1,0,0,1},
                                {1,0,1,1,1},
                                {0,1,0,1,0},
                                {0,1,1,0,1},
                                {1,1,0,1,0}
                            };
  #endif
    vector<int> vec;
    
    BFS(v);
    
    return 0;
}