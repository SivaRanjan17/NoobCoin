#ifndef WALLET_H
#define WALLET_H
#include <stdlib.h>
#include <iostream>

using namespace std;


class Wallet
{
    public:
        Wallet(int, float);
        ~Wallet();

        float getBalance();
        void SubBalance(float);
        void AddBalance(float);

        string privatekey;
        string publickey;

        void GenerateKeyPair();

        int ID;
        float balance;

};

#endif // WALLET_H
