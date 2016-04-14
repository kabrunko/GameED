#pragma once
#define DEFAULTSIZE 10;

// Classe StaticStack
template <class T>
class StaticStack
{
public:
	StaticStack();				// Construtor padrão
	StaticStack(int);			// Construtor com tamanho definido pelo usuário

	~StaticStack();				// Destrutor de pilha

	bool push(T);				// Push
	T pop();				// Pop

	bool isFull();				// Verifica se a pilha está cheia
	bool isEmpty();				// Verifica se a pilha está vazia

	T getTop();				// Retorna item do topo da pilha

private:
	T * node;				// Ponteiro do tipo pilha
	int top;				// Índice do topo da pilha
	int max;				// Tamanho máximo da pilha
};

