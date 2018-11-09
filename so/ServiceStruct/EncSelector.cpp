#include "../stdafx.h"
#include "EncSelector.h"

EncSelector::EncSelector()
{
}


EncSelector::~EncSelector()
{
}

void EncSelector::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "enc/getFeatureByLine;get";
}

