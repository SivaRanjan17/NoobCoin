#include <iostream>
#include <stdlib.h>
#include "Transaction.h"
#include "Wallet.h"
#include "Blockchain.h"

using namespace std;

int main()
{
    int amt;

    cout << "\nEnter starting amount for Person A: ";
    cin >> amt;

    Wallet A(1, amt);

    cout << "\nEnter starting amount for Person B: ";
    cin >> amt;

    Wallet B(2, amt);

    Blockchain bChain = Blockchain();

    Transaction T1(A, B, 50);
    A.SubBalance(50);
    B.AddBalance(50);

    cout << "\nBalance of Wallet A: " << A.getBalance() << " NC";
    cout << "\nBalance of Wallet B: " << B.getBalance() << " NC";

    cout << "\nMining Block 1: ";
    bChain.AddBlock(Block(1, T1.calculateHash()));

    Transaction T2(B, A, 300);
    A.AddBalance(300);
    B.SubBalance(300);

    cout << "\nBalance of Wallet A: " << A.getBalance() << " NC";
    cout << "\nBalance of Wallet B: " << B.getBalance() << " NC";

    cout << "\nMining block 2: ";
    bChain.AddBlock(Block(2, T2.calculateHash()));



    bChain.isChainValid();

    return 0;

}
