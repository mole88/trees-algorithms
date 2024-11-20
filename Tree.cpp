//
// Created by gospo on 20.11.2024.
//
#include "Tree.h"
#include <iostream>
#include <cstring>

Tree::Tree(char nm, char mnm, int mxr):
        num(nm), maxnum(mnm), maxrow(mxr), offset(40), root(nullptr),
        SCREEN(new char * [maxrow]){
    for(int i = 0; i < maxrow; ++i)
        SCREEN[ i ] = new char[80];

}

Tree::~Tree( ) {
    for(int i = 0; i < maxrow; ++i)
        delete [ ]SCREEN[ i ];
    delete [ ]SCREEN; delete root;
}

Node * Tree :: MakeNode(int depth){
    Node * v = nullptr;
    int Y = (depth < rand( )%6+1) && (num <= 'z'); //Вариант: cout << "Node (" << num << ',' << depth << ")1/0: "; cin >> Y;
    if (Y) {	// создание узла, если Y = 1
        v = new Node;
        v->d = num++;	 // разметка в прямом порядке (= «в глубину»)
        v->lft = MakeNode(depth+1);
        //	 v->d = num++;          //вариант — во внутреннем
        v->rgt = MakeNode(depth+1);
        //	 v->d = num++;		// вариант — в обратном
    }
    return v;
}

void Tree :: OutTree( ){
    clrscr( );
    OutNodes(root, 1, offset);
    for (int i = 0; i < maxrow; i++)
    {
        SCREEN[ i ][ 79 ] = 0;
        std::cout << '\n' << SCREEN[ i ];
    }
    std::cout << '\n';
}

void Tree :: clrscr( ){
    for(int i = 0; i < maxrow; i++)
        memset(SCREEN[i], '.', 80);
}

void Tree :: OutNodes(Node * v, int r, int c){
    if (r && c && (c<80))
        SCREEN[r - 1][c - 1] = v->d; // вывод метки
    if (r < maxrow) {
        if (v->lft) OutNodes(v->lft, r + 1, c - (offset >> r)); //левый сын
        if (v->rgt) OutNodes(v->rgt, r + 1, c + (offset >> r)); //правый сын
    }
}

template <class Item> class QUEUE
{
    Item * Q; int h, t, N;
public:
    QUEUE(int maxQ): h(0), t(0), N(maxQ), Q(new Item[maxQ + 1]) { }
    int empty( ) const {
        return (h % N) == t;
    }
    void push(Item item) {
        Q[ t++ ] = item;
        t %= N;
    }
    Item pop( ) {
        h %= N;
        return Q[ h++ ];
    }
};

int Tree :: BFS( ){
    const int MaxQ = 20; //максимальный размер очереди
    int count = 0;
    QUEUE <Node *> Q(MaxQ);  //создание очереди указателей на узлы
    Q.push(root); // QUEUE <- root поместить в очередь корень дерева
    while (!Q.empty( )) //пока очередь не пуста
    {
        Node * v = Q.pop( );// взять из очереди,
        std::cout << v->d << '_'; count++; // выдать тег, счёт узлов
        if (v->lft) Q.push(v->lft); // QUEUE <- (левый сын)
        if (v->rgt) Q.push(v->rgt); // QUEUE <- (правый сын)
    }
    return count;
}

int Tree::CountLeaves() {
    return CountLeaves(root);
}

// Рекурсивная вспомогательная функция
int Tree::CountLeaves(Node* node) {
    if (node == nullptr)
        return 0; // Если узел пустой, возвращаем 0

    if (node->lft == nullptr && node->rgt == nullptr)
        return 1; // Узел — лист, возвращаем 1

    // Рекурсивно подсчитываем листья в левом и правом поддеревьях
    return CountLeaves(node->lft) + CountLeaves(node->rgt);
}





