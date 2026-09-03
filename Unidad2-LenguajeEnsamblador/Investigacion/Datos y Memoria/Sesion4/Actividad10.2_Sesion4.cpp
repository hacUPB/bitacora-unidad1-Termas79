#include <iostream>
using namespace std;
class Punto {
		public:    int x;    int y;
    // Constructor
    Punto(int _x, int _y) : x(_x), y(_y) {
		    cout << "Constructor: Punto(" << x << ", " << y << ") creado." << endl;
		    }
    // Destructor
    ~Punto() {
		    cout << "Destructor: Punto(" << x << ", " << y << ") destruido." << endl;
		    }
    // Método para imprimir valores
    void imprimir() {
		    cout << "Punto(" << x << ", " << y << ")" << endl;
		    }
		};
int main() {
		{
				cout << "Inicio del bloque" << endl;
				Punto pBloque(100, 200);
				pBloque.imprimir();
				// Coloca un breakpoint aquí para ver 'pBloque' en el stack.
		}
		// Al salir del bloque, el destructor de 'pBloque' se invoca.
		cout << "Fuera del bloque" << endl;
		// Creación dinámica:
		Punto* pDinamico = new Punto(300, 400);
		pDinamico->imprimir();
		// 'pDinamico' sigue existiendo hasta que se libere manualmente.
		// Coloca un breakpoint aquí y observa la dirección de memoria.
		delete pDinamico;
		// Después de 'delete', el destructor se llama y la memoria se libera.
	  {
		  cout << "Inicio del bloque 2" << endl;
		  Punto* pBloque2 = new Punto(500, 600);
		  pBloque2->imprimir();
		}
			pBloque2->imprimir();
			delete pBloque2;
	    return 0;
}