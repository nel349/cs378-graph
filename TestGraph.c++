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
#include <typeinfo> 

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

TYPED_TEST(TestGraph, add_vertex_2) {
    typedef typename TestFixture::graph_type         graph_type;

    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    graph_type g; // only to test

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);
    vertex_descriptor vdA7 = add_vertex(g);
    vertex_descriptor vdA8 = add_vertex(g);

    // printVertices(g); // Only works with graph_type

    ASSERT_EQ( 0,vdA0);
    ASSERT_EQ(1,vdA1);
    ASSERT_EQ(2,vdA2);
    ASSERT_EQ(3,vdA3);
    ASSERT_EQ(4,vdA4);
    ASSERT_EQ(5,vdA5);
    ASSERT_EQ(6,vdA6);
    ASSERT_EQ(7,vdA7);
    ASSERT_EQ(8,vdA8);

    vertex_descriptor find0 = vertex(0, g);
    vertex_descriptor find1 = vertex(1, g);
    vertex_descriptor find2 = vertex(2, g);
    vertex_descriptor find3 = vertex(3, g);
    vertex_descriptor find4 = vertex(4, g);
    vertex_descriptor find5 = vertex(5, g);
    vertex_descriptor find6 = vertex(6, g);
    vertex_descriptor find7 = vertex(7, g);
    vertex_descriptor find8 = vertex(7, g);

    ASSERT_EQ(vdA0,find0);
    ASSERT_EQ(vdA1,find1);
    ASSERT_EQ(vdA2,find2);
    ASSERT_EQ(vdA3,find3);
    ASSERT_EQ(vdA4,find4);
    ASSERT_EQ(vdA5,find5);
    ASSERT_EQ(vdA6,find6);
    ASSERT_EQ(vdA7,find7);

    ASSERT_NE(vdA6,find5);
}

TYPED_TEST(TestGraph, add_vertex_3) {
    typedef typename TestFixture::graph_type         graph_type;

    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    graph_type g; // only to test

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);
    vertex_descriptor vdA7 = add_vertex(g);
    vertex_descriptor vdA8 = add_vertex(g);

    // printVertices(g); // Only works with graph_type

    ASSERT_EQ( 0,vdA0);
    ASSERT_EQ(1,vdA1);


    vertex_descriptor find0 = vertex(0, g);
    vertex_descriptor find1 = vertex(1, g);


    ASSERT_EQ(vdA0,find0);
    ASSERT_EQ(vdA1,find1);


    ASSERT_NE(vdA0,find1);
    ASSERT_EQ(vdA0,find0);
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
TYPED_TEST(TestGraph, vertex_2) {
    typedef typename TestFixture::graph_type         graph_type;

    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    graph_type g; // only to test

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);


    // printVertices(g); // Only works with graph_type

    ASSERT_EQ( 0,vdA0);
    ASSERT_EQ(1,vdA1);


    vertex_descriptor find0 = vertex(0, g);
    vertex_descriptor find1 = vertex(1, g);


    ASSERT_EQ(vdA0,find0);
    ASSERT_EQ(vdA1,find1);


    ASSERT_NE(vdA0,find1);
    ASSERT_EQ(vdA0,find0);
}
TYPED_TEST(TestGraph, vertex_3) {
    typedef typename TestFixture::graph_type         graph_type;

    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    graph_type g; // only to test

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);


    // printVertices(g); // Only works with graph_type

    ASSERT_EQ( 0,vdA0);
    ASSERT_EQ(1,vdA1);


    vertex_descriptor find0 = vertex(vdA0, g);
    vertex_descriptor find1 = vertex(vdA1, g);


    ASSERT_EQ(vdA0,find0);
    ASSERT_EQ(vdA1,find1);


    ASSERT_NE(vdA0,find1);
    ASSERT_EQ(vdA0,find0);
}

TYPED_TEST(TestGraph, Vertex_4) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);


    vertex_descriptor vd = vertex(0, g);
    vertex_descriptor vd1 = vertex(1, g);
    ASSERT_EQ(vdA, vd);
    ASSERT_EQ(vdA1, vd1);




    vertex_descriptor vd_test = vertex(1, g);
    ASSERT_EQ(1,vd_test);

    vertices_size_type vs = num_vertices(g);
    ASSERT_EQ(2, vs);}



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

TYPED_TEST(TestGraph, num_vertices_2) {
    typedef typename TestFixture::graph_type         graph_type;

    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    typedef typename TestFixture::vertices_size_type vertices_size_type;


    graph_type g; // only to test


    vertices_size_type vs = num_vertices(g);
  
    ASSERT_EQ(0, vs);
}


TYPED_TEST(TestGraph, num_vertices_3) {
    typedef typename TestFixture::graph_type         graph_type;

    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    typedef typename TestFixture::vertices_size_type vertices_size_type;


    graph_type g; // only to test

    vertex_descriptor vdA = add_vertex(g);
    vertices_size_type vs = num_vertices(g);
  
    ASSERT_EQ(1, vs);
}


TYPED_TEST(TestGraph, num_vertices_4) {
    typedef typename TestFixture::graph_type         graph_type;

    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;

    typedef typename TestFixture::vertices_size_type vertices_size_type;


    graph_type g; // only to test

    for(int i =0; i <100 ; ++i)
        add_vertex(g);
    vertices_size_type vs = num_vertices(g);
  
    ASSERT_EQ(100, vs);
}







  

TYPED_TEST(TestGraph, source_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    add_edge(vdA1, vdA6, g);
    ASSERT_EQ(6, num_edges(g));

    
    vertex_descriptor vd1 = source(e4, g);
    ASSERT_EQ(vdA5, vd1);


}

TYPED_TEST(TestGraph, source_2) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    edge_descriptor e1= add_edge(vdA1, vdA4, g).first;//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    add_edge(vdA1, vdA6, g);
    ASSERT_EQ(6, num_edges(g));

    
    vertex_descriptor vd1 = source(e3, g);
    ASSERT_EQ(vdA3, vd1);


}


TYPED_TEST(TestGraph, source_3) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    edge_descriptor e1 = add_edge(vdA1, vdA4, g).first;//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    add_edge(vdA1, vdA6, g);
    ASSERT_EQ(6, num_edges(g));

    
    vertex_descriptor vd1 = source(e1, g);
    ASSERT_EQ(vdA1, vd1);


}


TYPED_TEST(TestGraph, target_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    add_edge(vdA1, vdA6, g);
    ASSERT_EQ(6, num_edges(g));


 
    vertex_descriptor vd2 = target(e3, g);
    ASSERT_EQ(vdA6, vd2);


}


TYPED_TEST(TestGraph, target_2) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    edge_descriptor e1 = add_edge(vdA1, vdA4, g).first;//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    add_edge(vdA1, vdA6, g);
    ASSERT_EQ(6, num_edges(g));


 
    vertex_descriptor vd2 = target(e1, g);
    ASSERT_EQ(vdA4, vd2);

}

TYPED_TEST(TestGraph, target_3) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    edge_descriptor e5 = add_edge(vdA1, vdA6, g).first;
    ASSERT_EQ(6, num_edges(g));


 
    vertex_descriptor vd2 = target(e5, g);
    ASSERT_EQ(vdA6, vd2);

}


TYPED_TEST(TestGraph, vertices_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    std::pair<vertex_iterator, vertex_iterator> p = vertices(g);
    vertex_iterator                             b = p.first;
    vertex_iterator                             e = p.second;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdA, vd);}
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdB, vd);}
    ++b;
    ASSERT_EQ(e, b);}


    TYPED_TEST(TestGraph, vertices_2) {
        typedef typename TestFixture::graph_type         graph_type;
        typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
        typedef typename TestFixture::edge_descriptor    edge_descriptor;
        typedef typename TestFixture::vertex_iterator    vertex_iterator;
        typedef typename TestFixture::edge_iterator      edge_iterator;
        typedef typename TestFixture::adjacency_iterator adjacency_iterator;
        typedef typename TestFixture::vertices_size_type vertices_size_type;
        typedef typename TestFixture::edges_size_type    edges_size_type;

        graph_type g;

        vertex_descriptor vdA0 = add_vertex(g);
        vertex_descriptor vdA1 = add_vertex(g);
        vertex_descriptor vdA2 = add_vertex(g);
        vertex_descriptor vdA3 = add_vertex(g);
        vertex_descriptor vdA4 = add_vertex(g);
        vertex_descriptor vdA5 = add_vertex(g);
        vertex_descriptor vdA6 = add_vertex(g);


        auto b = vertices(g).first;
        auto e = vertices(g).second;

        int i = 0 ;
        while( b != e && i < 4){
            ASSERT_EQ(i, *b);
            ++b;
            ++i;

            }
    }   



    TYPED_TEST(TestGraph, vertices_3) {
        typedef typename TestFixture::graph_type         graph_type;
        typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
        typedef typename TestFixture::edge_descriptor    edge_descriptor;
        typedef typename TestFixture::vertex_iterator    vertex_iterator;
        typedef typename TestFixture::edge_iterator      edge_iterator;
        typedef typename TestFixture::adjacency_iterator adjacency_iterator;
        typedef typename TestFixture::vertices_size_type vertices_size_type;
        typedef typename TestFixture::edges_size_type    edges_size_type;

        graph_type g;
        // Graph g;

        for (int i =0 ; i < 1000 ; ++i)
            add_vertex(g);
 


        auto b = vertices(g).first;
        auto e = vertices(g).second;

        int i = 0 ;
        while( b != e){
            ASSERT_EQ(i, *b);
            ++b;
            ++i;

            }
    }  

TYPED_TEST(TestGraph, vertex_iterator_constructor_1 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);


    auto b = vertices(g).first;
    auto e = vertices(g).second;

    int i =0;
    while( b != e ){
        ASSERT_EQ(i, *b);
        ++b;
        ++i;

    }

}


TYPED_TEST(TestGraph, vertex_iterator_constructor_2 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);


    auto b = vertices(g).first;

    ASSERT_EQ(vdA0, *b);

}


TYPED_TEST(TestGraph, vertex_iterator_constructor_3 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);


    auto e = vertices(g).second;
    --e;
    ASSERT_EQ(vdA1, *e);

}







TYPED_TEST(TestGraph, vertex_iterator_plusplus_1 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);


    auto b = vertices(g).first;
    auto e = vertices(g).second;

    int i =0;
    while( b != e ){
        // cout << *b << " " ; 
        ASSERT_EQ(i, *b);
        ++b;
        ++i;

    }

}


TYPED_TEST(TestGraph, vertex_iterator_plusplus_2 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);


    auto b = vertices(g).first;

    ++b;
    b++;
        ASSERT_EQ(vdA2, *b);


}


TYPED_TEST(TestGraph, vertex_iterator_plusplus_3 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);


    auto b = vertices(g).first;

    ++b;
    b++;
    b++;
    ++b;
        ASSERT_EQ(vdA4, *b);


}

TYPED_TEST(TestGraph, vertex_iterator_minuminus_1 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);


    auto b = vertices(g).first;
    auto e = vertices(g).second;

    int i =6;
    --e;
    while( b != e ){
        ASSERT_EQ(i, *e);
        --e;
        --i;

    }

}


TYPED_TEST(TestGraph, vertex_iterator_minuminus_2 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);


    auto e = vertices(g).second;
    --e;
    e--;
        ASSERT_EQ(vdA5, *e);

}


TYPED_TEST(TestGraph, vertex_iterator_minuminus_3 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);


    auto e = vertices(g).second;
    --e;
    e--;
    --e;
    e--;
        ASSERT_EQ(vdA3, *e);

}


TYPED_TEST(TestGraph, vertex_iterator_plusequal_1 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);


    auto b = vertices(g).first;

        b+= 6;
        ASSERT_EQ(6, *b);

}


TYPED_TEST(TestGraph, vertex_iterator_plusequal_2 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    for(int i = 0; i < 1000 ; ++i)
        add_vertex(g);


    auto b = vertices(g).first;

        b+= 999;
        ASSERT_EQ(999, *b);

}


TYPED_TEST(TestGraph, vertex_iterator_plusequal_3 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    for(int i = 0; i < 1000 ; ++i)
        add_vertex(g);


    auto b = vertices(g).first;

        b+= 999;
        ASSERT_NE(993, *b);
        ASSERT_NE(998, *b);
        ASSERT_NE(1000, *b);
        ASSERT_EQ(999, *b);

}

TYPED_TEST(TestGraph, vertex_iterator_minusequal_1 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);


    auto e = vertices(g).second;

        e-= 7;
        ASSERT_EQ(0, *e);

}


TYPED_TEST(TestGraph, vertex_iterator_minusequal_2 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);


    auto e = vertices(g).second;

        e-= 6;
        ASSERT_EQ(1, *e);

}


TYPED_TEST(TestGraph, vertex_iterator_minusequal_3 ) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);


    auto e = vertices(g).second;

        e-= 3;
        ASSERT_EQ(4, *e);

}


  TYPED_TEST(TestGraph, add_edge_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    pair<edge_descriptor, bool> s = add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(false, s.second);

    // printEdges(g);

    // printGraph(g); //prints adjacency list

}


  TYPED_TEST(TestGraph, add_edge_2) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge

    pair<edge_descriptor, bool> s = add_edge(vdA5, vdA6, g);// Does not exist

    ASSERT_EQ(true, s.second);


}



  TYPED_TEST(TestGraph, add_edge_3) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    add_edge(vdA5, vdA6, g);
    pair<edge_descriptor, bool> s = edge(vdA5, vdA6, g);// Does  exist

    ASSERT_EQ(true, s.second);


}

TYPED_TEST(TestGraph, edge_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA5, vdA6, g);// Already Exist!

    std::pair<edge_descriptor, bool> p2 = edge(vdA5, vdA6, g);
    ASSERT_EQ(e4, p2.first);
    ASSERT_EQ(true, p2.second);

    // printEdges(g);

    // printGraph(g); //prints adjacency list

}

TYPED_TEST(TestGraph, edge_2) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    edge_descriptor e2 = add_edge(vdA2, vdA3, g).first;//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA5, vdA6, g);// Already Exist!

    std::pair<edge_descriptor, bool> p2 = edge(vdA2, vdA3, g);
    ASSERT_EQ(e2, p2.first);
    ASSERT_EQ(true, p2.second);


}

TYPED_TEST(TestGraph, edge_3) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;

    std::pair<edge_descriptor, bool> p1 = add_edge(vdA, vdB, g);
    ASSERT_EQ(edAB,  p1.first);
    ASSERT_EQ(false, p1.second);

    std::pair<edge_descriptor, bool> p2 = edge(vdA, vdB, g);
    ASSERT_EQ(edAB, p2.first);
    ASSERT_EQ(true, p2.second);

}


TYPED_TEST(TestGraph, num_edges_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    add_edge(vdA1, vdA6, g);
    ASSERT_EQ(6, num_edges(g));

    // printEdges(g);

    // printGraph(g); //prints adjacency list

}


TYPED_TEST(TestGraph, num_edges_2) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge


    ASSERT_EQ(2, num_edges(g));



}


TYPED_TEST(TestGraph, num_edges_3) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);
    ASSERT_EQ(0, num_edges(g));
}

TYPED_TEST(TestGraph, edge_iterator_constructor_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    edge_descriptor e0 = add_edge(vdA0, vdA1, g).first; //0 edge
    edge_descriptor e1 = add_edge(vdA1, vdA4, g).first;//1 edge
    edge_descriptor e2 = add_edge(vdA2, vdA3, g).first;//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge


    auto  b = edges(g).first;
        ASSERT_EQ(e0, (*b) ) ;

}


TYPED_TEST(TestGraph, edge_iterator_plusplus_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    edge_descriptor e0 = add_edge(vdA0, vdA1, g).first; //0 edge
    edge_descriptor e1 = add_edge(vdA1, vdA4, g).first;//1 edge
    edge_descriptor e2 = add_edge(vdA2, vdA3, g).first;//2 edge
    edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    edge_descriptor e5 = add_edge(vdA1, vdA6, g).first;
    ASSERT_EQ(6, num_edges(g));

    auto  b = edges(g).first;

        ASSERT_EQ(e0, (*b) ) ;
        ++b;

        ASSERT_EQ(e1, *b);
        
        ++b;

        ASSERT_EQ(e5, *b);
        ++b;

        ASSERT_EQ(e2, *b);
        ++b;

        ASSERT_EQ(e3, *b);
        ++b;

        ASSERT_EQ(e4, *b);
        ++b;


}






TYPED_TEST(TestGraph, edges_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    edge_descriptor edAB = add_edge(vdA, vdB, g).first;
    edge_descriptor edAC = add_edge(vdA, vdC, g).first;

    std::pair<edge_iterator, edge_iterator> p = edges(g);
    edge_iterator                           b = p.first;
    edge_iterator                           e = p.second;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(edAB, ed);}
    ++b;
    if (b != e) {
        edge_descriptor ed = *b;
        ASSERT_EQ(edAC, ed);}
    ++b;
    ASSERT_EQ(e, b);}

TYPED_TEST(TestGraph, Adjacent_Vertices) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA = add_vertex(g);
    vertex_descriptor vdB = add_vertex(g);
    vertex_descriptor vdC = add_vertex(g);

    add_edge(vdA, vdB, g);
    add_edge(vdA, vdC, g);

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA, g);
    adjacency_iterator b = p.first;
    adjacency_iterator e = p.second;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdB, vd);
    }
    ++b;
    if (b != e) {
        vertex_descriptor vd = *b;
        ASSERT_EQ(vdC, vd);}
    ++b;
    ASSERT_EQ(e, b);


}

TYPED_TEST(TestGraph, iterator_adjacent_vertices_constructor_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    add_edge(vdA3, vdA6, g);//3 edge
    add_edge(vdA5, vdA6, g);//4 

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    add_edge(vdA1, vdA6, g).first;
    ASSERT_EQ(6, num_edges(g));

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA1, g);
    adjacency_iterator b = p.first;
    adjacency_iterator e = p.second;
    
    ASSERT_EQ(vdA4, *b);


}



TYPED_TEST(TestGraph, iterator_adjacent_vertices_plusplus_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    // edge_descriptor e0 = add_edge(vdA0, vdA1, g).first; //0 edge
    // edge_descriptor e1 = add_edge(vdA1, vdA4, g).first;//1 edge
    // edge_descriptor e2 = add_edge(vdA2, vdA3, g).first;//2 edge
    // edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    // edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    add_edge(vdA3, vdA6, g);//3 edge
    add_edge(vdA5, vdA6, g);//4 

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    add_edge(vdA1, vdA6, g).first;
    ASSERT_EQ(6, num_edges(g));

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA1, g);
    adjacency_iterator b = p.first;

    
    // cout << *b << endl;
    ASSERT_EQ(vdA4, *b);
    ++b;

    ASSERT_EQ(vdA6, *b);

}


TYPED_TEST(TestGraph, iterator_adjacent_vertices_plusequal_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    // edge_descriptor e0 = add_edge(vdA0, vdA1, g).first; //0 edge
    // edge_descriptor e1 = add_edge(vdA1, vdA4, g).first;//1 edge
    // edge_descriptor e2 = add_edge(vdA2, vdA3, g).first;//2 edge
    // edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    // edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    add_edge(vdA3, vdA6, g);//3 edge
    add_edge(vdA5, vdA6, g);//4 

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    add_edge(vdA1, vdA6, g).first;

    add_edge(vdA1, vdA5, g).first;


    ASSERT_EQ(7, num_edges(g));

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA1, g);
    adjacency_iterator b = p.first;

    
    // cout << *b << endl;
    ASSERT_EQ(vdA4, *b);
    ++b;
    ASSERT_EQ(vdA5, *b);
    ++b;
    ASSERT_EQ(vdA6, *b);
    

    

}


TYPED_TEST(TestGraph, iterator_adjacent_vertices_minuminus_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    add_edge(vdA3, vdA6, g);//3 edge
    add_edge(vdA5, vdA6, g);//4 

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    add_edge(vdA1, vdA6, g).first;
    ASSERT_EQ(6, num_edges(g));

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA1, g);
    adjacency_iterator e = p.second;

    --e;
    // cout << *b << endl;
    ASSERT_EQ(vdA6, *e);
    --e;

    ASSERT_EQ(vdA4, *e);

}


TYPED_TEST(TestGraph, iterator_adjacent_vertices_minusequal_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    add_edge(vdA3, vdA6, g);//3 edge
    add_edge(vdA5, vdA6, g);//4 

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    add_edge(vdA1, vdA6, g).first;
    ASSERT_EQ(6, num_edges(g));

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA1, g);
    adjacency_iterator e = p.second;

    --e;


    ASSERT_EQ(vdA6, *e);

}



TYPED_TEST(TestGraph, iterator_adjacent_vertices_1) {
    typedef typename TestFixture::graph_type         graph_type;
    typedef typename TestFixture::vertex_descriptor  vertex_descriptor;
    typedef typename TestFixture::edge_descriptor    edge_descriptor;
    typedef typename TestFixture::vertex_iterator    vertex_iterator;
    typedef typename TestFixture::edge_iterator      edge_iterator;
    typedef typename TestFixture::adjacency_iterator adjacency_iterator;
    typedef typename TestFixture::vertices_size_type vertices_size_type;
    typedef typename TestFixture::edges_size_type    edges_size_type;

    graph_type g;
    // Graph g;

    vertex_descriptor vdA0 = add_vertex(g);
    vertex_descriptor vdA1 = add_vertex(g);
    vertex_descriptor vdA2 = add_vertex(g);
    vertex_descriptor vdA3 = add_vertex(g);
    vertex_descriptor vdA4 = add_vertex(g);
    vertex_descriptor vdA5 = add_vertex(g);
    vertex_descriptor vdA6 = add_vertex(g);

    // edge_descriptor e0 = add_edge(vdA0, vdA1, g).first; //0 edge
    // edge_descriptor e1 = add_edge(vdA1, vdA4, g).first;//1 edge
    // edge_descriptor e2 = add_edge(vdA2, vdA3, g).first;//2 edge
    // edge_descriptor e3 = add_edge(vdA3, vdA6, g).first;//3 edge
    // edge_descriptor e4 = add_edge(vdA5, vdA6, g).first;//4 edge

    add_edge(vdA0, vdA1, g); //0 edge
    add_edge(vdA1, vdA4, g);//1 edge
    add_edge(vdA2, vdA3, g);//2 edge
    add_edge(vdA3, vdA6, g);//3 edge
    add_edge(vdA5, vdA6, g);//4 

    add_edge(vdA5, vdA6, g);// Already Exist!

    ASSERT_EQ(5, num_edges(g));

    add_edge(vdA1, vdA6, g).first;
    ASSERT_EQ(6, num_edges(g));

    std::pair<adjacency_iterator, adjacency_iterator> p = adjacent_vertices(vdA1, g);
    adjacency_iterator b = p.first;
    adjacency_iterator e = p.second;

    
    // cout << *b << endl;
    ASSERT_EQ(vdA4, *b);
    ++b;
    // cout << *b << endl;

    ASSERT_EQ(vdA6, *b);

    // ++b;
    //     cout << *b << endl;

    // ASSERT_EQ(vdA6, *b);
    std::pair<edge_iterator, edge_iterator> ed = edges(g);
    edge_iterator                           be = ed.first;
    edge_iterator                           ee = ed.second;

    // while(be != ee){
    //     cout << *be << " ";
    //     ++be;
    // }
    // cout << endl;



    // printEdges(g);

    // printGraph(g);

}
