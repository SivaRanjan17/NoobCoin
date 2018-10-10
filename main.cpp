#include <iostream>

#include "Blockchain.h"

using namespace std;

int main()
{
    Blockchain bChain = Blockchain();

    cout << "Mining Block 1: ";
    bChain.AddBlock(Block(1, "Block 1 Data"));

    bChain.isChainValid();

    return 0;
}
