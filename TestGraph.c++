// ----------------------------
// projects/graph/TestGraph.c++
// Copyright (C) 2014
// Glenn P. Downing
// ----------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

/*
Google Test Libraries:
    % ls -al /usr/include/gtest/
    ...
    gtest.h
    ...

    % locate libgtest.a
    /usr/lib/libgtest.a

    % locate libpthread.a
    /usr/lib/x86_64-linux-gnu/libpthread.a
    /usr/lib32/libpthread.a

    % locate libgtest_main.a
    /usr/lib/libgtest_main.a

To compile the test:
    % g++-4.7 -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Graph.c++ TestGraph.c++ -o TestGraph -lgtest -lgtest_main -lpthread

To run the test:
    % valgrind TestGraph

To obtain coverage of the test:
    % gcov-4.7 -b Graph.c++ TestGraph.c++
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <iterator> // ostream_iterator
#include <sstream>  // ostringstream
#include <utility>  // pair

#include "boost/graph/adjacency_list.hpp"  // adjacency_list
#include "boost/graph/topological_sort.hpp"// topological_sort

#include "gtest/gtest.h"

#include "Graph.h"

// ---------
// TestGraph
// ---------

template <typename G>
struct TestGraph : testing::Test {
    // --------
    // typedefs
    // --------

    typedef          G                     graph_type;
    typedef typename G::vertex_descriptor  vertex_descriptor;
    typedef typename G::edge_descriptor    edge_descriptor;
    typedef typename G::vertex_iterator    vertex_iterator;
    typedef typename G::edge_iterator      edge_iterator;
    typedef typename G::adjacency_iterator adjacency_iterator;
    typedef typename G::vertices_size_type vertices_size_type;
    typedef typename G::edges_size_type    edges_size_type;};

// directed, sparse, unweighted
// possibly connected
// possibly cyclic
typedef testing::Types<
            boost::adjacency_list<boost::setS, boost::vecS, boost::directedS>,
            Graph>
        my_types;

TYPED_TEST_CASE(TestGraph, my_types);



TYPED_TEST(TestGraph, add_vertex_1) {
    typedef typename TestFixture::graph_type         graph_type;

    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    graph_type g; // only to test

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);

    // printVertices(g); // Only works with graph_type


 
    ASSERT_EQ( 0,vdA);
    ASSERT_EQ(1,vdA1);
    ASSERT_EQ(2,vdA2);
    ASSERT_EQ(3,vdA3);
    ASSERT_EQ(4,vdA4);
    ASSERT_EQ(5,vdA5);

    vertex_descriptor find0 = vertex(0, g);



    vertex_descriptor find1 = vertex(1, g);

    vertex_descriptor find2 = vertex(2, g);
    vertex_descriptor find3 = vertex(3, g);

    vertex_descriptor find4 = vertex(4, g);
    vertex_descriptor find5 = vertex(5, g);

    ASSERT_EQ(0,find0);
    ASSERT_EQ(1,find1);
    ASSERT_EQ(2,find2);
    ASSERT_EQ(3,find3);
    ASSERT_EQ(4,find4);
    ASSERT_EQ(5,find5);

    ASSERT_NE(6,find5);






}


TYPED_TEST(TestGraph, vertex_1) {
    typedef typename TestFixture::graph_type         graph_type;

    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    graph_type g; // only to test

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);

    // printVertices(g); // Only works with graph_type


 
    ASSERT_EQ( 0,vdA);
    ASSERT_EQ(1,vdA1);
    ASSERT_EQ(2,vdA2);
    ASSERT_EQ(3,vdA3);
    ASSERT_EQ(4,vdA4);
    ASSERT_EQ(5,vdA5);

    vertex_descriptor find0 = vertex(0, g);



    vertex_descriptor find1 = vertex(1, g);

    vertex_descriptor find2 = vertex(2, g);
    vertex_descriptor find3 = vertex(3, g);

    vertex_descriptor find4 = vertex(4, g);
    vertex_descriptor find5 = vertex(5, g);

    // cout << "found: " << find0 << endl;

    // cout << "found: " << find1 << endl;
    // cout << "found: " << find2 << endl;
    // cout << "found: " << find3 << endl;
    // cout << "found: " << find4 << endl;

    ASSERT_EQ(0,find0);
    ASSERT_EQ(1,find1);
    ASSERT_EQ(2,find2);
    ASSERT_EQ(3,find3);
    ASSERT_EQ(4,find4);
    ASSERT_EQ(5,find5);

    ASSERT_NE(6,find5);

}



TYPED_TEST(TestGraph, num_vertices_1) {
    typedef typename TestFixture::graph_type         graph_type;

    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    typedef typename TestFixture::vertices_size_type vertices_size_type;


    graph_type g; // only to test

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);

    // printVertices(g); // Only works with graph_type


 
    ASSERT_EQ( 0,vdA);
    ASSERT_EQ(1,vdA1);
    ASSERT_EQ(2,vdA2);
    ASSERT_EQ(3,vdA3);
    ASSERT_EQ(4,vdA4);
    ASSERT_EQ(5,vdA5);


    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(6, vs);


    vertex_descriptor vdA6 = add_vertex(g);

    vs = num_vertices(g);

    ASSERT_EQ(7, vs);







}



// TYPED_TEST(TestGraph, Vertex) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::edge_descriptor    edge_descriptor;
//     typedef typename TestFixture::vertex_iterator    vertex_iterator;
//     typedef typename TestFixture::edge_iterator      edge_iterator;
//     typedef typename TestFixture::adjacency_iterator adjacency_iterator;
//     typedef typename TestFixture::vertices_size_type vertices_size_type;
//     typedef typename TestFixture::edges_size_type    edges_size_type;

//     graph_type g;

//     vertex_descriptor vdA = add_vertex(g);
//     vertex_descriptor vdA1 = add_vertex(g);


//     vertex_descriptor vd = vertex(0, g);
//     vertex_descriptor vd1 = vertex(1, g);
//     ASSERT_EQ(vdA, vd);
//     ASSERT_EQ(vdA1, vd1);




//     vertex_descriptor vd_test = vertex(1, g);
//     ASSERT_EQ(vd_test, vdA);

//     vertices_size_type vs = num_vertices(g);
//     ASSERT_EQ(1, vs);}

// TYPED_TEST(TestGraph, Edge) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::edge_descriptor    edge_descriptor;
//     typedef typename TestFixture::vertex_iterator    vertex_iterator;
//     typedef typename TestFixture::edge_iterator      edge_iterator;
//     typedef typename TestFixture::adjacency_iterator adjacency_iterator;
//     typedef typename TestFixture::vertices_size_type vertices_size_type;
//     typedef typename TestFixture::edges_size_type    edges_size_type;

//     graph_type g;

//     vertex_descriptor vdA = add_vertex(g);
//     vertex_descriptor vdB = add_vertex(g);

//     edge_descriptor edAB = add_edge(vdA, vdB, g).first;

//     std::pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
//     ASSERT_EQ(edAB,  p1.first);
//     ASSERT_EQ(false, p1.second);

//     std::pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
//     ASSERT_EQ(edAB, p2.first);
//     ASSERT_EQ(true, p2.second);

//     edges_size_type es = num_edges(g);
//     ASSERT_EQ(1, es);

//     vertex_descriptor vd1 = source(edAB, g);
//     ASSERT_EQ(vdA, vd1);

//     vertex_descriptor vd2 = target(edAB, g);
//     ASSERT_EQ(vdB, vd2);}

// TYPED_TEST(TestGraph, Vertices) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::edge_descriptor    edge_descriptor;
//     typedef typename TestFixture::vertex_iterator    vertex_iterator;
//     typedef typename TestFixture::edge_iterator      edge_iterator;
//     typedef typename TestFixture::adjacency_iterator adjacency_iterator;
//     typedef typename TestFixture::vertices_size_type vertices_size_type;
//     typedef typename TestFixture::edges_size_type    edges_size_type;

//     graph_type g;

//     vertex_descriptor vdA = add_vertex(g);
//     vertex_descriptor vdB = add_vertex(g);

//     std::pair<vertex_iterator, vertex_iterator> p = vertices(g);
//     vertex_iterator                             b = p.first;
//     vertex_iterator                             e = p.second;
//     if (b != e) {
//         vertex_descriptor vd = *b;
//         ASSERT_EQ(vdA, vd);}
//     ++b;
//     if (b != e) {
//         vertex_descriptor vd = *b;
//         ASSERT_EQ(vdB, vd);}
//     ++b;
//     ASSERT_EQ(e, b);}

// TYPED_TEST(TestGraph, Edges) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::edge_descriptor    edge_descriptor;
//     typedef typename TestFixture::vertex_iterator    vertex_iterator;
//     typedef typename TestFixture::edge_iterator      edge_iterator;
//     typedef typename TestFixture::adjacency_iterator adjacency_iterator;
//     typedef typename TestFixture::vertices_size_type vertices_size_type;
//     typedef typename TestFixture::edges_size_type    edges_size_type;

//     graph_type g;

//     vertex_descriptor vdA = add_vertex(g);
//     vertex_descriptor vdB = add_vertex(g);
//     vertex_descriptor vdC = add_vertex(g);

//     edge_descriptor edAB = add_edge(vdA, vdB, g).first;
//     edge_descriptor edAC = add_edge(vdA, vdC, g).first;

//     std::pair<edge_iterator, edge_iterator> p = edges(g);
//     edge_iterator                           b = p.first;
//     edge_iterator                           e = p.second;
//     if (b != e) {
//         edge_descriptor ed = *b;
//         ASSERT_EQ(edAB, ed);}
//     ++b;
//     if (b != e) {
//         edge_descriptor ed = *b;
//         ASSERT_EQ(edAC, ed);}
//     ++b;
//     ASSERT_EQ(e, b);}

// TYPED_TEST(TestGraph, Adjacent_Vertices) {
//     typedef typename TestFixture::graph_type         graph_type;
//     typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
//     typedef typename TestFixture::edge_descriptor    edge_descriptor;
//     typedef typename TestFixture::vertex_iterator    vertex_iterator;
//     typedef typename TestFixture::edge_iterator      edge_iterator;
//     typedef typename TestFixture::adjacency_iterator adjacency_iterator;
//     typedef typename TestFixture::vertices_size_type vertices_size_type;
//     typedef typename TestFixture::edges_size_type    edges_size_type;

//     graph_type g;

//     vertex_descriptor vdA = add_vertex(g);
//     vertex_descriptor vdB = add_vertex(g);
//     vertex_descriptor vdC = add_vertex(g);

//     add_edge(vdA, vdB, g);
//     add_edge(vdA, vdC, g);

//     std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
//     adjacency_iterator b = p.first;
//     adjacency_iterator e = p.second;
//     if (b != e) {
//         vertex_descriptor vd = *b;
//         ASSERT_EQ(vdB, vd);}
//     ++b;
//     if (b != e) {
//         vertex_descriptor vd = *b;
//         ASSERT_EQ(vdC, vd);}
//     ++b;
//     ASSERT_EQ(e, b);}
