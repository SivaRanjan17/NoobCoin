#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "Block.h"
#include<cstdio>
#include<cstdlib>

struct Node
{
    Block block;
    Node *next;
    Node *prev;
};

using namespace std;

class Blockchain
{
    public:

        Blockchain();
        void AddBlock(Block bNew);
        void isChainValid();

    protected:

    private:

        uint32_t Difficulty;
        vector<Block> Chain;

        Block GetLastBlock() const;

        Node *start;
};

#endif // BLOCKCHAIN_H
