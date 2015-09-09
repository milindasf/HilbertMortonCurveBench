#include <iostream>
#include "include/benchmark.h"
#include "include/rotation.h"


int main(int argc, char **argv) {
    std::cout<<"Hilbert Morton Bench Version 2.0"<<std::endl;
    Benchmark* bench;
       
    int args=argc;
    int arg_dim=atoi(argv[1]);
    int arg_num_pts=atoi(argv[2]);
    int arg_max_depth=atoi(argv[3]);
    int arg_iter=atoi(argv[4]);   
    initializeHilbetTable(2);
    
    initializeHilbetTable(3);
    
    
    bench=new Benchmark(arg_max_depth,arg_dim,arg_num_pts,arg_iter);
    bench->run_bench();
    free(bench);
    
//     std::vector<Rotation3D> rotations;
//     generateRotationPermutations<Rotation3D>(3,rotations);
//     //std::sort(rotations.begin(),rotations.end());
//     for(int i=0;i<rotations.size();i++)
//     {
//         char rot[9];
// 	char rot_index[9];
// 	Rotation3D item=rotations[i];
// 	for(int i=0;i<8;i++)
// 	{
// 	  rot[i]=item.rot_perm[i]+'0';
// 	  rot_index[i]=item.rot_index[i]+'0';
// 	}
// 	
// 	std::cout<<"New Rotation:"<<std::string(rot)<<"\t Rotation Index"<<std::string(rot_index)<<std::endl;
//       
//     }
//     std::cout<<"Num Rotations:"<<rotations.size()<<std::endl;
    //std::cout.setf( std::ios_base::unitbuf );
    
    return 0;
}
