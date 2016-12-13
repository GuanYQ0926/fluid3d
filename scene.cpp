#include "scene.h"
#include <stdio.h>
#include <math.h>

Scene::Scene()
{
    //Advect
    if(!programs.Advect.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/vertex.vs",
                                              GLSLShader::VERTEX))
    {
        printf("Advect::Vertex shader failed to compile!\n%s",
               programs.Advect.log().c_str());
        exit(1);
    }
    if(!programs.Advect.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/pickLayer.gs",
                                              GLSLShader::GEOMETRY))
    {
        printf("Advect::Geometry shader failed to compile!\n%s",
               programs.Advect.log().c_str());
        exit(1);
    }
    if(!programs.Advect.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/advect.fs",
                                              GLSLShader::FRAGMENT))
    {
        printf("Advect::Fragment shader failed to compile!\n%s",
               programs.Advect.log().c_str());
        exit(1);
    }
    if(!programs.Advect.link())
    {
        printf("Advect::Shader program failed to link!\n");
        exit(1);
    }
    //Jacobi
    if(!programs.Jacobi.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/vertex.vs",
                                              GLSLShader::VERTEX))
    {
        printf("Jacobi::Vertex shader failed to compile!\n%s",
               programs.Jacobi.log().c_str());
        exit(1);
    }
    if(!programs.Jacobi.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/pickLayer.gs",
                                              GLSLShader::GEOMETRY))
    {
        printf("Jacobi::Geometry shader failed to compile!\n%s",
               programs.Advect.log().c_str());
        exit(1);
    }
    if(!programs.Jacobi.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/jacobi.fs",
                                              GLSLShader::FRAGMENT))
    {
        printf("Jacobi::Fragment shader failed to compile!\n%s",
               programs.Jacobi.log().c_str());
        exit(1);
    }
    if(!programs.Jacobi.link())
    {
        printf("Jacobi::Shader program failed to link!\n");
        exit(1);
    }
    //SubtractGradient
    if(!programs.SubtractGradient.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/vertex.vs",
                                                        GLSLShader::VERTEX))
    {
        printf("SubtractGradient::Vertex shader failed to compile!\n%s",
               programs.SubtractGradient.log().c_str());
        exit(1);
    }
    if(!programs.SubtractGradient.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/pickLayer.gs",
                                              GLSLShader::GEOMETRY))
    {
        printf("SubtractGradient::Geometry shader failed to compile!\n%s",
               programs.Advect.log().c_str());
        exit(1);
    }
    if(!programs.SubtractGradient.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/subtractGradient.fs",
                                                        GLSLShader::FRAGMENT))
    {
        printf("SubtractGradient::Fragment shader failed to compile!\n%s",
               programs.SubtractGradient.log().c_str());
        exit(1);
    }
    if(!programs.SubtractGradient.link())
    {
        printf("SubtractGradient::Shader program failed to link!\n");
        exit(1);
    }
    //ComputeDivergence
    if(!programs.ComputeDivergence.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/vertex.vs",
                                                         GLSLShader::VERTEX))
    {
        printf("ComputeDivergence::Vertex shader failed to compile!\n%s",
               programs.ComputeDivergence.log().c_str());
        exit(1);
    }
    if(!programs.ComputeDivergence.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/pickLayer.gs",
                                              GLSLShader::GEOMETRY))
    {
        printf("ComputeDivergence::Geometry shader failed to compile!\n%s",
               programs.Advect.log().c_str());
        exit(1);
    }
    if(!programs.ComputeDivergence.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/computeDivergence.fs",
                                                         GLSLShader::FRAGMENT))
    {
        printf("ComputeDivergence::Fragment shader failed to compile!\n%s",
               programs.ComputeDivergence.log().c_str());
        exit(1);
    }
    if(!programs.ComputeDivergence.link())
    {
        printf("ComputeDivergence::Shader program failed to link!\n");
        exit(1);
    }
    //ApplyImpulse
    if(!programs.ApplyImpulse.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/vertex.vs",
                                                    GLSLShader::VERTEX))
    {
        printf("ApplyImpulse::Vertex shader failed to compile!\n%s",
               programs.ApplyImpulse.log().c_str());
        exit(1);
    }
    if(!programs.ApplyImpulse.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/pickLayer.gs",
                                              GLSLShader::GEOMETRY))
    {
        printf("ApplyImpulse::Geometry shader failed to compile!\n%s",
               programs.Advect.log().c_str());
        exit(1);
    }
    if(!programs.ApplyImpulse.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/splat.fs",
                                                    GLSLShader::FRAGMENT))
    {
        printf("ApplyImpulse::Fragment shader failed to compile!\n%s",
               programs.ApplyImpulse.log().c_str());
        exit(1);
    }
    if(!programs.ApplyImpulse.link())
    {
        printf("ApplyImpulse::Shader program failed to link!\n");
        exit(1);
    }
    //ApplyBuoyancy
    if(!programs.ApplyBuoyancy.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/vertex.vs",
                                                     GLSLShader::VERTEX))
    {
        printf("ApplyBuoyancy::Vertex shader failed to compile!\n%s",
               programs.ApplyBuoyancy.log().c_str());
        exit(1);
    }
    if(!programs.ApplyBuoyancy.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/pickLayer.gs",
                                              GLSLShader::GEOMETRY))
    {
        printf("ApplyBuoyancy::Geometry shader failed to compile!\n%s",
               programs.Advect.log().c_str());
        exit(1);
    }
    if(!programs.ApplyBuoyancy.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/buoyancy.fs",
                                                     GLSLShader::FRAGMENT))
    {
        printf("ApplyBuoyancy::Fragment shader failed to compile!\n%s",
               programs.ApplyBuoyancy.log().c_str());
        exit(1);
    }
    if(!programs.ApplyBuoyancy.link())
    {
        printf("ApplyBuoyancy::Shader program failed to link!\n");
        exit(1);
    }
}

void Scene::initScene()
{
    if(!raycastProgram.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/raycast.vs",
                                             GLSLShader::VERTEX))
    {
        printf("InitScene::RaycastProgram::Vertex shader failed to compile!\n%s",
               raycastProgram.log().c_str());
        exit(1);
    }
    if(!raycastProgram.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/raycast.gs",
                                             GLSLShader::GEOMETRY))
    {
        printf("InitScene::RaycastProgram::Geometry shader failed to compile!\n%s",
               raycastProgram.log().c_str());
        exit(1);
    }
    if(!raycastProgram.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/raycast.fs",
                                             GLSLShader::FRAGMENT))
    {
        printf("InistScene::RaycastProgram::Fragment shader failed to compile!\n%s",
               raycastProgram.log().c_str());
        exit(1);
    }
    if(!raycastProgram.link())
    {
        printf("InitScene::RaycastProgram::Shader failed to link!\n");
        exit(1);
    }


    cubeCenter = createPointVao(0, 0, 0);
    fullScreenQuad = createQuadVao();

    velocity = createSlab(gridWidth, gridHeight, gridDepth, 3);
    density = createSlab(gridWidth, gridHeight, gridDepth, 1);
    pressure = createSlab(gridWidth, gridHeight, gridDepth, 1);
    temperature = createSlab(gridWidth, gridHeight, gridDepth, 1);

    divergence = createVolume(gridWidth, gridHeight, gridDepth, 3);
    obstacles = createVolume(gridWidth, gridHeight, gridDepth, 3);
    createObstacles(obstacles);
    clearSurface(temperature.ping, ambientTemperature);

    glDisable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnableVertexAttribArray(slotPosition);
}

void Scene::renderScene(glm::vec3 cameraPosition, glm::mat4 cameraView, glm::mat4 cameraProjection)
{
    //update
    glViewport(0, 0, gridWidth, gridHeight);
    advect(velocity.ping, velocity.ping, obstacles, velocity.pong, velocityDissipation);
    swapSurfaces(&velocity);
    advect(velocity.ping, temperature.ping, obstacles, temperature.pong, temperatureDissipation);
    swapSurfaces(&temperature);
    advect(velocity.ping, density.ping, obstacles, density.pong, densityDissipation);
    swapSurfaces(&density);
    applyBuoyancy(velocity.ping, temperature.ping, density.ping, velocity.pong);
    swapSurfaces(&velocity);
    applyImpulse(temperature.ping, impulsePosition, impulseTemperature);
    applyImpulse(density.ping, impulsePosition, impulseDensity);
    computeDivergence(velocity.ping, obstacles, divergence);
    clearSurface(pressure.ping, 0);
    for(int i=0;i<numJacobiIterations;i++)
    {
        jacobi(pressure.ping, divergence, obstacles, pressure.pong);
        swapSurfaces(&pressure);
    }
    subtractGradient(velocity.ping, pressure.ping, obstacles, velocity.pong);
    swapSurfaces(&velocity);

    //Render
    raycastProgram.use();
    glEnable(GL_BLEND);

    glViewport(0, 0, viewportWidth, viewportHeight);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glClearColor(0.1, 0.1f, 0.1f, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    //draw ink
    glBindBuffer(GL_ARRAY_BUFFER, cubeCenter);
    glVertexAttribPointer(slotPosition, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), 0);
    glBindTexture(GL_TEXTURE_3D, density.ping.colorTexture);
    raycastProgram.setUniform("FillColor", glm::vec3(1));
    raycastProgram.setUniform("Scale", glm::vec3(1.0f/viewportWidth, 1.0f/viewportHeight, 1.0f/viewportWidth));
    glDrawArrays(GL_POINTS, 0, 1);

    //draw obstacles
    glBindTexture(GL_TEXTURE_3D, obstacles.colorTexture);
    raycastProgram.setUniform("FillColor", glm::vec3(0.125f, 0.4f, 0.75f));
    glDrawArrays(GL_POINTS, 0, 1);

    glDisable(GL_BLEND);
}



void Scene::resetState()
{
    glActiveTexture(GL_TEXTURE2); glBindTexture(GL_TEXTURE_3D, 0);
    glActiveTexture(GL_TEXTURE1); glBindTexture(GL_TEXTURE_3D, 0);
    glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_3D, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDisable(GL_BLEND);
}

void Scene::swapSurfaces(Slab* slab)
{
    Surface temp = slab->ping;
    slab->ping = slab->pong;
    slab->pong = temp;
}

void Scene::clearSurface(Surface s, float v)
{
    glBindFramebuffer(GL_FRAMEBUFFER, s.fboHandle);
    glClearColor(v, v, v, v);
    glClear(GL_COLOR_BUFFER_BIT);
}



Surface Scene::createSurface(int width, int height, int numComponent)
{
    GLuint fboHandle;
    glGenFramebuffers(1, &fboHandle);
    glBindFramebuffer(GL_FRAMEBUFFER, fboHandle);

    GLuint textureHandle;
    glGenTextures(1, &textureHandle);
    glBindTexture(GL_TEXTURE_2D, textureHandle);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    switch(numComponent)
    {
    case 1:
        glTexImage2D(GL_TEXTURE_2D, 0, GL_R16F, width, height, 0, GL_RED, GL_HALF_FLOAT, 0);
        break;
    case 2:
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RG16F, width, height, 0, GL_RG, GL_HALF_FLOAT, 0);
        break;
    case 3:
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, width, height, 0, GL_RGB, GL_HALF_FLOAT, 0);
        break;
    case 4:
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, width, height, 0, GL_RGBA, GL_HALF_FLOAT, 0);
        break;
    default:
        printf("CreateSurface::Switch Error!\n");
        exit(1);
    }

    GLuint colorbuffer;
    glGenRenderbuffers(1, &colorbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, colorbuffer);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureHandle, 0);
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER)!=GL_FRAMEBUFFER_COMPLETE){
        printf("CreateSurface::Framebuffer is not complete!\n");
    }

    Surface surface = {fboHandle, textureHandle, width, height, 1};

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    return surface;
}

Slab Scene::createSlab(GLsizei width, GLsizei height, GLsizei depth, int numComponent)
{
    Slab slab;
    slab.ping = createVolume(width, height, depth, numComponent);
    slab.pong = createVolume(width, height, depth, numComponent);
    return slab;
}

Surface Scene::createVolume(int width, int height, int depth, int numComponent)
{
    GLuint fboHandle;
    glGenFramebuffers(1, &fboHandle);
    glBindFramebuffer(GL_FRAMEBUFFER, fboHandle);

    GLuint textureHandle;
    glGenTextures(1, &textureHandle);
    glBindTexture(GL_TEXTURE_3D, textureHandle);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    switch(numComponent)
    {
    case 1:
        glTexImage3D(GL_TEXTURE_3D, 0, GL_R16F, width, height, depth, 0, GL_RED, GL_HALF_FLOAT, 0);
        break;
    case 2:
        glTexImage3D(GL_TEXTURE_3D, 0, GL_RG16F, width, height, depth, 0, GL_RG, GL_HALF_FLOAT, 0);
        break;
    case 3:
        glTexImage3D(GL_TEXTURE_3D, 0, GL_RGB16F, width, height, depth, 0, GL_RGB, GL_HALF_FLOAT, 0);
        break;
    case 4:
        glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA16F, width, height, depth, 0, GL_RGBA, GL_HALF_FLOAT, 0);
        break;
    default:
        printf("CreateVolume::Switch error!\n");
        exit(1);
    }

    GLuint colorbuffer;
    glGenRenderbuffers(1, &colorbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, colorbuffer);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, textureHandle, 0);
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER)!=GL_FRAMEBUFFER_COMPLETE){
        printf("CreateVolume::Framebuffer is not complete!\n");
    }

    Surface surface = {fboHandle, textureHandle, width, height, depth};

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    return surface;
}

GLuint Scene::createPointVao(float x, float y, float z)
{
    float p[] = {x, y, z};

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(p), &p[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, ((GLubyte*)NULL+(0)));
    return vao;
}

GLuint Scene::createQuadVao()
{
    short positions[] = {
        -1, -1,
         1, -1,
        -1,  1,
         1,  1
    };

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    GLsizeiptr size = sizeof(positions);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(slotPosition, 2, GL_SHORT, GL_FALSE, 2*sizeof(short), 0);
    return vao;
}

void Scene::createObstacles(Surface dest)
{
    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glViewport(0, 0, dest.width, dest.height);
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    GLSLProgram program;
    if(!program.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/vertex.vs",
                                      GLSLShader::VERTEX))
    {
        printf("CreateObstacles::Vertex shader failed to compile!\n%s",
               program.log().c_str());
    }
    if(!program.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/fill.fs",
                                      GLSLShader::FRAGMENT))
    {
        printf("CreateObstacles::Fragment shader failed to compile\n%s",
               program.log().c_str());
    }
    if(!program.link())
    {
        printf("CreateObstacles::Shader program failed to link!\n%s",
               program.log().c_str());
    }
    program.use();

    GLuint lineVbo;
    glGenBuffers(1, &lineVbo);
    GLuint circleVbo;
    glGenBuffers(1, &circleVbo);
    glEnableVertexAttribArray(slotPosition);

    for(int slice=0;slice<dest.depth;slice++)
    {
        glFramebufferTextureLayer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, dest.colorTexture,
                                  0, dest.depth-1-slice);
        float z = dest.depth/2.0f;
        z = abs(slice-z)/z;
        float fraction = 1 - sqrt(z);
        float radius = 0.5f * fraction;

        if(slice==0||slice==dest.depth-1){
            radius *= 100;
        }

        const bool drawBorder = true;
        if(drawBorder && slice!=0 && slice!=dest.depth-1)
        {
            #define T 0.9999f
            float positions[] = {
                -T, -T,
                 T, -T,
                 T,  T,
                -T,  T,
                -T, -T
            };
            #undef T
            GLsizeiptr size = sizeof(positions);
            glBindBuffer(GL_ARRAY_BUFFER, lineVbo);
            glBufferData(GL_ARRAY_BUFFER, size, positions, GL_STATIC_DRAW);
            GLsizeiptr stride = 2 * sizeof(positions[0]);
            glVertexAttribPointer(slotPosition, 2, GL_FLOAT, GL_FALSE, stride, 0);
            glDrawArrays(GL_LINE_STRIP, 0, 5);
        }

        const bool drawSphere = false;
        if(drawSphere || slice==0 || slice==dest.depth-1)
        {
            const int slices = 64;
            float positions[slices*2*3];
            float twopi = 8*atan(1.0f);
            float theta = 0;
            float dtheta = twopi/(float)(slices-1);
            float* pPositions = &positions[0];
            for(int i=0;i<slices;i++)
            {
                *pPositions++ = 0;
                *pPositions++ = 0;

                *pPositions++ = radius * cos(theta);
                *pPositions++ = radius * sin(theta);
                theta += dtheta;

                *pPositions++ = radius * cos(theta);
                *pPositions++ = radius * sin(theta);
            }
            GLsizeiptr size = sizeof(positions);
            glBindBuffer(GL_ARRAY_BUFFER, circleVbo);
            glBufferData(GL_ARRAY_BUFFER, size, positions, GL_STATIC_DRAW);
            GLsizeiptr stride = 2*sizeof(positions[0]);
            glVertexAttribPointer(slotPosition, 2, GL_FLOAT, GL_FALSE, stride, 0);
            glDrawArrays(GL_TRIANGLES, 0, slices*3);
        }
    }
    glDeleteProgram(program.getHandle());
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &lineVbo);
    glDeleteBuffers(1, &circleVbo);
}



void Scene::advect(Surface velocity, Surface source, Surface obstacles,
                   Surface dest, float dissipation)
{
    programs.Advect.use();

    programs.Advect.setUniform("InverseSize", glm::vec3(float(1.0f/gridWidth),
                                                        float(1.0f/gridHeight), float(1.0f/gridDepth)));
    programs.Advect.setUniform("TimeStep", timeStep);
    programs.Advect.setUniform("Dissipation", dissipation);
    programs.Advect.setUniform("SourceTexture", 1);
    programs.Advect.setUniform("Obstacles", 2);

    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D, velocity.colorTexture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_3D, source.colorTexture);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_3D, obstacles.colorTexture);

    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, dest.depth);
    resetState();
}

void Scene::jacobi(Surface pressure, Surface divergence, Surface obstacles, Surface dest)
{
    programs.Jacobi.use();

    programs.Jacobi.setUniform("Alpha", -cellSize*cellSize);
    programs.Jacobi.setUniform("InverseBeta", 0.1666f);
    programs.Jacobi.setUniform("Divergence", 1);
    programs.Jacobi.setUniform("Obstacles", 2);

    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D, pressure.colorTexture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_3D, divergence.colorTexture);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_3D, obstacles.colorTexture);

    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, dest.depth);
    resetState();
}

void Scene::subtractGradient(Surface velocity, Surface pressure, Surface obstacles,
                             Surface dest)
{
    programs.SubtractGradient.use();

    programs.SubtractGradient.setUniform("GradientScale", gradientScale);
    programs.SubtractGradient.setUniform("Pressure", 1);
    programs.SubtractGradient.setUniform("Obstacles", 2);

    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D, velocity.colorTexture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_3D, pressure.colorTexture);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_3D, obstacles.colorTexture);

    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, dest.depth);
    resetState();
}

void Scene::computeDivergence(Surface velocity, Surface obstacles, Surface dest)
{
    programs.ComputeDivergence.use();

    programs.ComputeDivergence.setUniform("HalfInverseCellSize", 0.5f/cellSize);
    programs.ComputeDivergence.setUniform("Obstacles", 1);

    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D, velocity.colorTexture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_3D, obstacles.colorTexture);

    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, dest.depth);
    resetState();
}

void Scene::applyImpulse(Surface dest, glm::vec3 position, float value)
{
    programs.ApplyImpulse.use();

    programs.ApplyImpulse.setUniform("Point", position);
    programs.ApplyImpulse.setUniform("Radius", splatRadius);
    programs.ApplyImpulse.setUniform("FillColor", glm::vec3(value));

    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glEnable(GL_BLEND);
    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, dest.depth);
    resetState();
}

void Scene::applyBuoyancy(Surface velocity, Surface temperature, Surface density, Surface dest)
{
    programs.ApplyBuoyancy.use();

    programs.ApplyBuoyancy.setUniform("Temperature", 1);
    programs.ApplyBuoyancy.setUniform("Density", 2);
    programs.ApplyBuoyancy.setUniform("AmbientTemperature", ambientTemperature);
    programs.ApplyBuoyancy.setUniform("TimeStep", timeStep);
    programs.ApplyBuoyancy.setUniform("Sigma", smokeBuoyancy);
    programs.ApplyBuoyancy.setUniform("Kappa", smokeWeight);

    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D, velocity.colorTexture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_3D, temperature.colorTexture);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_3D, density.colorTexture);

    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, dest.depth);
    resetState();
}









