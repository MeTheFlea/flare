#include "core/inputManager.h"
using namespace flare;

InputManager Input;

InputManager::InputManager() {
	Reset();
}

InputManager::~InputManager() {
	
}

bool InputManager::GetKeyDown( const KeyCode& a_key ) const {
	return m_keyChange[(unsigned char)a_key] && m_keyState[(unsigned char)a_key];
}

bool InputManager::GetKey( const KeyCode& a_key ) const {
	return m_keyState[(unsigned char)a_key];
}

bool InputManager::GetKeyUp( const KeyCode& a_key ) const {
	return m_keyChange[(unsigned char)a_key] && !m_keyState[(unsigned char)a_key];
}

bool InputManager::GetButtonDown( const std::string& a_button ) const {
	auto findResult = GetKeysFromButton( a_button );

	for( auto it = (findResult).first; it != (findResult).second; ++it ) {
		KeyCode key = (*it).second;
		
		if( GetKeyDown( key ) ) {
			return true;
		}
	}

	return false;
}

bool InputManager::GetButtonUp( const std::string& a_button ) const {
	auto findResult = GetKeysFromButton( a_button );

	for( auto it = (findResult).first; it != (findResult).second; ++it ) {
		KeyCode key = (*it).second;
		
		if( GetKeyUp( key ) ) {
			return true;
		}
	}

	return false;
}

bool InputManager::GetButton( const std::string& a_button ) const {
	auto findResult = GetKeysFromButton( a_button );

	for( auto it = (findResult).first; it != (findResult).second; ++it ) {
		KeyCode key = (*it).second;
		
		if( GetKey( key ) ) {
			return true;
		}
	}

	return false;
}

InputManager::ButtonKeyCodes InputManager::GetKeysFromButton( const std::string& a_button ) const {
	const Key hashed = HashString( a_button );

	auto findResult = m_inputMap.equal_range( hashed );
	if( findResult.first == findResult.second ) {
		// TODO: warn that key is not in map
	}
	return findResult;
}

InputManager::Key InputManager::HashString( const std::string& a_string ) const {
	static std::hash<std::string> hashFunc;
	return hashFunc( a_string );
}

void InputManager::SetKey( const KeyCode& a_key, const bool a_value ) {
	if( m_keyState[(unsigned char)a_key] != a_value ) {
		m_keyChange[(unsigned char)a_key] = true;
		m_keyState[(unsigned char)a_key] = a_value;
	}
}

void InputManager::Reset() {
	memset( m_keyChange, false, sizeof( m_keyChange ) );
}

void InputManager::AddKeyMap( const std::string& a_map, const KeyCode& a_key ) {
	const Key hashed = HashString( a_map );
	bool duplicate = false;
	
	auto findResult = m_inputMap.equal_range( hashed );
	for( auto it = (findResult).first; it != (findResult).second; ++it ) {
		if( (*it).second == a_key ) {
			duplicate = true;
			break;
		}
	}

	if( !duplicate ) {
		m_inputMap.insert( std::pair<Key, KeyCode>( hashed, a_key ) );
	}
}

void InputManager::RemoveKeyMap( const std::string& a_map, const KeyCode& a_key ) {
	const Key hashed = HashString( a_map );
	
	auto findResult = m_inputMap.equal_range( hashed );
	for( auto it = (findResult).first; it != (findResult).second; ++it ) {
		if( (*it).second == a_key ) {
			m_inputMap.erase( (it) );
			break;
		}
	}

}