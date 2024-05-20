#include <iostream>
#include <vector>

struct Node {
    std::string data; //The name of each node
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

    //Add new node into vector nodes
    void addNode(std::string flag) {
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
    int N;
    std::string identifier;
    int vertexMenu,source,destination,weight;
    std::cout<<"How many vertices are there?\n";
    std::cin>>N;
    Graph test(N);
    for(int i = 1 ; i <= N ; i++){
        std::cout<<"What is the identifier for vertex-"<<i<<"?\n";
        std::cin>>identifier;
        test.addNode(identifier);
    }

    bool isRunning{true};
    do{
        std::cout<<"Which vertex do you want the vertex to start?\n";
        for(int i = 0 ; i < N ; i++){
            std::cout<<i+1<<". "<<test.nodes[i].data<<std::endl;
        }
        std::cout<<"0. There is no more vertex to add\n";
        std::cin>>vertexMenu;
        if(vertexMenu == 0){
            isRunning = false;
        } else{
            source = vertexMenu-1;
            std::cout<<"Where does this edge ends?\n";
            for(int i = 0 ; i < N ; i++){
                std::cout<<i+1<<". "<<test.nodes[i].data<<std::endl;
            }
            std::cin>>destination;
            destination--;
            std::cout<<"What is the weight of this edge?\n";
            std::cin>>weight;
            test.addEdge(source,destination,weight);
        }
    }while(isRunning);

    test.print();
}