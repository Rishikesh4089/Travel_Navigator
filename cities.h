#include <iostream>
#include <string>

using namespace std;

const int max_v = 100;  // Maximum number of vertices

class Graph {
public:
    int v;
    int adj[max_v][max_v];
    string ind_name[max_v];
    int name_ind[max_v];
    int days[max_v];

    Graph(){
        v = 0;
        for (int i = 0; i < max_v; i++) {
            ind_name[i] = "";
            name_ind[i] = -1;
            for (int j = 0; j < max_v; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addNode(string label, int x) {
        if (v < max_v) {
            name_ind[v] = v;
            ind_name[v] = label;
            days[v] = x;
            v++;
        } else {
            cout << "Graph has reached its maximum capacity." << endl;
        }
    }

    int getIndexFromLabel(string label) {
        for (int i = 0; i < v; i++) {
            if (ind_name[i] == label) {
                return i;
            }
        }
        return -1;
    }

    void addEdge(string u, string v, int weight) {
        int uIndex = getIndexFromLabel(u);
        int vIndex = getIndexFromLabel(v);
        if (uIndex != -1 && vIndex != -1) {
            adj[uIndex][vIndex] = weight;
            adj[vIndex][uIndex] = weight;
        }
    }

    void createMap() {

        addNode("Rajasthan", 8);
        addNode("Jaisalmer", 3);
        addNode("Jodhpur", 2);
        addNode("Udaipur", 3);
        addNode("Himachal Pradesh", 9);
        addNode("Shimla", 3);
        addNode("Kullu", 3);
        addNode("Manali", 3);
        addNode("Jammu&Kashmir", 10);
        addNode("Leh Ladakh", 4);
        addNode("Gulmarg", 3);
        addNode("Srinagar", 3);

        addEdge("Rajasthan", "Udaipur", 350);
        addEdge("Rajasthan", "Jodhpur", 300);
        addEdge("Rajasthan", "Jaisalmer", 500);
        addEdge("Rajasthan", "Jammu&Kashmir", 700);
        addEdge("Rajasthan", "Himachal Pradesh", 600);
        addEdge("Jammu&Kashmir", "Himachal Pradesh", 300);
        addEdge("Udaipur", "Jodhpur", 250);
        addEdge("Jaisalmer", "Jodhpur", 300);
        addEdge("Udaipur", "Jaisalmer", 500);
        addEdge("Jammu&Kashmir", "Srinagar", 200);
        addEdge("Jammu&Kashmir", "Leh Ladakh", 300);
        addEdge("Jammu&Kashmir", "Gulmarg", 200);
        addEdge("Srinagar", "Gulmarg", 50);
        addEdge("Leh Ladakh", "Gulmarg", 450);
        addEdge("Leh Ladakh", "Srinagar", 400);
        addEdge("Himachal Pradesh", "Shimla", 200);
        addEdge("Himachal Pradesh", "Kullu", 50);
        addEdge("Himachal Pradesh", "Manali", 50);
        addEdge("Kullu", "Shimla", 200);
        addEdge("Manali", "Shimla", 250);
        addEdge("Kullu", "Manali", 50);
    }
};

