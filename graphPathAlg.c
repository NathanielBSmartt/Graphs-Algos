#include "graph.h"
#include "graphPathAlg.h"

/* printName
 * input: none
 * output: none
 *
 * Prints the name of the student who worked on this solution
 */
void printName()
{
    /* TODO : Fill in your names */
    printf("This solution was completed by:\n");
    printf("Nathaniel Bucknor-Smartt\n");
}

Graph *buildGraphx(array2D *maze /* and other parameters you find helpful */)
{

    Graph *graphMaze = createGraph(maze->length * maze->width + maze->length * maze->width);
    int i, j = 0;

    for (i = 0; i < maze->length; i++)
    {
        for (j = 0; j < maze->width; j++)
        {
            if (maze->array2D[i][j] == ' ' || maze->array2D[i][j] == 'S' || maze->array2D[i][j] == 'F')
            {
                Point2D curPoint = createPoint(i, j);
                addVertex(graphMaze, curPoint);

                if (i > 0 && (maze->array2D[i - 1][j] == ' ' || maze->array2D[i - 1][j] == 'S' || maze->array2D[i - 1][j] == 'F'))
                {
                    Point2D up = createPoint(i - 1, j);
                    setEdge(graphMaze, curPoint, up, 0);
                }
                else
                {
                    Point2D up = createPoint(i - 1, j);
                    setEdge(graphMaze, curPoint, up, 1);
                }
                if (j > 0 && (maze->array2D[i][j - 1] == ' ' || maze->array2D[i][j - 1] == 'S' || maze->array2D[i][j - 1] == 'F'))
                {
                    Point2D left = createPoint(i, j - 1);
                    setEdge(graphMaze, curPoint, left, 0);
                }
                else
                {
                    Point2D left = createPoint(i, j - 1);
                    setEdge(graphMaze, curPoint, left, 1);
                }
                if (i < maze->length - 1 && (maze->array2D[i + 1][j] == ' ' || maze->array2D[i + 1][j] == 'S' || maze->array2D[i + 1][j] == 'F'))
                {
                    Point2D down = createPoint(i + 1, j);
                    setEdge(graphMaze, curPoint, down, 0);
                }
                else
                {
                    Point2D down = createPoint(i + 1, j);
                    setEdge(graphMaze, curPoint, down, 1);
                }
                if (j < maze->width - 1 && (maze->array2D[i][j + 1] == ' ' || maze->array2D[i][j + 1] == 'S' || maze->array2D[i][j + 1] == 'F'))
                {
                    Point2D right = createPoint(i, j + 1);
                    setEdge(graphMaze, curPoint, right, 0);
                }
                else
                {
                    Point2D right = createPoint(i, j + 1);
                    setEdge(graphMaze, curPoint, right, 1);
                }
            }
            else
            {
                Point2D curPoint = createPoint(i, j);
                addVertex(graphMaze, curPoint);

                if (i > 0 && (maze->array2D[i - 1][j] == ' ' || maze->array2D[i - 1][j] == 'S' || maze->array2D[i - 1][j] == 'F'))
                {
                    Point2D up = createPoint(i - 1, j);
                    setEdge(graphMaze, curPoint, up, 0);
                }
                else
                {
                    Point2D up = createPoint(i - 1, j);
                    setEdge(graphMaze, curPoint, up, 1);
                }
                if (j > 0 && (maze->array2D[i][j - 1] == ' ' || maze->array2D[i][j - 1] == 'S' || maze->array2D[i][j - 1] == 'F'))
                {
                    Point2D left = createPoint(i, j - 1);
                    setEdge(graphMaze, curPoint, left, 0);
                }
                else
                {
                    Point2D left = createPoint(i, j - 1);
                    setEdge(graphMaze, curPoint, left, 1);
                }
                if (i < maze->length - 1 && (maze->array2D[i + 1][j] == ' ' || maze->array2D[i + 1][j] == 'S' || maze->array2D[i + 1][j] == 'F'))
                {
                    Point2D down = createPoint(i + 1, j);
                    setEdge(graphMaze, curPoint, down, 0);
                }
                else
                {
                    Point2D down = createPoint(i + 1, j);
                    setEdge(graphMaze, curPoint, down, 1);
                }
                if (j < maze->width - 1 && (maze->array2D[i][j + 1] == ' ' || maze->array2D[i][j + 1] == 'S' || maze->array2D[i][j + 1] == 'F'))
                {
                    Point2D right = createPoint(i, j + 1);
                    setEdge(graphMaze, curPoint, right, 0);
                }
                else
                {
                    Point2D right = createPoint(i, j + 1);
                    setEdge(graphMaze, curPoint, right, 1);
                }
            }
        }
    }
    return graphMaze;
}

/* OPTIONAL HELPER FUNCTION
 * buildGraph
 *
 * IMPORTANT NOTE: This is an entirely optional helper function which is only called by student implemented functions.
 * Creates a new graph to represent the given maze.
 */
Graph *buildGraph(array2D *maze /* and other parameters you find helpful */)
{
    // OPTIONAL TODO: Translate the given maze into a graph.  'X' represents impassable locations.  Only moves of up, down, left, and right are allowed.
    /* With the right parameters this can be used by all three functions below to build the graph representing their different maze problems. */
    /* HINT 1: To solve this, my solution used the functions createGraph and setEdge from graph.c */
    /* HINT 2: My solution also used createPoint from point2D.c */
    Graph *graphMaze = createGraph(maze->length * maze->width);
    int i, j = 0;

    for (i = 0; i < maze->length; i++)
    {
        for (j = 0; j < maze->width; j++)
        {
            if (maze->array2D[i][j] == ' ' || maze->array2D[i][j] == 'S' || maze->array2D[i][j] == 'F')
            {
                Point2D curPoint = createPoint(i, j);
                addVertex(graphMaze, curPoint);

                if (i > 0 && (maze->array2D[i - 1][j] == ' ' || maze->array2D[i - 1][j] == 'S' || maze->array2D[i - 1][j] == 'F'))
                {
                    Point2D up = createPoint(i - 1, j);
                    setEdge(graphMaze, curPoint, up, 1);
                }
                if (j > 0 && (maze->array2D[i][j - 1] == ' ' || maze->array2D[i][j - 1] == 'S' || maze->array2D[i][j - 1] == 'F'))
                {
                    Point2D left = createPoint(i, j - 1);
                    setEdge(graphMaze, curPoint, left, 1);
                }
                if (i < maze->length - 1 && (maze->array2D[i + 1][j] == ' ' || maze->array2D[i + 1][j] == 'S' || maze->array2D[i + 1][j] == 'F'))
                {
                    Point2D down = createPoint(i + 1, j);
                    setEdge(graphMaze, curPoint, down, 1);
                }
                if (j < maze->width - 1 && (maze->array2D[i][j + 1] == ' ' || maze->array2D[i][j + 1] == 'S' || maze->array2D[i][j + 1] == 'F'))
                {
                    Point2D right = createPoint(i, j + 1);
                    setEdge(graphMaze, curPoint, right, 1);
                }
            }
        }
    }
    return graphMaze;
}

/* hasPath
 * input: an array2D pointer to a maze
 * output: pathResult
 *
 * Detects whether a path exists from 'S' to 'F' in the graph. 'X' marks impassable regions.
 */
pathResult hasPath(array2D *maze)
{
    // TODO: Complete this function
    /* HINT 1: To solve this, my solution used the functions createGraph, freeGraph, setEdge, dijkstrasAlg, getDistance from graph.c */
    /* HINT 2: My solution also used createPoint from point2D.c */
    /* HINT 3: You might also consider using the new helper function buildGraph to build the graph representing maze. */

    Point2D start = createPoint(0, 0);
    Point2D finish = createPoint(0, 0);
    int i = 0;
    int j = 0;
    for (i = 0; i < maze->length; i++)
    {
        for (j = 0; j < maze->width; j++)
        {
            if (maze->array2D[i][j] == 'S')
            {
                start = createPoint(i, j);
                break;
            }
        }
        if (start.x == i && start.y == j)
        {
            break;
        }
    }

    for (i = 0; i < maze->length; i++)
    {
        for (j = 0; j < maze->width; j++)
        {
            if (maze->array2D[i][j] == 'F')
            {
                finish = createPoint(i, j);
                break;
            }
        }
        if (finish.x == i && finish.y == j)
        {
            break;
        }
    }

    Graph *mazeGraph = buildGraph(maze);

    dijkstrasAlg(mazeGraph, start);

    return (getDistance(mazeGraph, start, finish) == INT_MAX) ? PATH_IMPOSSIBLE : PATH_FOUND; /* TODO: Replace with PATH_FOUND or PATH_IMPOSSIBLE based on whether a path exists */
}

/* findNearestFinish
 * input: an array2D pointer to a maze, a pointer to an int
 * output: pathResult
 *
 * The maze contains one 'S' and multiple 'F's (1 or more).  'X' marks impassable regions.
 * Find the length of the shortest path to any 'F' from 'S' and return it in spDist.
 * If no 'F' is reachable set spDist to INT_MAX.
 */
pathResult findNearestFinish(array2D *maze, int *spDist)
{
    // TODO: Complete this function
    /* HINT 1: To solve this, my solution used the functions createGraph, freeGraph, setEdge, dijkstrasAlg, getDistance from graph.c */
    /* HINT 2: My solution also used createPoint from point2D.c */
    /* HINT 3: You might also consider using the new helper function buildGraph to build the graph representing maze. */

    Point2D start;
    Point2D *finish;
    int distanceTracker = INT_MAX;
    int numFinish = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    // Find the start
    for (i = 0; i < maze->length; i++)
    {
        for (j = 0; j < maze->width; j++)
        {
            if (maze->array2D[i][j] == 'S')
            {
                start = createPoint(i, j);
                break;
            }
        }
        if (start.x == i && start.y == j)
        {
            break;
        }
    }

    // Count the number of finishes
    for (i = 0; i < maze->length; i++)
    {
        for (j = 0; j < maze->width; j++)
        {
            if (maze->array2D[i][j] == 'F')
            {
                numFinish++;
            }
        }
    }

    // Create the finish array
    finish = (Point2D *)malloc(sizeof(Point2D) * numFinish);

    // Fill the finish array
    for (i = 0; i < maze->length; i++)
    {
        for (j = 0; j < maze->width; j++)
        {
            if (maze->array2D[i][j] == 'F')
            {
                finish[k] = createPoint(i, j);
                k++;
            }
        }
    }

    // Create the graph and update shortest paths
    Graph *mazeGraph = buildGraph(maze);
    dijkstrasAlg(mazeGraph, start);

    // find the shortest finish path
    for (k = 0; k < numFinish; k++)
    {
        if (getDistance(mazeGraph, start, finish[k]) <= distanceTracker)
        {
            distanceTracker = getDistance(mazeGraph, start, finish[k]);
        }
    }

    (*spDist) = distanceTracker;

    return (hasPath(maze)) ? PATH_FOUND : PATH_IMPOSSIBLE; /* TODO: Replace with PATH_FOUND or PATH_IMPOSSIBLE based on whether a path exists */
}

/* findTunnelRoute
 * input: an array2D pointer to a maze, an int representing the number X's you can travel through
 * output: pathResult
 *
 * Detects whether a path exists from 'S' to 'F' in the graph where you pass through at most k 'X' symbols.
 */
pathResult findTunnelRoute(array2D *maze, int k)
{
    // TODO: Complete this function
    /* HINT 1: To solve this, my solution used the functions createGraph, freeGraph, setEdge, dijkstrasAlg, getDistance from graph.c */
    /* HINT 2: My solution also used createPoint from point2D.c */
    /* HINT 3: You might also consider using the new helper function buildGraph to build the graph representing maze. */

    Point2D start;
    Point2D finish;
    int i, j = 0;

    // Find the start
    for (i = 0; i < maze->length; i++)
    {
        for (j = 0; j < maze->width; j++)
        {
            if (maze->array2D[i][j] == 'S')
            {
                start = createPoint(i, j);
                break;
            }
        }
        if (start.x == i && start.y == j)
        {
            break;
        }
    }

    // find the finish
    for (i = 0; i < maze->length; i++)
    {
        for (j = 0; j < maze->width; j++)
        {
            if (maze->array2D[i][j] == 'F')
            {
                finish = createPoint(i, j);
                break;
            }
        }
        if (finish.x == i && finish.y == j)
        {
            break;
        }
    }

    // build the graph
    Graph *mazeGraph = buildGraphx(maze);
    dijkstrasAlg(mazeGraph, start);

    return (k <= getDistance(mazeGraph, start, finish) - 1) ? PATH_IMPOSSIBLE : PATH_FOUND; /* TODO: Replace with PATH_FOUND or PATH_IMPOSSIBLE based on whether a path exists */
}
