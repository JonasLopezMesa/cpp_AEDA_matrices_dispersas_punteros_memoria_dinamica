#include "matrices_5.hpp"
#include "matrices_d_5.hpp"

int main(void)
{
    cout << "hola" << endl;
	matrix_t A;

	cout << endl;
	A.read(cin);
	cout << "---  MATRIZ ORIGINAL                     ---" << endl;
	A.mostrarMatriz();

	sparse_matrix_t B(A,1E-5);

	cout << "---  MATRIZ DISPERSA EN FORMATO DENSO 1  ---" << endl;
	B.mostrarMatrizDensa_1();
	cout << endl;

	cout << "---  MATRIZ DISPERSA EN FORMATO DENSO 2  ---" << endl;
	B.mostrarMatrizDensa_2();
	cout << endl;

	cout << "---  MATRIZ DISPERSA EN FORMATO DISPERSO ---" << endl;
	B.mostrarMatrizDispersa();
	cout << endl;
    
    cout << "Adiós" << endl;
}
