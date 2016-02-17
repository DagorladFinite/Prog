#include "ListaHabilidades.h"



ListaHabilidades::ListaHabilidades()
{
	std::cout << "Lista Habilidades::Constructor por defecto" << std::endl;
}


ListaHabilidades::~ListaHabilidades()
{
}

void ListaHabilidades::addAbility(Habilidad a)
{
	push_back(a);
}

void ListaHabilidades::addAbility(std::string name, int mE)
{
	Habilidad a(name.c_str(), mE);
	push_back(a);
}

void ListaHabilidades::deleteAbility(Habilidad _skill)
{
	this->erase(std::find(this->begin(), this->end(), _skill));
}

void ListaHabilidades::deletePosAbility(int _pos)
{
	this->erase(this->begin() + (_pos - 1));
}

Habilidad ListaHabilidades::operator[](int pos)
{
	//this->at(pos);
	return this->at(pos);
}


ListaHabilidades::ListaHabilidades(ListaHabilidades & listhab)
{
	for (int i = 0; i < listhab.size(); i++) {
		this->push_back(listhab[i]);
	}
}

std::ostream& operator<<(std::ostream& os, ListaHabilidades & listhab)
{
	for (size_t i = 0; i < listhab.size(); i++)
	{
		os << listhab[i] << "\n";
	}
	return os;
}

std::istream& operator>>(std::istream& is, ListaHabilidades & listhab)
{
	
	return is;
}

