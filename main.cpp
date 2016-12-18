#include <iostream>
#include <sstream>
#include <string>

#include "glinclude.h"
//#include "scene.h"
#include "fluid.h"
#include "camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void Do_Movement();
Camera camera(glm::vec3(0.0f, 0.0f, 0.0f));
bool keys[1024];
GLfloat lastX = 400, lastY = 300;
bool firstMouse = true;
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
GLfloat currentTime = 0.0f;

glm::mat4 cameraView = glm::mat4(1.0f);
glm::mat4 cameraProjection = glm::mat4(1.0f);
glm::vec3 cameraPosition = glm::vec3(1.0f);

int main()
{
    int frames = 0;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(viewportWidth, viewportHeight,
                                          "fluid3d", NULL, NULL);
    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glewExperimental = GL_TRUE;
    glewInit();

    //Scene* scene = new Scene();
    //scene->initScene();

    Fluid* fluid = new Fluid();
    fluid->initFluid();

    GLfloat lastFrame = glfwGetTime();

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        GLfloat currentFrame = glfwGetTime();
        currentTime = currentFrame;
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        if(currentFrame-lastFrame>=1.0)
        {
            string title;
            std::stringstream sfps;
            sfps << double(frames)/double(currentFrame-lastFrame);
            sfps >> title;
            lastFrame = glfwGetTime();
            glfwSetWindowTitle(window, title.c_str());
            frames = 0;
        }

        Do_Movement();
        cameraView = camera.GetViewMatrix();
        cameraProjection = glm::perspective(camera.Zoom,
                                                      (float)800/(float)600, 0.1f, 100.0f);
        cameraPosition = camera.Position;
        //scene->renderScene(cameraPosition, cameraView, cameraProjection);
        fluid->renderFluid(cameraPosition, cameraView, cameraProjection);

        glfwSwapBuffers(window);
        frames++;
        glfwPollEvents();
        //break;
    }
    glfwTerminate();
    return 0;
}


void Do_Movement()
{
    // Camera controls
    if(keys[GLFW_KEY_W])
    {
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }
    if(keys[GLFW_KEY_S])
    {
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }
    if(keys[GLFW_KEY_A])
    {
        camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if(keys[GLFW_KEY_D])
    {
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }
}

void key_callback(GLFWwindow* window, int key, int scancode, int action,
                  int mode)
{
    if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if(action == GLFW_PRESS)
    {
        keys[key] = true;
    }
    else if(action == GLFW_RELEASE)
    {
        keys[key] = false;
    }
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{

    if(firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }
    GLfloat xoffset = xpos - lastX;
    GLfloat yoffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;
    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}
