#include "matrices_d_5.hpp"


//========================================================================================
// Constructor.
//========================================================================================

sparse_matrix_t::sparse_matrix_t(matrix_t& M, double precision):
matval_(NULL),
matind_(NULL),
matbeg_(NULL),
matcnt_(NULL),
nz_(0),
m_(M.get_m()),
n_(M.get_n())
{	
	for(int i=1;i<=m_;i++)
		for(int j=1;j<=n_;j++)
			if (!zero(M.get_matrix_item(i,j),precision))
				nz_++;

	matval_ = new matrix_item_t [nz_];
	matind_ = new vector_inx_t  [nz_];
	matbeg_ = new vector_inx_t  [n_];
	matcnt_ = new vector_inx_t  [n_];

	int nz_i=0;
	
	for(int j=1;j<=n_;j++){

		matcnt_[j-1]=0;
		matbeg_[j-1]=nz_i;

		for(int i=1;i<=m_;i++)	
			if (!zero(M.get_matrix_item(i,j),precision)){

				matval_[nz_i]=M.get_matrix_item(i,j);
				matind_[nz_i]=i-1;

				matcnt_[j-1]++;
		
				nz_i++;						
			}
	}

}



//========================================================================================
// Destructor.
//========================================================================================

sparse_matrix_t::~sparse_matrix_t(void)
{
	
	delete [] matval_;
	delete [] matind_;
	delete [] matbeg_;
	delete [] matcnt_;

	matval_=NULL;
	matind_=NULL;
	matbeg_=NULL;
	matcnt_=NULL;

	nz_=0;
	m_=0;
	n_=0;
}


//========================================================================================
// Función que le damos a los alumnos para que comprendan cómo funciona la estructura
//========================================================================================

void  sparse_matrix_t::mostrarMatrizDensa_1(void)
{
	char aux[80];

	for(int i=0;i<get_m();i++){

		for(int j=0;j<get_n();j++){

			bool encontrado=false;
			int l=matbeg_[j];

			for(;(l<matbeg_[j]+matcnt_[j]) && (!encontrado);l++)
				if (matind_[l]==i)
					encontrado=true;
			if (encontrado)
				sprintf(aux," %10.6lf ",matval_[l-1]);
			else
				sprintf(aux," %10.6lf ",0.0);

			cout << aux;							
		}

		std::cout << endl;
	}
}

//========================================================================================
// Función que tendrán que implementar los alumnos
//========================================================================================

void  sparse_matrix_t::mostrarMatrizDensa_2(void)
{
	char aux[80];

	vector_inx_t**  matind_ptr = NULL; //puntero a un puntero. Contiene la dirección de memoria del puntero que apunta a la dirección de memoria de un valor.
	vector_inx_t**  matind_end_ptr = NULL;
	matrix_item_t** matval_ptr = NULL;

	matind_ptr = new vector_inx_t* [n_]; //asigna el tamaño de esos vectores a n_ es decir que el tamaño de esos vectores es igual al número de columnas
	matind_end_ptr = new vector_inx_t* [n_];
	matval_ptr     = new matrix_item_t*[n_];

	for(int j=0;j<n_;j++){ //por cada columna
		matind_ptr[j]     = matind_ + matbeg_[j]; // 
		matval_ptr[j]     = matval_ + matbeg_[j];
		matind_end_ptr[j] = matind_ptr[j] + matcnt_[j];
	}

	for(int i=0;i<get_m();i++){                             //RECORRE TODAS LAS FILAS
            // FASE III	<====================================
		for(int j=0;j<get_n();j++){                         //DE CADA FILA RECORRE CADA COLUMNA
            if (matind_ptr[j] == matind_end_ptr[j]) {       //Si se ha llegado al último elemento no nulo de esa fila
                sprintf(aux," %10.6lf ",0.0);               //Almacena en aux 0
            } else                                          //Si no se ha llegado al último elemento no nulo de esa fila
                if ((*matind_ptr[j])==i) {                  //Si ese elemento es uno de los elementos no nulos
                    sprintf(aux," %10.6lf ",*matval_ptr[j]);//Almacena en aux el valor del elemento no nulo de esa posición
                    matind_ptr[j]++;                        //Incrementar la dirección del indice de filas.
                    matval_ptr[j]++;                        //Incrementar la dirección del índice de valores.
                } else {                                    //Si no
                    sprintf(aux," %10.6lf ",0.0);           //Almacena en aux 0
                }
            cout << aux;                                    //imprime lo que haya en aux
		}
		std::cout << endl;
	}

	delete [] matind_ptr;
	delete [] matval_ptr;
	delete [] matind_end_ptr;

	matind_ptr=NULL;
	matval_ptr=NULL;
	matind_end_ptr=NULL;
}

//========================================================================================
// Muestra por pantalla
//========================================================================================

void  sparse_matrix_t::mostrarMatrizDispersa(void)
{
			// FASE II	<====================================	
    for (unsigned short int j = 0; j < n_; j++) {               // RECORRER TODAS LAS COLUMNAS
        cout << "COLUMNA " << j << ": " << endl;                // Imprimir "COLUMNA" y el número de la columna actual
        for (unsigned short int l = 0; l < matcnt_[j]; l++) {   // RECORRER TODOS LOS ELEMENTOS NO NULOS DE CADA COLUMNA
            cout << "           " << "Fila :";                  // Imprimir "Fila:"
            cout << matind_[matbeg_[j]+l] << "  ";              // Imprimir el índice de esa fila.
                                                                    // matbeg: Vector que contiene la posición de comienzo de cada una de las columas en el vector matval
                                                                    // matind: Vector que contiene el número de la fila del elemento no nulo
            cout << matval_[matbeg_[j]+l] << endl;              // Imprimir el valor de el elemento no nulo de esa fila y de esa columna 
                                                                    // matval: Vector que contiene los elementos no nulos de la matriz
        }
        cout << endl;
    }
}

/*void  sparse_matrix_t::mostrarMatrizDispersa(void)
{
    // FASE II	<====================================	
    for (unsigned short int j = 0; j < m_; j++) {               // RECORRER TODAS LAS COLUMNAS
        cout << "COLUMNA " << j << ": " << endl;                // Imprimir "COLUMNA" y el número de la columna actual
        for (unsigned short int l = 0; l < matcnt_[j]; l++) {   // RECORRER TODOS LOS ELEMENTOS NO NULOS DE CADA COLUMNA
            cout << "           " << "Fila :";                  // Imprimir "Fila:"
            cout << matind_[matbeg_[j]+l] << "  ";              // Imprimir el índice de esa fila.
            // matbeg: Vector que contiene la posición de comienzo de cada una de las columas en el vector matval
            // matind: Vector que contiene el número de la fila del elemento no nulo
            cout << matval_[matbeg_[j]+l] << endl;              // Imprimir el valor de el elemento no nulo de esa fila y de esa columna 
            // matval: Vector que contiene los elementos no nulos de la matriz
        }
        cout << endl;
    }
}*/

matrix_inx_t sparse_matrix_t::get_m(void)
{	
		return m_;
}


matrix_inx_t sparse_matrix_t::get_n(void)
{
		return n_;
}

