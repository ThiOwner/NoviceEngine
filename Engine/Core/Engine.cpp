#include "Engine.hpp"
#include "FrameContext.hpp"
#include "Assets/AssetManager.hpp"

Engine::Engine(): _window(),_input(_window){
    AssetManager::loadShader("default","Assets/Shaders/default.vert","Assets/Shaders/default.frag");
    _currentState = ENGINE_STATE::EDIT_MODE;
    _window.setCursorCaptured(_capturedMouse);
}

void Engine::run() {
    while (!_window.shouldClose()) {
        _window.pollEvents();

        _time.update();
        _input.update();

        update();

        _window.clear();
        render();

        _window.swapBuffers();
    }
    AssetManager::clear();
}

void Engine::update() {
    if (_input.isKeyJustPressed(Key::Escape)) _window.close();
    if (_input.isKeyJustPressed(Key::F1)) _window.setCursorCaptured(_capturedMouse = !_capturedMouse);

    if (_currentState == ENGINE_STATE::PLAY_MODE) {
        FrameContext context{ _time.getDeltaTime(), _time.getElapsedTime(), _input };
        scene.update(context);
    }
}

void Engine::render() {
    if (_currentState == ENGINE_STATE::PLAY_MODE) {
        Camera* camera = scene.getActiveCamera();
        glm::mat4 view = camera->getViewMatrix();

        RenderView rv{
            view,
            camera->getProjectionMatrix(_window.getAspectRatio()),
            glm::normalize(glm::mat3(view) * -scene.dirLight.getDirection()),
            scene.dirLight.color,
            scene.dirLight.intensity
        };

        std::vector<MeshRenderer*> renderers;
        for (auto* object : scene.getGameObjects())
            object->getComponents<MeshRenderer>(renderers);

        Renderer::render(renderers, rv);
    }
}