#include "Boton.h"



Boton::Boton( Texto t ) :
	texto(t)
{
}


Boton::~Boton()
{
	texto.~Texto();
}

void Boton::draw()
{
	texto.draw();
}
