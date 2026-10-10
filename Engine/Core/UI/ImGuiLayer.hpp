#pragma once

struct GLFWwindow;
class Scene;

class ImGuiLayer {
public:
    explicit ImGuiLayer(GLFWwindow* window);
    ~ImGuiLayer();

    ImGuiLayer(const ImGuiLayer&) = delete;
    ImGuiLayer& operator=(const ImGuiLayer&) = delete;

    void beginFrame();
    void endFrame();

    void setMouseEnabled(bool enabled);

    void drawDebugPanels(Scene& scene, float fps, float frameTimeMs);

    bool visible = true;
};