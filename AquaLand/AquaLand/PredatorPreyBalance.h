#pragma once

#include "ItemVisitor.h"

/**
* A visitor that will check if there are too 
* many predators than prey.
* 
* Too many in this case is if there are less
* than twice as many prey as predators.
*/
class CPredatorPreyBalance
	: public CItemVisitor
{
public:
	virtual ~CPredatorPreyBalance() {};

	virtual void VisitFishAngler(CFishAngler* item) override;

	virtual void VisitFishBeta(CFishBeta* fish) override;

	virtual void VisitFishMolly(CFishMolly* fish) override;

	virtual void VisitFishNemo(CFishNemo* fish) override;

	bool TooManyPredators();
};

