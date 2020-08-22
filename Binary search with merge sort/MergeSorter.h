#include <cstdlib>
#include <iostream>

#ifndef MERGESORTER_H
#define MERGESORTER_H

	
	void CopyArray(char *A, int iBegin, int iEnd, char *B){
		for(int k = iBegin; k < iEnd; k++){
			 B[k] = A[k];
		}
	}
	
	void TopDownMerge(char *A, int iBegin, int iMiddle, int iEnd, char *B){
		int i = iBegin, j = iMiddle;
 
      // While there are elements in the left or right runs...
      for (int k = iBegin; k < iEnd; k++) {
          // If left run head exists and is <= existing right run head.
          if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
              B[k] = A[i];
              i = i + 1;
          } else {
              B[k] = A[j];
              j = j + 1;
          }
      } 
	}
	
	void TopDownSplitMerge(char *B, int iBegin, int iEnd, char *A){
	  if(iEnd - iBegin < 2)                       // if run size == 1
        return;                                 //   consider it sorted
      // split the run longer than 1 item into halves
      int iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
      // recursively sort both runs from array A[] into B[]
      TopDownSplitMerge(A, iBegin,  iMiddle, B);  // sort the left  run
      TopDownSplitMerge(A, iMiddle,    iEnd, B);  // sort the right run
      // merge the resulting runs from array B[] into A[]
      TopDownMerge(B, iBegin, iMiddle, iEnd, A);
	}
	//  Left source half is A[ iBegin:iMiddle-1].
    // Right source half is A[iMiddle:iEnd-1   ].
    // Result is            B[ iBegin:iEnd-1   ].
	
	void TopDownMergeSort(char * A, char* B, int n){
		CopyArray(A, 0, n, B);           // one time copy of A[] to B[]
        TopDownSplitMerge(B, 0, n, A);
	}
	

#endif

