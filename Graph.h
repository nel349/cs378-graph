// ----------------------
// projects/graph/Graph.h
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector>  // vector
#include <map> //  map
#include <iostream>
#include <memory>    // allocator
#include <algorithm>

using namespace std;


// -----
// Graph
// -----

class Graph {


    public:
        // --------
        // typedefs
        // --------

        typedef int vertex_descriptor   ; 
        typedef int edge_descriptor;   

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;


     private:
        // ----
        // data
        // ----


        map< vertex_descriptor, vector<vertex_descriptor> > graph;
        map< vertices_size_type, vertex_descriptor> vertices; // vertices and its edges

        map< edge_descriptor, pair<vertex_descriptor, vertex_descriptor> > edges; // edges

        vertex_descriptor vid;

    public:

        //HELPFUL Functions

        friend void printVertices(Graph& g){
           for ( auto it = g.vertices.begin(); it != g.vertices.end(); ++it )
                cout << " " << it->first << ":" << it->second;
        
            cout << endl;

        }


        friend void printEdges(Graph& g){
            for ( auto it = g.edges.begin(); it != g.edges.end(); ++it ){
                cout << "edge: " << it->first << " (" << it->second.first << " , "<< it->second.second << ")" << endl;
            }
        }


        friend void printGraph(Graph& g){
            for ( auto vertex = g.graph.begin(); vertex != g.graph.end(); ++vertex ){
                cout << "vertex: " << vertex->first << "(";
                vector<vertex_descriptor> adjl = vertex->second;
                for(vertex_descriptor x : adjl){
                    cout << " " << x ;
                }
                cout << " )" << endl;

            }
        }

        // --------
        // add_edge
        // --------

        /*
        * @param a - vertex descriptor a
        * @param b - vertex descriptor b
        * @return std::pair<edge_descriptor, bool>
         * Adds edge (u,v) to the graph and returns the edge descriptor for the new edge. For graphs that do 
         * not allow parallel edges, if the edge is already in the graph then a duplicate will not be added and the bool flag will be false. When the flag is false, the returned edge descriptor points to the already existing edge.
         */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor a, vertex_descriptor b, Graph& g) {

            edge_descriptor ed = (edge_descriptor)10 * a  + b;
            bool            add_edge  = true;
            for ( auto it = g.edges.begin(); it != g.edges.end(); ++it ){
                if( (it->second.first  == a && it->second.second == b) ||
                    (it->second.first  == b && it->second.second == a) )  {
                    add_edge= false;
                }
            }
            if(add_edge){
                
                g.edges[ed] = make_pair(a,b);
                if(g.graph.find(a) == g.graph.end()){
                    g.graph[a] = {};
                    g.graph[a].push_back(b);
                }
                else{
                    g.graph[a].push_back(b);
                }
                
                // if(g.graph.find(b) == g.graph.end()){
                //     g.graph[b] = {};
                //     g.graph[b].push_back(a);


                // }
                // else{
                //     g.graph[b].push_back(a);
                // }
            }
            else{
                std::pair<edge_descriptor, bool> found =edge(a, b, g); 
                ed = found.first;      
            }
            // sort(g.edges.begin(), g.edges.end(), less_second);

            sort(g.graph[a].begin(),g.graph[a].end());
            return std::make_pair(ed, add_edge);
        }




        // ----------
        // add_vertex
        // ----------

        /*
         * @param g - Graph g
         * @return vertex_descriptor
         * returns the vertex_descriptor of the added vertex
         */
        friend vertex_descriptor add_vertex (Graph& g) {
            g.vertices[(vertices_size_type)g.vid] = g.vid;
            vertex_descriptor v  =  g.vid;       
            ++g.vid;
            return v;}

        

        // ----
        // edge
        // ----

        /**
         * @param a - vertex descriptor a of an edge
         * @param b - vertex descriptor b of an edge
         * @param g - vAdjacency list
         * @return bool
         * If an edge from vertex a to vertex b exists, return a pair containing one such edge and true. 
         * If there are no edges between a and b, return a pair with an arbitrary edge descriptor and false.
         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor a, vertex_descriptor b, const Graph& g) {
            bool            exist  = false;
            edge_descriptor ed = 0;


            for ( auto it = g.edges.begin(); it != g.edges.end(); ++it ){
                if( (it->second.first  == a && it->second.second == b) ||
                    (it->second.first  == b && it->second.second == a) )  {
                    exist= true;
                    ed = it->first;
                }
            }
            return std::make_pair(ed, exist);}

       

        // ---------
        // num_edges
        // ---------

        /**
         *@param g - Adjacency list
         *@return edges_size_type
         *Returns the number of edges in the graph g.
         */
        friend edges_size_type num_edges (const Graph& g) {
            edges_size_type s = (edges_size_type) g.edges.size() ; 
            return s;}

        // ------------
        // num_vertices
        // ------------

        /**
         *@param g - Adjacency list
         *@return vertex_size_type                     
         * Returns the number of vertices in the graph g.
         */
        friend vertices_size_type num_vertices (const Graph& g) {
            vertices_size_type s = g.vertices.size(); 
            return s;}

        // ------
        // source
        // ------

        /**
         * @param ed - edge_descriptor
         * @param g - Adjacency list
         * @return vertex_descriptor
         * Returns the source vertex of edge ed.
         */
        friend vertex_descriptor source (edge_descriptor ed, const Graph& g) {
            vertex_descriptor v =  g.edges.at(ed).first; 
            return v;}

        // ------
        // target
        // ------

        /**
         * @param ed - edge_descriptor
         * @param g - Adjacency list
         * @return vertex_descriptor
         * Returns the target vertex of edge ed.
         */
        friend vertex_descriptor target (edge_descriptor ed, const Graph& g) {

                vertex_descriptor v = g.edges.at(ed).second;
            return v;}

        // ------
        // vertex
        // ------

        /**
         * @param n - nth vertex 
         * @return vertex_descriptor
         * Returns the nth vertex in the graph's vertex list
         */
        friend vertex_descriptor vertex (vertices_size_type n, const Graph& g) {
            auto it_vd = g.vertices.find(n);
            vertex_descriptor vd = it_vd -> second; 
            return vd;}

        // --------
        // vertices
        // --------
        public:
            class vertex_iterator{
           public:
                // --------
                // typedefs
                // --------
                typedef typename Graph::vertices_size_type           size_type;

            public:
                // -----------
                // operator ==
                // -----------

                /**
                 * @param lhs - vertex_iterator left hand side of operation
                 * @param rhs - vertex_iterator right hand side of operation
                 * @return bool
                 * returns whether two iterators iterate over same container
                 */
                friend bool operator == (const vertex_iterator& lhs, const vertex_iterator& rhs) {
                    return *lhs == *rhs;
                }

                /**
                 * @param lhs - vertex_iterator left hand side of operation
                 * @param rhs - vertex_iterator right hand side of operation
                 * @return bool
                 * returns whether two iterators don't iterate over same things uses ==
                 */
                friend bool operator != (const vertex_iterator& lhs, const vertex_iterator& rhs) {
                    return !(lhs == rhs);}



            private:
                // ----
                // data
                // ----
                // <your data>

                Graph* _c;
                size_type index;

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    return index >= 0;}

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * @param Graph _c
                 * @param index i
                 * construct a vertex_iterator for _c starting at i
                 */
                vertex_iterator (Graph* c, size_type i = 0) : _c(c), index(0){

                    index = i;

                    assert(valid());
                }

                // Default copy, destructor, and copy assignment.
                // iterator (const iterator&);
                // ~iterator ();
                // iterator& operator = (const iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * @param vertex_iterator
                 * @return reference - vertex_descriptor&
                 * dereferences vertex_iterator
                 */
                vertex_descriptor& operator * () const {
                    return (*_c).vertices[index];}

                // -----------
                // operator ->
                // -----------

                 /**
                 * @param vertex_iterator
                 * @return pointer - vertex_descriptor*
                 * dereferences vertex_iterator
                 */
                vertex_descriptor* operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------
                /**
                 * @param vertex_iterator
                 * @return vertex_iterator reference
                 * pre-increments vertex_iterator
                 */
                vertex_iterator& operator ++ () {
                    // ++(*this);
                    ++index;
                    assert(valid());
                    return *this;}

                /**
                 * @param vertex_iterator
                 * @return vertex_iterator reference
                 * post-increments vertex_iterator
                 */
                vertex_iterator operator ++ (int) {
                    vertex_iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}

                // -----------
                // operator --
                // -----------

                /**
                 * @param vertex_iterator
                 * @return vertex_iterator reference
                 * pre-decrement vertex_iterator
                 */
                vertex_iterator& operator -- () {
                //     // --(*this);
                    --index;
                    assert(valid());
                    return *this;}
                /**
                 * @param vertex_iterator
                 * @return vertex_iterator reference
                 * post-decrements vertex_iterator
                 */
                vertex_iterator operator -- (int) {
                    vertex_iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;}


                 /**
                 * @param vertex_iterator
                 * @param value d
                 * @return vertex_iterator reference
                 * adds d to iterator
                 */
                vertex_iterator& operator += (vertices_size_type d) {

                    index += d;
                    assert(valid());
                    return *this;}

                // -----------
                // operator -=
                // -----------

                /**
                 * @param vertex_iterator
                 * @param value d
                 * @return vertex_iterator reference
                 * subtracts d from iterator
                 */
                vertex_iterator& operator -= (vertices_size_type d) {
                    index -= d;
                    assert(valid());
                    return *this;
                }
    


            };


        // --------
        // Edges iterator
        // --------
        public:
            class edge_iterator{
           public:
                // --------
                // typedefs
                // --------

                typedef typename Graph::edges_size_type           size_type;

            public:
                // -----------
                // operator ==
                // -----------

                /**
                 * @param lhs - edge iterator left hand side of operation
                 * @param rhs - edge iterator right hand side of operation
                 * @return bool
                 * returns whether two iterators iterate over same container
                 */
                friend bool operator == (const edge_iterator& lhs, const edge_iterator& rhs) {
                    return *lhs == *rhs;
                }

                /**
                 * @param lhs - edge iterator left hand side of operation
                 * @param rhs - edge iterator right hand side of operation
                 * @return bool
                 * returns whether two iterators don't iterate over same things uses ==
                 */
                friend bool operator != (const edge_iterator& lhs, const edge_iterator& rhs) {
                    return !(lhs == rhs);}



            private:
                // ----
                // data
                // ----
                // <your data>

                Graph* _c;
                size_type index;

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    return index >= 0;}

            public:
                // -----------
                // constructor
                // -----------

                /**
                 * @param Graph _c
                 * @param index i
                 * construct a edge_iterator for _c starting at i
                 */
                edge_iterator (Graph* c, size_type i = 0) : _c(c), index(0){

                    index = i;

                    assert(valid());
                }

                // Default copy, destructor, and copy assignment.
                // iterator (edge iterator&);
                // ~iterator ();
                // iterator& operator = (edge iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * @param edge_iterator
                 * @return edge_descriptor
                 * dereferences edge_iterator
                 */
                edge_descriptor operator * () const {
                    edge_descriptor r =0;
                    auto it = (*_c).edges.begin();
                    advance(it, index);
                    r= it->first;
                    return r;
                }



                // -----------
                // operator ++
                // -----------

                /**
                 * @param edge_iterator
                 * @return edge_iterator reference
                 * pre-increments edge_iterator
                 */
                edge_iterator& operator ++ () {
                    ++index;
                    assert(valid());
                    return *this;}

                /**
                 * @param edge_iterator
                 * @return edge_iterator reference
                 * post-increments edge_iterator
                 */
                edge_iterator operator ++ (int) {
                    edge_iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}



                 /**
                 * @param edge_iterator
                 * @param value d
                 * @return edge_iterator reference
                 * adds d to edge_iterator
                 */
                edge_iterator& operator += (edges_size_type d) {

                    index += d;
                    assert(valid());
                    return *this;}

     
    


            };




             // --------
        // Edges iterator
        // --------
        public:
            class adjacency_iterator{
           public:
                // --------
                // typedefs
                // --------

                typedef typename Graph::vertices_size_type           size_type;

            public:
                // -----------
                // operator ==
                // -----------

                /**
                 * @param lhs - constant iterator left hand side of operation
                 * @param rhs - constant iterator right hand side of operation
                 * @return bool
                 * returns whether two iterators iterate over same container
                 */
                friend bool operator == (const adjacency_iterator& lhs, const adjacency_iterator& rhs) {
                    return lhs._c == rhs._c && lhs.index == rhs.index && lhs._vd == rhs._vd;
                }

                /**
                 * @param lhs - constant iterator left hand side of operation
                 * @param rhs - constant iterator right hand side of operation
                 * @return bool
                 * returns whether two iterators don't iterate over same things uses ==
                 */
                friend bool operator != (const adjacency_iterator& lhs, const adjacency_iterator& rhs) {
                    return !(lhs == rhs);}



            private:
                // ----
                // data
                // ----
                // <your data>

                Graph* _c;
                size_type index;
                vertex_descriptor _vd;

            private:
                // -----
                // valid
                // -----

                bool valid () const {
                    return index >= 0;}

            public:
                // -----------   
                // constructor
                // -----------

                /**
                 * @param Graph _c
                 * @param index i
                 * @param index vd
                 * construct a adjacency_iterator for _c starting at vd starting at i
                 */
                adjacency_iterator (Graph* c, size_type i = 0, vertex_descriptor vd = 0) : _c(c), index(0), _vd(vd){

                    index = i;

                    _vd = vd;
                    assert(valid());
                }

                // Default copy, destructor, and copy assignment.
                // iterator (const iterator&);
                // ~iterator ();
                // iterator& operator = (const iterator&);

                // ----------
                // operator *
                // ----------

                /**
                 * @param adjacency_iterator
                 * @return vertex_descriptor
                 * dereferences adjacency_iterator
                 */
                vertex_descriptor& operator * () const {                   
                    return (*_c).graph[_vd][index];
                }



                // -----------
                // operator ++
                // -----------

                /**
                 * @param adjacency_iterator
                 * @return adjacency_iterator reference
                 * pre-increments adjacency_iterator
                 */
                adjacency_iterator& operator ++ () {
                    ++index;
                    assert(valid());
                    return *this;}

                 /**
                 * @param adjacency_iterator
                 * @return adjacency_iterator reference
                 * post-increments adjacency_iterator
                 */
                adjacency_iterator operator ++ (int) {
                    adjacency_iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}



                 /**
                 * @param adjacency_iterator
                 * @param value d
                 * @return adjacency_iterator reference
                 * adds d to adjacency_iterator
                 */
                adjacency_iterator& operator += (vertices_size_type d) {

                    index += d;
                    assert(valid());
                    return *this;}




                // -----------
                // operator --
                // -----------

                 /**
                 * @param adjacency_iterator
                 * @return adjacency_iterator reference
                 * pre-decrement adjacency_iterator
                 */
                adjacency_iterator& operator -- () {
                    --index;
                    assert(valid());
                    return *this;}

                 /**
                 * @param adjacency_iterator
                 * @return adjacency_iterator reference
                 * post-decrement adjacency_iterator
                 */
                adjacency_iterator operator -- (int) {
                    adjacency_iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;}

     
            };



        /**
         * @param g - Adjacency list
         * @return std::pair<vertex_iterator, vertex_iterator>
         * Returns an iterator-range providing access to the vertex set of graph g.
         */                                          
        friend std::pair<vertex_iterator, vertex_iterator> vertices ( Graph& g) {
                // dummy data
           
            vertex_iterator b = g.begin();
            vertex_iterator e = g.end();
            return std::make_pair(b, e);}


        // -----
        // edges
        // -----

        /**
         * @param g - Adjacency list
         * @return std::pair<edge_iterator, edge_iterator>
         * Returns an iterator-range providing access to the edge set of graph g.
         */                                              
        friend std::pair<edge_iterator, edge_iterator> edges (Graph& g) { 
            edge_iterator b = g.edge_begin();
            edge_iterator e = g.edge_end();
            return std::make_pair(b, e);} 

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * @param vd - Vertex descriptor
         * @param g - Adjacency list
         *
         *Returns an iterator-range providing access to the vertices in graph g to which vd is adjacent. (inv is for inverse.) 
         *For example, if v -> vd is an edge in the graph, then v will be in this iterator range. This function is only available for bidirectional and undirected
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor vd,  Graph& g) {
            // vector<vertex_descriptor> m = g.graph[vd];
            adjacency_iterator b = g.adjacency_begin(vd);
            adjacency_iterator e = g.adjacency_end(vd);
            return std::make_pair(b, e);}           


        /**
         * @param this
         * @return vertex_iterator
         * returns vertex_iterator pointing to first object in vertices
         */
        vertex_iterator begin () {
            return vertex_iterator(this, 0);
        }

        /**
         * @param this
         * @return vertex_iterator
         * returns vertex_iterator to one index past the last element in vertices
         */
        vertex_iterator end () {
            return vertex_iterator(this, vertices.size());
        }      


        /**
         * @param this
         * @return edge_iterator
         * returns edge_iterator pointing to first object in the edge set
         */
        edge_iterator edge_begin () {
            return edge_iterator(this, 0);
        }

        /**
         * @param this
         * @return edge_iterator
         * returns edge_iterator to one index past the last element in the edges set
         */
        edge_iterator edge_end () {
            return edge_iterator(this, edges.size());
        }  



        /**
         * @param this
         * @param vd - vertex descriptor
         * @return adjacency_iterator
         * returns adjacency_iterator pointing to first object adjacent to the vertex vd
         */
        adjacency_iterator adjacency_begin (vertex_descriptor& vd) {
            return adjacency_iterator(this, 0, vd);
        }

        /**
         * @param this
         * @param vd - vertex descriptor
         * @return adjacency_iterator
         * returns adjacency_iterator to one index past the last element in the set of vertices adjacent to vd
         */
        adjacency_iterator adjacency_end (vertex_descriptor& vd) {
            return adjacency_iterator(this, graph[vd].size(), vd);
        }  



   

        // -----
        // valid
        // -----

        /**
         * <your documentation>
         */
        bool valid () const {
            // <your code>
            return true;}

        bool valid (vertex_descriptor& a, vertex_descriptor& b) const {
            return vertices.find(a) != vertices.end() && vertices.find(b) != vertices.end();}

    public:
        // ------------
        // constructors
        // ------------

        /**
         * Constructs and empty graph with empty sets vertices and edges.
         */
        Graph () {

            graph={};
            vertices={};
            edges={};

            vid = 0;


            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);



    };



#endif // Graph_h
