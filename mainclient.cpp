#include <arpa/inet.h>
#include<iostream>
#include <string.h>
#include <sys/socket.h>
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
};
class travel{
        public:
                travel(){
                        cout<<"travel booking app";
                }
void loadUser(User arr[], int size);
bool findUser(User arr[], int size, User toFind);
		
 void admin_login();
};
*/
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
    serv_addr.sin_family = AF_INET;

    serv_addr.sin_port = htons(PORT);


    // Convert IPv4 and IPv6 addresses from text to binary
// form

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)

        <= 0) {

        printf( "\nInvalid address/ Address not supported \n");

        return -1;

    }


    if ((client_fd

         = connect(sock, (struct sockaddr*)&serv_addr,

                   sizeof(serv_addr)))

        < 0) {

        printf("\nConnection Failed \n");
        return -1;
 }
travel t;


t.menu();
    return 0;

}
