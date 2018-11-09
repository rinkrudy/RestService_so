

#include "../../stdafx.h"
#include "CatalogueAll.h"


CatalogueAll::CatalogueAll()
{
}


CatalogueAll::~CatalogueAll()
{
}

void CatalogueAll::Init(){
	m_arrRestUrl[(int)Service::E_RestType::eSelect] = "sv40/catalogue/CatalogueAll;get";
}

//TEST
//#define AFIELD_S(fld)	CopyStringToWchar(pArray->fld, array[i].at(U(STRING(fld))).as_string().c_str()) //string
//#define AFIELD_I(fld)	pArray->fld = array[i].at(U(STRING(fld))).as_integer() //int
//
//#define FIELD_I(fld)	p->fld = root->at(U(STRING(fld))).as_integer() //int
//#define FIELD_S(fld)	CopyStringToWchar(p->fld, root->at(U(STRING(fld))).as_string().c_str()) //string
//#define FIELD_B(fld)	p->fld = root->at(U(STRING(fld))).as_bool() //int


void * CatalogueAll::GetStruct(json::value * root)
{

	auto array = root->at("data").as_array();

	int iArrayCount = array.size();
	DB_Catalogue *p;
	if (iArrayCount == 0)//�����Ͱ� ������� �ʱ�ȭ��  Struct return
	{
		return nullptr;
	}
	else
	{
		p = (DB_Catalogue *)malloc(sizeof(DB_Catalogue)*iArrayCount);
		memset(p, 0, sizeof(DB_Catalogue));
		DB_Catalogue *pArray = p;

		//���ڿ� ����
		for (int i = 0; i < iArrayCount; i++)
		{
			//EnaviBase.h ���Ͽ� ���ǵǾ� ����
			//���ڿ� ����
			AFIELD_I(catalogid);
			AFIELD_S(idIdentifier);
			AFIELD_I(idEditionnumber);
			AFIELD_S(idDate);
			AFIELD_S(exchangecatalogname);
			AFIELD_S(category);
			AFIELD_S(cataloguepath);
			AFIELD_S(fileuri);
			AFIELD_S(filedmzuri);
			AFIELD_S(filename);
			AFIELD_S(zone);
			AFIELD_S(productversion);
			AFIELD_S(encrypt);
			AFIELD_S(enctype);
			AFIELD_S(productdate);
			AFIELD_I(filesize);
			AFIELD_S(hash);

			pArray++;
		}
	}
	
	return p;
}
