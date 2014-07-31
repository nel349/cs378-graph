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

        typedef int* vertex_iterator;    // fix!
        typedef int* edge_iterator;      // fix!
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


        // friend void printEdges(Graph& g){

        // }


        // --------
        // add_edge
        // --------

        /**
         * <your documentation>
         */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor, vertex_descriptor, Graph&) {
            // <your code>
            edge_descriptor ed = 0;
            bool            b  = false;
            return std::make_pair(ed, b);}

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
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor, vertex_descriptor, const Graph&) {
            // <your code>
            edge_descriptor ed = 0;
            bool            b  = true;
            return std::make_pair(ed, b);}

        // -----
        // edges
        // -----

        /**
         * <your documentation>
         */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph&) {
            // <your code>
            static int a [] = {0, 0};     // dummy data
            edge_iterator b = a;
            edge_iterator e = a + 2;
            return std::make_pair(b, e);}

        // ---------
        // num_edges
        // ---------

        /**
         * <your documentation>
         */
        friend edges_size_type num_edges (const Graph&) {
            // <your code>
            edges_size_type s = 1; // fix
            return s;}

        // ------------
        // num_vertices
        // ------------

        /**
         * <your documentation>
         */
        friend vertices_size_type num_vertices (const Graph& g) {
            vertices_size_type s = g.vertices.size(); // fix
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
            vertex_descriptor vd = it_vd -> second;  // fix
            return vd;}

        // --------
        // vertices
        // --------

        /**
         * <your documentation>
         */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph&) {
            // <your code>
            static int a [] = {0, 0};     // dummy data
            vertex_iterator b = a;
            vertex_iterator e = a + 2;
            return std::make_pair(b, e);}

   

        // -----
        // valid
        // -----

        /**
         * <your documentation>
         */
        bool valid () const {
            // <your code>
            return true;}

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
