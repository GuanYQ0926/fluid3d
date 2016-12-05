#ifndef SCENE_H
#define SCENE_H

#include "glinclude.h"
#include "glslprogram.h"
#include <glm/glm.hpp>


const int gridWidth = 96;
const int gridHeight = gridWidth;
const int gridDepth = gridWidth;
const float cellSize = 1.25f;
const float timeStep = 0.25f;
const float gradientScale = 1.125f/cellSize;
const float splatRadius = gridWidth/8.0f;
const float ambientTemperature = 0.0f;
const float smokeBuoyancy = 1.0f;
const float smokeWeight = 0.0125f;
const int viewportWidth = 320;
const int viewportHeight = viewportWidth;
const float velocityDissipation = 0.99f;
const float temperatureDissipation = 0.99f;
const float densityDissipation = 0.9995f;
const glm::vec3 impulsePosition = glm::vec3(gridWidth/2.0f,
                                            gridHeight-(int)splatRadius/2.0f, gridDepth/2.0f);
const float impulseTemperature = 10.0f;
const float impulseDensity = 1.0f;
const int numJacobiIterations = 40;



enum AttributeSlot{
    slotPosition,
    slotTexCoord
};

struct ProgramSrc{
    GLSLProgram Advect;
    GLSLProgram Jacobi;
    GLSLProgram SubtractGradient;
    GLSLProgram ComputeDivergence;
    GLSLProgram ApplyImpulse;
    GLSLProgram ApplyBuoyancy;
};

struct Surface{
    GLuint fboHandle;
    GLuint colorTexture;
    GLsizei width;
    GLsizei height;
    GLsizei depth;
};

struct Slab{
    Surface ping;
    Surface pong;
};


class Scene
{
public:
    Scene();
    void initScene();
    void renderScene(glm::vec3 cameraPosition, glm::mat4 cameraView, glm::mat4 cameraProjection);

private:
    ProgramSrc programs;
    GLSLProgram raycastProgram;
    Slab velocity, density, pressure, temperature;
    Surface divergence, obstacles, hireObstacles;
    GLuint cubeCenter, fullScreenQuad;

    void resetState();
    void swapSurfaces(Slab* slab);
    void clearSurface(Surface s, float v);

    Surface createSurface(int width, int height, int numComponent=4);
    Slab createSlab(GLsizei width, GLsizei height, GLsizei depth, int numComponent);
    Surface createVolume(int width, int height, int depth, int numComponent=4);
    GLuint createPointVbo(float x, float y, float z);
    GLuint createQuadVbo();
    void createObstacles(Surface dest);

    void advect(Surface velocity, Surface source, Surface obstacles, Surface dest, float dissipation);
    void jacobi(Surface pressure, Surface divergence, Surface obstacles, Surface dest);
    void subtractGradient(Surface velocity, Surface pressure, Surface obstacles, Surface dest);
    void computeDivergence(Surface velocity, Surface obstacles, Surface dest);
    void applyImpulse(Surface dest, glm::vec3 position, float value);
    void applyBuoyancy(Surface velocity, Surface temperature, Surface density, Surface dest);
};

#endif // SCENE_H
