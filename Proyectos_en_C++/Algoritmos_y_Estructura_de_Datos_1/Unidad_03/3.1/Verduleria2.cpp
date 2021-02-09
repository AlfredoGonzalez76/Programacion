#include <iostream>
#include <string>

using namespace std;

/* Una Verdulería nos pide que armemos el pedido para el mayorista para lo cual
deberemos pedir al usuario el código de proveedor, razón social, fecha de solicitud
y fecha de entrega. Las frutas estarán enumeradas (tomar solo 6 a modo de ejemplo),
mostrando los datos por pantalla. */


typedef enum { Banana, Kiwi, Mandarina, Manzana, Naranja, Pera } tFruta;

typedef enum { LA, MC, JJ, LR, LH } tCod;


tCod colocaCodigoProveedor();

string ingresaRazonSocial();

string ingresaFechaSolicitud();

string ingresaFechaEntrega();

bool quierePedir();

tFruta eligeFruta();

void ingresaFrutaCantidad(tFruta fruta, int &banana, int &kiwi, int &mandarina, int &manzana, int &naranja, int &pera );


void imprimeProveedor(tCod proveedor);

void imprimeRazonSocial(string rs);

void imprimeFechaSolicitud(string fechaPedido);

void imprimeFechaEntrega(string fechaEntrega);

void imprimeCuerpoPedido(int banana, int kiwi, int mandarina, int manzana, int naranja, int pera);

void menuPedido(tFruta fruta, int &banana, int &kiwi, int &mandarina, int &manzana, int &naranja, int &pera);

void emitePedido(tCod proveedor, string rs, string fechaPedido, string fechaEntrega, int banana, int kiwi, int mandarina, int manzana, int naranja, int pera);


int main()
{
	tCod codProv;
	tFruta fruta;
	string fechaEntrega, fechaPedido, razonSocial;
	int banana = 0, kiwi = 0, mandarina = 0, manzana = 0, naranja = 0, pera = 0;

	razonSocial = ingresaRazonSocial();

	codProv = colocaCodigoProveedor();

	fechaEntrega = ingresaFechaSolicitud();

	fechaPedido = ingresaFechaEntrega();

	menuPedido(fruta, banana, kiwi, mandarina, manzana, naranja, pera);

	emitePedido(codProv, razonSocial, fechaPedido, fechaEntrega, banana, kiwi, mandarina, manzana, naranja, pera);

	return 0;
}


tCod colocaCodigoProveedor()
{
	int op;
	cout << "Proveedores:" << endl;
	cout << endl;
	cout << "1. Los Amigos" << endl;
	cout << "2. Maritn y Carolina" << endl;
	cout << "3. Juan Jose" << endl;
	cout << "4. Los Rodriguez" << endl;
	cout << "5. La Huerta" << endl;
	cout << endl;
	cout << "Elija un proveedor: ";
	do
	{
		cin >> op;
	}
	while ((op < 1) && (op > 5) );
	cout << endl;
	return tCod(op-1);
}


string ingresaRazonSocial()
{
	string nombre;
	cout << "Ingrese su Razon Social: ";
	getline(cin,nombre);
	cout << endl;
	return nombre;
}

string ingresaFechaSolicitud()
{
	string fechaPedido;
	cout << "Ingrese Fecha de Pedido (DD/MM/AAAA): ";
	cin >> fechaPedido;
	return fechaPedido;
}

string ingresaFechaEntrega()
{
	string fechaEntrega;
	cout << "Ingrese Fecha de Entrega (DD/MM/AAAA): ";
	cin >> fechaEntrega;
	return fechaEntrega;
}

bool quierePedir()
{
	int op;
	do
	{
		cout << endl;
		cout << "Desea pedir? ( 1 = SI / 0 = NO ): ";
		cin >> op;
	}
	while((op != 0) && (op != 1) );
	cout << endl;
	return bool(op);
}


tFruta eligeFruta()
{
	int op;
	cout << "Frutas Disponibles:" << endl;
	cout << endl;
	cout << "1) Banana" << endl;
	cout << "2) Kiwi" << endl;
	cout << "3) Mandarina" << endl;
	cout << "4) Manzana" << endl;
	cout << "5) Naranja" << endl;
	cout << "6) Pera" << endl;
	cout << endl;
	cout << "Ingrese una opcion para su pedido: ";
	do
	{
		cin >> op;
	} while ((op < 1) && (op > 6));
	return tFruta(op-1);
}


void ingresaFrutaCantidad(tFruta fruta, int &banana, int &kiwi, int &mandarina, int &manzana, int &naranja, int &pera )
{
	switch (fruta)
	{
	  case Banana:
	    cout << "Ingrese la cantidad de BANANA (cajones): ";
	    cin >> banana;
	    break;
	  case Kiwi:
	    cout << "Ingrese la cantidad de KIWI (cajones): ";
	    cin >> kiwi;
	    break;
	  case Mandarina:
	  	cout << "Ingrese la cantidad de MANDARINA (cajones): ";
	  	cin >> mandarina;
	    break;
	  case Manzana:
	  	cout << "Ingrese la cantidad de MANZANA (cajones): ";
	  	cin >> manzana;
	    break;
	  case Naranja:
	  	cout << "Ingrese la cantidad de NARANJA (cajones): ";
	  	cin >> naranja;
	    break;
	  case Pera:
	  	cout << "Ingrese la cantidad de PERA (cajones): ";
	  	cin >> pera;
	    break;
	}
}


void imprimeProveedor(tCod proveedor)
{
	cout << "Proveedor: ";
	switch (proveedor)
	{
	  case LA:
	    cout << "Los Amigos" << endl;
	    break;
	  case MC:
	    cout << "Martin y Carolina" << endl;
	    break;
	  case JJ:
	  	cout << "Juan Jose" << endl;
	    break;
	  case LR:
	  	cout << "Los Rodriguez" << endl;
	    break;
	  case LH:
	  	cout << "La Huerta" << endl;
	}
}


void imprimeRazonSocial(string rs)
{
	cout << "Razon Social: " << rs << endl;
}


void imprimeFechaSolicitud(string fechaPedido)
{
	cout << "Fecha de Pedido: " << fechaPedido << endl;
}


void imprimeFechaEntrega(string fechaEntrega)
{
	cout << "Fecha de Entrega: " << fechaEntrega << endl;
}


void imprimeCuerpoPedido(int banana, int kiwi, int mandarina, int manzana, int naranja, int pera)
{
    cout << "BANANA..................."<< banana << " (cajones): " << endl;
    cout << "KIWI....................."<< kiwi << " (cajones): " << endl;
    cout << "MANDARINA................"<< mandarina << " (cajones): " << endl;
    cout << "MANZANA.................."<< manzana << " (cajones): " << endl;
    cout << "NARANJA.................."<< naranja << " (cajones): " << endl;
    cout << "PERA....................."<< pera << " (cajones): " << endl;
}


void menuPedido(tFruta fruta, int &banana, int &kiwi, int &mandarina, int &manzana, int &naranja, int &pera)
{
	bool pedir;
	pedir = quierePedir();
	while(pedir)
	{
		fruta = eligeFruta();
		ingresaFrutaCantidad(fruta, banana, kiwi, mandarina, manzana, naranja, pera);
		pedir = quierePedir();
	}
}


void emitePedido(tCod proveedor, string rs, string fechaPedido, string fechaEntrega, int banana, int kiwi, int mandarina, int manzana, int naranja, int pera)
{
	imprimeProveedor(proveedor);
	imprimeRazonSocial(rs);
	imprimeFechaSolicitud(fechaPedido);
	imprimeFechaEntrega(fechaEntrega);
	imprimeCuerpoPedido(banana, kiwi, mandarina, manzana, naranja, pera);
}