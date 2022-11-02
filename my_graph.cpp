/*
   Graph(const vector<int> &start, const vector<int> &end)

   Requires: 2 vectors of equal sizes of type int.
   Effects: It maps every element in vector start at index i to end[i]. It builds the road start[i] -> end[i].
            An element in start vector may be mapping to more than one element in vector end.

   Testing Strategy: 1) Passing two empty vectors
                     2) Passing two vectors such that each element in start maps to one element in end.
                     3) Passing two vectors such that all all elements in start are equal, in other meaning only one starting point
                        and many destinations.
                     4) Passing two vectors such two or more starting points map to the same single or multiple destinations.
                     5) Passing two vectors such that all starting points map to one end point.

   ***********************************************************************************************************

   int numOutgoing(const int nodeID)

   Requires: Nothing
   Effects: Returns the number of destinations a node is mapping to.

   Testing Strategy: 1) nodeID was not initially present in the start vector.
                     2) Node maps to 0 destinations
                     3) Node maps to odd size of destinations
                     4) Node maps to even size of destinations

   ***********************************************************************************************************
   const vector<int> & adjacent(const int nodeID)
   
   Requires: Nothing
   Effects: Returns a reference to a vector containing the destinations of a given id to some starting point.

   Testing Strategy: 1) nodeID was not initially present in the start vector.
                     2) Node maps to 0 destinations
                     3) Node maps to odd size of destinations
                     4) Node maps to even size of destinations

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Graph 
{
    private :
    std :: map<int, vector<int>> Edges;

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
};

int main()
{
   std :: vector <int> starts = {0,0,0,4,4,3};
   std :: vector <int> ends = {1,2,3,3,1,1};

   Graph my_graph (starts, ends);
   cout << "The number of edges with node 0 as starting point: ";
   cout << my_graph.numOutgoing(0) <<endl;

   vector <int> testing = my_graph.adjacent(0);
   cout<< "Node 0 maps to: ";
   for(int i=0; i<testing.size();i++)
      cout<< testing.at(i) << " ";
}