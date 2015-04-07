#pragma once
#include "external/stl.h"

namespace flare {
	template <class TGame>
	class Engine;

	class TimeManager {
	public:
		TimeManager();
		~TimeManager();

		inline float GetDeltaTime() const { return m_deltaTime; }
		inline float GetUnscaledDeltaTime() const { return m_unscaledDeltaTime; }

		inline void SetTimescale( const float a_timescale ) { m_timescale = a_timescale; }



	private:
		template <class TGame>
		friend class Engine;

		float m_unscaledDeltaTime;
		float m_deltaTime;
		float m_timescale;
		
		void SetDeltaTime( const float a_deltaTime );
		void StartFrame();

		std::chrono::system_clock::time_point m_currentTime;
	};
}

extern flare::TimeManager Time;