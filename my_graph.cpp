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
                  if(start[j]==i)
                  {
                     destinations.push_back(j);
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
   //cout << my_graph.numOutgoing(9);

   vector <int> testing = my_graph.adjacent(0);
   cout<< testing.size();
}