

#include <vector>
#include <string>
#include <iostream>

/*
 * lib:color
 * 
 * */
#include "color.h"




 

//using namespace std;

struct Session{

    std::string user;
    std::string pass;
    bool state;


 };

struct root{

    /*string*/    
    std::string user;
    std::string pass;
    std::string mail;
    std::string rank;

 };

std::vector<root> TableRoot;

void space(){

    std::cout<<"          ";

 }

 
 
void printTable(const std::vector<root>& r1){

    std::cout<<"+========================================================================+"<<'\n';
    std::cout<<" id          user          pass          mail          rank      sizeoff"<<'\n';   


    for (int i = 0; i < (int) r1.size(); i++){

		color(hConsole,14);
        std::cout<<" "<<i; space();
        color(hConsole,10);
        std::cout<<r1[i].user; space();
        color(hConsole,12);
        std::cout<<r1[i].pass; space();
        color(hConsole,11);
        std::cout<<r1[i].mail; space();
        color(hConsole,13);
        std::cout<<r1[i].rank; space();
        color(hConsole,15);
        std::cout<<'\n';
        //std::cout<<sizeof(r1[i])<<"bytes"<<'\n'; 

     } 
     
     color(hConsole,15);


    /*

        user: user1
        pass: password1
        mail: user1@mail.com
        rank: root

    */    

 }

void tableMemory(const std::vector<root>& r1){

    std::cout<<"+========================================================================+"<<'\n';
    std::cout<<"                                 table memory                             "<<'\n';
    std::cout<<"+========================================================================+"<<'\n';
    std::cout<<" id (bytes)          user(bytes)          pass(bytes)          mail(bytes)          rank(bytes)     object(bytes)"<<'\n';   


    for (int i = 0; i < (int) r1.size(); i++){

		color(hConsole,14);
        std::cout<<" "<<sizeof(i)<<"(bytes)"; space();
        color(hConsole,10);
        std::cout<<sizeof(r1[i].user)<<"(bytes)"; space();
        color(hConsole,12);
        std::cout<<sizeof(r1[i].pass)<<"(bytes)"; space();
        color(hConsole,11);
        std::cout<<sizeof(r1[i].mail)<<"(bytes)"; space();
        color(hConsole,13);
        std::cout<<sizeof(r1[i].rank)<<"(bytes)"; space();
        color(hConsole,15);
        std::cout<<sizeof(r1[i])<<"(bytes)"<<'\n'; 

     } 
     
     color(hConsole,15);


    /*

        user: user1
        pass: password1
        mail: user1@mail.com
        rank: root

    */


 }
    
void add_user(std::string user,std::string pass, std::string mail, std::string rank){

    root r1;

    r1.user = user;
    r1.pass = pass;
    r1.mail = mail;
    r1.rank = rank;

    TableRoot.push_back(r1);
    /*

        send commands:

    */

 } 
 
 void add_user_line(){

    std::cout<<"[main] start";

	root r1;

	std::cout<<"[main] string: user:";
	std::cin>>r1.user;
	std::cout<<"[main] string: pass:";
	std::cin>>r1.pass;
	std::cout<<"[main] string: mail:";
	std::cin>>r1.mail;
	std::cout<<"[main] string: rank:";
	std::cin>>r1.rank;
	
	TableRoot.push_back(r1);


 }

void defect_database(){

    add_user("user1","password1","user1@mail.com","root1");
    add_user("user2","password2","user2@mail.com","root2");
    add_user("user3","password3","user3@mail.com","root3");
    add_user("user4","password4","user4@mail.com","root4");
    add_user("user5","password5","user5@mail.com","root5");


 }

struct Wifi{

    std::string ssid;
    std::string password;   

 };

std::vector<Wifi> WifiObject;




