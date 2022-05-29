#include <iostream>
#include <cmath>

using namespace std;

// вывод одномерного массива
void draw_float_array(double *arr, int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << "\t";
  cout << endl;
}

// вывод двумерного массива
void draw_float_double_array(double **arr, int size_x, int size_y) {
  for (int y = 0; y < size_y; y++) {
    for (int x = 0; x < size_x; x++) {
      cout << arr[y][x] << "\t";
    }
    cout << endl;
  }
}

// ввод значений для двумерного массива
double **read_double_arr(double **arr, int size_x, int size_y, bool random = false) {
  int x, y;

  for (y = 0; y < size_y; y++)
    for (x = 0; x < size_x; x++) {
      if (random) {
        arr[y][x] = random_int(-10, 10);
      } else {
        cout << "Array[" << y << "][" << x << "] = ";
        arr[y][x] = read_double();
      }
    }

    return arr;
}
