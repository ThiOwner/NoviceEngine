#pragma once
#include "Component.hpp"

class FlyCameraControl : public Component {
public:
    float moveSpeed = 5.0f;
    float mouseSensitivity = 0.1f;

    void update(const FrameContext& context) override;
};