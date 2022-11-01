#include <iostream>
#include <vector>
#include <map>
using namespace std;

template <typename T>
class Graph 
{
    private :
    std :: map<int, vector<int>> Edges;

    public :
     Graph::Graph(const vector<int> &start, const vector<int> &end)
     {
        int i=0;
        std :: vector <int> destinations;

        for(i; i<start.size();i++)
        {
            if(Edges.count(i) == 0)
            {
               
               for (int j=0;j<start.size();j++)
               {
                  if(j==i)
                  {
                     destinations.push_back(j);
                  }
               }
               Edges.insert(i,destinations);
               destinations.clear();
            }
        }
     }

     int numOutgoing(const int nodeID)
     {
         std :: vector<int> copy = Edges.at(nodeID);
         return copy.size();
     }

     const vector<int> & adjacent(const int nodeID)
     {
         std :: vector <int> & copy = Edges.at(nodeID);
         return copy;
     }
}