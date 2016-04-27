#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <cstdlib>
struct block{
    bool visited;
    int ends;
    int name;
    bool clue;
    bool heart;
    block *parent = NULL;
    block *leftChild = NULL;
    block *rightChild = NULL;

    block(){};

    block(int num_name)
    {
        clue = false;
        heart = false;
        visited = false;
        ends = 0;
        name = num_name;
        leftChild = NULL;
        rightChild = NULL;
    }

};
class Maze
{
    public:
        Maze();
        ~Maze();
        int ran();
        //bool visited;
        void buildMaze(int diff);
        void printMaze();
        void placeHealth();
        void movement();
        int leafCount(block* node);
        block *root = NULL;
        void deleteAll();
        void clues(block* node);
        void placeClues();



    protected:
    private:
        void movement(block* node);
        void printMaze(block* node);
        void deleteAll(block *node);
        block *search(int trophy);

};

#endif // MAZE_H
