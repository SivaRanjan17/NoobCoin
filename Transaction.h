#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "Wallet.h"

using namespace std;


class Transaction
{
    public:
        Transaction(Wallet, Wallet, float);
        ~Transaction();
        bool checkBalance(Wallet, float);
        void Update_Balance(Wallet, Wallet, float);

        string calculateHash();
        string transactionId;
        string sender;
        string reciepient;
        float amount;
       // string signature;
        static int sequence;
        ///vector #not required for now
};

#endif // TRANSACTION_H
