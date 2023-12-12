/*
Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file.
*/

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Employee{

    private:
    string name;
    double ID;
    float salary;

    public:
    void accept(){
        cout<<"Enter the name of the employee: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter the ID of the employee: ";
        cin>>ID;
        cout<<"Enter the salary of the employee: ";
        cin>>salary;
    }

    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Salary: "<<salary<<endl;
    }

};

int main(){
    int i,n;
    cout<<"Enter the number of employees: ";
    cin>>n;
    Employee o[10];
    fstream file;

    
    file.open("demo.txt", ios::out);
    for(i=0;i<n;i++){
        o[i].accept();
        file.write((char *)&o[i] , sizeof(o[i]));
    }

    file.close();

    file.open("demo.txt", ios::in);
    for(i=0;i<n;i++){
        file.read((char *)&o[i] , sizeof(o[i]));
        o[i].display();
    }

    file.close();

    return 0;

}