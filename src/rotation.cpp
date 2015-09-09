#include "../include/rotation.h"

std::vector<Rotation3D> rotations_3d;
std::vector<Rotation2D> rotations_2d;
char **HILBERT_2D_TABLE;
char **HILBERT_3D_TABLE;

void initializeHilbetTable(int dim)
{
  HILBERT_2D_TABLE=new char*[4];
  HILBERT_3D_TABLE=new char*[24];
  
  for(int i=0;i<4;i++)
    HILBERT_2D_TABLE[i]=new char[4];
  
  for(int i=0;i<24;i++)
    HILBERT_3D_TABLE[i]=new char[8];
  
  unsigned int num_children=1<<dim;
  if(dim==2)
  {
    
    // NOTE: Assuming the rotations vector is sorted. 
    generateRotationPermutations<Rotation2D>(dim,rotations_2d);
    Rotation2D temp;
    
    for(int i=0;i<rotations_2d.size();i++)
    {
      temp=rotations_2d[i];
      for(int j=0;j<num_children;j++)
      {
	rotate(j,temp.rot_perm,temp.rot_index,dim);
	auto lower = std::lower_bound(rotations_2d.begin(), rotations_2d.end(),temp);
	bool found = lower != rotations_2d.end() && *lower == temp;
	if(found==false)
	{
	  std::cout<<"Rotation Permutations Error. Found a rotations permutation which is not in the list"<<std::endl;
	}else
	{
	  int index=lower-rotations_2d.begin();
	  //std::cout<<"Index:"<<index<<std::endl;
	  HILBERT_3D_TABLE[i][j]=index;
	  std::cout<<"HILBERT_2D_TABLE["<<i<<"]"<<"["<<j<<"]="<<index<<";"<<std::endl;
	}
      }
    }
    
  }else if(dim=3)
  {
    
    // NOTE: Assuming the rotations vector is sorted. 
    generateRotationPermutations<Rotation3D>(dim,rotations_3d);
//     for(int i=0;i<rotations.size();i++){
//       std::cout<<"Rotation:"<<rotations[i].rot_perm_str()<<std::endl;
//     }
    Rotation3D temp;
    
    for(int i=0;i<rotations_3d.size();i++)
    {
      temp=rotations_3d[i];
      for(int j=0;j<num_children;j++)
      {
	rotate(j,temp.rot_perm,temp.rot_index,dim);
	auto lower = std::lower_bound(rotations_3d.begin(), rotations_3d.end(),temp);
	bool found = lower != rotations_3d.end() && *lower == temp;
	if(found==false)
	{
	  std::cout<<"Rotation Permutations Error. Found a rotations permutation which is not in the list"<<std::endl;
	}else
	{
	  int index=lower-rotations_3d.begin();
	  //std::cout<<"Index:"<<index<<std::endl;
	  HILBERT_3D_TABLE[i][j]=index;
	  std::cout<<"HILBERT_3D_TABLE["<<i<<"]"<<"["<<j<<"]="<<index<<";"<<std::endl;
	}
	
      }
    }
  }
  
  
  
  
}


void rotate_table_based(int index,char* current,char * rot_index,int dim)
{
  
  if(dim==2)
  {
    
  }else if(dim==3)
  {
    Rotation3D temp=Rotation3D(current,rot_index);
    auto lower = std::lower_bound(rotations_3d.begin(), rotations_3d.end(),temp);
    bool found = lower != rotations_3d.end() && *lower == temp;
    if(found==false)
    {
      std::cout<<"Rotation Permutations Error. Found a rotations permutation which is not in the list"<<std::endl;
    }else
    {
      int value_index=lower-rotations_3d.begin();
      int lookup=HILBERT_3D_TABLE[value_index][index];
      temp=rotations_3d[lookup];
      memcpy(current,temp.rot_perm,sizeof(char)*8);
      memcpy(rot_index,temp.rot_index,sizeof(char)*8);
    }
    
  }
  
  
}
