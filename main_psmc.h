#pragma once
#include "psmcreader.h"
#include "fastas.h"

//from psmc
typedef struct{
  int n; // $n$ in psmc.tex. number of intervals equals to $n+1$
  int n_free; // number of free lambdas
  int *par_map; // parameter groups
  char *pattern;
  double *times;
  double *params;
  double TR[2];
}psmc_par;


typedef struct {
  int smartsize;
  char *chooseChr;
  int start;
  int stop;
  size_t nSites;
  int maxIter;
  double tole;
  perpsmc * perc;
  char *fname;
  int onlyOnce;
  long seed;//<-seed=-1 old version;seed=0 means time; othervise it will be used as seed
  int block;
  psmc_par *par;
  char *tkfile;
  // double *tk;
  //  double *lambda;
  perFasta *pf;
  int RD;
  int nThreads;
  int nIter;
  int doQuad;
  char *outname;
  FILE *fres;
  FILE *flog;
}args;
args * getArgs(int argc,char **argv);
void destroy_args(args *p);
int main_psmc(int argc,char **argv);
