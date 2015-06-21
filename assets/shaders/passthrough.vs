#version 430 

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec2 in_uv;
layout(location = 3) in vec3 in_binormal;
layout(location = 4) in vec3 in_tangent;

out vec3 v_positionW;
out vec3 v_normalW;
out vec2 v_uv;
out mat4 v_mvp;

uniform mat4 mvp;
uniform mat4 modelMat;
uniform vec4 clipPlane;

out gl_PerVertex {
  vec4 gl_Position;
  float gl_PointSize;
  float gl_ClipDistance[];
};

void main() {
	v_uv = in_uv;
	gl_Position = vec4( in_position, 1.0f );
	
	v_mvp = mvp;
	
}