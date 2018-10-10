#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "Block.h"

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
};

#endif // BLOCKCHAIN_H
