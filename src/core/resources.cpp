#include "core/resources.h"

#include "structs/model.h"

using namespace flare;

Resources* Resources::s_instance = nullptr;

Resources::Resources() :
	m_assetDir( "assets/" ) {

}

Resources::~Resources() {

}

Resources* Resources::GetInstance() {
	if( s_instance == nullptr ) {
		s_instance = new Resources();
	}
	return s_instance;
}

void Resources::SetAssetDir( std::string a_assetDir ) { 
	m_assetDir = a_assetDir;
}

Model* Resources::LoadModel( std::string a_filepath ) {
	std::string filepath = m_assetDir + "models/" + a_filepath;

	Model* pModel = new Model( filepath.c_str() );
	pModel->Refresh( Renderer::GetGraphicsAPI() );

	return pModel;
}