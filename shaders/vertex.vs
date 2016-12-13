#version 440

layout (location = 0) in vec4 Position;
out int vInstance;

void main()
{
    gl_Position = Position;
    vInstance = gl_InstanceID;
}
