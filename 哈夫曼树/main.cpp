#include"HFtree.h"
using namespace std;


void printMenu() {
    cout << "===== Huffman Tree Menu =====" << endl;
    cout << "1. Read Data and Build Tree" << endl;
    cout << "2. Save Tree to File" << endl;
    cout << "3. Encode Text" << endl;
    cout << "4. Decode Text" << endl;
    cout << "5. Quit" << endl;
    cout << "=============================" << endl;
    cout << "Enter your choice (1-5): ";
}

int main() {
     HFtree huffmanTree;
     bool init = 0;

    char choice;
    do {
        printMenu();
        cin >> choice;
        cin.ignore();  

        switch (choice) {
        case '1': {
            int n;
            cout << "Enter the size of the character set: ";
            cin >> n;

            char* characters = new char[n];
            int* weights = new int[n];

            cout << "Enter " << n << " characters and their weights:\n";
            for (int i = 0; i < n; ++i) {
                cin >> characters[i] >> weights[i];
            }

            huffmanTree.createtree(n, characters, weights);

            delete[] characters;
            delete[] weights;
            break;
        }
        case '2': {
            huffmanTree.save("hfmTree");
            cout << "Huffman Tree has been saved to hfmTree." << endl;
            break;
        }
        case '3': {
            if (huffmanTree.isempty()) {
                cout << "Error: Huffman Tree is not initialized. Please choose option 1 first." << endl;
                break;
            }
            huffmanTree.encoder("test2.txt", "CodeFile", "");
            cout << "Text has been encoded. Result saved to CodeFile." << endl;
            break;
        }
        case '4': {
            if (huffmanTree.isempty()) {
                cout << "Error: Huffman Tree is not initialized. Please choose option 1 first." << endl;
                break;
            }

            huffmanTree.load("hfmTree");
            huffmanTree.decode("CodeFile", "TextFile");
            cout << "CodeFile has been decoded. Result saved to TextFile." << endl;
            break;
        }
        case '5':
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }

    } while (choice != '5');

    return 0;
}
