#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <vector>
//using namespace std;

/* include libs*/

#include "database.h"



 
#define color SetConsoleTextAttribute


bool check_user(std::string user){

    if (user == "root"){
        return 1;
    }
    
    return 0;
 }
bool check_pass(std::string pass){

    if (pass == "root"){
        return 1;
    }

    return 0;
 }
void time(){
    
    Sleep(1000);
    std::cout<<".";
    Sleep(1000);
    std::cout<<".";
    Sleep(100);
    std::cout<<".";
    system("cls"); 

 }
void CSession(Session& session){

    if (check_user(session.user) == 1 && check_pass(session.pass) == 1){
       std::cout<<"[main] login successfully"<<'\n';    
       system("cls");
       session.state = true;

     }else{

       std::cout<<"[main] exit"<<'\n';
       session.state = false;


     }


    
 }  

void load_wifi(std::vector<Wifi>& w1){ //Optional with a map with key relations 

    /* load ssid networks */

   // w1.ssid.push_back("C_O_N_E_C_T_I_V_E");   
   // w1.ssid.push_back("ETITC-DOCENTES");

   // std::cout<<"[main] number of SSID:"<<'\n';

    /*load passwords networks*/

   // w1.password.push_back("28546429");
   // w1.password.push_back("Navegar2018..");

 } 
 

int main(){
	
	

    Session session;
    
    color(hConsole,amarillo);
    std::cout<<"Welcome Administrator:"<<'\n';
    std::cout<<"[main] user:";
    std::cin>>session.user;
    std::cout<<"[main] pass:";   
    std::cin>>session.pass;   
    CSession(session);

    color(hConsole,15);
    std::cout<<"load modules"<<'\n';
    time();

    
    
    
    
    add_user("user1","password1","user1@mail.com","root1");
    add_user("user2","password2","user2@mail.com","root2");
    add_user("user3","password3","user3@mail.com","root3");
    add_user("user4","password4","user4@mail.com","root4");
    add_user("user5","password5","user5@mail.com","root5");


    
	
    printTable(TableRoot);
    system("pause");

    

    std::cout<<"load modules"<<'\n';
    load_wifi(WifiObject);
    time();

    return 0;
}
