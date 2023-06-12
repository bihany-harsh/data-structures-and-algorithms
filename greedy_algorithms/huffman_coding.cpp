#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq, Node* left = nullptr, Node* right = nullptr) {
        this->data = data;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};


// Comparison object to be used to order the heap
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to traverse the Huffman Tree and store Huffman Codes in a map
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (root == nullptr)
        return;

    // Found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->data] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

unordered_map<char, string> huffman_coding(string message) {
    unordered_map<char, int> freq;
    for (char ch: message) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (auto pair: freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    Node* root = pq.top();

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    return huffmanCode;
}

int main() {
    string message = "BCAADDDCCACACAC";
    unordered_map<char, string> huffmanCode = huffman_coding(message);

    for (auto pair: huffmanCode) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
