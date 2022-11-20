#include<iostream>
#include<string.h>
using namespace std;
string username;
string password;
string user;
string pass;
void travel :: user_registration()
{

        string username,password,user,pass;
        cout<<"Enter the username :";
        cin>>username;
        cout<<"\nEnter the password :";
        cin>>password;

        ofstream registration("database.txt",ios::app);
        registration<<username<<' '<<password<<endl;
        cout<<"\nRegistration Sucessful\n";
        user_login();

}

//User login
void travel :: user_login()
{
        int count;
        string username,password,user,pass;
        cout<<"please enter the following details to login"<<endl;
        cout<<"USERNAME :";
        cin>>username;
        cout<<"PASSWORD :";
        cin>>password;

        ifstream input("database.txt");
        while(input>>user>>pass)
        {
                if(username==user && password==pass)

                {
                        count=1;
                        cout<<("--------------");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello"<<username<<"\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                user_forgot();
        }
       
}

// displays login credentials if user forgot
void travel :: user_forgot()
{
    int ch;
    cout<<"Forgotten ?\n";
    cout<<"1.Search your id by username"<<endl;
    
        cout<<"2.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string search_user,user,password;
                        cout<<"\nEnter your remembered username :";
                        cin>>search_user;

                        ifstream search("database.txt");
                        while(search>>user>>password)
                        {
                                if(user==search_user)
                                {
                                        count=1;
                                }
                        }
                        search.close();
                        if(count==1)
                        {
                                cout<<"\n account found\n";
                                cout<<"\nYour password is "<<password;
                                cin.get();
                                cin.get();
                                user_login();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                user_registration();
                        }
                        break;
                }
               /*
                case 2:
                {
                        cin.get();
                        menu();
                }
		*/
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        user_forgot();
        }
}

