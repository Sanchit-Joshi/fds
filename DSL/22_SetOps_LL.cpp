#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to insert an element at the end of the linked list
void insert(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to compute the set of students who like both
Node* getIntersection(Node* setA, Node* setB) {
    Node* result = nullptr;
    Node* tempA = setA;
    while (tempA != nullptr) {
        Node* tempB = setB;
        while (tempB != nullptr) {
            if (tempA->data == tempB->data) {
                insert(&result, tempA->data);
                break;
            }
            tempB = tempB->next;
        }
        tempA = tempA->next;
    }
    return result;
}

// Function to compute the set of students who like either but not both
Node* getSymmetricDifference(Node* setA, Node* setB) {
    Node* result = nullptr;
    Node* tempA = setA;
    while (tempA != nullptr) {
        Node* tempB = setB;
        bool found = false;
        while (tempB != nullptr) {
            if (tempA->data == tempB->data) {
                found = true;
                break;
            }
            tempB = tempB->next;
        }
        if (!found) {
            insert(&result, tempA->data);
        }
        tempA = tempA->next;
    }
    Node* tempB = setB;
    while (tempB != nullptr) {
        Node* tempA = setA;
        bool found = false;
        while (tempA != nullptr) {
            if (tempB->data == tempA->data) {
                found = true;
                break;
            }
            tempA = tempA->next;
        }
        if (!found) {
            insert(&result, tempB->data);
        }
        tempB = tempB->next;
    }
    return result;
}

// Function to compute the set of students who like neither
Node* getComplement(Node* setA, Node* setB) {
    Node* result = nullptr;
    for (int i = 1; i <= 10; i++) {
        Node* tempA = setA;
        Node* tempB = setB;
        bool found = false;
        while (tempA != nullptr) {
            if (tempA->data == i) {
                found = true;
                break;
            }
            tempA = tempA->next;
        }
        if (!found) {
            while (tempB != nullptr) {
                if (tempB->data == i) {
                    found = true;
                    break;
                }
                tempB = tempB->next;
            }
        }
        if (!found) {
            insert(&result, i);
        }
    }
    return result;
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* setA = nullptr;
    Node* setB = nullptr;

    int numElementsA, numElementsB;
    cout << "Enter the number of elements for setA: ";
    cin >> numElementsA;
    cout << "Enter the elements for setA: ";
    for (int i = 0; i < numElementsA; i++) {
        int element;
        cin >> element;
        insert(&setA, element);
    }

    cout << "Enter the number of elements for setB: ";
    cin >> numElementsB;
    cout << "Enter the elements for setB: ";
    for (int i = 0; i < numElementsB; i++) {
        int element;
        cin >> element;
        insert(&setB, element);
    }

    int choice;

    while(true){
    cout << "Enter your choice:" << endl;
    cout << "1. Students who like both" << endl;
    cout << "2. Students who like either but not both" << endl;
    cout << "3. Students who like neither" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    switch (choice) {
        case 1: {
            Node* intersectionSet = getIntersection(setA, setB);
            cout << "Students who like both: ";
            display(intersectionSet);
            break;
        }
        case 2: {
            Node* symmetricDiffSet = getSymmetricDifference(setA, setB);
            cout << "Students who like either but not both: ";
            display(symmetricDiffSet);
            break;
        }
        case 3: {
            Node* complementSet = getComplement(setA, setB);
            cout << "Students who like neither: ";
            display(complementSet);
            break;
        }
        case 4:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
    }
    }

    return 0;
}

