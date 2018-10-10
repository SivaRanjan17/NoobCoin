#include "Blockchain.h"
///#include "Block.h"
#include <iostream>

using namespace std;

Blockchain::Blockchain()
{
    Chain.emplace_back(Block(0, "Genesis Block"));
    Difficulty = 5;
}



void Blockchain::AddBlock(Block bNew)
{
    bNew.PrevHash = GetLastBlock().GetHash();
    bNew.MineBlock(Difficulty);
    Chain.push_back(bNew);
}

Block Blockchain::GetLastBlock() const
{
    return Chain.back();
}

void Blockchain::isChainValid()
{
    for (vector<int>::iterator it = Chain.begin(); it != Chain.end(); ++it)
    {
        cout << "\n: " << *it;
    }
}
