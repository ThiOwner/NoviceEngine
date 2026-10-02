#pragma once

class Time {
public:
    Time();

    void update();

    float getDeltaTime() const;
    float getElapsedTime() const;

private:
    double lastTime;
    double deltaTime;
    double elapsedTime;
};