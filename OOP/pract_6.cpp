#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
    string name;
    int code, quantity;
    double cost;

public:
    Item(){
        name = "";
        code = 0;
        quantity = 0;
        cost = 0.0;
    }

    void accept() {
        cout << "\nEnter the Item Details:\n";
        cout << "\tName of Item: ";
        cin >> name;
        cout << "\tCode of Item: #";
        cin >> code;
        cout << "\tTotal quantity of Item: ";
        cin >> quantity;
        cout << "\tCost of Item: Rs.";
        cin >> cost;
    }

    bool operator==(int x) const {
        return (code == x);
    }

    int getcode() const {
        return code;
    }

    int getquantity() const {
        return quantity;
    }

    double getcost() const {
        return cost;
    }

    void display() const {
        cout << "\n\n\t----------- Details of Item #" << code << " -----------";
        cout << "\n\tItem Name: " << name;
        cout << "\n\tItem Code: " << code;
        cout << "\n\tItem Cost: Rs." << cost << "/-";
        cout << "\n\tItem Quantity: " << quantity;
    }

    inline void mesg(string s) {
        cout << "\nAll records have been sorted by " << s;
    }
};

bool less_code(const Item& obj1, const Item& obj2) {
    return (obj1.getcode() < obj2.getcode());
}

bool less_quantity(const Item& obj1, const Item& obj2) {
    return (obj1.getquantity() < obj2.getquantity());
}

bool less_cost(const Item& obj1, const Item& obj2) {
    return (obj1.getcost() < obj2.getcost());
}

int main() {
    vector<Item> v;
    vector<Item>::iterator it;
    int choice, itemCode;

    do {
        cout << "\n\n\t\t***** MENU *****";
        cout << "\n\t1. Insert Item Record\n\t2. Sort Item Records\n\t3. Search Item Record";
        cout << "\n\t4. Delete Item Record\n\t5. Display all Item Records\n\t6. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    Item obj;
                    obj.accept();
                    v.push_back(obj);
                    cout << "\nItem Record inserted successfully!";
                }
                break;

            case 2:
                {
                    int ch;
                    cout << "\n\n\tSort by:\n\t\t1. Item Code\n\t\t2. Item Quantity\n\t\t3. Item Cost\n";
                    cout << "\nEnter your choice: ";
                    cin >> ch;

                    switch (ch) {
                        case 1:
                            sort(v.begin(), v.end(), less_code);
                            v[0].mesg("Item Code");
                            break;

                        case 2:
                            sort(v.begin(), v.end(), less_quantity);
                            v[0].mesg("Item Quantity");
                            break;

                        case 3:
                            sort(v.begin(), v.end(), less_cost);
                            v[0].mesg("Item Cost");
                            break;

                        default:
                            cout << "\nInvalid option selected. Select a valid option!";
                    }
                }
                break;

            case 3:
                cout << "\nEnter the Item Code of the Item to be searched: #";
                cin >> itemCode;

                it = find(v.begin(), v.end(), itemCode);

                if (it != v.end()) {
                    cout << "\nItem with Item Code #" << itemCode << " found in the Records at position " << (it - v.begin()) + 1;
                    it->display();
                } else {
                    cout << "\nItem with Item Code #" << itemCode << " not found in the Records.";
                }
                break;

            case 4:
                cout << "\nEnter the Item Code you would like to delete: #";
                cin >> itemCode;

                it = find(v.begin(), v.end(), itemCode);

                if (it != v.end()) {
                    v.erase(it);
                    cout << "\nItem with Item Code #" << itemCode << " has been deleted successfully";
                } else {
                    cout << "\nItem with Item Code #" << itemCode << " does not exist in the Records.";
                }
                break;

            case 5:
                for (const auto& item : v) {
                    item.display();
                }
                cout << "\nAll the Item Records have been displayed successfully";
                break;

            case 6:
                break;

            default:
                cout << "\nInvalid option selected. Enter a valid choice!";
        }
    } while (choice != 6);

    cout << "\n\t\t***** End of Program *****";
    cout << "\nThank You!";
    return 0;
}
