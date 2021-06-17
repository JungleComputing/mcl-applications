/*
 * Copyright 2019 Vrije Universiteit Amsterdam, The Netherlands
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "vectoradd/vectoradd.h"
#include "timer.h"



void vectoraddCPUKernel(const int n, float *c, float *a, float *b) {
  for (int i = 0; i < n; i++) {
    c[i] = a[i] + b[i];
  }
}


void vectoraddCPU(int n, float *c, float *a, float *b) {
    timer t("cpu");

    t.start();
    vectoraddCPUKernel(n, c, a, b);
    t.stop();

    std::cerr << t << std::endl;
}


void vectoraddMCL(int n, float *c, float *a, float *b) {
  timer t("mcl");

  t.start();
  vectoradd(n, c, a, b);
  t.stop();
  
  std::cerr << t << std::endl;
}
