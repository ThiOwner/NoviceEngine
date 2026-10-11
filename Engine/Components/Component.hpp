#pragma once
#include "Core/FrameContext.hpp"

class GameObject;

class Component {
public:
    GameObject* owner = nullptr;
    bool hasStarted = false;
    bool isActive = true;

    virtual ~Component() = default;

    virtual void start(const FrameContext& context) {} // Called at the first frame.
    virtual void update(const FrameContext& context) {} // Called every frame
};