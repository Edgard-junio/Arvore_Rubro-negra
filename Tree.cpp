#include <iostream>
#include "Tree.h"

using std::cout;
using std::endl;

Tree::Node* Tree::newNode(int iValor, Color color)
{
    Tree::Node* ptrTemp = (Node*)malloc(sizeof(Node)); //Criando um nó com o tmanho de um Node

    //Atualizando os parametros
    ptrTemp->iData = iValor;
    ptrTemp->color = color;
    ptrTemp->ptrLeft = nullptr;
    ptrTemp->ptrRight = nullptr;
    ptrTemp->ptrParent = nullptr;

    return ptrTemp;

}

void Tree::insertTreeNode(Node** head, int iValor)
{
    Tree::Node* ptrTemp = Tree::newNode(iValor, Black); //Como não sabemos sua posição iniciamos com a cor Black

    if((*head) == nullptr)
    {
        (*head) = ptrTemp;
        return;
    }

    Node* current = (*head);
    Node* ptrParent = nullptr;
    int count = 1;//Criamos um contador para saber em que nével da Arvore estamos e poder definir a cor do nó

    while (current != nullptr)
    {
        count = count + 1;
        ptrParent = current;

        if(current->iData <= iValor)
        {
            current = current->ptrLeft;
        }
        else if(current->iData > iValor)
        {
            current = current->ptrRight;
        }
        else
        {
            return; // Tratando uma possível exeção
        }

    }

    ptrTemp->ptrParent = ptrParent; //definindo o nó pai

    if(count % 2 == 0)
    {
        ptrTemp->color = Red; //como estamos em um nível par vamos definir a cor como Red
    }
    if(ptrParent->iData <= iValor)
    {
        ptrParent->ptrLeft = ptrTemp;
    }
    else
    {
        ptrParent->ptrRight = ptrTemp;
    }
}

void Tree::showTree(Node* head)
{
    if(head == nullptr)
    {
        return;
    }
    
    cout << "Valor do nó = " << head->iData << " Sua cor é " << (head->color == Red ? "Red" : "Black") << endl;
    Tree::showTree(head->ptrLeft);
    Tree::showTree(head->ptrRight);
}
