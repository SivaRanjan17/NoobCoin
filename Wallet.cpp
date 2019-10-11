#include "Wallet.h"
#include <stdlib.h>



Wallet::Wallet(int id, float value)
{
    ID = id;
    balance = value;
}

Wallet::~Wallet()
{
    //dtor
}

void Wallet::GenerateKeyPair()
{
    publickey =  (100 + (rand() % (999 + 1 - 100)));

    privatekey = (100 + (rand() % (999 + 1 - 100)));

}

float Wallet::getBalance()
{
    return balance;
}

void Wallet::SubBalance(float value)
{
    balance -= value;
}

void Wallet::AddBalance(float value)
{
    balance += value;
}
