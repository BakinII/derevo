#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;


class Uzel
{
public:
    int info;
    Uzel *right, *left , *parrent;

    Uzel()
    {
        right = left = parrent = NULL;
    }

};

class BinaryTree
{
public:
    Uzel *current;

    BinaryTree(int info)//�����������
    {
        current = new Uzel();
        current->info=info;
    }

    void createLeftSon(int info)//������� ������ �������
    {
        Uzel *p = new Uzel();
        p->info = info;
        p->parrent = current;
        current->left = p;
    }

    void createRightSon(int info)//������� ������� �������
    {
        Uzel *p = new Uzel();
        p->info = info;
        p->parrent = current;
        current->right = p;
    }

    void goLeft()//������� �������� �� ������ �������
    {
        current = current->left;
    }

    void goRight()//������� �������� �� ������� �������
    {
        current = current->right;
    }

    void goUp()//������� �������� �����(� ��������)
    {
        current = current->parrent;
    }

    void print(Uzel *r, int k = 0)//����� ������
    {
        if (r!=NULL)
        {
            print(r->right, k + 3);

            for (int i = 0; i < k; i++)
            {
                cout<<" ";
            }

            cout << r->info<<endl;
            print(r->left, k+3);
        }
    }



    void del(Uzel *current)//����� �������� ����
    {
        if (current->left!=NULL)
        {
            del(current->left);
        }

        if (current->right!=NULL)
        {
            del(current->right);
        }

        delete current;
    }
    friend void createidealtree(int a,BinaryTree* t) {
        int q;
        cin >> q;
        if (a > 1) {
            t->createLeftSon(q);
            t->goLeft();
            createidealtree(int(a / 2), t);
            t->goUp();
            t->createRightSon(q);
            t->goRight();
            createidealtree(int(a / 2), t);
        }
        if (a==1){
            t->createRightSon(q);
        }
    }
};

int main()
{
    BinaryTree *root = new BinaryTree(2);
    Uzel *start = root->current;
/*
    root->createLeftSon(7);
    root->goLeft();
    root->createLeftSon(2);
    root->createRightSon(6);
    root->goRight();
    root->createLeftSon(5);
    root->createRightSon(11);
    root->goUp();
    root->goUp();

    root->createRightSon(5);
    root->goRight();
    root->createRightSon(9);
    root->goRight();
    root->createLeftSon(4);
    root->goUp();
    root->goUp();

    root->goLeft();
   // root->del(root->current);
    root->print(start); //����� �������� exception!!!
*/
    int a;
    cout<<"vvedite koli4estvo vershin";
    cin>>a;
    createidealtree(a,root);
    root->print(start);
    system("pause");
    return 0;
}