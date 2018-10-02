
#include "classEntity.h"
#include <vector>

class classBoids{
    public:
        int boidsQuantity;
        std::vector<classEntity*> Boids;
        classBoids();
        classBoids(int mBoidsQuantity);
        void initialize();
        void drawBoids();
}