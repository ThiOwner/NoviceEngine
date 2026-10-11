#include "Engine.hpp"
#include "FrameContext.hpp"
#include "Assets/AssetManager.hpp"
#include "Components/FreeCamera.hpp"

Engine::Engine() : _window(), _input(_window) {
    AssetManager::loadShader("default", "Assets/Shaders/default.vert", "Assets/Shaders/default.frag");

    _editorCameraComponent = _editorCamera.addComponent<Camera>(45.0f, 0.1f, 1000.0f);
    _editorCamera.addComponent<FreeCamera>();
    _editorCamera.getTransform()->setPosition(glm::vec3(0.0f, 0.0f, -2.0f));

    _window.setCursorCaptured(_capturedMouse);
}

void Engine::toggleState() { _currentState = (_currentState == ENGINE_STATE::EDIT_MODE) ? ENGINE_STATE::PLAY_MODE : ENGINE_STATE::EDIT_MODE; }

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
    if (_input.isKeyJustPressed(Key::F2)) toggleState();

    FrameContext context{ _time.getDeltaTime(), _time.getElapsedTime(), _input };

    if (_currentState == ENGINE_STATE::PLAY_MODE) {
        scene.update(context);
    } else {
        _editorCamera.update(context);
        scene.processingPendingObjects();
        scene.processingDestroyObjects();
    }
}

void Engine::render() {
    Camera* camera = (_currentState == ENGINE_STATE::PLAY_MODE) ? scene.getActiveCamera() : _editorCameraComponent;
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