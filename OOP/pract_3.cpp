/*
Imagine a publishing company which does marketing for book
and audiocassette versions.
 Create a class publication that stores the title (a string)
and price (type float) of a
 publication.From this class derive two classes: book, which
adds a page count(type int),
 and tape, which adds a playing time in minutes(type float).
 Write a program that instantiates the book and tape classes,
allows user to enter data and
 displays the data members.If an exception is caught, replace
all the data member values
 with zero values.
*/

#include<iostream>
#include<string.h>
using namespace std;

class Publication{

    private:
    string title;
    float price;

    public:
    //default constructor
    Publication(){
        title="";
        price=0.0;
    }

    void get_data(){
        cout<<"Enter the name of Title: ";
        cin.ignore();
        getline(cin,title);
        cout<<"Enter the price: ";
        cin>>price;
    }

    void display(){
        cout<<"-----------------"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<price<<endl;
    }

};

class Book:public Publication{
    private:
    int page_count;

    public:

    void add_page(){

        try{ get_data();
            cout<<"Enter the page count: ";
            cin>>page_count;
            if(page_count<=0){
                throw page_count;
            }
        }
        catch(int i){
            cout<<"Invalid page count"<<endl;
            page_count=0;
        }
    }

    void display_book(){
        display();
        cout<<"Page count: "<<page_count<<endl;
    }

};

class Tape: public Publication{

    private:
    float playing_time;
    public:

    void get_time(){

        try{
            get_data();
            cout<<"Enter the playing time: ";
            cin>>playing_time;
            if(playing_time<=0){
                throw playing_time;
            }
        }
        catch(float i){
            cout<<"Invalid playing time"<<endl;
            cout<<"Enter playing time again: ";
            playing_time=0;
        }
    }

    void diplay_tape(){
        display();
        cout<<"Playing time: "<<playing_time<<endl;
    }
}; 

int main(){
    
    Book* b=new Book[10];
    Tape* t=new Tape[10];
    int b_count=0;
    int t_count=0;

    int choice;
    do{     cout<<"***Publication***"<<endl;
    cout<<"1. Add Book"<<endl;
    cout<<"2. Add Tape"<<endl;
    cout<<"3. Display Book"<<endl;
    cout<<"4. Display Tape"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<endl;
    cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: 
            b[b_count].add_page();
            b_count++;
            cout<<endl;
            break;

            case 2:
            t[t_count].get_time();
            t_count++;
            cout<<endl;
            break;

            case 3:
            for(int i=0;i<b_count;i++)
            b[i].display_book();
            cout<<endl;
            break;

            case 4:
            for(int i=0;i<t_count;i++)
            t[i].diplay_tape();
            cout<<endl;

            break;

            case 5:
            cout<<"Thank you"<<endl;
            exit(0);
            break;

            default:
                exit(0);
            
        }

    }while (choice!=5);

    return 0;

}