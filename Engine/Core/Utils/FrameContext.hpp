#pragma once

class Input;

struct FrameContext {
    float deltaTime;
    float ElapsedTime;
    Input& input;
};