#include <glm/glm.hpp>
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class CamaraLast {
    public:
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    float fov = 90.0f;
    float yaw = -90.0f;
    float pitch = 0.0f;
    float cameraAngle = 45.0f;

    void first(GLFWwindow* window){
         glm::vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        cameraFront = glm::normalize(front);

        // Crear la matriz de vista
        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

        // Configurar las matrices de proyección y vista en los shaders
        glm::mat4 projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    
        if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
        {
            // Aumentar el ángulo de visión
            yaw += 3.5f;
            if (yaw > 360.0f)
                yaw = 360.0f;
            //cout << "Ángulo de visión aumentado" << endl;
        }

        if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
        {
            // Disminuir el ángulo de visión
            yaw -= 3.5f;
            if (yaw < -360.0f)
                yaw = -360.0f;
           // cout << "Ángulo de visión disminuido" << endl;
        } 

        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
        {
            // Aumentar el ángulo de visión
            pitch += 3.5f;
            if (pitch > 360.0f)
                pitch = 360.0f;
          //  cout << "Ángulo de visión aumentado" << endl;
        }

        if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
        {
            // Disminuir el ángulo de visión
            pitch -= 3.5f;
            if (pitch < 1.0f)
                pitch = 1.0f;
            //cout << "Ángulo de visión disminuido" << endl;
        } 
    }
    void inputIfs(GLFWwindow* window)
    {
        float cameraSpeed = 0.05f;
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            cameraPos += cameraSpeed * cameraFront;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            cameraPos -= cameraSpeed * cameraFront;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

            static float angle = 0.0f;
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
        {
            angle += 5.0f;
            glm::vec3 center = glm::vec3(0.0f, 0.0f, 0.0f); // El centro alrededor del cual girará la cámara
            float radius = glm::distance(cameraPos, center); // La distancia entre la cámara y el centro
            cameraPos.x = center.x + radius * sin(glm::radians(angle));
            cameraPos.z = center.z + radius * cos(glm::radians(angle));
            cameraFront = glm::normalize(center - cameraPos);
        }
    }
};
