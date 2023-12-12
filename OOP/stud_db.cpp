#include<iostream>
#include<string.h>
#include<typeinfo>
#include<stdexcept>

using namespace std;

class info{
    char address[20] ,license[20] , insurance[15];
    long int contact;

    public:
        info(){ //default constructor
            strcpy(address , "XYZ");
            strcpy(license , "XY-00000000");
            strcpy(insurance , " XY000000000");
            contact = 0000000000;
        }

        ~info(){
            cout<<"in destructor";
        }

        friend class person;

};

class person{
     char name[20],dob[10],blood[5];
     float hgt , wgt;

     static int count;
     info *pai;

     public:
        person(){
            strcpy(name, "XYZ");
            strcpy(dob , "dd-mm-yyyy");
            strcpy(blood , "O -");
            hgt=0.0;
            wgt=0.0;

            pai = new info;

        }

        person (person*p1){
            strcpy(name, p1->name);
            strcpy(dob, p1->dob);
            strcpy(blood , p1->blood);
            hgt=p1->hgt;
            wgt=p1->wgt;

            pai = new info;
            strcpy(pai->address,p1->pai->address);
            strcpy(pai->license, p1->pai->license);
            strcpy(pai->insurance,p1->pai->insurance);
            pai->contact=p1->pai->contact;
        }

        static void showcount()
        {
            cout<<"\n Number of Records = "<<count<<"\n";
        }

        ~person(){
            cout<<"Person class destructor"<<endl;

        }

        void getdata(char name[20]);
        inline void display();

};

void person::getdata(char name[20]){
    strcpy(this->name,name);

    //using this pointer

    cout<<"\n Enter date of birth";
    cin>>dob;
    cout<<"\n Enter blood group";
    cin>>blood;
    cout<<"\n Enter height";
    cin>>hgt;

    //implementing exception handling for height

    try{
        if(hgt<=0)
            throw runtime_error("\n Height should be greater");
    }
    catch(const exception &e){
        cout<<"Exception caught"<<e.what();
    }

    cout<<"Enter Weight";
    cin>>wgt;
    cout<<"\n Enter address";
    cin>>pai->address;
    cout<<"\n Enter License Number";
    cin>>pai->license;

    cout<<"\n Enter Insurance Policy Number";
    cin>>pai->insurance;
    cout<<"\n Enter contact number";
    cin>>pai->contact;
    count++;
}

//defining the inline function
void person::display(){
    cout<<"\t"<<name<<"\t"<<dob<<"\t"<<hgt<<"\t"<<wgt<<"\t"<<pai->address<<"\t"<<pai->license<<"\t"<<pai->insurance<<"\t"<<pai->contact;
}

//defining static variable
int person::count;

int main(){

person *p1 , *p2;
int ch;
p1=new person; //memory allocation
p2=new person(p1); // copy constructor
   
int n;
    cout<<"\nEnter number of records you want to enter: ";
    cin>>n;
person p3[n];

char name[20];
int x=0;
do
{
    cout<<"\nWelcome to Personal database system";
    cout<<"\n1.Enter the record";
    cout<<"\n2.Display the record";
    cout<<"\n3.Exit";
    cout<<"\n\n ENter your choice"; 
    cin>>ch;
switch(ch)
{
    case 1:
    {
        cout<<"\nEnter the Name ";
        cin>>name;
        p3[x].getdata(name);
        person::showcount(); // calls static function
        x++;
        break;
    }
    case 2:
    {
        cout<<"\tName";
        cout<<"\tDob";
        cout<<"\tBlood";
        cout<<"\tHt";
        cout<<"\tWt";
        cout<<"\tAddress";
        cout<<"\tLicense";
        cout<<"\tInsurance";
        cout<<"\tContact";
        for(int i=0;i<n;i++)
        {
        cout<<"\n";
        p3[i].display(); //calling inline function
    }
    break;
        }
        }
}while(ch!=3);
delete p1; //dynamic memory de-allocation
delete p2;
return 0;
}