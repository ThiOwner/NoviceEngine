#pragma once

class Time {
public:
    Time();

    void update();

    float getDeltaTime() const;
    float getElapsedTime() const;

private:
    double _lastTime;
    double _deltaTime;
    double _elapsedTime;
};