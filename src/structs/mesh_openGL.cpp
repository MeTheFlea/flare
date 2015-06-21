#include "structs/mesh_openGL.h"
#include "structs/vertex.h"
#include "structs/mesh.h"

using namespace flare;

#define VERTEX_ATTRIB( name, index, floats, member )\
	GLint name = index;\
	glVertexAttribPointer( name, floats, GL_FLOAT, false, sizeof( Vertex ), (void*)offsetof( Vertex, member ) );\
	glEnableVertexAttribArray( name )

Mesh_OpenGL::Mesh_OpenGL() {
	
}

Mesh_OpenGL::~Mesh_OpenGL() {
	Clean();
}

void Mesh_OpenGL::Refresh( const Mesh& a_mesh ) {
	Clean();
	Set( a_mesh );
}

void Mesh_OpenGL::Render( const Mesh& a_mesh ) {
	glBindVertexArray( m_vao );
	glDrawElements( GL_TRIANGLES, a_mesh.m_vertexIndices.size(), GL_UNSIGNED_INT, a_mesh.m_vertexIndices.data() );
}

void Mesh_OpenGL::Clean() {
	glDeleteVertexArrays( 1, &m_vao );
	glDeleteBuffers( 1, &m_vertexBuffer );
}

void Mesh_OpenGL::Set( const Mesh& a_mesh ) {
	glGenVertexArrays( 1, &m_vao );
	glGenVertexArrays( 1, &m_vertexBuffer );

	glBindVertexArray( m_vao );

	glBindBuffer( GL_ARRAY_BUFFER, m_vertexBuffer );
	glBufferData( GL_ARRAY_BUFFER, sizeof( Vertex ) * a_mesh.m_vertices.size(), a_mesh.m_vertices.data(), GL_STATIC_DRAW );

	VERTEX_ATTRIB( posLoc, 0, 3, m_position );
	VERTEX_ATTRIB( normalLoc, 1, 3, m_normal );
	VERTEX_ATTRIB( binormalLoc, 2, 3, m_binormal );
	VERTEX_ATTRIB( tangentLoc, 3, 3, m_tangent );

	VERTEX_ATTRIB( uvLoc, 4, 2, m_uv );

	glBindVertexArray( 0 );
	glBindBuffer( GL_ARRAY_BUFFER, 0 );
}