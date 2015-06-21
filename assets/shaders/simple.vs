#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec2 in_uv;
layout(location = 3) in vec3 in_binormal;
layout(location = 4) in vec3 in_tangent;

out vec3 f_positionW;
out vec3 f_normalW;
out vec2 f_uv;
out float gl_ClipDistance[1];

uniform mat4 mvp;
uniform mat4 modelMat;
uniform vec4 clipPlane;

void main() {
	gl_Position = mvp * vec4( in_position, 1 );
	
	f_positionW = ( modelMat * vec4( in_position, 1 ) ).xyz;
	f_normalW = ( modelMat * vec4( in_normal, 0 ) ).xyz;
	f_uv = in_uv;
	
	gl_ClipDistance[0] = dot( modelMat * vec4( in_position, 1 ), clipPlane );
}