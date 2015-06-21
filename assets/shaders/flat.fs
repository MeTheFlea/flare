#version 330 core

in vec3 f_positionW;
in vec3 f_normalW;
in vec2 f_uv;

out vec4 out_colour;

uniform sampler2D tex0;

void main() {
	out_colour = texture( tex0, f_uv );
}