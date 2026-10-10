#include "ImGuiLayer.hpp"

#include "Scene/Scene.hpp"
#include "Scene/GameObject.hpp"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

ImGuiLayer::ImGuiLayer(GLFWwindow* window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

ImGuiLayer::~ImGuiLayer() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void ImGuiLayer::beginFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void ImGuiLayer::endFrame() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiLayer::setMouseEnabled(bool enabled) {
    ImGuiIO& io = ImGui::GetIO();
    if (enabled) io.ConfigFlags &= ~ImGuiConfigFlags_NoMouse;
    else         io.ConfigFlags |=  ImGuiConfigFlags_NoMouse;
}

void ImGuiLayer::drawDebugPanels(Scene& scene, float fps, float frameTimeMs) {
    if (!visible) return;

    ImGui::Begin("Debug");
    ImGui::Text("FPS : %.1f", fps);
    ImGui::Text("Frame : %.2f ms", frameTimeMs);
    ImGui::End();

    ImGui::Begin("Directional Light");
    ImGui::DragFloat3("Rotation", &scene.dirLight.rotation.x, 0.5f);
    ImGui::ColorEdit3("Color", &scene.dirLight.color.x);
    ImGui::DragFloat("Intensity", &scene.dirLight.intensity, 0.01f, 0.0f, 5.0f);
    ImGui::End();

    ImGui::Begin("Scene");
    for (GameObject* object : scene.getGameObjects()) {
        ImGui::PushID(object);
        if (ImGui::TreeNode("Object")) {
            glm::vec3 pos = object->getTransform()->getPosition();
            if (ImGui::DragFloat3("Position", &pos.x, 0.05f)) {
                object->getTransform()->setPosition(pos);
            }
            ImGui::TreePop();
        }
        ImGui::PopID();
    }
    ImGui::End();
}