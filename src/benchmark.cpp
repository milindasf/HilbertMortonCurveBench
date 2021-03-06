/*
 * Copyright (c) 2015 <copyright holder> <email>
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 */

#include "../include/benchmark.h"


Benchmark::Benchmark(unsigned int max_depth, unsigned int dim, int number_pts, int num_iterations)
{
  this->max_depth=max_depth;
  this->dim=dim;
  this->num_pts=number_pts;
  this->num_iterations=num_iterations;
  
  MAX_LIMIT=(1<<max_depth)-1;
  MIN_LIMIT=0;
  
  G_MAX_DEPTH=max_depth;
  G_dim=dim;
  
  
}



float Benchmark::rand_float(float a, float b)
{
  float random = ((float) std::rand()) / (float) RAND_MAX;
  float diff = b - a;
  float r = random * diff;
  return a + r;
}

int Benchmark::rand_int(int a, int b)
{

  int randNum = rand()%(b-a + 1) + a;
  return randNum;
}


void Benchmark::generate_random_points()
{
  Point temp;
  unsigned int rand_x,rand_y,rand_z;
  point_vec.clear();
  if (dim==2)
  {
    for(int i=0;i<num_pts;i++)
    {
      rand_x=rand_int(MIN_LIMIT,MAX_LIMIT);
      rand_y=rand_int(MIN_LIMIT,MAX_LIMIT);
      rand_z=0;
      temp=Point(rand_x,rand_y,rand_z);
      point_vec.push_back(temp);
      
    }
    
  }else if (dim ==3)
  {
    for(int i=0;i<num_pts;i++)
    {
      rand_x=rand_int(MIN_LIMIT,MAX_LIMIT);
      rand_y=rand_int(MIN_LIMIT,MAX_LIMIT);
      rand_z=rand_int(MIN_LIMIT,MAX_LIMIT);
      temp=Point(rand_x,rand_y,rand_z);
      point_vec.push_back(temp);
      
    }
  }
  
  
}

int Benchmark::order_points(int implementation)
{

  if (implementation==HILBERT_BASELINE){
    std::sort(point_vec.begin(),point_vec.end(),hilbert_order);
  }else if(implementation==HILBERT_NCA)
  {
    std::sort(point_vec.begin(),point_vec.end(),hilbert_order_NCA);
  }else if(implementation==MORTON_BASELINE)
  {
    std::sort(point_vec.begin(),point_vec.end(),morton_order);
  }else if (implementation==MORTON_NCA)
  {
    std::sort(point_vec.begin(),point_vec.end(),morton_order_NCA);
  }
  return 0;
}

void Benchmark::output_points()
{
  for(int i=0;i<point_vec.size();i++)
  {
    
    std::cout<<"Index:"<<i<<" :"<<point_vec[i].x()<<", "<<point_vec[i].y()<<","<<point_vec[i].z()<<std::endl;
    
  }
  
}

void Benchmark::output_to_csv(std::string file_name)
{
  
  std::ofstream myfile;
  std::string filename="../octave/"+file_name+".csv";
  std::cout<<filename<<std::endl;
  myfile.open(filename.c_str());
   
  for(int i=0;i<point_vec.size();i++)
  {  
    myfile <<point_vec[i].x()<<"\t"<<point_vec[i].y()<<"\t"<<point_vec[i].z()<<std::endl;;
  }
  myfile.close();
  
  
}

double Benchmark::getMean(std::vector< int > v)
{
  int sum;
  double mean;
  sum=std::accumulate(v.begin(),v.end(),0.0);
  mean= (double)sum/v.size();
  return mean;
}

double Benchmark::getSD(std::vector< int > v,double mean)
{
  std::vector<double> diff(v.size());
  std::transform(v.begin(), v.end(), diff.begin(),std::bind2nd(std::minus<double>(), mean));
  double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
  double stdev = std::sqrt(sq_sum / v.size());
  
  return stdev;
}


bool Benchmark::compare_vec(std::vector< Point > v, std::vector< Point > u)
{

  bool is_equal=false;
  if ( v.size() <= u.size() )
	is_equal = std::equal ( v.begin(), v.end(), u.begin() );
  else
	is_equal = std::equal ( u.begin(), u.end(), v.begin() );
  
  return is_equal;
  
}


void Benchmark::run_bench()
{
  
  runtime_hilbert_baseline.clear();
  runtime_morton_baseline.clear();
  runtime_hilbert_NCA.clear();
  runtime_morton_NCA.clear();
  
  int temp;
  for(int i=0;i<num_iterations;i++)
  {
    this->generate_random_points();
    //this->output_to_csv("pts");
    
    auto start_hilbert_basline=std::chrono::system_clock::now();
    this->order_points(HILBERT_BASELINE);
    auto duration_hilbert_baseline=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start_hilbert_basline);
    runtime_hilbert_baseline.push_back(duration_hilbert_baseline.count());
    std::cout<<"duration_hilbert_baseline:"<<duration_hilbert_baseline.count()<<std::endl;
    std::vector<Point> h_bl=point_vec;
    //this->output_points();
    //this->output_to_csv("hilbert_bl");
    //this->output_points();
    
    auto start_morton_baseline=std::chrono::system_clock::now();
    this->order_points(MORTON_BASELINE);
    auto duration_morton_baseline=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start_morton_baseline);
    runtime_morton_baseline.push_back(duration_morton_baseline.count());
    std::cout<<"duation_morton baseline:"<<duration_morton_baseline.count()<<std::endl;
    //this->output_points();
    //this->output_to_csv("morton");
    std::vector<Point> m_bl=point_vec;
    
    
    auto start_hilbert_nca=std::chrono::system_clock::now();
    this->order_points(HILBERT_NCA);
    auto duration_hilbert_nca=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start_hilbert_nca);
    runtime_hilbert_NCA.push_back(duration_hilbert_nca.count());
    std::cout<<"duration_hilbert_NCA:"<<duration_hilbert_nca.count()<<std::endl;
    
    std::vector<Point> h_nca=point_vec;
    this->output_to_csv("hilbert_nca");
    
    auto start_morton_nca=std::chrono::system_clock::now();
    this->order_points(MORTON_NCA);
    auto duration_morton_nca=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()-start_morton_nca);
    runtime_morton_NCA.push_back(duration_morton_nca.count());
    std::cout<<"duration_morton_NCA:"<<duration_morton_nca.count()<<std::endl;
    
    std::vector<Point> m_nca=point_vec;
    bool h_state=false; 
    bool m_state=false;
    
    h_state=this->compare_vec(h_bl,h_nca);
    m_state=this->compare_vec(m_bl, m_nca);
  
    std::cout<<"comparison between morton bl and nca and hilbert bl and nca"<<std::endl;
    if( h_state && m_state )
    {
      std::cout <<"Interation i:"<<i<<" ordered points matched successfully"<<std::endl;
    }else
    {
      std::cout<<"Interation i:"<<i<<" ordered points mismatched"<<std::endl;
    }
    
    
  }
  
  
  double h_mean_bl,m_mean_bl,h_mean_nca, m_mean_nca;
  double h_sd_bl,m_sd_bl,h_sd_nca,m_sd_nca;
  
  h_mean_bl=this->getMean(runtime_hilbert_baseline);
  h_sd_bl=this->getSD(runtime_hilbert_baseline,h_mean_bl);
  
  m_mean_bl=this->getMean(runtime_morton_baseline);
  m_sd_bl=this->getSD(runtime_morton_baseline,m_mean_bl);
  
  h_mean_nca=this->getMean(runtime_hilbert_NCA);
  h_sd_nca =this->getSD(runtime_hilbert_NCA,h_mean_nca);
  
  m_mean_nca=this->getMean(runtime_morton_NCA);
  m_sd_nca=this->getSD(runtime_morton_NCA,m_mean_nca);
  
  std::cout<<"\n\nIterations Executed:"<<num_iterations<<" Dimention:"<<this->dim<<std::endl;
  std::cout<<"MIN_LIMIT: "<<MIN_LIMIT<<"  MAX_LIMIT: "<<MAX_LIMIT<<"  MAX_DEAPTH:"<<G_MAX_DEPTH<<std::endl; 
  std::cout<<"Hilbert Mean Baseline:"<<h_mean_bl<< "\t SD:"<<h_sd_bl<<std::endl;
  std::cout<<"Hilbert Mean NCA:"<<h_mean_nca<<"\t SD:"<<h_sd_nca<<std::endl;;
  std::cout<<"Morton Mean BaseLine:"<<m_mean_bl<<"\t SD:"<<m_sd_bl<<std::endl;
  std::cout<<"Morton Mean NCA:"<<m_mean_nca<<"\t SD:"<<m_sd_nca<<std::endl;
  
  std::cout<<"CSV Output:"<<std::endl<<std::endl;
  std::cout<<h_mean_bl<< "\t"<<h_sd_bl<<std::endl;
  std::cout<<h_mean_nca<<"\t"<<h_sd_nca<<std::endl;;
  std::cout<<m_mean_bl<<"\t"<<m_sd_bl<<std::endl;
  std::cout<<m_mean_nca<<"\t"<<m_sd_nca<<std::endl;
  
  
}


