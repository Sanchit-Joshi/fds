#include <iostream>
#include <map>
#include <string>
using namespace std;

class Map
{
    string name;
    float population;
public:
    Map()
    {
        name="None";
        population=0.0;
    }

    void getdata()
    {
        cout<<"\nEnter the name of the state: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter the population of the state(in crores): ";
        cin>>population;
        cout<<"--------Data Inserted Successfully!---------\n";
    }

    string putname()
    {
        return name;
    }

    float putpopulation()
    {
        return population;
    }

};

int main()
{
    int ch;
    string s;
    float f;

    Map mobj;
    map <string,float> sp_map;
    map <string,float>::iterator sp_it;

    cout<<"\t****WELCOME TO STATE AND POPULATION STATS****"<<endl;
    do
    {
        cout<<"\n     Menu";
        cout<<"\n1)Insert Record.\n2)Delete Record.\n3)Display All Records.\n4)Exit.";
        cout<<"\nEnter Your Choice: ";
        cin>>ch;

        switch(ch)
        {
        case 1: mobj.getdata();
                s = mobj.putname();
                f = mobj.putpopulation();
                sp_map.insert(pair<string,float>(s,f));
                break;

        case 2: if(sp_map.empty())
                {
                    cout<<"\n-------- Record is empty!---------"<<endl;
                }
                else
                {
                    string tofind;
                    cout<<"\nEnter the state data you want to delete: ";
                    cin>>tofind;
                    sp_it=sp_map.find(tofind);

                    if(sp_it!=sp_map.end())
                    {
                        sp_map.erase(tofind);
                        cout<<"\n------- "<<tofind<<" data deleted successfully. -----------";
                    }
                    else
                    {
                        cout<<"\nRecord you wished for does not exist.";
                    }
                }
                break;

        case 3: if(sp_map.empty())
                {
                    cout<<"\n-------- Record is empty!---------"<<endl;
                }
                else
                {
                    sp_it=sp_map.begin();
                    int i=1;
                    while(sp_it != sp_map.end())
                    {
                        cout<<"\n------ Record "<<i<<" -------";
                        cout<<"\nName of state: "<<sp_it->first;
                        cout<<"\nPopulation: "<<sp_it->second<<" crores"<<endl;
                        i++; sp_it++;
                    }
                    cout<<"--------- All Records displayed Successfully!! ----------"<<endl;
                }
                break;

        case 4: break;

        default: cout<<"\nPlease enter valid choice!!";
        }
    }while(ch!=4);

cout<<"\n\tThank You!\n   Please visit again.";
return 0;
}
