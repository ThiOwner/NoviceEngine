#include <iostream>
#include "../Engine/Rendering/Shader.hpp"
#include "../Engine/Rendering/Window.hpp"
#include "../Engine/Scene/GameObject.hpp"
#include "../Engine/Components/MeshRenderer.hpp"

int main() {
    try {
        Window engineWindow;
        Shader defaultShaders("Assets/Shaders/default.vert", "Assets/Shaders/default.frag");

        GameObject teapot;
        teapot.addComponent<MeshRenderer>("Assets/Models/utah_teapot.obj",&defaultShaders);

        while (!engineWindow.shouldClose()) {
            engineWindow.clear();
            teapot.render();
            engineWindow.swapBuffers();
            engineWindow.pollEvents();
        }
        return 0;

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}