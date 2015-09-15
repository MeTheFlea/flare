#pragma once
#include "external/stl.h"

namespace flare {
	class Model;
	class Resources {
	public:
		static Resources* GetInstance();
		~Resources();

		void SetAssetDir( std::string a_assetDir );

		Model* LoadModel( std::string a_filepath );


	private:
		Resources();
		static Resources* s_instance;

		std::string m_assetDir;
	};

}