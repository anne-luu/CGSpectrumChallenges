#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node
{
    string name;
    int currentCost;
    bool hasVisited;
    unordered_map<Node*, int> neighbors;

    Node(string n)
        :name(n)
        ,currentCost(0)
        ,hasVisited(false)
    {

    }
};

//Comparator will order list in ascending order as default
class CompareNodes
{
    bool reverse;
public:
    CompareNodes(const bool& revparam = false)
    {
        reverse = revparam;
    }
    bool operator() (const Node* lhs, const Node* rhs) const
    {
        if (reverse) return (lhs->currentCost < rhs->currentCost);
        else return (lhs->currentCost > rhs->currentCost);
    }
};

void BreadthFirstSearch(Node* start, Node* dest);
void DijkstraAlgorithm(Node* start, Node* dest);
void A_Star(Node* start, Node* dest);
int heuristic(Node* a, Node* b);

int main()
{
    //Create nodes
    Node a("A");
    Node b("B");
    Node c("C");
    Node d("D");

    //Add edges
    a.neighbors[&b] = 5;
    a.neighbors[&d] = 7;
    b.neighbors[&c] = 1;
    c.neighbors[&d] = 1;

    BreadthFirstSearch(&a, &c);
    
    cout << endl << endl;

    DijkstraAlgorithm(&a, &c);

    cout << endl << endl;

    A_Star(&a, &c);
}

void BreadthFirstSearch(Node* start, Node* dest)
{
    queue<Node*> frontier;
    frontier.push(start);
    unordered_map<Node*, Node*> came_from;

    while (!frontier.empty())
    {
        cout << "Visiting node " << frontier.front()->name << endl;

        if (dest == frontier.front())
        {
            cout << "Reached Destination" << endl;
            break;
        }

        //Add neighbors to the queue
        for (auto& neighbor : frontier.front()->neighbors)
        {
            cout << neighbor.first->name << endl;
            //Check if neighbor was visited and if path
            if (!neighbor.first->hasVisited && came_from.find(neighbor.first) == came_from.end())
            {
                frontier.push(neighbor.first);
                came_from[neighbor.first] = frontier.front();
            }
        }

        //Remove visited node
        frontier.front()->hasVisited = true;
        frontier.pop();
    }

    //Trace path
    Node* trace = dest;

    while (trace != start)
    {
        cout << trace->name << "<-";
        trace = came_from[trace];
    }

    cout << trace->name << endl;
}

void DijkstraAlgorithm(Node* start, Node* dest)
{
    priority_queue<Node*, vector<Node*>, CompareNodes> frontier;
    frontier.push(start);
    unordered_map<Node*, Node*> came_from;
    unordered_map<Node*, int> cost_so_far;
    cost_so_far[start] = 0;

    while (!frontier.empty())
    {
        cout << "Visiting node " << frontier.top()->name << endl;

        if (dest == frontier.top())
        {
            cout << "Reached Destination" << endl;
            break;
        }

        //Need to store reference to top as it will change if priority queue top changes in below logic
        Node* currentTop = frontier.top();

        //Add neighbors to the queue
        for (auto& neighbor : currentTop->neighbors)
        {
            cout << neighbor.first->name << endl;

            int new_cost = cost_so_far[currentTop] + neighbor.second;
            cout << "New Cost: " << new_cost << endl;
            
            if (cost_so_far.find(neighbor.first) == cost_so_far.end() || new_cost < cost_so_far[neighbor.first])
            {
                cost_so_far[neighbor.first] = new_cost;
                neighbor.first->currentCost = new_cost;
                frontier.push(neighbor.first);
                came_from[neighbor.first] = currentTop;
            }            
        }

        //Remove top node
        frontier.top()->hasVisited = true;
        frontier.pop();
    }

    //Trace path
    Node* trace = dest;

    while (trace != start)
    {
        cout << trace->name << "<-";
        trace = came_from[trace];
    }

    cout << trace->name << endl;
}

void A_Star(Node* start, Node* dest)
{
    priority_queue<Node*, vector<Node*>, CompareNodes> frontier;
    frontier.push(start);
    unordered_map<Node*, Node*> came_from;

    while (!frontier.empty())
    {
        cout << "Visiting node " << frontier.top()->name << endl;

        if (dest == frontier.top())
        {
            cout << "Reached Destination" << endl;
            break;
        }

        //Need to store reference to top as it will change if priority queue top changes in below logic
        Node* currentTop = frontier.top();

        //Add neighbors to the queue
        for (auto& neighbor : currentTop->neighbors)
        {
            cout << neighbor.first->name << endl;

            if (came_from.find(neighbor.first) == came_from.end())
            {
                int priority = heuristic(dest, neighbor.first);
                frontier.push(neighbor.first);
                came_from[neighbor.first] = currentTop;
            }
        }

        //Remove top node
        frontier.top()->hasVisited = true;
        frontier.pop();
    }

    //Trace path
    Node* trace = dest;

    while (trace != start)
    {
        cout << trace->name << "<-";
        trace = came_from[trace];
    }

    cout << trace->name << endl;
}

int heuristic(Node* a, Node* b)
{
    //Return 0 as there is no heuristic to calculate on this graph
    return 0;
}