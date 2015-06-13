#include "entity/entityTest.h"
using namespace flare;

EntityTest::EntityTest() {
	
}

void EntityTest::SetNumber( int a_number ) {
	if( m_numberPrint == nullptr ) { 
		m_numberPrint = AddComponent<PrintNumberComponent>();
	}
	m_numberPrint->m_number = a_number;
}

void EntityTest::PrintNumber() {
	if( m_numberPrint == nullptr ) { 
		m_numberPrint = AddComponent<PrintNumberComponent>();
	}
	m_numberPrint->PrintNumber();
}

void EntityTest::DeleteComponent() {
	DestroyComponent( m_numberPrint );
}