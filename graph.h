#ifndef _graph_h
#define _graph_h
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#include "hashTable.h"
#include "point2D.h"
#include "priorityQueuePoint2D.h"

typedef Point2D graphType;

typedef struct Vertex
{
    graphType data;
    bool visited;   /* store whether this vertex has been visited */

    /* the successors are stored in the matrix at this index */
    int index;
    int currentSuccessorIndex;
    int currentPredecessorIndex;

}  Vertex;

typedef struct Graph
{
    hashTable* vertexTable;
    Vertex* vertexArray;
    int numVertices;
    int capacity;

    /* weights of edges are stored in this matrix (-1 if edge isn't present) */
    double** adjacencyMatrix;

    bool changed;           /* check for changes to know whether paths needs to be updated */
    int** pathsArray;       /* keep list of next vertex to visit on shortest path */
    double** distance;      /* shortest path distance between the pair of vertices */

}  Graph;

Graph* createGraph( int numVertex ); // creates an empty graph of size numVertex
void freeGraph( Graph* g );

void addVertex( Graph* g, graphType p );
bool isVertex( Graph* g, graphType p );
bool getVertexByIndex( Graph* g, int index, graphType* next );

void setEdge( Graph* g, graphType p1, graphType p2, double value );
double getEdge( Graph* g, graphType p1, graphType p2 );

bool getSuccessor( Graph* g, graphType start, graphType* pnext );
bool getPredecessor( Graph* g, graphType start, graphType* pprev );

void setVisited( Graph* g, graphType p, bool value );
bool getVisited( Graph* g, graphType p ); 

void setDistance( Graph* g, graphType from, graphType to, double dist ); // sets the distance from 'from' to 'to'
double getDistance( Graph* g, graphType from, graphType to ); // returns the distance from 'from' to 'to' or INT_MAX if there is no path

void dijkstrasAlg( Graph* g, graphType start ); // dijkstras algorithm for shortest path search

#endif
