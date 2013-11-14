#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstdlib>
#include <ctime>

using namespace std;

const int v = 50; // no of vertices

class Graph
{
    public:

        typedef pair<double , int> p;

        class comparePair
        {
            public:
                bool operator()(p x , p y)
                {
                    return x.first > y.first;
                }
        };

        vector< vector<p> > edge;
        priority_queue< p , vector<p> , comparePair > pq;

    public:

        Graph(int v)
        {
            edge.resize(v+1);
        }

        void addEdge(int i , int j , double w)
        {
            edge[i].push_back(p(w,j));
            edge[j].push_back(p(w,i));
        }

        double averageShortestPath(double arr[])
        {
            double sum =0.0;
            int k=0;
            for(int i=1 ; i<=v ; i++)
            {
                if(arr[i]!=INT_MAX)
                {
                    sum+=arr[i];
                    k++;
                }
            }

            return sum/k;
        }

        double dijkstra(int src)
        {
            double dist[v+1];

            for(int i=1 ; i<=v ; i++)
            {
                dist[i] = static_cast<double> (INT_MAX);
            }

            dist[src] = 0;

            pq.push(p(0 , src));

            while(!pq.empty())
            {
                p top = pq.top();
                pq.pop();
                double d = top.first;
                int u = top.second;

                if(dist[u] >= d)
                {
                    for(int i=0 ; i<edge[u].size() ; i++)
                    {
                        int v = edge[u][i].second;

                        if(dist[v] > d + edge[u][i].first)
                        {
                            dist[v] = d + edge[u][i].first;
                            pq.push(p(dist[v] , v));
                        }
                    }
                }
            }
            return averageShortestPath(dist);
        }


};
// function to find a random number between x and y
inline double getRandomNumber( double x , double y)
{
    return (y-x)*(static_cast<double>(rand())/ static_cast<double>(RAND_MAX)) + x;
}
int main()
{


    srand(time(NULL));

    double sum1 = 0 , sum2 = 0;

    for(int i=0 ; i<10000 ; i++)
    {
        Graph g1(v);
        Graph g2(v);

        for(int j=1 ; j<=v ; j++)
        {
            for(int k=j+1 ; k<=v ; k++)
            {
                if(getRandomNumber(0.0 ,1.0) <= .2)
                {
                    g1.addEdge(j , k , getRandomNumber(1.0, 10.0));
                }
                if(getRandomNumber(0.0 ,1.0) <= .4)
                {
                    g2.addEdge(j , k , getRandomNumber(1.0, 10.0));
                }
            }
        }

        sum1+=g1.dijkstra(1);
        sum2+=g2.dijkstra(1);

    }
    cout<<sum1/10000<<"\n"<<sum2/10000<<endl;
    return 0;
}
