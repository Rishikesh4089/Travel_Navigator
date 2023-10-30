#include <iostream>
#include <string>

using namespace std;

const int max_v = 100; 

class Graph {
public:
    int name_ind[max_v],days[max_v], adj[max_v][max_v], v, totalWeight;
    string ind_name[max_v];

    Graph(){
        v = 0;
        totalWeight = 0;
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

        addNode("Jaisalmer", 3);
        addNode("Jodhpur", 2);
        addNode("Udaipur", 3);
        addNode("Shimla", 3);
        addNode("Rishikesh", 3);
        addNode("Manali", 3);
        addNode("Leh Ladakh", 4);
        addNode("Gulmarg", 3);
        addNode("Srinagar", 3);

        addEdge("Srinagar", "Jaisalmer", 350);
        addEdge("Rishikesh", "Jaisalmer", 800);
        addEdge("Rishikesh", "Srinagar", 750);
        addEdge("Jaisalmer", "Udaipur", 500);
        addEdge("Jaisalmer", "Jodhpur", 300);
        addEdge("Udaipur", "Jodhpur", 250);
        addEdge("Srinagar", "Gulmarg", 50);
        addEdge("Leh Ladakh", "Gulmarg", 450);
        addEdge("Leh Ladakh", "Srinagar", 400);
        addEdge("Rishikesh", "Shimla", 250);
        addEdge("Manali", "Shimla", 250);
        addEdge("Rishikesh", "Manali", 500);
    }

    bool dfs(string start, string end, int max_days, int u, int totalDays, string &pathString) {
        int uIndex = getIndexFromLabel(start);
        int endIndex = getIndexFromLabel(end);

        if (uIndex == endIndex) {
            if (totalDays >= max_days - 5 && totalDays <= max_days) {
                pathString += "Path found with Total Days: " + to_string(totalDays) + "\n";
                return true;
            }
            return false;
        }

        for (int i = 0; i < v; i++) {
            if (adj[uIndex][i] != 0) {
                if (totalDays + days[i] <= max_days) {
                    if (dfs(ind_name[i], end, max_days, i, totalDays + days[i], pathString)) {
                        if (!pathString.empty()) {
                            pathString += " -> ";
                        }
                        pathString += ind_name[i]; 
                        totalWeight += adj[uIndex][i];
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfsBool(string start, string end, int max_days, int u, int totalDays) {
        int uIndex = getIndexFromLabel(start);
        int endIndex = getIndexFromLabel(end);

        if (uIndex == endIndex) {
            if (totalDays >= max_days - 5 && totalDays <= max_days) {
                totalWeight += adj[uIndex][endIndex];
                return true;
            }
            return false;
        }

        for (int i = 0; i < v; i++) {
            if (adj[uIndex][i] != 0) {
                if (totalDays + days[i] <= max_days) {
                    if (dfsBool(ind_name[i], end, max_days, i, totalDays + days[i])) {
                        totalWeight += adj[uIndex][i];
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool pathFinder(int max_days, string start, string end) {
        int startIndex = getIndexFromLabel(start);
        int endIndex = getIndexFromLabel(end);

        if (startIndex != -1 && endIndex != -1) {
            string pathString = start;
            if (dfs(start, end, max_days, startIndex, 0, pathString)) {
                cout << pathString << endl<<endl; 
                return true;
            }else if(pathString.empty()){
                cout<<"No tour with specified conditions available\n"<<endl;
                return false;
            }
        } else {
            cout << "Start or end location not found"<<endl;
        }
        return false;
    }

    bool pathFinderBool(int max_days, string start, string end) {
        int startIndex = getIndexFromLabel(start);
        int endIndex = getIndexFromLabel(end);

        if (startIndex != -1 && endIndex != -1) {
            string pathString = start;
            if (dfsBool(start, end, max_days, startIndex, 0)) {
                return true;
            }else if(pathString.empty()){
                return false;
            }
        }
        return false;
    }
};

