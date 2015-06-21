#version 330 core

in vec3 f_positionW;
in vec3 f_normalW;
in vec2 f_uv;

out vec4 out_colour;

void main() {
	out_colour = vec4( 1, 0, 1, 1 );
}