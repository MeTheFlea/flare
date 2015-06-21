#version 430

layout( points ) in;
layout( triangle_strip, max_vertices = 3 ) out;

in vec3 v_positionW[];
in vec3 v_normalW[];
in vec2 v_uv[];
in mat4 v_mvp[];

in gl_PerVertex {
  vec4 gl_Position;
  float gl_PointSize;
  float gl_ClipDistance[];
} gl_in[];

out gl_PerVertex {
  vec4 gl_Position;
  float gl_PointSize;
  float gl_ClipDistance[];
};

void main() {
	gl_Position = v_mvp[0] * ( gl_in[0].gl_Position + vec4( 10.0f, 0.0f, 0.0f, 0.0f ) );
	EmitVertex();
	
	gl_Position = v_mvp[0] * ( gl_in[0].gl_Position + vec4( 0.0f, 10.0f, 0.0f, 0.0f ) );
	EmitVertex();
	
	gl_Position = v_mvp[0] * ( gl_in[0].gl_Position + vec4( -10.0f, 0.0f, 0.0f, 0.0f ) );
	EmitVertex();
	
	EndPrimitive();
    
}
