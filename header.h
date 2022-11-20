#include<iostream>
#include<fstream>
using namespace std;
#define MAX_length 20
char admin[MAX_length]="Tour.txt";
char user[MAX_length]="Reservation.txt";

struct tour{
        char admin_place[MAX_length],admin_code[MAX_length],admin_country[MAX_length],admin_days[MAX_length],admin_prices[MAX_length],admin_payments[MAX_length];
        char user_phone[MAX_length],user_name[MAX_length],user_people[MAX_length],user_date[MAX_length],user_status[MAX_length],user_dcode[MAX_length],user_prices[MAX_length],user_payments[MAX_length];
};
/*
class travel{
             public:
             travel()
             {
                 cout<<"Travel Booking App"<<endl;
             }

                void menu();
                void admin_login();
                void admin_package(tour r);
                 tour admin_showpackage(char a[]);
                    void admin_writedata();
                    void admin_display();
                    void admin_modify();
                    void user_registration();
                    void user_login();
                    void user_forgot();
                    void user_package(tour r);
                    tour user_showpackage(char a[]);
                    void user_writedata();
                    void user_display();
                    void user_search();
                    void user_cancel();
};

  */                          
