//client
#include <arpa/inet.h>
#include<iostream>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include<fstream>
#include"header.h"
#include"functions.h"
#include"tour.cpp"
#include"reservations.cpp"
#include"main.cpp"

#define MAX_length 20
using namespace std;
#define PORT 8080

int main(int argc, char const* argv[])
{

    int sock = 0, valread, client_fd;

    struct sockaddr_in serv_addr;

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
    
     travel t;
    t.menu();
   


    return 0;

}
