#version 330 core

in vec3 f_positionW;
in vec3 f_normalW;
in vec2 f_uv;

out vec4 out_colour;

uniform vec3 diffuseColour;
uniform vec3 cameraPosition;

void main() {
	out_colour = vec4( diffuseColour * max( 0.2f, dot( f_normalW, normalize( cameraPosition - f_positionW ) ) ), 1.0f );
}