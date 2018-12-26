#ifndef _VECTOR_H
#define _VECTOR_H

#include "Shape.h"

class Vector : public Shape {
public:
  Vector(int s);
  double& operator[](int i);
  int size();

  void stop() override;
private:
  double* elem;
  int sz;
};

#endif
