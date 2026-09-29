#pragma once

class GameObject;

class Component {
public:
    GameObject* parent = nullptr;
    bool isActive = false;

    virtual ~Component() = default;

    virtual void awake() {} // Called at the creation.
    virtual void start() {} // Called at the first frame.
    virtual void update(float deltaTime) {} // Called every frame
    virtual void render() {} // Called at the render
};