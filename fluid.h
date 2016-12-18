#ifndef FLUID_H
#define FLUID_H


#include "glinclude.h"
#include "glslprogram.h"
#include <glm/glm.hpp>
#include <stdio.h>



const int viewportWidth = 640;
const int viewportHeight = viewportWidth;
const int gridWidth = viewportWidth/2;
const int gridHeight = gridWidth;
const int gridDepth = gridWidth;
const float timeStep = 0.25f;
const float cellSize = 1.25f;
const float gradientScale = 1.125f/cellSize;
const float splatRadius = gridWidth/8.0f;
const float ambientTemperature = 10.0f;
const float smokeBuoyancy = 1.0f;
const float smokeWeight = 0.0125f;
const float velocityDissipation = 0.99f;
const float temperatureDissipation = 0.99f;
const float densityDissipation = 0.9995f;
const vec3 impulsePosition = vec3(gridWidth/2.0f,
                                  gridHeight-(int)splatRadius/2.0f,
                                  gridDepth/2.0f);
const float impulseTemperature = 10.0f;
const float impulseDensity = 1.0f;
const int numJacobiIterations = 40;



struct ProgramRec{
    GLSLProgram Advect;
    GLSLProgram Jacobi;
    GLSLProgram SubtractGradient;
    GLSLProgram ComputeDivergence;
    GLSLProgram ApplyImpulse;
    GLSLProgram ApplyBuoyancy;
    GLSLProgram Visualize;
};

struct Volume{
    GLuint fboHandle;
    GLuint textureHandle;
    GLsizei width;
    GLsizei height;
    GLsizei depth;
};

struct Slab{
    Volume ping;
    Volume pong;
};


class Fluid
{
public:
    Fluid();
    void initFluid();
    void renderFluid(vec3 cameraPos, mat4 cameraView, mat4 cameraProjection);
private:
    ProgramRec programs;
    Slab velocity, density, pressure, temperature;
    Volume divergence, obstacles;
    GLuint cubeCenter, fullScreenQuad;

    Slab createSlab(GLsizei width, GLsizei height, GLsizei depth, int numComponent);
    Volume createVolume(GLsizei width, GLsizei height, GLsizei depth, int numComponent);
    GLuint createPointVao(float x, float y, float z);
    GLuint createQuadVao();
    GLuint createPointVbo(float x, float y, float z);
    GLuint createQuadVbo();
    void createObstacles(Volume dest);

    void resetState();
    void swapVolumes(Slab* slab);
    void clearVolume(Volume volume, float value);

    void advect(Volume velocity, Volume source, Volume obstacles,
                Volume dest, float dissipation);
    void jacobi(Volume pressure, Volume divergence, Volume obstacles,
                Volume dest);
    void subtractGradient(Volume velocity, Volume pressure, Volume obstacles,
                          Volume dest);
    void computeDivergence(Volume velocity, Volume obstacles, Volume dest);
    void applyImpulse(Volume dest, vec3 position, float value);
    void applyBuoyancy(Volume velocity, Volume temperature, Volume density, Volume dest);
};


#endif // FLUID_H
