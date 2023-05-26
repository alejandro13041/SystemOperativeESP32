#include <iostream>
#include <ctime>
#include <string>
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <vector>
//using namespace std;


struct Wifi{

    std::string ssid;
    std::string password;
    std::string ap_ssid;
    std::string ap_password;

    std::vector<std::string> list_ssid;
    std::vector<std::string> list_pass; 





 };
struct Data{

    /*string variables */

    std::string user;
    std::string pass;
 
    /*bool variables*/

    bool session = false;

 };

bool check_user(std::string user){

    if (user == "root"){
        return 1;
    }
    
    return 0;
 }
bool check_pass(std::string pass){

    if (pass == "123456789"){
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
void session(Data& data){

    if (check_user(data.user) == 1 && check_pass(data.pass) == 1){
       std::cout<<"[main] login successfully"<<'\n';    
       system("cls");
       data.session = true;



     }else{

       std::cout<<"[main] exit"<<'\n';
       data.session = false;


     }


    
 }  

void load_wifi(Wifi& wifi){ //Optional with a map with key relations 

    /* load ssid networks */

    wifi.list_ssid.push_back("C_O_N_E_C_T_I_V_E");   
    wifi.list_ssid.push_back("ETITC-DOCENTES");

    std::cout<<"[main] number of SSID:"<<'\n';

    /*load passwords networks*/

    wifi.list_pass.push_back("28546429");
    wifi.list_pass.push_back("Navegar2018..");

 } 
int main(){

    Data data;
    
    std::cout<<"Welcome Administrator:"<<'\n';
    std::cout<<"[main] user:";
    std::cin>>data.user;
    std::cout<<"[main] pass:";   
    std::cin>>data.pass;   
    session(data);

    std::cout<<"load modules"<<'\n';
    time();

    Wifi wifi;

    std::cout<<"load modules"<<'\n';
    time();

    




     






    


    return 0;
}