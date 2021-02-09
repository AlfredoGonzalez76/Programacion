#include <iostream>
#include <string>

using namespace std;

class Mascota
{
public:
  Mascota(string nombre, int patas);
  virtual string hablar() = 0;

private:
  string nombre;
  int patas;
};

Mascota::Mascota(string nombre, int patas):nombre(nombre),patas(patas)
{
  cout << "Acaba de nacer tu mascota " << nombre << " con " << patas << " patas" << endl;
}

class Perro : public  Mascota
{
public:
  Perro(string nombre);

  string hablar();
};

Perro::Perro(string nombre):Mascota(nombre, 4)
{
}

string Perro::hablar()
{
  return "GUAU";
}

class Gato : public  Mascota
{
public:
  Gato(string nombre);

  string hablar();
};

Gato::Gato(string nombre):Mascota(nombre, 4)
{
}

string Gato::hablar()
{
  return "MIAU";
}

int main()
{
  Mascota *p, *g;
 
  p=new Perro("Ramiro");
  g=new Gato("Lancelot");

  cout << p->hablar() << endl;
  cout << g->hablar() << endl;

  return 0;
}