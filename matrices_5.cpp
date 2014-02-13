#include "matrices_5.hpp"

#define MAX_MATRIX_ITEM 100


//========================================================================================
// Funciones generales.
//========================================================================================


bool zero(matrix_item_t a, double precision)
{
	return (fabs(a)<precision);
}

//========================================================================================
// Métodos privados.
//========================================================================================


vector_inx_t matrix_t::pos(matrix_inx_t i,matrix_inx_t j)
{
	if ((i<1)||(i>get_m())||(j<1)||(j>get_n())){
		std::cerr << "Error accediendo a matriz"<< std::endl;
		return 0;
        }

	if (traspuesta_)
		return (j-1)*n_+i-1;
	else
		return (i-1)*n_+j-1;


}


void matrix_t::crearMatriz(void) 
{
	M_= new matrix_item_t [m_*n_];	// Crea un vector de mxn elementos. 
	
	if (M_==NULL)  		// Si ha fallado la reserva de memoria. 
		std::cerr << "Error creando matriz." << std::endl;
}		


void matrix_t::destruirMatriz(void)
{
	if (M_!=NULL){
		delete [] M_;		// Libera la memoria previamente reservada para la matriz.
		M_=NULL;		// Asigna NULL al puntero.
	}

	m_=0;
	n_=0;
}



void matrix_t::redimensiona(matrix_inx_t m,matrix_inx_t n)
{
	destruirMatriz();

	m_=m;
	n_=n;

	crearMatriz();
}


//========================================================================================
// Métodos públicos.
//========================================================================================

matrix_t::matrix_t(matrix_inx_t m,matrix_inx_t n):
traspuesta_(false),
M_(NULL),
m_(m),
n_(n)
{
	crearMatriz();
}	



matrix_t::matrix_t(void):
traspuesta_(false),
M_(NULL),
m_(0),
n_(0)
{}		


matrix_t::~matrix_t(void)
{
	destruirMatriz();
	traspuesta_=false;
}



void  matrix_t::mostrarMatriz(void)
{

	char aux[80];

	for(int i=1;i<=get_m();i++){
		
		for(int j=1;j<=get_n();j++){
			sprintf(aux," %10.6lf ",get_matrix_item(i,j));
			cout << aux;
		}
		cout << endl;
	}

	cout << endl;	
}


matrix_item_t matrix_t::get_matrix_item(matrix_inx_t i,matrix_inx_t j)
{
	return M_[pos(i,j)];
}



void matrix_t::set_matrix_item(matrix_inx_t i,matrix_inx_t j,matrix_item_t it)
{
	M_[pos(i,j)]=it;	
}




matrix_inx_t matrix_t::get_m(void)
{
	if (traspuesta_)
		return n_;
	else 
		return m_;
}


matrix_inx_t matrix_t::get_n(void)
{
	if (traspuesta_)
		return m_;
	else 
		return n_;
}


istream& matrix_t::read(istream& is)
{
	int m,n;
	is >> m >> n;

	redimensiona(m,n);

	const int sz=m*n;

	for(int i=0;i<sz;i++)
		is >> M_[i];
	return is;
}

ostream& matrix_t::write(ostream& os)
{
	char aux[80];

	sprintf(aux, " %10d  %10d ",get_m(),get_n());
	os << aux<<endl;

	for(int i=1;i<=get_m();i++){
		for(int j=1;j<=get_n();j++){
			sprintf(aux," %10.6lf ",get_matrix_item(i,j));
			os << aux;
		}
		os << endl;
	}
    return os;
}

