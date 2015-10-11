//
// @author Milinda Fernando
// School of Computing, University of Utah

// NOTE: DO NOT CHANGE THIS FILE FOR ANY REASON.


// This header file contains all the rotation permutations + hilbert rotation table data hard corded to improve the performance of the hilbert curve.
// Note that: Rotations contains the concatenated strings of rot_perm and rot_index.
// Created by Milinda Fernando
// on 10/2/15.
//



#include "../include/hcurvedata.h"

char* rotations;
char* HILBERT_TABLE;

void _InitializeHcurve() {

#ifdef DENDRO_DIM2

    rotations=new char[_2D_ROTATIONS_SIZE];
    HILBERT_TABLE=new char[_2D_HILBERT_TABLE];

    strcpy(rotations+0,"01230123");
    strcpy(rotations+8,"03210321");
    strcpy(rotations+16,"21032103");
    strcpy(rotations+24,"23012301");



    /*HILBERT_TABLE[0]=1;
    HILBERT_TABLE[1]=0;
    HILBERT_TABLE[2]=0;
    HILBERT_TABLE[3]=2;
    HILBERT_TABLE[4]=0;
    HILBERT_TABLE[5]=1;
    HILBERT_TABLE[6]=1;
    HILBERT_TABLE[7]=3;
    HILBERT_TABLE[8]=3;
    HILBERT_TABLE[9]=2;
    HILBERT_TABLE[10]=2;
    HILBERT_TABLE[11]=0;
    HILBERT_TABLE[12]=2;
    HILBERT_TABLE[13]=3;
    HILBERT_TABLE[14]=3;
    HILBERT_TABLE[15]=1;*/

    HILBERT_TABLE[0]=1;
    HILBERT_TABLE[1]=0;
    HILBERT_TABLE[2]=0;
    HILBERT_TABLE[3]=2;
    HILBERT_TABLE[4]=0;
    HILBERT_TABLE[5]=3;
    HILBERT_TABLE[6]=1;
    HILBERT_TABLE[7]=1;
    HILBERT_TABLE[8]=2;
    HILBERT_TABLE[9]=2;
    HILBERT_TABLE[10]=3;
    HILBERT_TABLE[11]=0;
    HILBERT_TABLE[12]=3;
    HILBERT_TABLE[13]=1;
    HILBERT_TABLE[14]=2;
    HILBERT_TABLE[15]=3;


#else

    rotations = new char[_3D_ROTATIONS_SIZE];
    HILBERT_TABLE = new char[_3D_HILBERT_TABLE];

    strcpy(rotations + 0,  "0123456701234567");
    strcpy(rotations + 16, "0167452301674523");
    strcpy(rotations + 32, "0321654703216547");
    strcpy(rotations + 48, "0347652107612543");
    strcpy(rotations + 64, "0743256107432561");
    strcpy(rotations + 80, "0761254303476521");
    strcpy(rotations + 96, "2103476521034765");
    strcpy(rotations + 112, "2165470361074325");
    strcpy(rotations + 128, "2301674523016745");
    strcpy(rotations + 144, "2345670167012345");
    strcpy(rotations + 160, "2543076147032165");
    strcpy(rotations + 176, "2561074343076125");
    strcpy(rotations + 192, "4307612525610743");
    strcpy(rotations + 208, "4325610765210347");
    strcpy(rotations + 224, "4523016745230167");
    strcpy(rotations + 240, "4567012345670123");
    strcpy(rotations + 256, "4703216525430761");
    strcpy(rotations + 272, "4765210365470321");
    strcpy(rotations + 288, "6107432521654703");
    strcpy(rotations + 304, "6125430761254307");
    strcpy(rotations + 320, "6521034743256107");
    strcpy(rotations + 336, "6547032147652103");
    strcpy(rotations + 352, "6701234523456701");
    strcpy(rotations + 368, "6745230167452301");


   /* HILBERT_TABLE[0] = 4;
    HILBERT_TABLE[1] = 1;
    HILBERT_TABLE[2] = 0;
    HILBERT_TABLE[3] = 18;
    HILBERT_TABLE[4] = 10;
    HILBERT_TABLE[5] = 0;
    HILBERT_TABLE[6] = 14;
    HILBERT_TABLE[7] = 19;
    HILBERT_TABLE[8] = 3;
    HILBERT_TABLE[9] = 0;
    HILBERT_TABLE[10] = 1;
    HILBERT_TABLE[11] = 6;
    HILBERT_TABLE[12] = 21;
    HILBERT_TABLE[13] = 1;
    HILBERT_TABLE[14] = 15;
    HILBERT_TABLE[15] = 7;
    HILBERT_TABLE[16] = 5;
    HILBERT_TABLE[17] = 3;
    HILBERT_TABLE[18] = 2;
    HILBERT_TABLE[19] = 12;
    HILBERT_TABLE[20] = 11;
    HILBERT_TABLE[21] = 2;
    HILBERT_TABLE[22] = 20;
    HILBERT_TABLE[23] = 13;
    HILBERT_TABLE[24] = 1;
    HILBERT_TABLE[25] = 2;
    HILBERT_TABLE[26] = 3;
    HILBERT_TABLE[27] = 8;
    HILBERT_TABLE[28] = 15;
    HILBERT_TABLE[29] = 3;
    HILBERT_TABLE[30] = 21;
    HILBERT_TABLE[31] = 9;
    HILBERT_TABLE[32] = 0;
    HILBERT_TABLE[33] = 5;
    HILBERT_TABLE[34] = 4;
    HILBERT_TABLE[35] = 22;
    HILBERT_TABLE[36] = 14;
    HILBERT_TABLE[37] = 4;
    HILBERT_TABLE[38] = 10;
    HILBERT_TABLE[39] = 23;
    HILBERT_TABLE[40] = 2;
    HILBERT_TABLE[41] = 4;
    HILBERT_TABLE[42] = 5;
    HILBERT_TABLE[43] = 16;
    HILBERT_TABLE[44] = 20;
    HILBERT_TABLE[45] = 5;
    HILBERT_TABLE[46] = 11;
    HILBERT_TABLE[47] = 17;
    HILBERT_TABLE[48] = 10;
    HILBERT_TABLE[49] = 7;
    HILBERT_TABLE[50] = 6;
    HILBERT_TABLE[51] = 19;
    HILBERT_TABLE[52] = 4;
    HILBERT_TABLE[53] = 6;
    HILBERT_TABLE[54] = 16;
    HILBERT_TABLE[55] = 18;
    HILBERT_TABLE[56] = 9;
    HILBERT_TABLE[57] = 6;
    HILBERT_TABLE[58] = 7;
    HILBERT_TABLE[59] = 0;
    HILBERT_TABLE[60] = 23;
    HILBERT_TABLE[61] = 7;
    HILBERT_TABLE[62] = 17;
    HILBERT_TABLE[63] = 1;
    HILBERT_TABLE[64] = 11;
    HILBERT_TABLE[65] = 9;
    HILBERT_TABLE[66] = 8;
    HILBERT_TABLE[67] = 13;
    HILBERT_TABLE[68] = 5;
    HILBERT_TABLE[69] = 8;
    HILBERT_TABLE[70] = 22;
    HILBERT_TABLE[71] = 12;
    HILBERT_TABLE[72] = 7;
    HILBERT_TABLE[73] = 8;
    HILBERT_TABLE[74] = 9;
    HILBERT_TABLE[75] = 2;
    HILBERT_TABLE[76] = 17;
    HILBERT_TABLE[77] = 9;
    HILBERT_TABLE[78] = 23;
    HILBERT_TABLE[79] = 3;
    HILBERT_TABLE[80] = 6;
    HILBERT_TABLE[81] = 11;
    HILBERT_TABLE[82] = 10;
    HILBERT_TABLE[83] = 20;
    HILBERT_TABLE[84] = 16;
    HILBERT_TABLE[85] = 10;
    HILBERT_TABLE[86] = 4;
    HILBERT_TABLE[87] = 21;
    HILBERT_TABLE[88] = 8;
    HILBERT_TABLE[89] = 10;
    HILBERT_TABLE[90] = 11;
    HILBERT_TABLE[91] = 14;
    HILBERT_TABLE[92] = 22;
    HILBERT_TABLE[93] = 11;
    HILBERT_TABLE[94] = 5;
    HILBERT_TABLE[95] = 15;
    HILBERT_TABLE[96] = 15;
    HILBERT_TABLE[97] = 13;
    HILBERT_TABLE[98] = 12;
    HILBERT_TABLE[99] = 9;
    HILBERT_TABLE[100] = 1;
    HILBERT_TABLE[101] = 12;
    HILBERT_TABLE[102] = 18;
    HILBERT_TABLE[103] = 8;
    HILBERT_TABLE[104] = 17;
    HILBERT_TABLE[105] = 12;
    HILBERT_TABLE[106] = 13;
    HILBERT_TABLE[107] = 3;
    HILBERT_TABLE[108] = 7;
    HILBERT_TABLE[109] = 13;
    HILBERT_TABLE[110] = 19;
    HILBERT_TABLE[111] = 2;
    HILBERT_TABLE[112] = 16;
    HILBERT_TABLE[113] = 15;
    HILBERT_TABLE[114] = 14;
    HILBERT_TABLE[115] = 21;
    HILBERT_TABLE[116] = 6;
    HILBERT_TABLE[117] = 14;
    HILBERT_TABLE[118] = 0;
    HILBERT_TABLE[119] = 20;
    HILBERT_TABLE[120] = 12;
    HILBERT_TABLE[121] = 14;
    HILBERT_TABLE[122] = 15;
    HILBERT_TABLE[123] = 10;
    HILBERT_TABLE[124] = 18;
    HILBERT_TABLE[125] = 15;
    HILBERT_TABLE[126] = 1;
    HILBERT_TABLE[127] = 11;
    HILBERT_TABLE[128] = 14;
    HILBERT_TABLE[129] = 17;
    HILBERT_TABLE[130] = 16;
    HILBERT_TABLE[131] = 23;
    HILBERT_TABLE[132] = 0;
    HILBERT_TABLE[133] = 16;
    HILBERT_TABLE[134] = 6;
    HILBERT_TABLE[135] = 22;
    HILBERT_TABLE[136] = 13;
    HILBERT_TABLE[137] = 16;
    HILBERT_TABLE[138] = 17;
    HILBERT_TABLE[139] = 4;
    HILBERT_TABLE[140] = 19;
    HILBERT_TABLE[141] = 17;
    HILBERT_TABLE[142] = 7;
    HILBERT_TABLE[143] = 5;
    HILBERT_TABLE[144] = 21;
    HILBERT_TABLE[145] = 19;
    HILBERT_TABLE[146] = 18;
    HILBERT_TABLE[147] = 7;
    HILBERT_TABLE[148] = 3;
    HILBERT_TABLE[149] = 18;
    HILBERT_TABLE[150] = 12;
    HILBERT_TABLE[151] = 6;
    HILBERT_TABLE[152] = 23;
    HILBERT_TABLE[153] = 18;
    HILBERT_TABLE[154] = 19;
    HILBERT_TABLE[155] = 1;
    HILBERT_TABLE[156] = 9;
    HILBERT_TABLE[157] = 19;
    HILBERT_TABLE[158] = 13;
    HILBERT_TABLE[159] = 0;
    HILBERT_TABLE[160] = 22;
    HILBERT_TABLE[161] = 21;
    HILBERT_TABLE[162] = 20;
    HILBERT_TABLE[163] = 15;
    HILBERT_TABLE[164] = 8;
    HILBERT_TABLE[165] = 20;
    HILBERT_TABLE[166] = 2;
    HILBERT_TABLE[167] = 14;
    HILBERT_TABLE[168] = 18;
    HILBERT_TABLE[169] = 20;
    HILBERT_TABLE[170] = 21;
    HILBERT_TABLE[171] = 11;
    HILBERT_TABLE[172] = 12;
    HILBERT_TABLE[173] = 21;
    HILBERT_TABLE[174] = 3;
    HILBERT_TABLE[175] = 10;
    HILBERT_TABLE[176] = 20;
    HILBERT_TABLE[177] = 23;
    HILBERT_TABLE[178] = 22;
    HILBERT_TABLE[179] = 17;
    HILBERT_TABLE[180] = 2;
    HILBERT_TABLE[181] = 22;
    HILBERT_TABLE[182] = 8;
    HILBERT_TABLE[183] = 16;
    HILBERT_TABLE[184] = 19;
    HILBERT_TABLE[185] = 22;
    HILBERT_TABLE[186] = 23;
    HILBERT_TABLE[187] = 5;
    HILBERT_TABLE[188] = 13;
    HILBERT_TABLE[189] = 23;
    HILBERT_TABLE[190] = 9;
    HILBERT_TABLE[191] = 4;*/


    HILBERT_TABLE[0]=4;
    HILBERT_TABLE[1]=1;
    HILBERT_TABLE[2]=0;
    HILBERT_TABLE[3]=18;
    HILBERT_TABLE[4]=10;
    HILBERT_TABLE[5]=0;
    HILBERT_TABLE[6]=14;
    HILBERT_TABLE[7]=19;
    HILBERT_TABLE[8]=3;
    HILBERT_TABLE[9]=0;
    HILBERT_TABLE[10]=15;
    HILBERT_TABLE[11]=7;
    HILBERT_TABLE[12]=21;
    HILBERT_TABLE[13]=1;
    HILBERT_TABLE[14]=1;
    HILBERT_TABLE[15]=6;
    HILBERT_TABLE[16]=5;
    HILBERT_TABLE[17]=12;
    HILBERT_TABLE[18]=2;
    HILBERT_TABLE[19]=3;
    HILBERT_TABLE[20]=20;
    HILBERT_TABLE[21]=2;
    HILBERT_TABLE[22]=11;
    HILBERT_TABLE[23]=13;
    HILBERT_TABLE[24]=1;
    HILBERT_TABLE[25]=9;
    HILBERT_TABLE[26]=21;
    HILBERT_TABLE[27]=2;
    HILBERT_TABLE[28]=3;
    HILBERT_TABLE[29]=3;
    HILBERT_TABLE[30]=15;
    HILBERT_TABLE[31]=8;
    HILBERT_TABLE[32]=0;
    HILBERT_TABLE[33]=23;
    HILBERT_TABLE[34]=14;
    HILBERT_TABLE[35]=22;
    HILBERT_TABLE[36]=4;
    HILBERT_TABLE[37]=4;
    HILBERT_TABLE[38]=10;
    HILBERT_TABLE[39]=5;
    HILBERT_TABLE[40]=2;
    HILBERT_TABLE[41]=16;
    HILBERT_TABLE[42]=20;
    HILBERT_TABLE[43]=17;
    HILBERT_TABLE[44]=11;
    HILBERT_TABLE[45]=5;
    HILBERT_TABLE[46]=5;
    HILBERT_TABLE[47]=4;
    HILBERT_TABLE[48]=6;
    HILBERT_TABLE[49]=7;
    HILBERT_TABLE[50]=10;
    HILBERT_TABLE[51]=19;
    HILBERT_TABLE[52]=4;
    HILBERT_TABLE[53]=18;
    HILBERT_TABLE[54]=16;
    HILBERT_TABLE[55]=6;
    HILBERT_TABLE[56]=17;
    HILBERT_TABLE[57]=6;
    HILBERT_TABLE[58]=9;
    HILBERT_TABLE[59]=1;
    HILBERT_TABLE[60]=23;
    HILBERT_TABLE[61]=0;
    HILBERT_TABLE[62]=7;
    HILBERT_TABLE[63]=7;
    HILBERT_TABLE[64]=8;
    HILBERT_TABLE[65]=13;
    HILBERT_TABLE[66]=11;
    HILBERT_TABLE[67]=9;
    HILBERT_TABLE[68]=22;
    HILBERT_TABLE[69]=12;
    HILBERT_TABLE[70]=5;
    HILBERT_TABLE[71]=8;
    HILBERT_TABLE[72]=23;
    HILBERT_TABLE[73]=3;
    HILBERT_TABLE[74]=7;
    HILBERT_TABLE[75]=8;
    HILBERT_TABLE[76]=9;
    HILBERT_TABLE[77]=2;
    HILBERT_TABLE[78]=17;
    HILBERT_TABLE[79]=9;
    HILBERT_TABLE[80]=16;
    HILBERT_TABLE[81]=21;
    HILBERT_TABLE[82]=6;
    HILBERT_TABLE[83]=20;
    HILBERT_TABLE[84]=10;
    HILBERT_TABLE[85]=11;
    HILBERT_TABLE[86]=4;
    HILBERT_TABLE[87]=10;
    HILBERT_TABLE[88]=22;
    HILBERT_TABLE[89]=14;
    HILBERT_TABLE[90]=8;
    HILBERT_TABLE[91]=15;
    HILBERT_TABLE[92]=5;
    HILBERT_TABLE[93]=10;
    HILBERT_TABLE[94]=11;
    HILBERT_TABLE[95]=11;
    HILBERT_TABLE[96]=12;
    HILBERT_TABLE[97]=12;
    HILBERT_TABLE[98]=18;
    HILBERT_TABLE[99]=13;
    HILBERT_TABLE[100]=15;
    HILBERT_TABLE[101]=8;
    HILBERT_TABLE[102]=1;
    HILBERT_TABLE[103]=9;
    HILBERT_TABLE[104]=19;
    HILBERT_TABLE[105]=13;
    HILBERT_TABLE[106]=13;
    HILBERT_TABLE[107]=12;
    HILBERT_TABLE[108]=17;
    HILBERT_TABLE[109]=3;
    HILBERT_TABLE[110]=7;
    HILBERT_TABLE[111]=2;
    HILBERT_TABLE[112]=6;
    HILBERT_TABLE[113]=14;
    HILBERT_TABLE[114]=14;
    HILBERT_TABLE[115]=21;
    HILBERT_TABLE[116]=16;
    HILBERT_TABLE[117]=15;
    HILBERT_TABLE[118]=0;
    HILBERT_TABLE[119]=20;
    HILBERT_TABLE[120]=18;
    HILBERT_TABLE[121]=15;
    HILBERT_TABLE[122]=1;
    HILBERT_TABLE[123]=11;
    HILBERT_TABLE[124]=12;
    HILBERT_TABLE[125]=14;
    HILBERT_TABLE[126]=15;
    HILBERT_TABLE[127]=10;
    HILBERT_TABLE[128]=16;
    HILBERT_TABLE[129]=16;
    HILBERT_TABLE[130]=0;
    HILBERT_TABLE[131]=23;
    HILBERT_TABLE[132]=14;
    HILBERT_TABLE[133]=22;
    HILBERT_TABLE[134]=6;
    HILBERT_TABLE[135]=17;
    HILBERT_TABLE[136]=7;
    HILBERT_TABLE[137]=17;
    HILBERT_TABLE[138]=19;
    HILBERT_TABLE[139]=5;
    HILBERT_TABLE[140]=13;
    HILBERT_TABLE[141]=4;
    HILBERT_TABLE[142]=17;
    HILBERT_TABLE[143]=16;
    HILBERT_TABLE[144]=18;
    HILBERT_TABLE[145]=19;
    HILBERT_TABLE[146]=12;
    HILBERT_TABLE[147]=18;
    HILBERT_TABLE[148]=3;
    HILBERT_TABLE[149]=6;
    HILBERT_TABLE[150]=21;
    HILBERT_TABLE[151]=7;
    HILBERT_TABLE[152]=13;
    HILBERT_TABLE[153]=18;
    HILBERT_TABLE[154]=19;
    HILBERT_TABLE[155]=19;
    HILBERT_TABLE[156]=9;
    HILBERT_TABLE[157]=1;
    HILBERT_TABLE[158]=23;
    HILBERT_TABLE[159]=0;
    HILBERT_TABLE[160]=8;
    HILBERT_TABLE[161]=15;
    HILBERT_TABLE[162]=20;
    HILBERT_TABLE[163]=20;
    HILBERT_TABLE[164]=2;
    HILBERT_TABLE[165]=21;
    HILBERT_TABLE[166]=22;
    HILBERT_TABLE[167]=14;
    HILBERT_TABLE[168]=12;
    HILBERT_TABLE[169]=10;
    HILBERT_TABLE[170]=3;
    HILBERT_TABLE[171]=21;
    HILBERT_TABLE[172]=21;
    HILBERT_TABLE[173]=20;
    HILBERT_TABLE[174]=18;
    HILBERT_TABLE[175]=11;
    HILBERT_TABLE[176]=22;
    HILBERT_TABLE[177]=17;
    HILBERT_TABLE[178]=2;
    HILBERT_TABLE[179]=22;
    HILBERT_TABLE[180]=8;
    HILBERT_TABLE[181]=16;
    HILBERT_TABLE[182]=20;
    HILBERT_TABLE[183]=23;
    HILBERT_TABLE[184]=9;
    HILBERT_TABLE[185]=4;
    HILBERT_TABLE[186]=13;
    HILBERT_TABLE[187]=23;
    HILBERT_TABLE[188]=23;
    HILBERT_TABLE[189]=5;
    HILBERT_TABLE[190]=19;
    HILBERT_TABLE[191]=22;


#endif
}
