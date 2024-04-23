#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Hospital{
    public:
    static int id;
    int hos_id;
    string hos_name;
    string hos_add;
    int hos_num;
    Hospital(){
        hos_id = ++id;

    }
};

class Doctor{
    public:
    static int id;
    int doc_id;
    int mob_num;
    string doc_name;
    string specilization;
    int avb=0;
    int app_id;
    Doctor() {
        doc_id=++id;
        app_id=-1;
        }

    Doctor(string n,string s,int m) {
        doc_name=n;
        specilization=s;
        mob_num=m;
        if(doc_id==1){
            avb=6;
        }
        else if(doc_id==2){
            avb=8;
        }
        else if(doc_id==3){
            avb=10;
        }
        
        }
};
int Doctor::id;


class Patient{
    public:
    static int id;
    int pat_id;
    //string name;
    int age;
    string pat_name;
    int doc_id;
    int app_id;
    Patient() {
        pat_id=++id;
        doc_id=-1;
        app_id=-1;
    } 
    Patient(string n,int a) {
        pat_name=n;
        age=a;
    }        
};
int Patient::id;

class Appointment{
    public:
    static int id;
    int app_id;
    int pat_id;
    int doc_id;
    int start;
    int date;
    int mon;
    int year;
    string spec;
    Appointment(){
        app_id = ++id;
        pat_id=-1;
        doc_id=-1;
        start=-1;
        date=-1;
    }
    Appointment(int id,int s,int e,int i,int m,int y,string n){
        doc_id=id;
        start=s;
        date=e;
        pat_id=i;
        mon=m;
        year=y;
        spec=n;
    }
};

int Appointment::id;

class payment{
    public:
    char p_sts;
    int p_num;
    int pat_id;
    int app_id;
    float amt;
    payment(float a,char b) {
        amt=a;
        p_sts=b;
        p_sts='S';
    }
};


int main(){
    cout<<setw(20)<<"Hospital management"<<endl;
    Doctor d;
    Patient p;
    Appointment a;
    do{
        cout<<"1.Register Doc\n2.Register patient\n3.book an appointment"<<endl;
        int choice,i,j,k,l;
        cout<<"enter your choice";
        cin>>choice;
        // Doctor d;
        // Patient p;
        //string name;
        switch (choice){
            case 1 :
            cout<<"Register Doctor";
            cout<<"\nEnter the doctor's name: ";
            cin>>d.doc_name;
            cout<<"\nEnter specialization of the doctor : ";
            cin>>d.specilization;
            cout<<"\nEnter doctor's mobile number : ";
            cin>>d.mob_num;
            break;
            case 2:
            cout<<"Patient Register";
            cout<<"\nEnter the patient name";
            cin>>p.pat_name;
            cout<<"\nenter the age of the patient";
            cin>>p.age;
            break;
            case 3:
            cout<<"viewing the patient"<<endl;
            cout<<p.pat_name<<" "<<p.age<<endl;
            break;
            case 4:
            cout<<"viewing the doctor"<<endl;
            cout<<d.doc_id<<" "<<d.doc_name<<" "<<d.mob_num<<" "<<d.specilization;
            break;
            case 5:
            cout<<"\nBook an appointment"<<endl;
            cout<<"Enter the data";
            int da;
            cin>>da;
            cout<<"enter the month";
            int mo;
            cin>>mo;
            cout<<"enter the year";
            int yr;
            cin>>yr;
            cout<<"enter the time";
            int t;
            cin>>t;
            cout<<"enter the doc id";
            int i;
            cin>>i;
            cout<<"enter the pat id";
            int g;
            cin>>g;
            cout<<"enter the speciliation";
            string spe;
            cin>>spe;
            Appointment a(i,t,da,g,mo,yr,spe);
            int avb;
            if(i==1){
                if(avb>5&&avb<7){
                    cout<<"the doctor is available";
                }
                else{
                    cout<<d.doc_id+1<<" is availabel";
                }
            }
            else if(i==2){
                if(avb>7&&avb<9){
                    cout<<"the doctor is available";
                }
                else{
                    cout<<d.doc_id+1<<" is available";
                }
            }
            else if(i==3){
                if(avb>9&&avb<11){
                    cout<<"the doctor is available";
                }
                else{
                    cout<<"no doctors is available";
                }
            }
            int amt=0;
            if(spe=="cardio")
            amt=100;
            else if(spe=="nephro")
            amt=200;
            cout<<"Your amt is"<<amt<<endl;
            

        }
       
    }while(1);
     return 0;
}
