/*
  Составить две программы, первая из которых вводит составные части структуры данных,
  приведѐнной в индивидуальном варианте, как десятичные числа и формирует из них заданную
  упакованную структуру как 16-ричное число. Вторая программа вводит упакованную структуру
  как 16-ричное число и выводит значения отдельных еѐ составных частей как десятичные числа.
*/

// Информация о состоянии устройства в системе ввода-вывода представляется в виде

#include <iostream>
#include "lib.h"
#include "info_device.h"

using namespace std;

int main() {
  // смена кодировки
  system("chcp 65001");

  int c = 0; // 3 номер канала
  int u = 0; // 5 номер устройства в канале
  int e = 0; // 6 код состояния
  int b = 0; // 1 признак занятости устройства

  draw_line(20);

  cout << "Номер канала: ";
  c = read_int();

  cout << "Номер устройства в канале: ";
  u = read_int();

  cout << "Код состояния: ";
  e = read_int();

  cout << "Признак занятости устройства: ";
  b = read_int();

  draw_line(20);

  unsigned short z =  code(c, u, e, b);
  cout << "Информация о состоянии устройства: 0x" << hex << z << endl;

  return 0;
}
