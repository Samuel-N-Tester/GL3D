#ifndef GAMEASSET_H
#define GAMEASSET_H


#include <iostream>
#include <GL/gl.h>

class GameAsset {
 public:
  virtual void Draw(GLuint) = 0;
  glm::mat4 getModelMatrix();

  void translate(double, double, double);

  void moveX(double);
  void moveY(double);
  void moveZ(double);

  void rotateX(double);
  void rotateY(double);

 protected:
  glm::mat4 model;

};

#endif
