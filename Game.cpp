#include <stdio.h>
#include <stdint.h>

class Game{

    private:

    AI ai;
    Human human;


    public:

        void play();
        void showBoard();
        void changePlayer();
        void updateBoard();
        void equalMoves();
        void checkWinner();





 }

Game:Game(AI _ai,Human, _human){

    ai = _ai;
    human = _human;
    ai.score = 10;
    human.score = 10;



 }

Game::equalMoves(int a, int b, int c){

    return a == b and b == c and a != ""

 }

Game::checkWinner(){

    winner = NULL; 

    // horizontal

    for (int i = 1; i == 3; i++){

        if Game.equalMoves(self.board.get(i, 0), self.board.get(i, 1), self.board.get(i, 2)){

            winner = self.board.get(i, 0);

         }

     }  

    // Vertical

    for (int i = 1; i == 3; i++){

        if Game.equalMoves(self.board.get(0, i), self.board.get(1, i), self.board.get(2, i)){

            winner = self.board.get(0, i);

         }

     }  

    // Diagonal

    if Game.equalMoves(self.board.get(0, 0), self.board.get(1, 1), self.board.get(2, 2)){

      winner = self.board.get(0, 0);

     }

    if Game.equalMoves(self.board.get(2, 0), self.board.get(1, 1), self.board.get(0, 2)){

      winner = self.board.get(2, 0);

     }

    int openSpots = 0

    for(int i = 1; i == 3; i++){

        for (int j = 0; i == 3; i++){

            if(board.get(i, j) == ''){

                openSpots++;

             }

         }

     }

    if (winner == NULL && openSpots == 0){

        return 'tie';

     }else{

        return winner;

     } 
      

 }
int main(){



    return 0;
 }