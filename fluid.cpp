#include "fluid.h"

Fluid::Fluid()
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
    //Visualize
    if(!programs.Visualize.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/raycast.vs",
                                                 GLSLShader::VERTEX))
    {
        printf("Visualize::Vertex shader failed to compile!\n%s",
               programs.Visualize.log().c_str());
        exit(1);
    }
    if(!programs.Visualize.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/raycast.gs",
                                                 GLSLShader::GEOMETRY))
    {
        printf("Visualize::Geometry shader failed to compile!\n%s",
               programs.Visualize.log().c_str());
        exit(1);
    }
    if(!programs.Visualize.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/raycast.fs",
                                                 GLSLShader::FRAGMENT))
    {
        printf("Visualize::Fragment shader failed to compile!\n%s",
               programs.Visualize.log().c_str());
        exit(1);
    }
    if(!programs.Visualize.link())
    {
        printf("Visualize::Shaders failed to link!\n%s",
               programs.Visualize.log().c_str());
        exit(1);
    }
}

void Fluid::initFluid()
{
    velocity = createSlab(gridWidth, gridHeight, gridDepth, 3);
    density = createSlab(gridWidth, gridHeight, gridDepth, 1);
    pressure = createSlab(gridWidth, gridHeight, gridDepth, 1);
    temperature = createSlab(gridWidth, gridHeight, gridDepth, 1);

    divergence = createVolume(gridWidth, gridHeight, gridDepth, 3);
    obstacles = createVolume(gridWidth, gridHeight, gridDepth, 3);
    createObstacles(obstacles);// In this func program has been used and then glDrawArrays is called, vao should be defined after it
    clearVolume(temperature.ping, ambientTemperature);
    cubeCenter = createPointVao(0, 0, 0);
    fullScreenQuad = createQuadVao();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    model = mat4(1.0f);
    projection = mat4(1.0f);
}


void Fluid::renderFluid(glm::vec3 cameraPos, glm::mat4 cameraView, glm::mat4 cameraProjection)
{
    //update
    programs.Visualize.setUniform("ModelViewProjection", cameraProjection*cameraView*model);

    glViewport(0, 0, gridWidth, gridHeight);
    advect(velocity.ping, velocity.ping, obstacles, velocity.pong, velocityDissipation);
    swapVolumes(&velocity);
    advect(velocity.ping, temperature.ping, obstacles, temperature.pong, temperatureDissipation);
    swapVolumes(&temperature);
    advect(velocity.ping, density.ping, obstacles, density.pong, densityDissipation);
    swapVolumes(&density);

    applyBuoyancy(velocity.ping, temperature.ping, density.ping, velocity.pong);
    swapVolumes(&velocity);
    applyImpulse(temperature.ping, impulsePosition, impulseTemperature);
    applyImpulse(density.ping, impulsePosition, impulseDensity);

    computeDivergence(velocity.ping, obstacles, divergence);
    clearVolume(pressure.ping, 0);
    for(int i=0;i<numJacobiIterations;i++)
    {
        jacobi(pressure.ping, divergence, obstacles, pressure.pong);
        swapVolumes(&pressure);
    }
    subtractGradient(velocity.ping, pressure.ping, obstacles, velocity.pong);
    swapVolumes(&velocity);

    //render
    programs.Visualize.use();
    glEnable(GL_BLEND);

    glViewport(0, 0, viewportWidth, viewportHeight);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //set the view
    projection = cameraProjection;
    view = cameraView;
    programs.Visualize.setUniform("ModelViewProjection", projection*view*model);
    //draw ink
    glBindTexture(GL_TEXTURE_3D, density.ping.textureHandle);
    programs.Visualize.setUniform("FillColor", vec3(1));
    programs.Visualize.setUniform("Scale", vec3(1.0f/viewportWidth, 1.0f/viewportHeight,
                                                1.0f/viewportWidth));
    glDrawArrays(GL_POINTS, 0, 1);

    //draw obstacles
    //glBindTexture(GL_TEXTURE_3D, obstacles.textureHandle);
    //programs.Visualize.setUniform("FillColor", vec3(0.125f, 0.4f, 0.75f));
    //glDrawArrays(GL_POINTS, 0, 1);

}



Slab Fluid::createSlab(GLsizei width, GLsizei height, GLsizei depth, int numComponent)
{
    Slab temp;
    temp.ping = createVolume(width, height, depth, numComponent);
    temp.pong = createVolume(width, height, depth, numComponent);
    return temp;
}

Volume Fluid::createVolume(GLsizei width, GLsizei height, GLsizei depth, int numComponent)
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
        printf("CreateVolume::numComponent error!\n");
        exit(1);
    }

    //GLuint colorbuffer;
    //glGenRenderbuffers(1, &colorbuffer);
    //glBindRenderbuffer(GL_RENDERBUFFER, colorbuffer);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, textureHandle, 0);
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER)!=GL_FRAMEBUFFER_COMPLETE)
    {
        printf("CreateVolume::Framebuffer is not complete!\n");
    }

    Volume volume = {fboHandle, textureHandle, width, height, depth};

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    return volume;
}

GLuint Fluid::createPointVao(float x, float y, float z)
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte*)NULL+(0)));
    return vao;
}

GLuint Fluid::createQuadVao()
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
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_SHORT, GL_FALSE, 0, ((GLubyte*)NULL+(0)));
    return vao;
}

void Fluid::createObstacles(Volume dest)
{
    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glViewport(0, 0, dest.width, dest.height);
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    GLSLProgram tempObstacle;
    if(!tempObstacle.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/vertex.vs",
                                           GLSLShader::VERTEX))
    {
        printf("CreateObstacles::Vertex shader failed to compile!\n%s",
               tempObstacle.log().c_str());
        exit(1);
    }
    if(!tempObstacle.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/fluid3d/fluid3d/shaders/fill.fs",
                                           GLSLShader::FRAGMENT))
    {
        printf("CreateObstacles::Fragment shader failed to compile!\n%s",
               tempObstacle.log().c_str());
        exit(1);
    }
    if(!tempObstacle.link())
    {
        printf("CreateObstacles::Shaders failed to link!\n%s",
               tempObstacle.log().c_str());
        exit(1);
    }
    tempObstacle.use();

    GLuint lineVbo;
    glGenBuffers(1, &lineVbo);
    glEnableVertexAttribArray(0);

    for(int slice=0;slice<dest.depth;slice++)
    {
        glFramebufferTextureLayer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, dest.textureHandle,
                                  0, dest.depth-1-slice);
        if(slice!=0 && slice!=dest.depth-1)
        {
            const float T = 0.9999f;
            float positions[] = {
                -T, -T,
                 T, -T,
                 T,  T,
                -T,  T,
                -T, -T
            };
            glBindBuffer(GL_ARRAY_BUFFER, lineVbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, ((GLubyte*)NULL+(0)));
            glDrawArrays(GL_LINE_STRIP, 0, 5);
        }
        //slice==0 || slice==dest.depth
    }
    glDeleteProgram(tempObstacle.getHandle());
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &lineVbo);
}



void Fluid::resetState()
{
    glActiveTexture(GL_TEXTURE2); glBindTexture(GL_TEXTURE_3D, 0);
    glActiveTexture(GL_TEXTURE1); glBindTexture(GL_TEXTURE_3D, 0);
    glActiveTexture(GL_TEXTURE0); glBindTexture(GL_TEXTURE_3D, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDisable(GL_BLEND);
}

void Fluid::swapVolumes(Slab* slab)
{
    Volume temp = slab->ping;
    slab->ping = slab->pong;
    slab->pong = temp;
}

void Fluid::clearVolume(Volume volume, float value)
{
    glBindFramebuffer(GL_FRAMEBUFFER, volume.fboHandle);
    glClearColor(value, value, value, value);
    glClear(GL_COLOR_BUFFER_BIT);
}



void Fluid::advect(Volume velocity, Volume source, Volume obstacles,
                   Volume dest, float dissipation)
{
    programs.Advect.use();
    programs.Advect.setUniform("InverseSize", vec3(float(1.0/gridWidth),
                                                   float(1.0/gridHeight),
                                                   float(1.0/gridDepth)));
    programs.Advect.setUniform("TimeStep", timeStep);
    programs.Advect.setUniform("Dissipation", dissipation);
    programs.Advect.setUniform("SourceTexture", 1);
    programs.Advect.setUniform("Obstacles", 2);

    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D, velocity.textureHandle);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_3D, source.textureHandle);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_3D, obstacles.textureHandle);

    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, dest.depth);
    resetState();
}

void Fluid::jacobi(Volume pressure, Volume divergence, Volume obstacles, Volume dest)
{
    programs.Jacobi.use();
    programs.Jacobi.setUniform("Alpha", -cellSize*cellSize);
    programs.Jacobi.setUniform("InverseBeta", 0.1666f);
    programs.Jacobi.setUniform("Divergence", 1);
    programs.Jacobi.setUniform("Obstacles", 2);

    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D, pressure.textureHandle);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_3D, divergence.textureHandle);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_3D, obstacles.textureHandle);

    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, dest.depth);
    resetState();
}

void Fluid::subtractGradient(Volume velocity, Volume pressure, Volume obstacles, Volume dest)
{
    programs.SubtractGradient.use();
    programs.SubtractGradient.setUniform("GradientScale", gradientScale);
    programs.SubtractGradient.setUniform("Pressure", 1);
    programs.SubtractGradient.setUniform("Obstacles", 2);

    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D, velocity.textureHandle);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_3D, pressure.textureHandle);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_3D, obstacles.textureHandle);

    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, dest.depth);
    resetState();
}

void Fluid::computeDivergence(Volume velocity, Volume obstacles, Volume dest)
{
    programs.ComputeDivergence.use();
    programs.ComputeDivergence.setUniform("HalfInverseCellSize", 0.5f/cellSize);
    programs.ComputeDivergence.setUniform("Obstacles", 1);

    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_3D, velocity.textureHandle);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_3D, obstacles.textureHandle);

    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, dest.depth);
    resetState();
}

void Fluid::applyImpulse(Volume dest, glm::vec3 position, float value)
{
    programs.ApplyImpulse.use();
    programs.ApplyImpulse.setUniform("Point", position);
    programs.ApplyImpulse.setUniform("Radius", splatRadius);
    programs.ApplyImpulse.setUniform("FillColor", vec3(value));

    glBindFramebuffer(GL_FRAMEBUFFER, dest.fboHandle);
    glEnable(GL_BLEND);
    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, dest.depth);
    resetState();
}

void Fluid::applyBuoyancy(Volume velocity, Volume temperature, Volume density, Volume dest)
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
    glBindTexture(GL_TEXTURE_3D, velocity.textureHandle);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_3D, temperature.textureHandle);
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_3D, density.textureHandle);

    glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 4, dest.depth);
    resetState();
}


