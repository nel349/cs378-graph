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
#include <unordered_map> // unordered map
#include <iostream>
#include <memory>    // allocator

using namespace std;


// -----
// Graph
// -----

class Graph {


    public:
        // --------
        // typedefs
        // --------

        typedef int vertex_descriptor   ;  // fix!
        typedef int edge_descriptor;    // fix!

        // typedef int* vertex_iterator;    // fix!
        // typedef int* edge_iterator;      // fix!
        typedef int* adjacency_iterator; // fix!

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;


     private:
        // ----
        // data
        // ----

        // std::vector< std::vector<vertex_descriptor> > g; // something like this

        unordered_map< vertex_descriptor, vector<vertex_descriptor> > graph;
        unordered_map< vertices_size_type, vertex_descriptor> vertices; // vertices and its edges

        unordered_map< edge_descriptor, pair<vertex_descriptor, vertex_descriptor> > edges; // edges

        vertex_descriptor vid;
        edge_descriptor eid;    

    public:

        //HELPFUL Functions

        friend void printVertices(Graph& g){
           for ( auto it = g.vertices.begin(); it != g.vertices.end(); ++it )
                cout << " " << it->first << ":" << it->second;
        
            cout << endl;

            // cout << "Is this failing" << endl;

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

        /**
         * <your documentation>
         */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor a, vertex_descriptor b, Graph& g) {

            edge_descriptor ed = g.eid;
            bool            add_edge  = true;
            for ( auto it = g.edges.begin(); it != g.edges.end(); ++it ){
                if( (it->second.first  == a && it->second.second == b) ||
                    (it->second.first  == b && it->second.second == a) )  {
                    add_edge= false;
                    // cout << a << " "<< b<<"Edge not added" << endl;
                }
            }
            if(add_edge){
                ++g.eid;
                g.edges[ed] = make_pair(a,b);
                // cout << "Added edge " << ed <<endl;
                if(g.graph.find(a) == g.graph.end()){
                    g.graph[a] = {};
                    g.graph[a].push_back(b);
                }
                else{
                    g.graph[a].push_back(b);
                }
                
                if(g.graph.find(b) == g.graph.end()){
                    g.graph[b] = {};
                    g.graph[b].push_back(a);


                }
                else{
                    g.graph[b].push_back(a);
                }
            }
            else{
                 // cout << "Edge : " << g.eid << " already exist" << endl;
            }
            
            return std::make_pair(ed, add_edge);}

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

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * <your documentation>
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor, const Graph&) {
            // <your code>
            static int a [] = {0, 0};     // dummy data
            adjacency_iterator b = a;
            adjacency_iterator e = a + 2;
            return std::make_pair(b, e);}

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
        friend vertex_descriptor source (edge_descriptor, const Graph&) {
            // <your code>
            vertex_descriptor v = 0; // fix
            return v;}

        // ------
        // target
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor target (edge_descriptor, const Graph&) {
            // <your code>
            vertex_descriptor v = 0; // fix
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

                // typedef std::bidirectional_iterator_tag   iterator_category;
                // typedef typename Graph::value_type      value_type;
                // typedef typename Graph::difference_type difference_type;
                // typedef typename &*vertex_descriptor               reference;
                // typedef typename Graph::vertex_iterator                         reference;
// 
                // typedef typename Graph::vertex_iterator*                         pointer;

                // typedef typename allocator_type::reference          reference;
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

                // typedef std::bidirectional_iterator_tag   iterator_category;
                // typedef typename Graph::value_type      value_type;
                // typedef typename Graph::difference_type difference_type;
                // typedef typename &*edge_descriptor               reference;
                // typedef typename Graph::edge_iterator                         reference;
// 
                // typedef typename Graph::edge_iterator*                         pointer;

                typedef typename Graph::edges_size_type           size_type;

            public:
                // -----------
                // operator ==
                // -----------

                /**
                 * <your documentation>
                 */
                friend bool operator == (const edge_iterator& lhs, const edge_iterator& rhs) {
                    return lhs._c == rhs._c && lhs.index == rhs.index;
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

                    edge_descriptor d = index;

                    return d;
                }



                // -----------
                // operator ++
                // -----------

                /**
                 * <your documentation>
                 */
                edge_iterator& operator ++ () {
                    // ++(*this);
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


        /**
         * <your documentation>
         */                                             //Ther ShOULD be a const version here!!!
        friend std::pair<vertex_iterator, vertex_iterator> vertices ( Graph& g) {// <------------
            // <your code>
                // dummy data
           
            vertex_iterator b = g.begin();
            vertex_iterator e = g.end();
            return std::make_pair(b, e);}


        // -----
        // edges
        // -----

        /**
         * <your documentation>
         */                                              //Ther ShOULD be a const version here!!!
        friend std::pair<edge_iterator, edge_iterator> edges (Graph& g) { // <------------
            edge_iterator b = g.edge_begin();
            edge_iterator e = g.edge_end();
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
            eid = 0;

            assert(valid());}

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);



    };



#endif // Graph_h
