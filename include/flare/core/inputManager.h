#pragma once
#include "external/stl.h"

namespace flare {
	template <class TGame>
	class Engine;

	enum class KeyCode : unsigned char {
		A = 0U, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		ESCAPE, RETURN, SPACE, LSHIFT, RSHIFT, LALT, RALT, BACKSPACE, TAB,
		Count
	};

	class InputManager {
	public:
		InputManager();
		~InputManager();

		// This will add a mapping from a string to a KeyCode
		void AddKeyMap( const std::string& a_map, const KeyCode& a_key );
		// This will remove a mapping from a string to a KeyCode
		void RemoveKeyMap( const std::string& a_map, const KeyCode& a_key );

		// Down happens once on first key press
		bool GetButtonDown( const std::string& a_button ) const;
		bool GetKeyDown( const KeyCode& a_key ) const;

		// This is true as long as a key is depressed
		bool GetButton( const std::string& a_button ) const;
		bool GetKey( const KeyCode& a_key ) const;
		
		// Up happens once on first key release
		bool GetKeyUp( const KeyCode& a_key ) const;
		bool GetButtonUp( const std::string& a_button ) const;
	private:
		template <class TGame>
		friend class flare::Engine;
		
		typedef size_t Key;
		typedef std::pair<std::unordered_map<Key, KeyCode>::const_iterator, std::unordered_map<Key, KeyCode>::const_iterator> ButtonKeyCodes;

		bool m_keyState[(unsigned char)KeyCode::Count];
		bool m_keyChange[(unsigned char)KeyCode::Count];

		const Key HashString( const std::string& a_string ) const;
		void SetKey( const KeyCode& a_key, const bool a_value );
		void Reset();

		
		ButtonKeyCodes GetKeysFromButton( const std::string& a_button ) const;

		std::unordered_multimap<Key, KeyCode> m_inputMap;
	};
}

extern flare::InputManager Input;