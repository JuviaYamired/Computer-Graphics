#include <cmath>

class ClassBoundaryBox{    
    public:
        float center[2];
        float halfSize[2];
        
        ClassBoundaryBox(float iCenter[2], float iHalfSize[2]){
            center[0] = iCenter[0];
            center[1] = iCenter[1];
            halfSize[0] = iHalfSize[0];
            halfSize[1] = iHalfSize[1];
        }

        bool Collision(ClassBoundaryBox object){
            if(std::abs(center[0] - object.center[0]) > halfSize[0] + object.halfSize[0])
                return false;
            if(std::abs(center[1] - object.center[1]) > halfSize[1] + object.halfSize[1])
                return false;
            return true;
        }
};