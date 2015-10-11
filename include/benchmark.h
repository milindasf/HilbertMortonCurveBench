/*
 *@author: Milinda Fernando
 *@date: 09/04/2015 // This is refactored code from HilbertBenchmark code.
 *School of Computing, University of Utah
 *
 *Compare the performance of differernt SFC implemnetations. 
 *Currently supports for HILBERT and MORTON Curves.  
 *
 * 
 */
#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <iostream>
#include <algorithm>
#include "point.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>

#include "hilbert.h"
#include "morton.h"


#include <typeinfo>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>



#define MORTON_BASELINE 0
#define HILBERT_BASELINE 1
#define HILBERT_NCA 2
#define MORTON_NCA 3




class Benchmark
{
private:
  
  unsigned int max_depth;
  unsigned int dim;
  
  int num_pts;
  int num_iterations;
  
  int MIN_LIMIT;
  int MAX_LIMIT;

  std::vector<Point> point_vec;
  
  std::vector<int> runtime_hilbert_baseline;
  std::vector<int> runtime_morton_baseline;
  std::vector<int> runtime_hilbert_NCA;
  std::vector<int> runtime_morton_NCA;

  
  
  
public: 
  Benchmark(unsigned int max_depth, unsigned int dim, int number_pts,int num_iterations);
  ~Benchmark();

  int rand_int(int a, int b);
  float rand_float(float a, float b);
  
  void generate_random_points();
  int  order_points(int implementation);
  
  void output_points();
  void output_to_csv(std::string file_name);
  void output_to_vtk(std::string file_name);

  bool pairwise_ordering_check(std::vector<Point>& nodes,int ordering_type);

  void run_bench();
  
  double getMean(std::vector<int> v);
  double getSD(std::vector<int>v,double mean);
  
  bool compare_vec(std::vector<Point> v, std::vector<Point> u);

  
  
};

#endif // BENCHMARK_H
