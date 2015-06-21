#version 430

out vec4 out_colour;

uniform vec3 diffuseColour;

void main() {
	out_colour = vec4( diffuseColour, 1.0f );
}