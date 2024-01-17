#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include "Component.hpp"

class Camera:public Component
{
    public:
        Camera(GameObject *gO, Scene* sn);
        ~Camera();

        void Init();
        void Update();

        float FOV;
        float near;
        float far;
        glm::mat4 viewMat;
    private:
        glm::mat4 projMat;
        float aspect;
};

#endif //CAMERA_H