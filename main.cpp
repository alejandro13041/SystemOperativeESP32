import serial as serial
import keyboard
import time

 

#include <Player.hpp>
#include <Game.hpp>
#include <AI.hpp>

void setup(){



 }

void loop(){

    human = Player("x", "Human");
    ai = AI("o", "TriquiBot");
    game = Game(ai, human);
    winner = game.checkWinner();
    printf("START");
    Sleep(3);

    while(winner == None){

      game.play();
      winner = game.checkWinner();

        if winner{

            print("Wins: ", winner);

         }

        if keyboard.is_pressed("q"){

            break;

         } 
     }

    except Exception as err{ //assert 

        print(str(err));

     }

 }