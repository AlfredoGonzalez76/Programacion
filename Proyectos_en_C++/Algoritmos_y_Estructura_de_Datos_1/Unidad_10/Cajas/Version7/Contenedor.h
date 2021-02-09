
#pragma once
class Contenedor //contenedor genérico, clase abstracta
{
	public:
		virtual double volumen() const = 0; //virtual sólo en declaración
		void mostrarVolumen() const;
		//al usar punteros a la clase base no se invocan a los destructores correctos
		virtual ~Contenedor(void); //para invocar el destructor correcto agrego virtual
};