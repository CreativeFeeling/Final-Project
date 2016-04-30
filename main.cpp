#include <iostream>
#include "Maze.h"
#include <string>

using namespace std;

int main()
{
    Maze m;
    int userInput = 0;
    while(userInput != 3){
        cout<<"======The Maze======"<<endl;
        cout<<"1. Play!"<<endl;
        cout<<"2. Information"<<endl;
        cout<<"3. Quit"<<endl;
        cin>>userInput;
        cin.ignore();
        if(userInput ==1){
            int diff = 0;
            string name;
            cout<<"What's your name?"<<endl;
            cin.ignore();
            getline(cin, name);

            cout<<"What difficulty would you like? (0-10)"<<endl; //difficulty adds that number of nodes to the 20 node tree
            cin>>diff;
            cin.ignore();
            if(diff>10){
                cout<<"Too high of a difficulty. Try again."<<endl;
                cin>>diff;
                cin.ignore();
            }else if(diff<0){
                cout<<"Too low of a difficulty. Try again."<<endl;
                cin>>diff;
                cin.ignore();
            }
            m.buildMaze(diff); //calls build maze
            m.placeHealth(); //calls the random heart placing function
            for(int i = 0; i<3;i++){ //calls the clue placing function three times
                m.placeClues();
            }

            m.movement();//calls the movement function
            cout<<"Deleting Tree"<<endl;
            m.deleteAll();
            //m.printMaze();
        }else if(userInput == 2){
            cout<<"In this maze game you traverse a binary tree until you reach either a dead end"<<endl;
            cout<<"or an exit, all leaf nodes are one or the other. If you hit a dead end you lose"<<endl;
            cout<<"a life, which you start with three of. At some blocks you can find a life. To"<<endl;
            cout<<"play you are given up to three options: to move left, right, or backwards. Some"<<endl;
            cout<<" blocks have a clue which tell you if you are within two moves of an ending."<<endl;
            cout<<"Once you find an exit you are congratulated then the tree is deleted and you"<<endl;
            cout<<"are brought back to the menu. If you choose to play again your health will stay"<<endl;
            cout<<" the same from the last game you played. Good luck!"<<endl;


        }else if(userInput == 3){
            cout<<"Goodbye!"<<endl;
            return 0;
        }
    }

}
