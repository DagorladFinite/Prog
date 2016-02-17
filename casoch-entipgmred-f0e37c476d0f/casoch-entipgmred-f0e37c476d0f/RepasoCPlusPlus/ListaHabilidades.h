#pragma once
#include <iostream>
#include <vector>
#include "Habilidad.h"

class ListaHabilidades: public std::vector<Habilidad>
{

public:
	ListaHabilidades(ListaHabilidades& listahab);
	ListaHabilidades();
	~ListaHabilidades();
	void addAbility(Habilidad a);
	void addAbility(std::string name, int mE);
	void deleteAbility(Habilidad _skill);
	void deletePosAbility(int _pos);
	friend std::ostream& operator<<(std::ostream& os, ListaHabilidades& listahb);
	friend std::istream& operator>>(std::istream& is, ListaHabilidades& listhab);
	Habilidad operator[](int pos);
};

