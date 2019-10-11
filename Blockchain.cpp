#include "Blockchain.h"
#include <iostream>
#include <vector>

using namespace std;

Blockchain::Blockchain()
{
    start = NULL;
    Chain.emplace_back(Block(0, "Genesis Block"));
    Difficulty = 5;
}



void Blockchain::AddBlock(Block bNew)
{
    bNew.PrevHash = GetLastBlock().GetHash();
    bNew.MineBlock(Difficulty);
    Chain.push_back(bNew);

    Node *s, *temp;
    temp = new Node;
    temp->block = bNew;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}


Block Blockchain::GetLastBlock() const
{
    return Chain.back();
}

void Blockchain::isChainValid()
{
    Block ver1,ver2;

    int _vFlag;

    int _cSize = Chain.size();

    for (int i = 1; i < _cSize; i++)
    {
        ver1 = Chain[i - 1];
        ver2 = Chain[i];

        if (ver2.PrevHash == ver1.GetHash())
        {
            _vFlag= 1;
        }

        else
        {
            _vFlag = 0;
            break;
        }
    }

    if (_vFlag == 1)
    {
        cout << "\nThe chain is valid!";
    }

    else
    {
        cout << "\nThe chain is not valid!";
    }
}
