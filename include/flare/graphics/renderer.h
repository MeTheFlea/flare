#pragma once
#include "external/stl.h"

namespace flare {
	class Model;

	class Renderer { 
	public:
		~Renderer();

		static Renderer* GetInstance();

		void Render();
		void AddToQueue( Model* a_model );
		//void AddToQueue( Mesh* a_mesh ); // shader and mesh

		virtual void ClearFrame() = 0;
		// normalised between 0.0f - 1.0f
		virtual void SetClearColour( float a_red, float a_green, float a_blue, float a_alpha = 1.0f ) = 0;

		enum class GraphicsAPI : unsigned char {
			Unknown = 0,
			OpenGL
		};

		static GraphicsAPI GetGraphicsAPI() {
			return GetInstance()->m_api;
		}
	protected:
		Renderer();
		GraphicsAPI m_api;

	private:
		static Renderer* s_instance;

		std::vector<Model*> m_renderQueue;
	};

}