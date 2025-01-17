/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <cstddef>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <climits>
#include <unordered_set>
#include <utility>

using namespace std;

template <class T>
struct Connection {
    T source;
    T destination;
    string airline;
};


template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;


/****************** Provided structures  ********************/

template <class T>
class Vertex {
    T info;                // contents
    vector<Edge<T> > adj;  // list of outgoing edges
    bool visited;          // auxiliary field
    bool processing;       // auxiliary field
    int indegree;          // auxiliary field
    int num;               // auxiliary field
    int low;               // auxiliary field
    bool stacked;
    Vertex<T> *pred;

    void addEdge(Vertex<T> *dest, double w, string airl);
    bool removeEdgeTo(Vertex<T> *d);
public:
    Vertex(T in);
    T getInfo() const;
    void setInfo(T in);
    bool isVisited() const;
    void setVisited(bool v);
    bool isProcessing() const;
    void setProcessing(bool p);
    const vector<Edge<T>> &getAdj() const;
    void setAdj(const vector<Edge<T>> &adj);

    int getIndegree() const;

    void setIndegree(int indegree);
    void addIndegree();

    int getNum() const;

    void setNum(int num);

    int getLow() const;

    void setLow(int low);

    bool getStacked() const;

    void setStacked(bool statement);

    friend class Graph<T>;
};

template <class T>
class Edge {
    Vertex<T> * dest;      // destination vertex
    double weight;         // edge weight
    string airline;
public:
    Edge(Vertex<T> *d, double w, string airl);
    Vertex<T> *getDest() const;
    string getAirline();
    void setDest(Vertex<T> *dest);
    double getWeight() const;
    void setWeight(double weight);
    friend class Graph<T>;
    friend class Vertex<T>;
};

template <class T>
class Graph {
    vector<Vertex<T> *> vertexSet;      // vertex set
    int _index_;                        // auxiliary field
    stack<Vertex<T>> _stack_;           // auxiliary field
    list<list<T>> _list_sccs_;        // auxiliary field

    void dfsVisit(Vertex<T> *v,  vector<T> & res) const;
    bool dfsIsDAG(Vertex<T> *v) const;
public:
    Vertex<T> *findVertex(const T &in) const;
    int getNumVertex() const;
    bool addVertex(const T &in);
    bool removeVertex(const T &in);
    bool addEdge(const T &sourc, const T &dest, double w, string airl);
    bool removeEdge(const T &sourc, const T &dest);
    vector<Vertex<T> * > getVertexSet() const;
    vector<T> dfs() const;
    vector<T> dfs(const T & source) const;
    vector<T> bfs(const T &source) const;
    vector<T> topsort() const;
    bool isDAG() const;


    vector<vector<Connection<T>>> multiBfs(vector<T> sources, vector<T> destinations, int maxAirlines) const;

    vector<vector<Connection<T>>> findAllShortestPaths(Vertex<T> *source, Vertex<T> *destination, int maxAirlines) const;

    Graph<T> *cloneGraph() const;
};

/****************** Provided constructors and functions ********************/

template <class T>
Graph<T>* Graph<T>::cloneGraph() const {
    auto newGraph = new Graph<T>();

    // Map to store the correspondence between original and new vertices
    map<Vertex<T>*, Vertex<T>*> origToNewMap;

    // Step 1: Clone vertices
    for (Vertex<T>* origVertex : vertexSet) {
        auto newVertex = new Vertex<T>(origVertex->info);
        newGraph->addVertex(newVertex->info);
        origToNewMap[origVertex] = newVertex;
    }

    // Step 2: Clone edges
    for (Vertex<T>* origVertex : vertexSet) {
        for (Edge<T>& edge : origVertex->adj) {
            Vertex<T>* newFrom = origToNewMap[origVertex];
            Vertex<T>* newTo = origToNewMap[edge.dest];
            newGraph->addEdge(newFrom->info, newTo->info, edge.weight, edge.airline);
        }
    }

    return newGraph;
}


template <class T>
Vertex<T>::Vertex(T in): info(in) {}

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w, string airl): dest(d), weight(w), airline(airl) {}


template <class T>
int Graph<T>::getNumVertex() const {
    return vertexSet.size();
}

template <class T>
vector<Vertex<T> * > Graph<T>::getVertexSet() const {
    return vertexSet;
}

template<class T>
T Vertex<T>::getInfo() const {
    return info;
}

template<class T>
void Vertex<T>::setInfo(T in) {
    Vertex::info = in;
}

template<class T>
bool Vertex<T>::isProcessing() const {
    return processing;
}

template<class T>
void Vertex<T>::setProcessing(bool p) {
    Vertex::processing = p;
}

template<class T>
Vertex<T> *Edge<T>::getDest() const {
    return dest;
}

template<class T>
string Edge<T>::getAirline() {
    return airline;
}

template<class T>
void Edge<T>::setDest(Vertex<T> *d) {
    Edge::dest = d;
}

template<class T>
double Edge<T>::getWeight() const {
    return weight;
}

template<class T>
void Edge<T>::setWeight(double weight) {
    Edge::weight = weight;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}

template <class T>
bool Vertex<T>::isVisited() const {
    return visited;
}

template<class T>
int Vertex<T>::getIndegree() const {
    return indegree;
}

template<class T>
void Vertex<T>::setIndegree(int indegree) {
    Vertex::indegree = indegree;
}

template<class T>
void Vertex<T>::addIndegree(){
    Vertex::indegree++;
}

template<class T>
int Vertex<T>::getNum() const {
    return num;
}

template<class T>
void Vertex<T>::setNum(int num) {
    Vertex::num = num;
}

template<class T>
int Vertex<T>::getLow() const {
    return low;
}

template<class T>
void Vertex<T>::setLow(int low) {
    Vertex::low = low;
}

template<class T>
bool Vertex<T>::getStacked() const {
    return stacked;
}

template<class T>
void Vertex<T>::setStacked(bool statement) {
    stacked = statement;
}

template <class T>
void Vertex<T>::setVisited(bool v) {
    Vertex::visited = v;
}

template<class T>
const vector<Edge<T>> &Vertex<T>::getAdj() const {
    return adj;
}

template <class T>
void Vertex<T>::setAdj(const vector<Edge<T>> &adj) {
    Vertex::adj = adj;
}


/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
    if ( findVertex(in) != NULL)
        return false;
    vertexSet.push_back(new Vertex<T>(in));
    return true;
}


/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w, string airl) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2,w, airl);
    return true;
}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w, string airl) {
    adj.push_back(Edge<T>(d, w, airl));
}


/*
 * Removes an edge from a graph (this).
 * The edge is identified by the source (sourc) and destination (dest) contents.
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    return v1->removeEdgeTo(v2);
}

/*
 * Auxiliary function to remove an outgoing edge (with a given destination (d))
 * from a vertex (this).
 * Returns true if successful, and false if such edge does not exist.
 */
template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
    for (auto it = adj.begin(); it != adj.end(); it++)
        if (it->dest  == d) {
            adj.erase(it);
            return true;
        }
    return false;
}

/*
 *  Removes a vertex with a given content (in) from a graph (this), and
 *  all outgoing and incoming edges.
 *  Returns true if successful, and false if such vertex does not exist.
 */
template <class T>
bool Graph<T>::removeVertex(const T &in) {
    for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
        if ((*it)->info  == in) {
            auto v = *it;
            vertexSet.erase(it);
            for (auto u : vertexSet)
                u->removeEdgeTo(v);
            delete v;
            return true;
        }
    return false;
}


/****************** DFS ********************/
/*
 * Performs a depth-first search (dfs) traversal in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order.
 * Follows the algorithm described in theoretical classes.
 */
template <class T>
vector<T> Graph<T>::dfs() const {
    vector<T> res;
    for (auto v : vertexSet)
        v->visited = false;
    for (auto v : vertexSet)
        if (! v->visited)
            dfsVisit(v, res);
    return res;
}

/*
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Updates a parameter with the list of visited node contents.
 */
template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, vector<T> & res) const {
    v->visited = true;
    res.push_back(v->info);
    for (auto & e : v->adj) {
        auto w = e.dest;
        if ( ! w->visited)
            dfsVisit(w, res);
    }
}


/****************** DFS ********************/
/*
 * Performs a depth-first search (dfs) in a graph (this).
 * Returns a vector with the contents of the vertices by dfs order,
 * from the source node.
 */
template <class T>
vector<T> Graph<T>::dfs(const T & source) const {
    vector<T> res;
    auto s = findVertex(source);
    if (s == nullptr)
        return res;

    for (auto v : vertexSet)
        v->visited = false;

    dfsVisit(s, res);
    return res;
}


/****************** BFS ********************/
/*
 * Performs a breadth-first search (bfs) in a graph (this), starting
 * from the vertex with the given source contents (source).
 * Returns a vector with the contents of the vertices by bfs order.
 */
template <class T>
vector<T> Graph<T>::bfs(const T & source) const {
    vector<T> res;
    auto s = findVertex(source);
    if (s == NULL)
        return res;
    queue<Vertex<T> *> q;
    for (auto v : vertexSet)
        v->visited = false;
    q.push(s);
    s->visited = true;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        res.push_back(v->info);
        for (auto & e : v->adj) {
            auto w = e.dest;
            if ( ! w->visited ) {
                q.push(w);
                w->visited = true;
            }
        }
    }
    return res;
}

/**
 * @brief Finds the best flights between the given origin and destination by using BFS logic
 * @details Time complexity: O(V+E⋅(L+A)), where V is the number of vertices in the graph, E is the number of edges in the graph, L represents the average length of the paths and A represents the maxAirlines
 * @param source The origin airport vertex
 * @param destination The destination airport vertex
 * @param maxAirlines The maximum amount of different airlines that the user wants to allow
 * @return A vector of vectors of flights, where each inner vector represents a possible flight path
 */
template <class T>
vector<vector<Connection<T>>> Graph<T>::findAllShortestPaths(Vertex<T> *source, Vertex<T> *destination, int maxAirlines) const {
    vector<vector<Connection<T>>> allPaths;
    if (source == nullptr || destination == nullptr) return allPaths;

    map<Vertex<T>*, int> level;
    for (auto v : vertexSet) {
        level[v] = -1;  // Initialize level for each vertex
    }

    queue<pair<vector<Connection<T>>, unordered_set<string>>> q;
    q.push({{}, {}});  // start with an empty path and an empty set of airlines
    level[source] = 0;

    int shortestPathLength = INT_MAX;

    while (!q.empty()) {
        auto [path, airlinesUsed] = q.front();
        q.pop();
        Vertex<T>* lastVertex = path.empty() ? source : findVertex(path.back().destination);

        if (lastVertex == destination) {
            if (path.size() < shortestPathLength) {
                allPaths.clear();
                shortestPathLength = path.size();
            }
            if (path.size() == shortestPathLength) {
                allPaths.push_back(path);
            }
            continue;
        }

        for (auto &e : lastVertex->adj) {
            Vertex<T>* nextVertex = e.dest;
            if (level[nextVertex] == -1 || level[nextVertex] >= level[lastVertex] + 1) {
                unordered_set<string> airlinesUpdated(airlinesUsed);
                airlinesUpdated.insert(e.airline);
                if (airlinesUpdated.size() <= maxAirlines) {
                    level[nextVertex] = level[lastVertex] + 1;
                    vector<Connection<T>> newPath(path);
                    Connection<T> conn;
                    conn.source = lastVertex->info;
                    conn.destination = nextVertex->info;
                    conn.airline = e.airline;
                    newPath.push_back(conn);
                    q.push({newPath, airlinesUpdated});
                }
            }
        }
    }

    return allPaths;
}

/**
 * @brief Runs the modified BFS algorithm for each possible origin and destiny
 * @details Time complexity: O(n*m), where n is the number of origins and m the number of destinies
 * @param sources Al of the possible sources
 * @param destinations All of the possible destinations
 * @param maxAirlines The maximum amount of airlines in the flight connections
 * @return A vector of vectors of flights, where each inner vector represents a possible flight path
 */
template <class T>
vector<vector<Connection<T>>> Graph<T>::multiBfs(vector<T> sources, vector<T> destinations, int maxAirlines) const {
    vector<vector<Connection<T>>> allPaths;

    for (int i = 0; i < sources.size(); i++) {
        auto sourceVertex = findVertex(sources[i]);
        for (int j = 0; j < destinations.size(); j++) {
            auto destinationVertex = findVertex(destinations[j]);
            vector<vector<Connection<T>>> paths = findAllShortestPaths(sourceVertex, destinationVertex, maxAirlines);

            // Add the found paths to the overall list of paths
            for (const auto &path : paths) {
                allPaths.push_back(path);
            }
        }
    }

    return allPaths;
}


/****************** isDAG  ********************/
/*
 * Performs a depth-first search in a graph (this), to determine if the graph
 * is acyclic (acyclic directed graph or DAG).
 * During the search, a cycle is found if an edge connects to a vertex
 * that is being processed in the stack of recursive calls (see theoretical classes).
 * Returns true if the graph is acyclic, and false otherwise.
 */

template <class T>
bool Graph<T>::isDAG() const {
    for (auto v : vertexSet) {
        v->visited = false;
        v->processing = false;
    }
    for (auto v : vertexSet)
        if (! v->visited)
            if ( ! dfsIsDAG(v) )
                return false;
    return true;
}

/**
 * Auxiliary function that visits a vertex (v) and its adjacent, recursively.
 * Returns false (not acyclic) if an edge to a vertex in the stack is found.
 */
template <class T>
bool Graph<T>::dfsIsDAG(Vertex<T> *v) const {
    v->visited = true;
    v->processing = true;
    for (auto & e : v->adj) {
        auto w = e.dest;
        if (w->processing)
            return false;
        if (! w->visited)
            if (! dfsIsDAG(w))
                return false;
    }
    v->processing = false;
    return true;
}


/****************** toposort ********************/

template<class T>
vector<T> Graph<T>::topsort() const {
    vector<T> res;
    //Initialize for each test
    for (auto i : vertexSet){
        i->indegree = 0;
        i->visited = false;
    }

    //Assign indegrees for all vertexs
    for (auto i : vertexSet){
        for (auto j: i->adj){
            j.dest->indegree++;
        }
    }

    //Initialize queue with first nodes
    queue<Vertex<T> *> q;
    for (auto i : vertexSet){
        if (i->indegree == 0){
            q.push(i);
        }
    }

    //Append nodes to List
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        for (auto j: v->adj){
            j.dest->indegree--;
            if (j.dest->indegree == 0){
                q.push(j.dest);
            }
        }
        res.push_back(v->info);
    }
    return res;
}

#endif /* GRAPH_H_ */
