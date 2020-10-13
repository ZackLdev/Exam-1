/**
 * \file InvasivePlant.h
 *
 * \author Ziyu Liu
 */

#pragma once

#include "Plant.h"


class CInvasivePlant : public CPlant
{
public:
	CInvasivePlant() = delete;

	CInvasivePlant(std::wstring name, std::wstring description);

	~CInvasivePlant(){}

	virtual std::wstring DisplayDescription() { return CPlant::DisplayDescription() + L" [invasive]"; };

	virtual std::wstring DisplayIncompatible() { return L"All"; };
};

