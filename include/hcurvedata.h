//
// @author Milinda Fernando
// School of Computing, University of Utah

// NOTE: DO NOT CHANGE THIS FILE FOR ANY REASON.


// This header file contains all the rotation permutations + hilbert rotation table data hard corded to improve the performance of the hilbert curve.
// Note that: Rotations contains the concatenated strings of rot_perm and rot_index.
// Created by Milinda Fernando
// on 10/2/15.
//

#ifndef HILBERTCURVEBENCH_HCURVEDATA_H
#define HILBERTCURVEBENCH_HCURVEDATA_H

#include <string.h>
#include <iostream>
#include <cstdlib>
#include <iostream>
//#include <stdlib>
#include<cstring>
#include<string>


using namespace std;


const int _2D_HILBERT_TABLE=16;
const int _3D_HILBERT_TABLE=192;
const int _2D_ROTATIONS_SIZE=32;
const int _3D_ROTATIONS_SIZE=384;


extern char* HILBERT_TABLE;
extern char* rotations;

#define DENDRO_DIM2

void _InitializeHcurve();



#endif //HILBERTCURVEBENCH_HCURVEDATA_H
