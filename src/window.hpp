#pragma once

#include "../common.hpp"
#include "../vulkan/core.hpp"

namespace BS {
    class Window {
        public:
        const int WIDTH = 800;
        const int HEIGHT = 600;
        const std::string TITLE = "Hello vulkan. My Engine.";

        Window();
        ~Window();

        void run();
        bool shouldClose();
        
        private:
        void initWindow();
        void update();
        void cleanup();
        

        const int width;
        const int height;
        std::string windowName;
        GLFWwindow* window;
        Vulkan::Core* vulkanCore;
    };
}