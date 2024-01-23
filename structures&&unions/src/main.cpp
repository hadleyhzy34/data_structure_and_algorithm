#include <iostream>

// a structure can either be declared with structure declaration
// or as a seperate declaration like basic types
struct Point {
  int x, y;
};

struct pcl {
  int x, y, z;
} p1;

// in c, this is considered to be error
struct points {
  int x = 0;
  int y = 0;
};

int main(int argc, char *argv[]) {
  struct Point p2;
  // in c, its mandtory to add struct keyword before declaration of a variable
  Point p3;

  // struct members initialization
  struct Point p4 = {1, 2};
  std::cout << "x= " << p4.x << std::endl;

  p4.x = 5;
  std::cout << "y= " << p4.x << std::endl;

  // access array memebers
  struct Point arrayPoints[5];
  arrayPoints[0].x = 10;
  arrayPoints[0].y = 20;

  std::cout << arrayPoints[0].x << " " << arrayPoints[0].y << std::endl;

  // structure pointer
  struct Point *p5 = &p4;
  std::cout << p5->x << " " << p5->y << std::endl;
  return 0;
}
