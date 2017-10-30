#include "Boton.h"



Boton::Boton( Texto t ) :
	texto(t)
{
}


Boton::~Boton()
{
}

void Boton::draw()
{
	texto.draw();
}
