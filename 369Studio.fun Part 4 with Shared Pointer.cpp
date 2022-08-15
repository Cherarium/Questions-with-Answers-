////Calculates the absolute minimum possible time that any 2 players in the passed in list could get to one another

#include <iostream>

#include <cmath>

#include <vector>

#include <string>

#include <ctime>

#include <memory>

#include <utility>

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
};

float CalcMinPossibleTimeUntilPlayerCollision(vector < shared_ptr < Player > > & PlayerList) {
  // First find the closest 2 players
  shared_ptr < Player > P1, P2;
  float MinDistance = 10000.0 f;

  //Check if players are null
  //Loop can pick the same player twice resulting in the player going to itself, and time being zero.
  //Therefore "j" shouldn't iterate form 0 but from i + 1 instead

  for (int i = 0; i < PlayerList.size(); i++) {
    for (int j = i + 1; j < PlayerList.size(); j++) {
      Vec3D VecDiff;
      VecDiff.x = PlayerList.at(i) -> Location.x - PlayerList.at(j) -> Location.x;
      VecDiff.y = PlayerList.at(i) -> Location.y - PlayerList.at(j) -> Location.y;
      VecDiff.z = PlayerList.at(i) -> Location.z - PlayerList.at(j) -> Location.z;

      float VecDiffSize = sqrt(VecDiff.x * VecDiff.x + VecDiff.y * VecDiff.y + VecDiff.z * VecDiff.z);

      if (VecDiffSize < MinDistance) {
        P1 = PlayerList.at(i);
        P2 = PlayerList.at(j);
        MinDistance = VecDiffSize;
      }
    }
  }

  //How long it would take the two of them to reach one another if they just bee-lined it.
  Vec3D VecDiff;
  VecDiff.x = P1 -> Location.x - P2 -> Location.x;
  VecDiff.y = P1 -> Location.y - P2 -> Location.y;
  VecDiff.z = P1 -> Location.z - P2 -> Location.z;

  float Distance = sqrt(VecDiff.x * VecDiff.x + VecDiff.y * VecDiff.y + VecDiff.z * VecDiff.z);

  // Assuming the two closest players are moving directly towards one another, this is the minimum possible time before a collision happens.
  float MinTime = Distance / (P1 -> MaxMoveSpeed + P2 -> MaxMoveSpeed);

  return MinTime;
}

int main() {
  int coord = 0;
  int speed = 1.0;
  vector < shared_ptr < Player > > players;
  for (int i = 0; i < 10; i++) {
    shared_ptr < Player > newPlayer = make_shared < Player > ();
    Vec3D newLocation = Vec3D();
    newLocation.x = coord++;
    newLocation.y = coord++;
    newLocation.z = coord++;
    newPlayer -> Location = newLocation;
    newPlayer -> MaxMoveSpeed = speed++;
    players.push_back(newPlayer);
  }
  float result = CalcMinPossibleTimeUntilPlayerCollision(players);
  printf("result: %f", result);
  return 0;
}
