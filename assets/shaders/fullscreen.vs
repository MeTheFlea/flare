#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec2 in_uv;
layout(location = 3) in vec3 in_binormal;
layout(location = 4) in vec3 in_tangent;

out vec4 f_position;
out vec2 f_uv;

void main() {
	f_position = vec4( in_position, 1 );
	f_uv = in_uv;
	gl_Position = f_position;
}