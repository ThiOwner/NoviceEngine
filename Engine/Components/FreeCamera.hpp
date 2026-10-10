#pragma once
#include "Component.hpp"

class FreeCamera : public Component {
public:
    float moveSpeed = 15.0f;
    float mouseSensitivity = 0.1f;

    void update(const FrameContext& context) override;
};