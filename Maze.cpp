#include "Maze.h"
#include <ctime>
#include <string>

Maze::Maze()
{
    root = NULL;
}

Maze::~Maze()
{
    deleteAll(root);
}
void Maze::movement(){
    movement(root);
}

int health = 3; //initializes health


/**
The movement function controls all of the traversal of the tree. This includes
finding paths, right, left, or backwards, checking for extra health pick ups, clues, and exits or dead ends.
As well as taking in all of the user's choices or restarting to the menu once the game has ended
**/
void Maze::movement(block * node){
    std::string choice;
    int ending = 0;
    node->visited = true; //states the node the user is on has been visited
    if(node->heart == true){ //checks if the node has the extra heart
        health=health+1;
        std::cout<<std::endl;
        std::cout<<"You've found a life!"<<std::endl;
        std::cout<<"Health: "<<health<<std::endl;
        std::cout<<std::endl;
    }
    if(node->clue == true){
        clues(node); //calls the clue function that checks if there's an ending close by
    }

    if(node->leftChild != NULL && node->rightChild != NULL){  //this whole chunk of code checks the various paths available then takes in the users input and recursively calls the movement function
        std::cout<<std::endl;
        std::cout<<"Right path or left path? Or back? (r/l/b)"<<std::endl;
        std::cout<<std::endl;
        if(node->leftChild->visited == true && node->rightChild->visited == true){
            std::cout<<"Left and right have been visited"<<std::endl;
            std::cout<<std::endl;
        }else if(node->leftChild->visited == true){
            std::cout<<"Left has been visited"<<std::endl;
            std::cout<<std::endl;
        }else if(node->rightChild->visited == true){
            std::cout<<"Right has been visited"<<std::endl;
            std::cout<<std::endl;
        }
        std::cin>>choice;
        std::cin.ignore();
        if(choice == "l"){
            std::cout<<"You move left."<<std::endl;
            std::cout<<std::endl;
            movement(node->leftChild);
        }else if(choice == "r"){
            std::cout<<"You move right."<<std::endl;
            std::cout<<std::endl;
            movement(node->rightChild);
        }else if(choice == "b"){
            if(node == root){//checks if player tries to go back but is currently at the root
                std::cout<<"Can't go back."<<std::endl;
                std::cout<<std::endl;
                movement(node);
            }else{
            std::cout<<"You move back."<<std::endl;
            std::cout<<std::endl;
            movement(node->parent);
            }

        }else{
            std::cout<<"Unexpected response, exiting."<<std::endl;//if input is something other than left right or back the function is called again with the same current node
            std::cout<<std::endl;
            movement(node);
        }
    }else if(node->leftChild != NULL && node->rightChild == NULL){
        std::cout<<std::endl;
        std::cout<<"Only a left path ahead, take it or go back? (l/b)"<<std::endl;
        std::cout<<std::endl;
        if(node->leftChild->visited == true){
            std::cout<<"Left has been visited"<<std::endl;
            std::cout<<std::endl;
        }
        std::cin>>choice;
        std::cin.ignore();
        if(choice == "l"){
            std::cout<<"You move left."<<std::endl;
            std::cout<<std::endl;
            movement(node->leftChild);
        }else if(choice == "b"){
            if(node == root){ //checks if player tries to go back but is currently at the root
                std::cout<<"Can't go back."<<std::endl;
                std::cout<<std::endl;
                movement(node);
            }else{
            std::cout<<"You move back."<<std::endl;
            std::cout<<std::endl;
            movement(node->parent);
            }
        }else{
            std::cout<<"Unexpected response, try again."<<std::endl; //if input is something other than left right or back the function is called again with the same current node
            std::cout<<std::endl;
            movement(node);
        }
    }else if(node->leftChild == NULL && node->rightChild != NULL){
        std::cout<<"Only a right path ahead, take it or go back? (r/b)"<<std::endl;
        std::cout<<std::endl;
        if(node->rightChild->visited == true){
            std::cout<<"Right has been visited"<<std::endl;
            std::cout<<std::endl;
        }
        std::cin>>choice;
        std::cin.ignore();
        if(choice == "r"){
            std::cout<<"You move right."<<std::endl;
            std::cout<<std::endl;
            movement(node->rightChild);
        }else if(choice == "b"){
            if(node == root){//checks if player tries to go back but is currently at the root
                std::cout<<"Can't go back."<<std::endl;
                std::cout<<std::endl;
                movement(node);
            }else{
            std::cout<<"You move back."<<std::endl;
            std::cout<<std::endl;
            movement(node->parent);
            }
        }else{
            std::cout<<"Unexpected response, exiting."<<std::endl;
            std::cout<<std::endl;
            movement(node);
        }
    }else if(node->leftChild == NULL && node->rightChild == NULL){
        if(node->ends == 1){
            std::cout<<std::endl;
            std::cout<<std::endl;
            std::cout<<"You've reached an exit! You won!"<<std::endl;
            std::cout<<"Your final health: "<<health<<std::endl;
            std::cout<<std::endl;
            std::cout<<std::endl;
            //break;
        }else if(node->ends == 2){
            if(health == 0){
                std::cout<<std::endl;
                std::cout<<std::endl;
                std::cout<<"You've died, game over."<<std::endl;
                std::cout<<std::endl;
                std::cout<<std::endl;
            }else{
                std::cout<<std::endl;
                std::cout<<"You've reached a dead end, you lose a heart. Do you want to quit or start at the beginning? (q/b). Health: "<<health<<std::endl;
                std::cin>>choice;
                std::cin.ignore();
                health = health - 1;
                if(choice=="b"){ //if q or another input is taken game will exit to the menu
                    movement(root);
                }
            }
        }
    }
    //}
}








void Maze::deleteAll(){ //public funtion of the delete all used to call the private function
    deleteAll(root);
    root=NULL;
}





void Maze::deleteAll(block * node){ //deletes current tree
    if(node){
        deleteAll(node->leftChild);
        deleteAll(node->rightChild);
        //std::cout<<"Deleting: "<<node->name<<std::endl;
        delete(node);
    }
}



int Maze::ran(){ //used to save some typing when using the multiple random functions throughout this code
    //srand(time(NULL));
    int ran = rand() % 100; //choses a number between 0-99
    return ran;
}






void Maze::placeHealth(){ //this function choses a random node to place a heart
    //srand(time(NULL));
    int heart = ran();//rand() % 100; //calls the random function
    block *heartBlock = search(heart); //pointer node toward node search returns

    if(!heartBlock){ //if search returns NULL
        placeHealth(); //recursively calls the funtion to try and find a match with a different number
        return;
    }
    //std::cout<<"end at: "<<heartBlock->name<<std::endl; //this was used for checking
    heartBlock->heart = true;
}




void Maze::placeClues(){ //choses a random block to place a clue at
    //srand(time(NULL));
    int clue;

        clue = ran();//rand() % 100;
        block *clueBlock = search(clue); //pointer node toward node search returns

        if(!clueBlock){ //if search returns NULL
            placeClues();
            return;
        }
        // std::cout<<"CLUE at: "<<clueBlock->name<<std::endl; //used to check
        clueBlock->clue = true; //makes the bool clue true of the node

}








void Maze::clues(block* node){ //used to check if an ending is within 2 moves
       std::cout<<"You've found a note!"<<std::endl;
       block* temp = node;
        int loop = 0; //loop is used to determine if the exit is within two moves or more than
       while(temp->leftChild != NULL && temp->rightChild != NULL){//this while loop checks to see how far an ending is and adds to the int loop every time the loop is iterated
            if(temp->leftChild != NULL){
                temp = temp->leftChild;
            }else if(temp->rightChild != NULL){
                temp->rightChild;
            }

            loop = loop + 1;
       }
       //std::cout<<loop<<std::endl; //checking

       if(loop <= 2){
        std::cout<<"It says there's an exit or dead end within two moves"<<std::endl;
       }else{
        std::cout<<"It says there's an exit or dead end more than two moves away"<<std::endl;
       }


}





int Maze::leafCount(block* node){ //used to count the amount of leaf nodes as well as assign them as exits or dead ends
    int ends;
    if(node == NULL){
    return 0;
    }
    if(node->leftChild == NULL && node->rightChild==NULL){
        int ends = ran(); //used to determine whether or not a leaf node will be an exit or dead end
        if(ends < 30){ //less likely to get an exit
            node->ends = 1; // if ends = 0 its a normal node, 1 is an exit, 2 is a dead end
        }else{
            node->ends = 2;
        }
        //std::cout<<node->ends<<std::endl; //used for debugging
        return 1;
    }
    else{
        return leafCount(node->leftChild)+
               leafCount(node->rightChild);
    }
}




block* Maze::search(int trophy){ //searching function
    block* temp = root;
    while(temp){ //while temp has a value
        if(temp->name > trophy){  //if that value is greater than title
            temp = temp->leftChild; //move temp to next left child
        }else if(temp->name < trophy){ //otherwise do the same for right child
            temp = temp->rightChild;
        }else{
            return temp; //returns when it has found the node
        }
    }
    return NULL; //otherwise it returns null if nothing is found
}




void Maze::buildMaze(int diff){ //builds a randomized tree
    srand(time(NULL)); //necessary in order to get different random values every time the random function is called
    for(int i = 0; i<diff+20;i++){
        int ran100 = rand() %100; //finds random value between 0-99
        if(root != NULL){ //if root has a value
            block *temp = root; //create temp pointer pointing at root
            block *newNode = new block(ran100);
            while(temp != NULL){
                if(ran100 < temp->name){ //checks is title is less than temp title
                    if(temp->leftChild !=NULL){ //if leftchild has a value move to next left child
                        temp = temp->leftChild;

                    }else{
                        temp->leftChild= newNode;
                        newNode->parent = temp;
                        //std::cout<<"blockleft: "<<newNode->name<<"parent: "<<temp->name<<std::endl; //checking again
                        break;
                    }

                }else{ //otherwise if title is greater than temp title
                    if(temp->rightChild != NULL){ //if rightchild has a value move to next right child
                        temp = temp ->rightChild;
                    }else{ //otherwise if print child and exit the loop
                        temp->rightChild = newNode;
                        newNode->parent =temp;
                        std::cout<<"blockright: "<<newNode->name<<"parent: "<<temp->name<<std::endl;
                        break;
                    }
                }
            }

        }else{
            root = new block(ran100); //if root is null create root
            std::cout<<"root: "<<root->name<<std::endl;


        }
    }

    std::cout<<"Leaves: "<<leafCount(root)<<std::endl;
    //placeClues();
}
void Maze::printMaze(){ //public print movie declaring the private one as the node being root
    printMaze(root);
}

void Maze::printMaze(block* node){
    if(node != NULL){
        printMaze(node->leftChild); //calls function with left child of node as new node in argument
                                                //calls until leftChild==NULL where it prints the title and quantity
        std::cout<<"block: "<<node->name<<std::endl;
        printMaze(node->rightChild); //once printed moves to right node and repeats
    }

};


