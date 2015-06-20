#pragma once

namespace flare {
	class Renderer { 
	public:
		~Renderer();

		static Renderer* GetInstance();

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
	};

}