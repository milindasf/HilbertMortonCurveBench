/*
 *@author: Milinda Fernando
 *@date: 09/04/2015 //// This is refactored code from HilbertBenchmark code.
 *School of Computing, University of Utah
 * 
 * Contains Contains some supporting functionality to run the benchmark. 
 * 
 */
#include "../include/dendro.h"

unsigned int binLength(unsigned int num) {
    unsigned int len = 1;
    while(num > 1) {
      num = (num >> 1);
      len++;
    }
    return len;
  }//end function

