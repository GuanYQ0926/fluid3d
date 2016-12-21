#version 440

out vec4 FragColor;

uniform sampler3D Sampler;
uniform vec3 Scale;
uniform vec3 FillColor;

void main()
{
    float L = texture(Sampler, gl_FragCoord.xyz*Scale).r;
    FragColor = vec4(1, 0, 0, 1);
}
