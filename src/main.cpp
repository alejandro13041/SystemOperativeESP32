#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <vector>
//using namespace std;

/* include libs*/

#include "../lib/database.h"



 
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
       exit(-1);


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

    
    int option;

    std::cout<<"[main] options:"<<'\n';
    std::cout<<"[main] manual database:1"<<'\n';
    std::cout<<"[main] defect database:2"<<'\n';

    std::cin>>option;

    switch (option){

        case 1: 
        add_user_line();
        printTable(TableRoot);
		tableMemory(TableRoot);
		
         break;
        case 2: defect_database();
        printTable(TableRoot);
		tableMemory(TableRoot);
		break;
        case 3: std::cout<<"[main] option desaible:";break;
        case 4: std::cout<<"[main] option desaible:";break;
        case 5: std::cout<<"[main] option desaible:";break;
        default:
        
            std::cout<<"[main] doesn't this option:"<<'\n';

         break;

     }
     
     /*load to switch*/
	
    
    system("pause");

    

    std::cout<<"load modules"<<'\n';
    load_wifi(WifiObject);
    time();

    return 0;
}
