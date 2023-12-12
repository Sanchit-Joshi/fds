#include <iostream>
#include <string>
#include<stdexcept>
using namespace std;

class Student {
private:
  string name;  
  int rollNumber;
  string className;
  string division;
  string dateOfBirth;
  string bloodGroup;
  string contactAddress;
  string telephoneNumber;
  string drivingLicenseNo;

public:
  // Default constructor
  Student() {
    name = "";
    rollNumber = 0;
    className = "";
    division = "";
    dateOfBirth = "";
    bloodGroup = "";
    contactAddress = "";
    telephoneNumber = "";
    drivingLicenseNo = "";
  }

  // Parameterized constructor with this pointer
  Student(string name, int rollNumber, string className, string division, string dateOfBirth, string bloodGroup, string contactAddress, string telephoneNumber, string drivingLicenseNo) {
    this->name = name;
    this->rollNumber = rollNumber;
    this->className = className;
    this->division = division;
    this->dateOfBirth = dateOfBirth;
    this->bloodGroup = bloodGroup;
    this->contactAddress = contactAddress;
    this->telephoneNumber = telephoneNumber;
    this->drivingLicenseNo = drivingLicenseNo;
  }

  // Copy constructor
  Student(const Student& other) {
    name = other.name;
    rollNumber = other.rollNumber;
    className = other.className;
    division = other.division;
    dateOfBirth = other.dateOfBirth;
    bloodGroup = other.bloodGroup;
    contactAddress = other.contactAddress;
    telephoneNumber = other.telephoneNumber;
    drivingLicenseNo = other.drivingLicenseNo;
  }

  // Destructor
  ~Student() {
    // Perform any necessary cleanup here
  }

  // Static member function
  static void displayDatabase(const Student& student) {
    cout << "Name: " << student.name << endl;
    cout << "Roll Number: " << student.rollNumber << endl;
    cout << "Class: " << student.className << endl;
    cout << "Division: " << student.division << endl;
    cout << "Date of Birth: " << student.dateOfBirth << endl;
    cout << "Blood Group: " << student.bloodGroup << endl;
    cout << "Contact Address: " << student.contactAddress << endl;
    cout << "Telephone Number: " << student.telephoneNumber << endl;
    cout << "Driving License No.: " << student.drivingLicenseNo << endl;
  }

  // Friend class
  friend class Database;
};

class Database {
private:
  Student* students; //dynamic array of students
  int size;

public:
  // Constructor
  Database(int size) {
    this->size = size;
    students = new Student[size];
  }

  // Destructor
  ~Database() {
    delete[] students;
  }

  // Inline member function to add a student to the database
  inline void addStudent(Student student, int index) {
    students[index] = student;
  }

  // Member function to display all students in the database
  void displayAllStudents() {
    for (int i = 0; i < size; i++) {
      Student::displayDatabase(students[i]);
      cout << endl;
    }
  }
};

int main() {
  int numRecords;
  cout << "Enter the number of records: ";
  cin >> numRecords;

  // Create a database with the given number of students
  Database* db = new Database(numRecords);

  int choice;
  while (true) {
    cout << "1. Add student record" << endl;
    cout << "2. Display all student records" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1: {
        string name, className, division, dateOfBirth, bloodGroup, contactAddress, telephoneNumber, drivingLicenseNo;
        int rollNumber;

        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNumber;

        // Exception handling to check if roll number is a natural number
        try {
          if (rollNumber <= 0) {
            throw runtime_error("Roll number must be a natural number.");
          }
        } 
        catch (const exception &e) {
          cout << "Exception: " << e.what() << endl;
          
          rollNumber = 0;
        }

        cout << "Enter class: ";
        cin.ignore();
        getline(cin, className);
        cout << "Enter division: ";
        getline(cin, division);
        cout << "Enter date of birth: ";
        getline(cin, dateOfBirth);
        cout << "Enter blood group: ";
        getline(cin, bloodGroup);
        cout << "Enter contact address: ";
        getline(cin, contactAddress);
        cout << "Enter telephone number: ";
        getline(cin, telephoneNumber);
        cout << "Enter driving license number: ";
        getline(cin, drivingLicenseNo);

        Student student(name, rollNumber, className, division, dateOfBirth, bloodGroup, contactAddress, telephoneNumber, drivingLicenseNo);
        db->addStudent(student, numRecords);
        numRecords++;
        break;
      }
      case 2:
        db->displayAllStudents();
        break;
      case 3:
        delete db; // Delete the database
        return 0;
      default:
        cout << "Invalid choice. Please try again." << endl;
    }
  }

  return 0;
}
