#include "matrices_5.hpp"

/**
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		27 de febrero de 2012

	\details 	Clase que representa una matriz de mxn elementos en formato de matriz dispersa. */

class sparse_matrix_t {

//========================================================================================
// Atributos privados.
//========================================================================================

private:

	matrix_inx_t  	m_;		/**< Número de filas.   */
	matrix_inx_t	n_;		/**< Número de columnas.*/

	matrix_inx_t	nz_;		/**< Número de elementos no nulos */

	matrix_item_t*	matval_;	/**< Vector que contiene los elementos no nulos de la matriz */
	vector_inx_t*   matind_;	/**< Vector que contiene el número de la fila del elemento no nulo */
	vector_inx_t*   matbeg_;	/**< Vector que contiene la posición de comienzo de cada una de las columas */
	vector_inx_t*   matcnt_;	/**< Vector que contiene el número de elementos de la columna */

public:

/**	
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		27 de febrero de 2012

	\details 	Constructor. Construye una matriz dispersa a partir de una matriz densa.

       * @param 	M Matriz a partir de la cual se construirá la matriz dispersa.            
       * @see 		matrix_t.

*/

	sparse_matrix_t(matrix_t& M, double precision); 	

/**
        \author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		27 de febrero de 2012

	\details 	Destructor. Libera la memoria de la matriz.
 */

	~sparse_matrix_t(void);

/**
       	\author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		27 de febrero de 2012

	\details 	Muestra la matriz formateada.

 */

	void  mostrarMatrizDispersa(void);

/**
       	\author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		27 de febrero de 2012

	\details 	Muestra la matriz formateada.

 */

	void  mostrarMatrizDensa_1(void);

/**
       	\author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		27 de febrero de 2012

	\details 	Muestra la matriz formateada.

 */

	void  mostrarMatrizDensa_2(void);

/**
       	\author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Devuelve el número de filas.

       * @return 	el número de filas m_.
       * @see 		matrix_inx_t.
  
 */

	matrix_inx_t get_m(void);


/**
       	\author   	Jorge Riera Ledesma (jorge.riera.ledesma@ull.edu.es)
        \date 		13 de febrero de 2012

	\details 	Devuelve el número de columnas.

       * @return 	el número de columnas n_.
       * @see 		matrix_inx_t.
  
 */

	matrix_inx_t get_n(void);


};

