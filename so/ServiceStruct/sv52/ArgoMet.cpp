#include "../../stdafx.h"
#include "ArgoMet.h"

ArgoMet::ArgoMet()
{
}


ArgoMet::~ArgoMet()
{
}

void ArgoMet::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "svext/ArgoMet;get";
}

