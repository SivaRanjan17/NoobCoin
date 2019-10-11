#include <cstdint>
#include <iostream>
#include "Transaction.h"
#include <vector>

using namespace std;

class Block
{
public:

    string PrevHash;

    Block (uint32_t IndexIn, const string &DataIN);

    string GetHash();

    void MineBlock (uint32_t Difficulty);

    Block();

    string getMerkleRoot();

private:

    uint32_t Index;
    int64_t Nonce;
    string Data;
    string Hash;
    time_t Time;
    //Transaction transaction;

    string CalculateHash() const;
};


