#ifndef __QUICKSORT_C_DECL_H
#define __QUICKSORT_C_DECL_H


#ifdef __cplusplus
extern "C" {
#endif

// I wonder if this is helpful for building multiple versions?
#ifndef PTYPE
#define PTYPE int
#endif

  
/* integer sort */
PTYPE* quicksort(PTYPE * arr, int nElems);


#ifdef __cplusplus
}
#endif


#endif
