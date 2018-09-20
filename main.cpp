#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "picosha2.h"

using namespace std;

 struct Node
{
    string hex;
    Node *next;
};

class Linked_List
{
    private:
        Node *head;

   public:

        Linked_List()
        {
            head = NULL;
        }

        Node* createnode(string thex)
        {
            Node *node = new Node;

            node->hex = thex;
            node->next = NULL;

            return node;
        }

        void Insert(string thex)
        {

            Node *node = createnode(thex);

            if (head == NULL)
            {
                head = node;
            }

            else
            {
                Node *p = head;

                while(p->next != NULL)
                {
                    p = p->next;
                }

                p->next = node;
            }
        }

        void Display()
        {
            if (head == NULL)
            {
                cout << "\nList empty!";
            }

            else
            {
                Node *p;

                p = head;



                while (p != NULL)
                {
                    cout << "\n" << p->hex;
                    p = p->next;
                }
            }
        }
/**
        Node* Find_Node(int ID)
        {
            if (head == NULL)
            {
                return NULL;
            }

            else
            {
                Node *p;

                p = head;

                while (p != NULL)
                {
                    if (p->next->Stud_ID == ID)
                    {
                        return p;
                    }

                    p = p->next;

                }

                return NULL;
            }

            return NULL;
        }

        void Delete_Node(int val)
        {
            Node *dp, *q;

            dp = Find_Node(val);

            if (dp == NULL)
            {
                cout << "\nDeletion Not Possible";
            }

            else
            {
                q = dp->next;

                dp->next = dp->next->next;

                delete q;

                cout << "Record Deleted!";
            }
        }
**/
        void Display_Node(string val)
        {
            Node *p, *q;

            p = head;

            q = NULL;

            if (p->next == NULL && p->hex == val)
            {
                q = p;
            }

            else
            {
                while (p != NULL)
                {
                    if (p->next->hex == val)
                    {
                            q = p;
                    }

                        p = p->next;
                }

            }

            if (q == NULL)
            {
                cout << "\nRecord not available";
            }

            else
            {
                cout << "\nRecord Found!";
                cout << "\nHash: " << q->hex;
            }
        }
};



class Block
{

    private :

        string data;
        string timestamp;
        int nonce;

    public:

        string hash;
        string previousHash;


        Block(string tdata, string tpreviousHash)
        {
            data = tdata;
            previousHash = tpreviousHash;
            time_t my_time = time(NULL);
            timestamp = ctime(&my_time);
            hash = calculateHash();
            nonce = 0;
            cout << "\nHash: " << hash;
        }

        string appySha256(const string& input)
        {
            string hex;
            hex = picosha2::hash256_hex_string(input);
            return hex;
        }

        string calculateHash()
        {

            string calculatedhash = appySha256(previousHash + timestamp + data);
            return calculatedhash;
        }

        Block()
        {

        }

        void MineBlock(int nDifficulty)
        {
            char cstr[nDifficulty + 1];
        for (uint32_t i = 0; i < nDifficulty; ++i)
        {
            cstr[i] = '0';
        }

        cstr[nDifficulty] = '\0';

        string str(cstr);

        do
        {
            nonce++;
            hash = calculateHash();
        }while (hash.substr(0, nDifficulty) != str);

        cout << "Block mined: " << hash << endl;
}


};



int main()
{

    Linked_List NoobChain;

    Block GenesisBlock("SIVA", "0");

    NoobChain.Insert(GenesisBlock.hash);

    Block Block2("RANJAN", GenesisBlock.hash);

    NoobChain.Insert(Block2.hash);

    Block Block3 ("M", Block2.hash);

    NoobChain.Insert(Block3.hash);

    ///NoobChain.Display();

    Block3.MineBlock(1);


//
   // cout << "\nHash1: " << GenesisBlock.hash;

    cout << "Hello WOrlf";

}
