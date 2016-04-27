# Final-Project

Summary:

In this maze game you traverse a binary tree until you reach either a dead end or an exit, all leaf nodes are one or the other. If you hit a dead end you lose a life, which you start with three of. At some blocks you can find a life. To play you are given up to three options: to move left, right, or backwards. Some blocks have a clue which tell you if you are within two moves of an ending. Once you find an exit you are congratulated then the tree is deleted and you are brought back to the menu. If you choose to play again your health will stay the same from the last game you played. In the actual program, creating the tree consists of adding randomly numbered nodes to a tree for 20 nodes plus whatever difficulty the player inputs. To move the program checks whether or not there is a left or right path, checks if the current node has a clue or a heart, as well as changes the node to visited. The program randomly places one heart and three clues throughout the tree, these functions are based on a random number and a search through the tree, if the random number doesn't match any of the nodes numbers then the function will be called again until a match is made which is where the clue or heart will be placed. The clue function checks from the current node whether or not an exit or dead end is within 2 moves based on a while loop that loops until a leaf node is found and counts the number of loops iterated. If more than two are iterated the clue states that the endings are more than two moves away other wise it states that they are within two moves. There is a funtion that counts all of the leaf nodes and assigns them based on random which will be an exit or a dead end. 

How to Run:
  to run first enter "1" then your name and a number between 0 and 10. Then begin moving throughout the tree based on what paths are ahead of you. For example, a series of inputs could be: "1" "Kelsey" "7" "l" (to move left if possible) "r" (to move right if possible) and "b" to move backwards, or if you hit a dead end "b" to go to the root of the tree or "q" to quit to main menu.
  
  Contributors:
  
    Kody Newman, Jia, Mike.
  
  Bugs:
   None known at the moment.
