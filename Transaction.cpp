#include "Transaction.h"
#include "sha256.h"
#include <bits/stdc++.h>
#include "Wallet.h"
#include <iostream>
#include <sstream>

using namespace std;

Transaction::Transaction(Wallet from, Wallet to, float value)
{
    stringstream stemp;
    stringstream rtemp;

    cout << "\n" << from.balance << ": " << to.balance;

    if (checkBalance(from, value))
    {
        cout << "The  following transaction is  not valid!";
    }

    else
    {
        stemp << from.ID;
        rtemp << to.ID;
        sender = stemp.str();
        reciepient = rtemp.str();
        amount = value;
    }
}

Transaction::~Transaction()
{
    //dtor
}

bool Transaction::checkBalance(Wallet A, float value)
{
    if (A.balance - value < 0)
    {
        return true;
    }

    return false;
}

string Transaction::calculateHash()
{
    sequence ++;

    stringstream ss;

    ss << sender << reciepient << amount << sequence;

    return sha256(ss.str());
}

int Transaction::sequence = 0;
