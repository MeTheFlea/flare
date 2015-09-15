#include "structs/model.h"
#include "graphics/renderer.h"
#include "core/logger.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "structs/mesh_platform.h"
using namespace flare;

Model::Model( std::string a_filepath ) {
	Assimp::Importer importer;

	const aiScene* pScene = importer.ReadFile( a_filepath, aiProcess_CalcTangentSpace | aiProcess_JoinIdenticalVertices | aiProcess_GenNormals | aiProcess_Triangulate );

	if( !pScene ) {
		Log.Fatal( "File: %s could not be loaded! Error code: %s", a_filepath.c_str(), importer.GetErrorString() );	
	}
	else {
		for( unsigned int i = 0; i < pScene->mNumMeshes; ++i ) {
			m_meshes.emplace_back();
			Mesh& mesh = m_meshes[m_meshes.size()-1];
			
			aiMesh*& currentMesh = pScene->mMeshes[i];

			for( unsigned int j = 0; j < currentMesh->mNumVertices; ++j ) {
				glm::vec3 pos( currentMesh->mVertices[j].x, currentMesh->mVertices[j].y, currentMesh->mVertices[j].z );

				glm::vec3 normal;
				if( currentMesh->HasNormals() ) {
					normal = glm::vec3( currentMesh->mNormals[j].x, currentMesh->mNormals[j].y, currentMesh->mNormals[j].z );
				}
				glm::vec3 binormal;
				glm::vec3 tangent;
				if( currentMesh->HasTangentsAndBitangents() ) {
					binormal = glm::vec3( currentMesh->mBitangents[j].x, currentMesh->mBitangents[j].y, currentMesh->mBitangents[j].z );
					tangent = glm::vec3( currentMesh->mTangents[j].x, currentMesh->mTangents[j].y, currentMesh->mTangents[j].z );
				}
				glm::vec2 uv;
				if( currentMesh->HasTextureCoords( 0 ) ) {
					uv = glm::vec2( currentMesh->mTextureCoords[0][j].x, currentMesh->mTextureCoords[0][j].y );
				}

				mesh.m_vertices.emplace_back( pos, normal, uv, binormal, tangent );
			}

			for( unsigned int j = 0; j < currentMesh->mNumFaces; ++j ) {
				mesh.m_vertexIndices.push_back( currentMesh->mFaces[j].mIndices[0] );
				mesh.m_vertexIndices.push_back( currentMesh->mFaces[j].mIndices[1] );
				mesh.m_vertexIndices.push_back( currentMesh->mFaces[j].mIndices[2] );
			}

		}
	}
}

void Model::Render() {
	for( unsigned int i = 0; i < m_meshes.size(); ++i ) {
		m_meshes[i].m_pMesh->Render( m_meshes[i] );
	}
}


void Model::Refresh( Renderer::GraphicsAPI a_api ) {
	for( size_t i = 0; i < m_meshes.size(); ++i ) {
		m_meshes[i].Refresh( a_api );
	}
}