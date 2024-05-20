#include <iostream>
#include <vector>

struct Node {
    char data; //The value of each node
};

struct Graph {
    std::vector<Node> nodes; //Store each node's value for more elegant print()
    int** matrix; //THE matrix (Array of pointers (The column) that points to an array (The row))
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
    void addNode(char flag) {
        Node* temp = new Node();
        temp->data = flag;
        nodes.push_back(*temp);
    }

    //Add an edge (1 = there is an edge, 0 = no edge)
    void addEdge(int sourceRow, int destinationColumn) {
        if (sourceRow >= 0 && sourceRow < size && destinationColumn >= 0 && destinationColumn < size) {
            matrix[sourceRow][destinationColumn] = 1;
        }
    }

    //Check if an edge exists
    bool checkEdge(int sourceRow, int destinationColumn) {
        if (sourceRow >= 0 && sourceRow < size && destinationColumn >= 0 && destinationColumn < size) {
            return matrix[sourceRow][destinationColumn] == 1;
        }
        return false;
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
    test.addNode('A'); // Index of 0
    test.addNode('B'); // Index of 1
    test.addNode('C'); // Index of 2
    test.addNode('D'); // Index of 3
    test.addNode('E'); // Index of 4

    test.addEdge(0, 1); //Edge that connects A and B
    test.addEdge(1, 2); //Edge that connects B and C
    test.addEdge(1, 4); //Bla bla bla
    test.addEdge(2, 3);
    test.addEdge(2, 4);
    test.addEdge(4, 1);
    test.addEdge(4, 2);

    test.print();
}