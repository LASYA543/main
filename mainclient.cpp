#include <arpa/inet.h>
#include<iostream>
#include <string.h>
#include <sys/socket.h>
#include "logger.h"
#include <unistd.h>
#include<fstream>
#include"admin_client.cpp"
using namespace std;
#define PORT 8080
/*
#define MAX_length 30

 char admin[MAX_length]="Tour.txt";
char user[MAX_length]="Reservation.txt";

struct tour{
        char admin_place[MAX_length],admin_code[MAX_length],admin_country[MAX_length],admin_days[MAX_length],admin_prices[MAX_length],admin_payments[MAX_length];
        char user_phone[MAX_length],user_name[MAX_length],user_people[MAX_length],user_date[MAX_length],user_status[MAX_length],user_dcode[MAX_length],user_prices[MAX_length],user_payments[MAX_length];
};*/
//class travel{
  //      public:
  //              travel(){
    //                    cout<<"travel booking app";
      //          }
/*		
void loadUser(User arr[], int size);
bool findUser(User arr[], int size, User toFind);
		
 void admin_login();
};
*/
void login(int client_fd)
{
        int count = 0;
	//int state = 0;
        string username,password,user,pass;
        cout<<"please enter the following details to login"<<endl;
        LOG_INFO("USERNAME :");
        cin>>username;
        LOG_INFO("PASSWORD :");
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
	//	state = 1;
                send(client_fd,&count,sizeof(int),0);
                cout<<"\nHello"<<username<<"\n<LOGIN SUCCESSFUL>\nThanks for logging in..\n";
		//state = 1;
        }
        else
        {
	//	state = 0;

                LOG_ERROR("\nLOGIN ERROR\nPlease check your username and password\n");

        }
}

void registration(int client_fd)
{
        string username,password,user,pass;
        LOG_INFO("Enter the username :");
        cin>>username;
        LOG_INFO("\nEnter the password :");
        cin>>password;

        ofstream registration("database.txt",ios::app);
        registration<<username<<' '<<password<<endl;
        LOG_INFO("\nRegistration Sucessful\n");
        login(client_fd);

        exit(1);

}
//void menu(int client_fd)
 /*
int main()
{
        LOG_INIT();
        int choice;

        LOG_INFO("welcome");
        LOG_INFO("\n1.Login");
        LOG_INFO("2.register");
        LOG_INFO("enter choice");
        cin>>choice;
        switch(choice){
                case 1:
                        login();
                        break;
                case 2:
                        registration();
                        login();
                        break;
                default:
                        cout<<"try agin";
        }

      LOG_DEINIT();
        return 0;
} */
int main(int argc, char const* argv[])
{

    int sock = 0, valread, client_fd;

    struct sockaddr_in serv_addr;
    char* hello = "Hello from client";

    char buffer[1024] = { 0 };

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {

        printf("\n Socket creation error \n");

        return -1;

    }
    else {
	    cout<<"Socket created successfully"<<endl;
    }
    serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(PORT);


    // Convert IPv4 and IPv6 addresses from text to binary
// form

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)

		    <= 0) {

        printf( "\nInvalid address/ Address not supported \n");

        return -1;

    }
    else {
	   
	    cout<<"Binding successful"<<endl;
    }

    if ((client_fd

         = connect(sock, (struct sockaddr*)&serv_addr,

                   sizeof(serv_addr)))

        < 0) {

        printf("\nConnection Failed \n");
        return -1;
 }
    else {

	    cout<<"connnection successful"<<endl;
    }
      
   
    LOG_INIT();
        int choice;

        LOG_INFO("welcome");
        LOG_INFO("\n1.Login");
        LOG_INFO("2.register");
        LOG_INFO("enter choice");
        cin>>choice;
        switch(choice){
                case 1:
                        login(client_fd);
                        break;
                case 2:
                        registration(client_fd);
                        login(client_fd);
                        break;
                default:
                        cout<<"try agin";
        }

      LOG_DEINIT();


    return 0;

}
