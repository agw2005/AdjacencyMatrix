#include <iostream>
#include <vector>

struct Node {
    int data; //The value of each node
};

struct Graph {
    std::vector<Node> nodes; //Store each node's value for more elegant print()
    int** matrix; //THE matrix (Array of pointers (The column) that points to an array (The row))
    //Non-dynamically allocated matrix cannot be declared without initialization, hence I used int** matrix
    int size; //THE matrix's size

    //Allocates memory for the 2D array
    Graph(int size) : size(size) {
        matrix = new int*[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new int[size]();
        }
    }

    //Destructor to deallocate the matrix (ChatGPT suggested to prevent memory leak)
    ~Graph() {
        for (int i = 0; i < size; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    //Add new node into vector nodes
    void addNode(int flag) {
        Node* temp = new Node();
        temp->data = flag;
        nodes.push_back(*temp);
    }

    //Add an edge (1 = there is an edge, 0 = no edge)
    void addEdge(int sourceColumn, int destinationRow, int weight) {
        if (sourceColumn >= 0 && sourceColumn < size && destinationRow >= 0 && destinationRow < size) {
            matrix[sourceColumn][destinationRow] = weight;
        }
    }

    //Check if an edge exists
    bool checkEdge(int sourceColumn, int destinationRow) {
        if (sourceColumn >= 0 && sourceColumn < size && destinationRow >= 0 && destinationRow < size) {
            return matrix[sourceColumn][destinationRow] > 0;
        } else {
            return false;
        }
    }

    //1+1=2
    void print() {
        std::cout << "  ";
        for (const auto& node : nodes) {
            std::cout << node.data << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < size; ++i) {
            std::cout << nodes[i].data << " ";
            for (int j = 0; j < size; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph test(5);
    test.addNode(1); // Index of 0
    test.addNode(2); // Index of 1
    test.addNode(3); // Index of 2
    test.addNode(4); // Index of 3
    test.addNode(5); // Index of 4

    test.addEdge(0, 1,10); //Edge that connects A and B
    test.addEdge(0, 3,5); //Edge that connects B and C
    test.addEdge(1, 2,1); //...
    test.addEdge(1, 3,2);
    test.addEdge(2, 4,4);
    test.addEdge(3, 1,3);
    test.addEdge(3, 2,9);
    test.addEdge(3, 4,2);
    test.addEdge(4, 0,7);
    test.addEdge(4, 2,6);

    test.print();
}