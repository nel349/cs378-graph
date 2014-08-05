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

         bool less_second(const pair<vertex_descriptor, vertex_descriptor>& a, const pair<vertex_descriptor, vertex_descriptor>& b){

            return true;
        }

        // --------
        // add_edge
        // --------

        /**
         * <your documentation>
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

        /**
         * <your documentation>
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
         * <your documentation>
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
         * <your documentation>
         */
        friend edges_size_type num_edges (const Graph& g) {
            edges_size_type s = (edges_size_type) g.edges.size() ; 
            return s;}

        // ------------
        // num_vertices
        // ------------

        /**
         * <your documentation>
         */
        friend vertices_size_type num_vertices (const Graph& g) {
            vertices_size_type s = g.vertices.size(); 
            return s;}

        // ------
        // source
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor source (edge_descriptor ed, const Graph& g) {
            vertex_descriptor v =  g.edges.at(ed).first; 
            return v;}

        // ------
        // target
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor target (edge_descriptor ed, const Graph& g) {

                vertex_descriptor v = g.edges.at(ed).second;
            return v;}

        // ------
        // vertex
        // ------

        /**
         * <your documentation>
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
                 * <your documentation>
                 */
                friend bool operator == (const vertex_iterator& lhs, const vertex_iterator& rhs) {
                    return *lhs == *rhs;
                }

                /**
                 * <your documentation>
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
                 * <your documentation>
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
                 * <your documentation>
                 */
                vertex_descriptor& operator * () const {
                    return (*_c).vertices[index];}

                // -----------
                // operator ->
                // -----------

                /**
                 * <your documentation>
                 */
                vertex_descriptor* operator -> () const {
                    return &**this;}

                // -----------
                // operator ++
                // -----------

                /**
                 * <your documentation>
                 */
                vertex_iterator& operator ++ () {
                    // ++(*this);
                    ++index;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
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
                 * <your documentation>
                 */
                vertex_iterator& operator -- () {
                //     // --(*this);
                    --index;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
                 */
                vertex_iterator operator -- (int) {
                    vertex_iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;}


                 /**
                 * @param cosnt_iterator
                 * @param value d
                 * @return const_iterator reference
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
                 * @param const_iterator
                 * @param value d
                 * @return const_iterator reference
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
                 * <your documentation>
                 */
                friend bool operator == (const edge_iterator& lhs, const edge_iterator& rhs) {
                    return *lhs == *rhs;
                }

                /**
                 * <your documentation>
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
                 * <your documentation>
                 */
                edge_iterator (Graph* c, size_type i = 0) : _c(c), index(0){

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
                 * <your documentation>
                 */
                edge_descriptor operator * () const {
                    edge_descriptor r =0;
                    // size_type i =0;
                    auto it = (*_c).edges.begin();

                    advance(it, index);
                    // while(  i < index ){
                    //     ++i;
                    //     ++it;
                    // }
                    r= it->first;
                    return r;
                }



                // -----------
                // operator ++
                // -----------

                /**
                 * <your documentation>
                 */
                edge_iterator& operator ++ () {
                    ++index;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
                 */
                edge_iterator operator ++ (int) {
                    edge_iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}



                 /**
                 * @param cosnt_iterator
                 * @param value d
                 * @return const_iterator reference
                 * adds d to iterator
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
                 * <your documentation>
                 */
                friend bool operator == (const adjacency_iterator& lhs, const adjacency_iterator& rhs) {
                    return lhs._c == rhs._c && lhs.index == rhs.index && lhs._vd == rhs._vd;
                }

                /**
                 * <your documentation>
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
                 * <your documentation>
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
                 * <your documentation>
                 */
                vertex_descriptor& operator * () const {                   
                    return (*_c).graph[_vd][index];
                }



                // -----------
                // operator ++
                // -----------

                /**
                 * <your documentation>
                 */
                adjacency_iterator& operator ++ () {
                    ++index;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
                 */
                adjacency_iterator operator ++ (int) {
                    adjacency_iterator x = *this;
                    ++(*this);
                    assert(valid());
                    return x;}



                 /**
                 * @param cosnt_iterator
                 * @param value d
                 * @return const_iterator reference
                 * adds d to iterator
                 */
                adjacency_iterator& operator += (vertices_size_type d) {

                    index += d;
                    assert(valid());
                    return *this;}




                // -----------
                // operator --
                // -----------

                /**
                 * <your documentation>
                 */
                adjacency_iterator& operator -- () {
                    --index;
                    assert(valid());
                    return *this;}

                /**
                 * <your documentation>
                 */
                adjacency_iterator operator -- (int) {
                    adjacency_iterator x = *this;
                    --(*this);
                    assert(valid());
                    return x;}

     
            };



        /**
         * <your documentation>
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
         * <your documentation>
         */                                             
        friend std::pair<edge_iterator, edge_iterator> edges (Graph& g) { 
            edge_iterator b = g.edge_begin();
            edge_iterator e = g.edge_end();
            return std::make_pair(b, e);} 

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * <your documentation>
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor vd,  Graph& g) {
            // vector<vertex_descriptor> m = g.graph[vd];
            adjacency_iterator b = g.adjacency_begin(vd);
            adjacency_iterator e = g.adjacency_end(vd);
            return std::make_pair(b, e);}           


        /**
         * <your documentation>
         */
        vertex_iterator begin () {
            return vertex_iterator(this, 0);
        }

        /**
         * <your documentation>
         */
        vertex_iterator end () {
            return vertex_iterator(this, vertices.size());
        }      


        /**
         * <your documentation>
         */
        edge_iterator edge_begin () {
            return edge_iterator(this, 0);
        }

        /**
         * <your documentation>
         */
        edge_iterator edge_end () {
            return edge_iterator(this, edges.size());
        }  



                /**
         * <your documentation>
         */
        adjacency_iterator adjacency_begin (vertex_descriptor& vd) {
            return adjacency_iterator(this, 0, vd);
        }

        /**
         * <your documentation>
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
         * <your documentation>
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
