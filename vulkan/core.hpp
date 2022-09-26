#pragma once

#include "../common.hpp"
#include "debug.hpp"

namespace Vulkan {
    class Core {
        public:
        Core();
        ~Core();

        void init();
        void update();
        void cleanup();

        private:
        VkInstance instance;
        Debug debugger;
        void createInstance();
        void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
        std::vector<const char*> getRequiredExtensions();
        bool checkValidationLayerSupport();

        const std::vector<const char*> validationLayers = {
                "VK_LAYER_KHRONOS_validation"
        };

    };
}