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

  void run_bench();
  
  double getMean(std::vector<int> v);
  double getSD(std::vector<int>v,double mean);
  
  bool compare_vec(std::vector<Point> v, std::vector<Point> u);

  
  
};

#endif // BENCHMARK_H
