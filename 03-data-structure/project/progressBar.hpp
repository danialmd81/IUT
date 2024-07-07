#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;
void printProgressBar(int time);