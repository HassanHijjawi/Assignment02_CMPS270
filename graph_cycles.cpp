/*
    bool isCyclic()
    
    Requires: Nothing
    Effects: Prints 1 if a cycle is found, else it prints nothing.

    Testing Strategy : 1) An empty graph.
                       2) Graph containing a cycle like std :: vector <int> starts = {0,1,2,3,4,3}
                                                        std :: vector <int> ends = {1,2,3,0,1,1}         --> The cycle is: 0 -> 1 -> 2 -> 3 -> 0.
                       3) Graph containing no cycles, nothing should be printed.


*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph 
{
    private :
    std :: map<int, vector<int>> Edges;
    std :: map<int, bool> visited;

    public :
      Graph(const vector<int> &start, const vector<int> &end)
     {
        if(start.size()!=end.size())
            throw invalid_argument("Different Vector sizes.\n");
        int i=0;
        std :: vector <int> destinations;

        for(i; i<start.size();i++)
        {
            if(Edges.count(i) == 0)
            {
               
               for (int j=0;j<start.size();j++)
               {
                  if(start[j]==start[i])
                  {
                     destinations.push_back(end.at(j));
                  }
               }
               Edges.insert({i,destinations});
               destinations.clear();
            }
        }
     }

     int numOutgoing(const int nodeID)
     {
         if(Edges.count(nodeID)>0)
         {
            vector<int> copy = Edges.at(nodeID);
            return copy.size();
         }
         cout<< "Invalid Vertix"<<endl ;
         return 0;
         
     }

     const vector<int> & adjacent(const int nodeID)
     {
         if(Edges.count(nodeID)>0)
         {
            std :: vector <int> & copy = Edges.at(nodeID);
            return copy;
         }
          
          else{
               cout << "Invalid Vertex";

          }
          
     }

    bool isCyclic()
    {
        bool isCycle = false;
        
        for ( auto &vertex : Edges ) {
            visited.insert({vertex.first, true});

            for ( auto &vertex2 : vertex.second )
            {
                if(Edges.count(vertex2))
                {
                   isCycle = isCyclic_helper(vertex2);
                }
                if(isCycle)
                {
                    return isCycle;
                }
            }
            visited.insert({vertex.first, false});
        }
        return isCycle;
    }

    bool isCyclic_helper(int nodeID)
    {
        bool found = false;
        
        visited.insert({nodeID, true});
        if(Edges.count(nodeID) == 0)
        {
            return false;
        }
        
        for( auto &vertex: Edges[nodeID] )
        {
            if(visited[vertex] == true)
            {
                return true;
            }
            
            found = found || isCyclic_helper(vertex);
            
        }
        visited.insert({nodeID, false});
        return found;
    }
};

int main()
{
   std :: vector <int> starts = {0,1,2,3,4,3};
   std :: vector <int> ends = {1,2,3,0,1,1};

   Graph my_graph (starts, ends);
//    cout << "The number of edges with node 0 as starting point: ";
//    cout << my_graph.numOutgoing(0) <<endl;

//    vector <int> testing = my_graph.adjacent(0);
//    cout<< "Node 0 maps to: ";
//    for(int i=0; i<testing.size();i++)
//       cout<< testing.at(i) << " ";

    cout << my_graph.isCyclic();
   
}