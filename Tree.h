//
// Created by gospo on 20.11.2024.
//

#ifndef LAB3_TREE_H
#define LAB3_TREE_H


class Node{
    char d;	 //тег узла
    Node * lft;	// левый сын
    Node * rgt;	// правый сын
public:
    Node() : lft(nullptr), rgt(nullptr) { } // конструктор узла
    ~Node(){
        if(lft) delete lft; // деструктор (уничтожает поддерево)
        if (rgt) delete rgt;
    }
    friend class Tree;	// дружественный класс «дерево»
} ;
// Класс «дерево в целом»
class Tree
{
    Node * root;	// указатель на корень дерева
    char num, maxnum;		//счётчик тегов и максимальный тег
    int maxrow, offset;		//максимальная глубина, смещение корня
    char ** SCREEN;	// память для выдачи на экран
    void clrscr();	// очистка рабочей памяти
    Node* MakeNode(int depth);	// создание поддерева
    void OutNodes(Node * v, int r, int c); // выдача поддерева
    Tree (const Tree &);	// фиктивный конструктор копии



public:
    Tree(char num, char maxnum, int maxrow);
    ~Tree();
    void MakeTree() // ввод — генерация дерева
    {
        root = MakeNode(0);
    }
    bool exist() {
        return root != nullptr;
    } // проверка «дерево не пусто»
    int BFS();	// обход «в ширину»
    void OutTree();	// выдача на экран
    int CountLeaves(); // Подсчёт листьев
private:
    int CountLeaves(Node* node); // Вспомогательная функция
};


#endif //LAB3_TREE_H
