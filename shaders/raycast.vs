#version 440

in vec4 Position;
out vec4 vPosition;
uniform mat4 ModelViewProjection;

void main()
{
    gl_Position = ModelViewProjection * Position;
    vPosition = Position;
}
