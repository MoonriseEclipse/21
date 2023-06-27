#include <stdio.h>
#include <math.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int *n);
int max(int *a, int *n);
int min(int *a, int *n);
double mean(int *a, int *n);
double variance(int *a, int *n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
  int n, data[NMAX];
  input(data, &n);
  output(data, &n);
  output_result(max(data, &n), min(data, &n), mean(data, &n),
                variance(data, &n));
  return 0;
}
int input(int *a, int *n) {
    if (scanf("%d", n) == 1) {
      for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
          printf("n/a");
        }
      }
    } else {
      printf("n/a");
    }
  return 0;
}
void output(int *a, int *n) {
  for (int *p = a; p - a < *n; p++) {
    printf("%d ", *p);
  }
  printf("\n");
}

int max(int *a, int *n) {
  int max = 0;
  for (int i = 0; i < *n; i++) {
    if(a[i]>a[i+1]){
    max = a[i];
    } 
  }
  return max;
}

int min(int *a, int *n) {
  int min = 0;
  for (int i = 0; i < *n; i++) {
    if(a[i]<a[i+1]){
    min = a[i];
    } 
  }
  return min;
}

double mean(int *a,int *n) {
  double sum = 0;
  double mean = 0;
  for (int i = 0; i < *n; i++){
     sum = sum + a[i];
  }
  mean = sum / *n;
  return mean;
}

double variance(int *a, int *n){
  double variance = 0;
  double sum = 0;
  double sum1 = 0;
  double mean = 0;
  for (int i = 0; i < *n; i++){
     sum = sum + a[i];
  }
  mean = sum / *n;
  for (int i = 0; i < *n; i++){
     sum1 = sum1 + pow((a[i]-mean),2);
  }
  variance = sum1 / *n;
  return variance; 
}

void output_result(int max_v, int min_v, double mean_v, double variance_v){
  printf("%d %d %f %f", max_v, min_v, mean_v, variance_v);
}
