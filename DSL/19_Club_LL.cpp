#include<iostream>
#include<string>
using namespace std;

struct Node{
    int prn;
    string name;
    struct Node *next;
};  

class LinkedList{
    public: 
    Node* head;
    Node* tail;

    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    bool p = false;
    bool vp = false;

    void add_president(int prn, string name){
        if(p == false){
           //insert as first node
            p=true;
        Node* newNode = new Node;
        newNode->prn = prn;
        newNode->name = name;
        newNode->next = head;
        head = newNode;

        }
        else{
            cout<<"President already exists"<<endl;
        }
    }

    void add_vp(int prn, string name){
        if(vp == false){
        //insert as last node  
        vp= true; 
        Node* newNode = new Node;
        newNode->prn = prn;
        newNode->name = name;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
        }
        else{
            cout<<"Vice President already exists"<<endl;
        }
    }

    //add member at positiong other than first and last
    void add_member(int prn, string name, int pos){
        Node* newNode = new Node;
        newNode->prn = prn;
        newNode->name = name;

        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    //delete members using position , if president or vice president is deleted, then update bool values
    //if president(first node) is deleted, then update p = false
    //if vice president(last node) is deleted, then update vp = false
    void delete_member(int pos){
        Node* temp = head;
        Node* prev = head;
        for(int i=0; i<pos-1; i++){
            prev = temp;
            temp = temp->next;
        }
        if(temp == head){
            head = head->next;
            delete temp;
            p = false;
        }
        else if(temp == tail){
            tail = prev;
            prev->next = NULL;
            delete temp;
            vp = false;
        }
        else{
            prev->next = temp->next;
            delete temp;
        }
    }

    //display all members
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->prn<<" "<<temp->name<<endl;
            temp = temp->next;
        }
    }

    //concate two lists
    void concat(LinkedList l1, LinkedList l2){
        Node* temp = l1.head;
        while(temp != NULL){
            add_member(temp->prn, temp->name, 1);
            temp = temp->next;
        }
        temp = l2.head;
        while(temp != NULL){
            add_member(temp->prn, temp->name, 1);
            temp = temp->next;
        }
    }

    //total number of members
    int total_members(){
        int count = 0;
        Node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main(){
    //add switch case for all operations
    LinkedList l1,l2;
    int choice , prn , total;
    string name;
    while(true){
         cout << "Select Division: " << endl;
        cout << "1. Division 1" << endl;
        cout << "2. Division 2" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout<<"Select Operation: "<<endl;
                cout<<"1. Add President"<<endl;
                cout<<"2. Add Vice President"<<endl;
                cout<<"3. Add Member"<<endl;
                cout<<"4. Delete Member"<<endl;
                cout<<"5. Display Members"<<endl;
                cout<<"6. Total Members"<<endl;
                cout<<"7. Concatenate"<<endl;
                cout<<"8. Exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice;
                switch(choice){
                    case 1:
                        cout<<"Enter PRN: ";
                        cin>>prn;
                        cout<<"Enter Name: ";
                        cin.ignore();
                        getline(cin, name);
                        l1.add_president(prn, name);
                        break;
                    case 2:
                        cout<<"Enter PRN: ";
                        cin>>prn;
                        cout<<"Enter Name: ";
                        cin>>name;
                        l1.add_vp(prn, name);
                        break;
                    case 3:
                        cout<<"Enter PRN: ";
                        cin>>prn;
                        cout<<"Enter Name: ";
                        cin>>name;
                        cout<<"Enter Position: ";
                        cin>>choice;
                        l1.add_member(prn, name, choice);
                        break;
                    case 4:
                        cout<<"Enter Position: ";
                        cin>>choice;
                        l1.delete_member(choice);
                        break;
                    case 5:
                        l1.display();
                        break;
                    case 6:
                        total = l1.total_members();
                        cout<<"Total Members: "<<total<<endl;
                        break;
                    case 7:
                        l1.concat(l1, l2);
                        break;
                    case 8:
                        exit(0);
                        break;
                    default:
                        cout<<"Invalid Choice"<<endl;
                        break;
                }
                break;
            case 2:
                cout<<"Select Operation: "<<endl;
                cout<<"1. Add President"<<endl;
                cout<<"2. Add Vice President"<<endl;
                cout<<"3. Add Member"<<endl;
                cout<<"4. Delete Member"<<endl;
                cout<<"5. Display Members"<<endl;
                cout<<"6. Total Members"<<endl;
                cout<<"7. Concatenate"<<endl;
                cout<<"8. Exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice;
                switch(choice){
                    case 1:
                        cout<<"Enter PRN: ";
                        cin>>prn;
                        cout<<"Enter Name: ";
                        cin.ignore();
                        getline(cin, name);
                        l2.add_president(prn, name);
                        break;
                    case 2:
                        cout<<"Enter PRN: ";
                        cin>>prn;
                        cout<<"Enter Name: ";
                        cin>>name;
                        l2.add_vp(prn, name);
                        break;
                    case 3:

                        cout<<"Enter PRN: ";
                        cin>>prn;
                        cout<<"Enter Name: ";
                        cin>>name;
                        cout<<"Enter Position: ";
                        cin>>choice;
                        l2.add_member(prn, name, choice);
                        break;
                    case 4:
                        cout<<"Enter Position: ";
                        cin>>choice;
                        l2.delete_member(choice);
                        break;
                    case 5:
                        l2.display();
                        break;
                    case 6:
                        total = l2.total_members();
                        cout<<"Total Members: "<<total<<endl;
                        break;
                    case 7:
                        l2.concat(l1, l2);
                        break;
                    case 8:
                        exit(0);
                        break;
                    default:
                        cout<<"Invalid Choice"<<endl;
                        break;
                        }
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"Invalid Choice"<<endl;
                break;  
            }//outer switch
    }//while


    return 0;
 }

