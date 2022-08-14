// QUESTION 1: The function determines if a character is moving backwards, or not. 
// Given the character's facing and their velocity, implement the function below.

#include <vector>

#include <cmath>

#include <string>

#include <iostream>

#include <bits/stdc++.h>

using namespace std;

struct Vec3D {
  float x, y, z;

  Vec3D operator - (const Vec3D & V) {
    Vec3D Result;
    Result.x = x - V.x;
    Result.y = y - V.y;
    Result.z = z - V.z;
    return Result;
  }
};

struct ListNode {
  ListNode * Next;
};

class Player {
  public:
    Vec3D Location;
  float MaxMoveSpeed;

  // ...
};

bool MovingBackwards(const Vec3D & CharacterVelocity,
  const Vec3D & CharacterFacing) {
  Vec3D result = Vec3D(CharacterFacing);
  result = result - CharacterVelocity;
  float old_sum = CharacterFacing.x + CharacterFacing.y + CharacterFacing.z;
  printf("old sum: %f\n", old_sum);
  float new_sum = result.x + result.y + result.z;
  printf("new sum: %f\n", new_sum);
  float diff = old_sum - new_sum;
  printf("diff: %f\n", diff);
  return diff >= 0;
}

int main() {
  Vec3D v = Vec3D();
  v.x = 10.0;
  v.y = 20.0;
  v.z = 30.0;
  Vec3D t = Vec3D();
  t.x = 100.0;
  t.y = 100.0;
  t.z = 100.0;
  if (MovingBackwards(v, t))
    printf("backwards\n");
  else
    printf("forward\n");
  return 0;
}
