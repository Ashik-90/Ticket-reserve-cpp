#include <bits/stdc++.h>
using namespace std;
int b_id=100;

class user
{
public:
    string name,mobile,pass;  //mobile number will act as user id number
    int age;
};

class journey
{
public:
    unsigned short int date;
    string time;
};

class manage:public user, public journey
{
public:
    char depr, des, coach, via; //departure, destination
    string booking_id;
    int Bill;
    void show_trips();       //places available to travel
    void recharge();
    void new_booking();      //new booking
    void show();             //current booked
    void change_trip();
    void New_registration();
    bool check_password();

};

void coaches()
{
    cout<<"Coach A: 6:30 am"<<endl;
    cout<<"Coach B: 8:30 am"<<endl;
    cout<<"Coach C: 10:00 am"<<endl;
    cout<<"Coach D: 2:00 pm"<<endl;
    cout<<"Coach E: 4:00 pm"<<endl;
    cout<<"Coach F: 6:30 pm"<<endl;
    cout<<"Coach G: 9:00 pm"<<endl;
    cout<<"Coach H: 11:00 pm"<<endl;
}

void location()

{
    system("COLOR 3F");
    vector <string> v;
    v.push_back("Khulna");
    v.push_back("Dhaka");
    v.push_back("Rajshahi");
    v.push_back("Chattogram");
    v.push_back("Mymensingh");
    v.push_back("Barishal");
    v.push_back("Sylhet");
    cout<<"We move within....\n";
    for (int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<"    ";
    }
    cout<<endl;
    coaches();
}

void menu()
{
    cout<<"1. New Registration"<<endl;
    cout<<"2. Show locations"<<endl;
    cout<<"3. Log in"<<endl;
    cout<<"4. Know the travel bill"<<endl;
    cout<<"0. Exit"<<endl;
}

float bill(char,char,char,char);

bool manage::check_password()
{

    cout<<"Enter username : ";
    cin>>name;
    cout<<"Enter your password: ";
    cin>>pass;
    {
        ifstream user;
        string n,p,m,line; //n=name, p=password, line for reaching eof, m for proper read
        user.open("reg.csv");
        while(user.good())
        {
            getline(user, n, ',');
            getline(user, p, ',');
            getline(user, m);
            if(name==n && p==pass)
            {
                mobile=m;
                return true;
            }
        }
        user.close();
        return false;
    }
}
void manage::New_registration()
{
    string s;
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter mobile number (it will act as your id number) :";
    cin>>mobile;
    do
    {
        cout<<"Enter password: ";
        cin>>pass;
        cout<<"re-enter password: ";
        cin>>s;
    }
    while (!(s==pass));

    cout<<"Age: ";
    cin>>age;
    ofstream reg("reg.csv", ios::app);
    reg<<name<<","<<pass<<","<<mobile<<endl;
    reg.close();
    cout<<"Registration successfull! ";
}
void manage::new_booking()
{
    system("COLOR 4A");
    cout<<"\n\t\t\t\tBOOK NEW TRIP\n";

    cout<<"------------------------------------------------------------\n";
    cout<<endl;
    system("PAUSE");
    cout<<"\n\nPress K for Khulna"<<endl;
    cout<<"Press D for Dhaka"<<endl;
    cout<<"Press S for Sylhet"<<endl;
    cout<<"Press M for Mymensingh"<<endl;
    cout<<"Press R for Rajshahi"<<endl;
    cout<<"Press C for Chattogram"<<endl;
    cout<<"Press B for Barishal"<<endl;
    cout<<"Press # to go back\n\n"<<endl;

    cout<<"Enter departure place : \n";      //goto A
    cin>>depr;
    cout<<"Enter destination place: \n";
    cin>>des;

    while(depr==des)
    {
        cout<<"You have entered same place as departure and destination! Enter again: ";

        cout<<"Enter departure place : \n";      //goto A
        cin>>depr;
        cout<<"Enter destination place: \n";
        cin>>des;
    }

    depr = tolower(depr);
    des = tolower(des);

    cout<<"How you wish to travel?\n A. Air\n B. Bus\n T. Train\n";
    cin>>via;
    if(via=='A' || via=='a')
    {
        coach='S';
        goto P;
    }
    cout<<"Select coach:\nN. Normal(Non-AC)\nS. Sleep (AC)\nL. Luxury (VIP)";
    cin>>coach;
P:
    cout<<"Enter journey date" ;
    cin>>date;
    cout<<"\nSelect Journey time\n____________________________\n";
    coaches();
    char p;
    cin>>p;
    p=toupper(p);

    if (p=='A')
    {
        time="6:30 am";
    }
    else if(p=='B')
    {
        time="8:30 am";
    }
    else if(p=='C')
    {
        time="10:00 am";
    }
    else if(p=='D')
    {
        time="2:00 pm";
    }
    else if(p=='E')
    {
        time="4:00 pm";
    }
    else if(p=='F')
    {
        time="6:30 pm";
    }
    else if(p=='G')
    {
        time="9:00 pm";
    }
    else if(p=='H')
    {
        time="11:00 pm";
    }

    cout<<"\nDear "<<name<<" (" <<mobile<< "), " <<"you are going to register ";

    {

        if(depr== 'k')
            cout<<"KHULNA to";
        else if(depr== 'd')
            cout<<"DHAKA to";
        else if(depr=='m')
            cout<<"MYMENSINGH to";
        else if( depr=='r')
            cout<<"RAJSHAHI to";
        else if(depr=='c')
            cout<<"CHATTOGRAM to";
        else if(depr=='b')
            cout<<"BARISHAL to";
        else if(depr=='s')
            cout<<"SYLHET to";

        if(des=='k')
            cout<<" KHULNA";
        else if(des=='d')
            cout<<" DHAKA";
        else if(des=='m')
            cout<<" MYMENSINGH";
        else if(des=='r')
            cout<<" RAJSHAHI";
        else if(des=='c')
            cout<<" CHATTOGRAM";
        else if(des=='b')
            cout<<" BARISHAL";
        else if(des=='s')
            cout<<" SYLHET";
    }
    cout<<"  AT "<<time<<endl;

    float cost = bill(depr, des, via, coach);
    cout<<"Your charge for the journey is "<<cost<<" tk"<<endl;
    cout<<"\n1.Confirm booking";
    cout<<"\n0.Cancel booking"<<endl;
    char c;
    cin>>c;
    if(c=='1')
    {
        recharge();
    }
    else
        exit(0);
}

float bill(char depr, char des, char via, char coach)
{
    float km;
    if((depr == 'k' && des=='d') || (depr=='d' && des=='k'))
    {
        km = 400;
    }
    else if((depr == 'k' && des=='m') || (depr=='d' && des=='k'))
    {
        km = 450;
    }
    else if((depr == 'k' && des=='r') || (depr=='d' && des=='k'))
    {
        km = 410;
    }
    else if((depr == 'k' && des=='c') || (depr=='d' && des=='k'))
    {
        km = 800;
    }
    else if((depr == 'k' && des=='b') || (depr=='d' && des=='k'))
    {
        km = 360;
    }
    else if((depr == 'k' && des=='s') || (depr=='d' && des=='k'))
    {
        km = 810;
    }

    //-----------------------------------------

    else if((depr == 'd' && des=='s') || (depr=='s' && des=='d'))
    {
        km = 390;
    }
    else if((depr == 'd' && des=='m') || (depr=='m' && des=='d'))
    {
        km = 280;
    }
    else if((depr == 'd' && des=='r') || (depr=='r' && des=='d'))
    {
        km = 300;
    }
    else if((depr == 'd' && des=='c') || (depr=='c' && des=='d'))
    {
        km = 330;
    }
    else if((depr == 'd' && des=='b') || (depr=='b' && des=='d'))
    {
        km = 400;
    }
    //------------------------------------------------------

    else if((depr == 'm' && des=='r') || (depr=='r' && des=='m'))
    {
        km = 460;
    }
    else if((depr == 'm' && des=='c') || (depr=='c' && des=='m'))
    {
        km = 500;
    }
    else if((depr == 'm' && des=='b') || (depr=='b' && des=='m'))
    {
        km = 480;
    }
    else if((depr == 'm' && des=='s') || (depr=='s' && des=='m'))
    {
        km = 470;
    }
    //-------------------------------------------------------

    else if((depr == 'r' && des=='c') || (depr=='c' && des=='r'))
    {
        km = 700;
    }
    else if((depr == 'r' && des=='s') || (depr=='s' && des=='r'))
    {
        km = 610;
    }
    else if((depr == 'r' && des=='b') || (depr=='b' && des=='r'))
    {
        km = 640;
    }
    //------------------------------------------------------

    else if((depr == 'c' && des=='b') || (depr=='b' && des=='c'))
    {
        km = 550;
    }
    else if((depr == 'c' && des=='s') || (depr=='s' && des=='c'))
    {
        km = 600;
    }
    //--------------------------------------------------------

    else if((depr == 's' && des=='b') || (depr=='b' && des=='s'))
    {
        km = 710;
    }

    if (via=='A' || via=='a')
    {
        km*= 7;
    }
    else if (via=='B'||via=='b')
    {
        km*=2;
    }
    else if(via == 'T' || via=='t')
    {
        km*=1.5;
    }

    if (coach=='S'||coach=='s')
    {
        km*=1.5;
    }
    else if(coach=='L'||coach=='l')
    {
        km*=3;
    }

    return km;
}

void know_bill()
{
    cout<<"\n\nPress K for Khulna"<<endl;
    cout<<"Press D for Dhaka"<<endl;
    cout<<"Press S for Sylhet"<<endl;
    cout<<"Press M for Mymensingh"<<endl;
    cout<<"Press R for Rajshahi"<<endl;
    cout<<"Press C for Chattogram"<<endl;
    cout<<"Press B for Barishal"<<endl;

    char a,b,v,c;
    cout<<"Enter departure place: ";
    cin>>a;
    cout<<"Enter destination place: ";
    cin>>b;
    cout<<"How you wish to travel?\n A. Air\n B. Bus\n T. Train\n";
    cin>>v;
    cout<<"Select coach:\nN. Normal(Non-AC)\nS. Sleep (AC)\nL. Luxury (VIP)";
    cin>>c;
    a = tolower(a);
    b = tolower(b);
    cout<<"You will be charged "<< bill(a,b,v,c)<<"tk\n";

}
void manage::recharge()
{
    string tran;
    cout<<"Please send the fees to us and Enter transaction id: ";
    cin>>tran;
    int linenum;
    string line;
    ifstream x;
    x.open("test.csv");
    while(getline(x, line))
    {
        linenum++;
    }
    cout<<"linenum:"<<linenum;
    b_id+=linenum;

    cout<<"Successfully Completed Payment"<<endl;
    cout<<"Booking id is "<<b_id;

}

int main()
{
    manage m;
    journey u,*ptr;
    ptr=&u;
    ptr=&m;   //RUNTIME POLYMORPHISM

    menu();
    char select;
    cin>>select;
    while(select!='0')
    {
        switch(select)
        {
        case '1':

            m.New_registration();
            break;

        case '2':
            location();
            break;

        case '3':
        {
            if(m.check_password()==true)
            {
                cout<<"1. New booking"<<endl;
                cout<<"2. Check booking"<<endl;
                cout<<"3. Exit to main menu"<<endl;

                int x;
                cout<<"Enter your choice: " ;
                cin>>x;
                while (x!=3)
                {
                    if (x==1)
                    {
                        ofstream myFile("Test.csv", ios::app);
                        m.new_booking();
                        myFile<<b_id<<", "<<m.name<<", "<<m.mobile<<", "<<m.depr<<", "<<m.des<<", "<<m.date<<", "<<m.time<<endl;
                        myFile.close();
                    }

                    else if (x==2)
                    {
                        ifstream info;
                        info.open("Test.csv");
                        string id, dep, des,mo,time,name,date;
                        while(info.good())
                        {
                            getline(info, id, ',');
                            getline(info, name, ',');
                            getline(info, mo, ',');
                            getline(info, dep, ',');
                            getline(info, des, ',');
                            getline(info, date, ',');
                            getline(info, time);

                            if(mo == m.mobile)
                            {
                                cout<<"You have booked from ";
                                if(dep.compare("k"))
                                    cout<<"KHULNA ";
                                else if(dep.compare ("d"))
                                    cout<<"DHAKA ";
                                else if(dep.compare("m"))
                                    cout<<"MYMENSINGH ";
                                else if( dep.compare("r"))
                                    cout<<"RAJSHAHI ";
                                else if(dep.compare("c"))
                                    cout<<"CHATTOGRAM ";
                                else if(dep.compare("b"))
                                    cout<<"BARISHAL ";
                                else if(dep.compare("s"))
                                    cout<<"SYLHET ";



                                cout<<" on"<<date<<"June "<<"at "<<time<<" under the booking id "<<id;
                                cout<<endl;

                            }
                        }
                    }
                    cout<<"1. New booking"<<endl;
                    cout<<"2. Check booking"<<endl;
                    cout<<"3. Exit to main menu"<<endl;
                    cout<<"Enter Choice: ";
                    cin>>x;
                }
            }

            else
            {
                cout<<"Incorrect user name or password!";
            }
            break;
        }

        case '4':
            know_bill();
            break;

        case '7':
            m.check_password();
            break;
        }

        cout<<"\n\n\n";
        menu();
        cout<<"Press your choice";
        cin>>select;
    }

    cout<<"T H A N K   Y O U!";
    return 0;

}
