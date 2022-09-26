#pragma once

#include "../common.hpp"

namespace Vulkan {
    class Debug {
        public:
            Debug();
            ~Debug();

            void init(VkInstance instance) ;
            void cleanup(VkInstance instance);
            static bool isEnable() { return enableValidationLayers; }
            static void createDebugInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

            static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
                    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                    VkDebugUtilsMessageTypeFlagsEXT messageType,
                    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                    void* pUserData);
        private:
            VkDebugUtilsMessengerEXT debugMessenger;
#ifdef NDEBUG
            const static bool enableValidationLayers = false;
#else
            const static bool enableValidationLayers = true;
#endif

            VkResult create(
                    VkInstance instance,
                    const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                    const VkAllocationCallbacks* pAllocator,
                    VkDebugUtilsMessengerEXT* pDebugMessenger);

            void destroy(
                    VkInstance instance,
                    VkDebugUtilsMessengerEXT debugMessenger,
                    const VkAllocationCallbacks* pAllocator);

        };
}