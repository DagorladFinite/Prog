#include "Habilidad.h"

Habilidad test(Habilidad h)
{
	return h;
}

int main()
{
	Habilidad h("Porrazo", 1);
	Habilidad h2 = test(h);
}